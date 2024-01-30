#include<iostream>

using namespace std;

class Device{
    private:
        string id;
    protected:
        Device(){
            cout<<"In device constructor"<<endl;
        }
        Device(string idArg):id{idArg}{}
    public:
        string getDeviceId(){ return this->id; } 
        ~Device(){
        }
};

class IPrinter{
    public:
        virtual void print(string path) = 0;
};

class IScanner{
    public:
        virtual void scan(string path) = 0;
};

class Printer:public Device, public IPrinter{
    public:
    Printer(){}
    Printer(string idArg): Device::Device{idArg}{
        cout<<"In Printer constructor"<<endl;
    }
     void print(string path){
        cout<<"Printing ....."<<path<<endl;
    }
};

class Scanner:public Device, public IScanner{
    public:
    Scanner(){}
    Scanner(string idArg): Device::Device{idArg}{
        cout<<"In Scanner constructor"<<endl;
    }
     void scan(string path){
        cout<<"Scanning ....."<<path<<endl;
    }
};

class PrintScanner:public Device, public IPrinter, public IScanner {
    private:
        Printer printer;
        Scanner scanner;
    
    public:
        PrintScanner(string idArg) :  Device::Device(idArg){
            cout << "In PrintScanner constructor" << endl;
        }
        ~PrintScanner() {
            cout << "In PrintScanner destructor" << endl;
        }
        void print(string path) {
            printer.print(path);
        }
        void scan(string path) {
            scanner.scan(path);
        }
};
class TaskManager{
    public:
    static void executePrintTask(IPrinter *printer,string documentPath){
            printer->print(documentPath);
    }
    
    static void executeScanTask(IScanner *scanner,string documentPath){
            scanner->scan(documentPath);
    }
};

int main(){
    Printer printerObj("p1");
    Scanner scannerObj("s1");
    PrintScanner printScannerObj("ps1");

    TaskManager::executePrintTask(&printerObj,"Test.doc");
    TaskManager::executeScanTask(&scannerObj,"MyImage.png");
    TaskManager::executePrintTask(&printScannerObj,"NewDoc.doc");
    TaskManager::executeScanTask(&printScannerObj,"YourImage.png");
}