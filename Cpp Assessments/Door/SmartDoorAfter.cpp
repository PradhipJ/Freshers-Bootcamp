#include<iostream>
#define OPEN 1
#define CLOSE 0

using namespace std;

class Printer{
    private:
        string message;
    public:
        void setMessage(string msg){
            this->message=msg;
        }
        void displayMessage(){
            cout<<this->message<<endl;
        }
};

class ISubscriber{
    public:
        virtual void updateState(int state) = 0;
};

class Feature{
    protected:
        int state;
        Printer *printer;
    public:
        Feature(Printer *p): printer{p}{}
        void print(string msg){
            printer->setMessage(msg);
            printer->displayMessage();
        }
        void setState(int s){
            this->state = s;
        }
};

class Buzzer: public ISubscriber, public Feature{
    public:
        Buzzer(Printer *p): Feature::Feature{p}{}
        void updateState(int s) override {
            setState(s);
            buzz();
        }
        
        void buzz(){
            if(this->state == OPEN){
                print("Buzzer is on!");
            }
        }
};

class SMSNotifier: public ISubscriber, public Feature{
    public:
        SMSNotifier(Printer *p): Feature::Feature{p}{}
        void updateState(int s) override {
            setState(s);
            sendSMS();
        }
        
        void sendSMS(){
            if(this->state == OPEN){
                print("Buzzer is on!");
            }
        }
};

class VisualizationManager: public ISubscriber, public Feature{
    public:
        VisualizationManager(Printer *p): Feature::Feature{p}{}
        void updateState(int s) override {
            setState(s);
            if(this->state == OPEN){
                print("Video is on");
            }
            if(this->state == CLOSE){
                print("Video is off");
            }
        }
};

class Door{
    private:
        int size;
        int capacity;
        ISubscriber** subscribers;
        void expandCapacity() {
            capacity *= 2; 
            ISubscriber** newSubs;
            newSubs = new ISubscriber*[capacity];
            for (int i = 0; i < size; ++i) {
                newSubs[i] = subscribers[i];
            }
            for (int i = 0; i < this->size; i++) {
			    delete subscribers[i];
		    }
            delete[] subscribers;
            subscribers = newSubs;
        }
    public:
        Door(int initialCapacity = 10) : size{0}, capacity{initialCapacity} {
            subscribers = new ISubscriber*[capacity];
        }
        
         ~Door() {
            for (int i = 0; i < this->size; i++) {
			    delete subscribers[i];
		    }
            delete[] subscribers;
        }
        void subscribe(ISubscriber *s){
            if (size >= capacity) {
                expandCapacity();
            }
            subscribers[size++] = s;
        }
        void unsubscribe(ISubscriber *s){
            for(int i = 0; i < size; i++){
                if(subscribers[i]==s){
                    while(i < size - 1){
                        subscribers[i] = subscribers[i+1];
                        i++;
                    }
                    size--;
                    break;
                }
            }
            
        }
        void notifySubscribers(int state){
            for(int i = 0; i < size; i++){
                if(subscribers[i] != NULL)
                    subscribers[i]->updateState(state);
            }
        }
        void open(){
            notifySubscribers(OPEN);
        }
        void close(){
            notifySubscribers(CLOSE);
        }
};

int main(){
    Buzzer *buzzer;
    SMSNotifier *smsNotifier;
    VisualizationManager *visualizationManager;
    Printer *printer;
    
    printer=new Printer();
    buzzer=new Buzzer(printer);
    smsNotifier=new SMSNotifier(printer);
    visualizationManager=new VisualizationManager(printer);
    
    
    Door door;
    
    door.subscribe(buzzer);
    door.subscribe(smsNotifier);
    door.subscribe(visualizationManager);
    
    door.open();
    
    door.close();
    
    door.unsubscribe(buzzer);
    door.unsubscribe(smsNotifier);
    door.unsubscribe(visualizationManager);
    
    delete buzzer;
    delete smsNotifier;
    delete visualizationManager;
    
    return 0;
}