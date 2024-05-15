#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

class FileManager {
    static FileManager* instance;

    FileManager() {}

public:
    static FileManager* GetInstance() {
        if (instance == nullptr)
            instance = new FileManager;
        return instance;
    }

    void CreateFile(string file_name) {
        ofstream file(file_name);
        if (file)
            cout << "file created..";
    }

    void OpenFile(string file_name){
        ofstream file(file_name);
        file.open(file_name, fstream::app);
        cout << "file is open\n";
    }

    void CloseFile(string file_name) {
        ofstream file(file_name);
        cout << "file closed\n";
        file.close();
    }

    void DestroyFile(const char* file_name){
        remove(file_name);
               
    }

    void Write(string file_name, string message){
        ofstream file(file_name, ios::app);
        if (file.is_open()) {
            cout << "writing\n";
            file << message << "\n";
        }
        else
            cout << "Opps file is closed\n";
    }

    string ReadLine(const char* file_name) {   
        ifstream file(file_name);
        if (!file) {
            cout << "error file closed..\n";
        }
        string line;
        getline(file, line);
        return line;
    }

    string ReadFile(const char* file_name) {
        ifstream file(file_name);
        string line;
        string current;
        while (getline(file, line)) {
            current += line;
        }
        return current;
    }

};

FileManager* FileManager::instance = nullptr;

int main()
{
    const char* file = "file.txt";
    auto ptr = FileManager::GetInstance();
    ptr->CreateFile(file);
    
    ptr->Write(file, "hi ghrgjkjfjgjfjkkjfg");
    ptr->Write(file,"Hello World!");
   
    cout << ptr->ReadFile(file);
}