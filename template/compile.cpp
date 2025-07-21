#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <cstdlib> // for system()

using namespace std;
namespace fs = std::filesystem;

void clear();

int main(int argc, char* argv[]) {
    string fileName;
    string targetDir = ""; 
    bool isTdInitialized = false;

    do {
        cout << endl
             << "Select your query:" << endl
             << "1) Set a target directory" << (isTdInitialized ? " (currently set at " + targetDir + ")" : "") << endl
             << "2) Compile a cpp file" << endl
             << "3) Test your compiled file" << endl
             << "4) Quit" << endl
             << ">> ";

        int k; cin >> k;
        clear();
        if (k == 1) {
            cout << "Enter your directory path >> ";
            string s; 
            cin >> s;

            if (!fs::exists(s)) {
                cout << "Oops, " << s << " does not exist!" << endl
                     << "Would you like to create the new directory based on the template? (y/n) >> ";
                char c; cin>>c;
                if(c!='y'&&c!='Y')  {
                    cout << "A directory was neither selected nor created." << endl;
                    continue;
                }
                cout << "Which contest are you attending today?" << endl;
                string dirName; cin>>dirName;
    
                if(filesystem::exists(dirName)) {
                    cerr << "Error: " << dirName << " already exists!" << endl; return 0;
                }

                filesystem::create_directories(dirName); 

                const string names[] = {"A", "B", "C", "D", "E", "F", "G"};
                const string templatePath = "template/template.cpp";

                ifstream in(templatePath);
                if(!in) {
                    cerr << "Error: template file not found!" << endl; 
                    cout << "Tips: create a template file at " << templatePath << " :)" << endl;
                    return 0;
                }
                
                string templ((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
                for(const auto& filename : names) {
                    string outPath = dirName + "/" + filename+ ".cpp";
                    ofstream out(outPath);
                    if(!out) {
                        cerr << "Error: failed to create a file " << outPath << endl; return 0;
                    }
                    out << templ;
                }
                clear();
                cout << "A directory for contest " << dirName << " was successfully created!" << endl;
            }
            targetDir = s; isTdInitialized = true;
            cout << "Target directory successfully set at " << targetDir << endl;
        } 
        else if (k == 2) {
            if (!isTdInitialized) {
                cerr << "Error: Target directory not set!" << endl;
                continue;
            }
            cout << "Enter your file name with its extension >> ";
            string s; cin >> s;
            string path = targetDir + '/' + s;

            if (!fs::exists(path)) {
                cerr << "Error: No file found at " << path << endl;
                continue;
            }
            string outputPath = "test.exe";
            if (filesystem::exists(outputPath)) filesystem::remove(outputPath);

            string compileCmd = "g++ " + path + " -o " + outputPath;

            clear();
            int result = system(compileCmd.c_str());
            if (result == 0) {
                cout << "Successfully generated output file: " << outputPath << endl;
            } else {
                cerr << "Failed to compile " << path << " ;-;" << endl;
            }
        } 
        else if (k == 3) {
            if (!fs::exists("test.exe")) {
                cerr << "Error: 'test.exe' not found. Compile a file first!" << endl;
                continue;
            }
            clear();
            cout << "Paste a sample input below: " << endl;
            system(".\\test.exe"); 
            cout << "A sammple output was generated!" << endl;
        }
        else {
            clear();
            break;
        }
    } while (true);
    cout << "May a shojin be with you." << endl;

    return 0;
}

void clear() {
    system("clear");
}