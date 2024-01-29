
#include <iostream>
using namespace std;
class Customer{
    private:
        char *name, *address, *email;
        long int panNum, aadharNum, phoneNum;
    public:
        Customer(char *nameArg, char *addressArg, long int panNumArg, long int aadharNumArg):name{nameArg}, address{addressArg}, panNum{panNumArg}, aadharNum{aadharNumArg}{}
        
        Customer(char *nameArg, char *addressArg, long int panNumArg, long int aadharNumArg, long int phoneNumArg): Customer(nameArg, addressArg, panNumArg, aadharNumArg){
            this->phoneNum=phoneNumArg;
        }
        
        Customer(char *nameArg, char *addressArg, long int panNumArg, long int aadharNumArg, char *emailArg): Customer(nameArg, addressArg, panNumArg, aadharNumArg){
            this->email=emailArg;
        }
            
        Customer(char *nameArg, char *addressArg, long int panNumArg, long int aadharNumArg, long int phoneNumArg, char *emailArg):
            Customer(nameArg, addressArg, panNumArg, aadharNumArg, phoneNumArg) {
                this->email=emailArg;
            }
        void displayDetails(){
            cout<<"Name :"<<this->name<<endl;
            cout<<"Address :"<<this->address<<endl;
            cout<<"Pan number :"<<this->panNum<<endl;
            cout<<"Aadhar number :"<<this->aadharNum<<endl;
            cout<<"Phone :"<<this->phoneNum<<endl;
            cout<<"Email :"<<this->email<<endl;
        }
};

int main() {
    Customer customer("A", "XXX", 123, 321);
    Customer customerWithPhone("A", "XXX", 123, 321, 999);
    Customer customerWithEmail("A", "XXX", 123, 321, "a@gmail.com");
    Customer customerWithPhoneAndEmail("A", "XXX", 123, 321, 999, "a@gmail.com");
    
    customer.displayDetails();
    customerWithPhone.displayDetails();
    customerWithEmail.displayDetails();
    customerWithPhoneAndEmail.displayDetails();
    return 0;
}