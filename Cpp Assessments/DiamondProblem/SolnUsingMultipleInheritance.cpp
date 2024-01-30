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
            cout<<"In device destructor"<<endl;
        }
};

class Printer:virtual public Device{
    public:
    Printer(){}
    Printer(string idArg): Device::Device{idArg}{
        cout<<"In Printer constructor"<<endl;
    }
     void print(string path){
        cout<<"Printing ....."<<path<<endl;
    }
};

class Scanner:virtual public Device{
    public:
    Scanner(){}
    Scanner(string idArg): Device::Device{idArg}{
        cout<<"In Scanner constructor"<<endl;
    }
     void scan(string path){
        cout<<"Scanning ....."<<path<<endl;
    }
};

class PrintScanner: public Printer, public Scanner {
    public:
    PrintScanner(string idArg): Device::Device{idArg}{
        cout<<"In Print Scanner constructor"<<endl;
    }
    ~PrintScanner(){
        cout<<"In Print Scanner destructor"<<endl;
    }
    
};
class TaskManager{
    public:
     static void executePrintTask(Printer *printer,string documentPath){
        printer->print(documentPath);
    }
     static void executeScanTask(Scanner *scanner,string documentPath){
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