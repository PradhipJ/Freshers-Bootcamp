#include<iostream>
using namespace std;

class A{
    public:
    ~A(){
        cout<<"A Destructed"<<endl;
    }
    void m(){
        cout<<"A method called"<<endl;
    }
};

class B{
    public:
    ~B(){
        cout<<"B Destructed"<<endl;
    }
    void m(){
        cout<<"B method called"<<endl;
    }
};
//Wrapper
template<typename T>
class SmartPointerTypeForAnytype{
    T* rawPtr;
    public:
        T& operator*() const {
		    return *rawPtr;
	    }
        
        T* operator->() const{
            return rawPtr;
        }
        
        SmartPointerTypeForAnytype(T* ptr): rawPtr{ptr}{}
        ~SmartPointerTypeForAnytype(){
            delete rawPtr;
        }
};

void init(){
    SmartPointerTypeForAnytype<A> smartPtr1{ new A() };
    smartPtr1->m();
    SmartPointerTypeForAnytype<B> smartPtr2{ new B() };
    smartPtr2->m();
}

int main(){
    init();
}