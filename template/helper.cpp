//g++ -std=c++17 template/helper.cpp -o helper.exe -lstdc++fs -luser32


// ──────────────
// 1) Util
// ──────────────
#ifdef _WIN32
    // #define WIN32_LEAN_AND_MEAN 
    // #define NOMINMAX
    // #include <windows.h>
    // #undef byte
    // #include <conio.h>
    // #include <fcntl.h>

    bool input_pending() {
        return false;
        // static HANDLE hConsole = CreateFileW(
        //     L"CONIN$",
        //     GENERIC_READ | GENERIC_WRITE,
        //     FILE_SHARE_READ | FILE_SHARE_WRITE,
        //     nullptr,
        //     OPEN_EXISTING,
        //     0,
        //     nullptr
        // );
        // if (hConsole == INVALID_HANDLE_VALUE) {
        //     return _kbhit() != 0;
        // }

        // HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
        // DWORD type = GetFileType(hStdIn);
        // if (type == FILE_TYPE_PIPE) {
        //     DWORD bytes = 0;
        //     if (!PeekNamedPipe(hStdIn, nullptr, 0, nullptr, &bytes, nullptr)) {
        //         return _kbhit() != 0;
        //     }
        //     return bytes > 0;
        // }

        // INPUT_RECORD records[16];
        // DWORD read = 0;
        // if (!PeekConsoleInputW(hConsole, records, sizeof(records)/sizeof(records[0]), &read)) {
        //     return _kbhit() != 0;
        // }
        // for (DWORD i = 0; i < read; ++i) {
        //     if (records[i].EventType == KEY_EVENT
        //         && records[i].Event.KeyEvent.bKeyDown
        //         && records[i].Event.KeyEvent.uChar.UnicodeChar != 0)
        //     {
        //         return true;
        //     }
        // }
        // return false;
    }

#else
    #include <unistd.h>
    #include <sys/select.h>
    #include <fcntl.h>
    bool input_pending() {
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds);
        timeval tv{0, 0};
        return select(STDIN_FILENO+1, &rfds, nullptr, nullptr, &tv)>0;
    }
#endif

#include <cstddef> 
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdint>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

class PathManager;
bool solve(PathManager&);
string ReadFileContents(const std::string&);
bool CopyToClipboard(const std::string&);
bool createExe(const string&);


void printOnDemand(const string& s) {
    if(!input_pending()) cout << s;
}
template<typename T> void ask(T& val) {
    printOnDemand("?");
    cin>>val;
}
template<typename T> void standby(T& val) {
    printOnDemand(">");
    cin>>val;
}

// ──────────────
// 2) PathManager
// ──────────────
class PathManager {
private:
    string dir;
    string file;
public:
    string getFilePath() {
        return (dir.size() > 0) ? (dir + "/" + file) : file;
    }
    bool registerFileName(const string& s, const string& ext = ".cpp") {
        const size_t len=ext.size();
        if(s.size() < len || s.substr(s.size()-len) != ext) {
            return false;
        }
        file = s; return true;
    }
    bool registerDirectory(const string& s) {
        fs::path p(s);
        if(fs::exists(p) && fs::is_directory(p)) {
            dir=s; return true;
        }
        return false;
    }
    bool isFileNameSet() {
        return file.size() > 0;
    }
    bool isDirNameSet() {
        return dir.size() > 0;
    }
};
// ──────────────
// 3) Solve()
// ──────────────
bool solve(PathManager& pm) {
    string q; standby(q);
    if(q == "help" || q == "h") {
        cout << "Available commands: " << endl
        << "- copy (-filepath/this)" << endl
        << "- test (-filepath/this/same)" << endl
        // << "- submit (-problempath/this)" << endl 
        << "- lock -directory" << endl
        << "- set -filename" << endl
        // << "- at -extension" << endl //TODO:
        << "- clear" << endl
        << "- get" << endl
        << "- exit" << endl;
    }
    else if(q == "get" || q == "g") {
        if(!pm.isFileNameSet()) cout << "file is NOT targetd" << endl;
        if(!pm.isDirNameSet()) cout << "directory is NOT set" << endl;
        if(pm.isFileNameSet() && pm.isDirNameSet()) cout << "pointing at " << pm.getFilePath() << endl;
    }
    else if(q == "copy" || q == "c") {
        string w; ask(w);
        if(w == "this") {
            if(!pm.isFileNameSet()) {
                cerr << "Error: target file is not set!" << endl;
                return true;
            }
        } else {
           pm.registerFileName(w);
        }
        string res = ReadFileContents(pm.getFilePath());
        cout << (CopyToClipboard(res) ? "Your code was copied successfully." : "Failed copying a file.") << endl; 
    }
    else if(q == "set") {
        string w; ask(w); 
        bool valid = pm.registerFileName(w);
        if(!valid) cout << "Error: file " << w << " must have an extension: " << ".cpp"  << " (or change the coding language setting via command: \"at\")"<< endl;
    }
    else if(q == "lock") {
        string w; ask(w); 
        bool found = pm.registerDirectory(w);
        if(!found) cout << "Error: directory not found : " << w << endl;
    } else if(q == "test" || q=="t") {
        string w; ask(w);
        if(w != "same" && w != "s") {
            if(w == "this" || w == "t") {
                if(!pm.isFileNameSet()) {
                    cerr << "Error: target file is not set!" << endl;
                    return true;
                }
            } else {
                pm.registerFileName(w);
            }
            string cmd = "g++ " + pm.getFilePath() + " -o test.exe";
            system(cmd.c_str());
        }
        cout << "Running a file: " << pm.getFilePath() << "..." << endl;
        cout << "Paste your input here: " << endl;
        int result = system(".\\test");
        cout << (result==0 ? "Test completed successfully." : "Compilation failed.") << endl;
    } else if(q == "clear") {
        system("clear");
    } else if(q == "exit") {
        return false;
    } else if(q == "submit") {
        string w; ask(w);
        if(w == "this" || w == "t") {
            if(!pm.isFileNameSet()) {
                cerr << "Error: target file is not set!" << endl;
                return true;
            }
        } else {
            pm.registerFileName(w);
        }
        //TODO: オンライン提出用のAPIを知る
    } else {
        cout << "Unknown command: " << q << endl;
    }
    return true;
}

// ──────────────
// 4) Create Exe file
// ──────────────
bool createExe(const string& path) {
    if (!fs::exists(path)) {
        cerr << "Error: No file found at " << path << endl;
        return false;
    }
    string outputPath = "test.exe";
    if (fs::exists(outputPath)) fs::remove(outputPath);

    string compileCmd = "g++ " + path + " -o " + outputPath;
    int result = system(compileCmd.c_str());
    if (result == 0) {
        cout << "Successfully generated output file: " << outputPath << endl;
        return true;
    } else {
        cerr << "Failed to compile " << path << endl;
        return false;
    }
}

// ──────────────
// 5) Read File Contents for copy-and-paste
// ──────────────
string ReadFileContents(const std::string& filePath) {
    ifstream file(filePath, ios::binary);
    if (!file) throw runtime_error("Could not open file: " + filePath);
    return string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
}

// ──────────────
// 6) Use clipboard API for copy-and-paste
// ──────────────
bool CopyToClipboard(const std::string& content) {
    if (!OpenClipboard(nullptr)) return false;
    EmptyClipboard();
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, content.size() + 1);
    if (!hMem) { CloseClipboard(); return false; }
    memcpy(GlobalLock(hMem), content.c_str(), content.size() + 1);
    GlobalUnlock(hMem);
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
    return true;
}

// ──────────────
// 7) the main
// ──────────────
int32_t main() {
    PathManager pm;
    bool conti=true;
    cout << "[Rhaazoe]" << endl;
    while (conti) {
        conti = solve(pm);
    }
    cout << "Alligator!" << endl;
    return 0;
}

//g++ -std=c++17 template/helper.cpp -o helper.exe -lstdc++fs -luser32