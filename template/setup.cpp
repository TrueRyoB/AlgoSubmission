#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;

//g++ -std=c++20 template/setup.cpp -o setup
int main(int argc, char* argv[]) {
    string dirName;
    if(argc >= 2) {
        dirName = argv[1];
    } else {
        cout << "Which contest are you attending today? >> ";
        cin>>dirName;
    }
    
    if(filesystem::exists(dirName)) {
        cerr << "Error: " << dirName << " already exists" << endl; return 0;
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
    cout << "May the Shojin be with you." << endl;

    return 0;
}
