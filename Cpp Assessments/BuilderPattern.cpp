#include<iostream>
#include <string>
using namespace std;
class Customer{
    private:
        string name;
        string address;
        string pan;
        string adhaar;
        long long phone;
        string email;
        
    public:
        Customer(string nameArg, string addressArg, string panArg, string adhaarArg) : name{nameArg}, address{addressArg}, pan{panArg}, adhaar{adhaarArg} {}
        
        void setPhone(long long phoneArg){
            this->phone=phoneArg;
        }
        
        void setEmail(string emailArg){
            this->email=emailArg;
        }

        void display() {
            cout << "Name: " << this->name << endl;
            cout << "Address: " << this->address << endl;
            cout << "Pan: " << this->pan << endl;
            cout << "Adhaar: " << this->adhaar << endl;
            cout << "Phone: " << this->phone << endl;
            cout << "Email: " << this->email << endl;
        }
};

class CustomerBuilder{
    private:
        Customer* customer;
        
    public:
        CustomerBuilder(string name, string address, string pan, string adhaar) {
            customer = new Customer(name, address, pan, adhaar);
        }

        CustomerBuilder* setPhone(long long phoneArg) {
            customer->setPhone(phoneArg);
            return this;
        }
        
        CustomerBuilder* setEmail(string emailArg) {
            customer->setEmail(emailArg);
            return this;
        }

        Customer* getInstance() {
            return customer;
        }
};

int main(){
  Customer* customer1 = (new CustomerBuilder{"venu","Blr","ADDRV007","ADH546899"})->getInstance();
  customer1->display();
  
  Customer* customer2 = (new CustomerBuilder{"venu","Blr","ADDRV007","ADH546899"})->setPhone(12345)->getInstance();
  customer2->display();
  
   Customer* customer3=(new CustomerBuilder{"venu","Blr","ADDRV007","ADH546899"})->setEmail("vgk@v.com")->getInstance();
  customer3->display();
  
   Customer* customer4=(new CustomerBuilder{"venu","Blr","ADDRV007","ADH546899"})->setPhone(12345)->setEmail("vgk@v.com")->getInstance();
  customer4->display();

}