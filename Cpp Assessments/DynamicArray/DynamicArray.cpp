#include<iostream>
using namespace std;

template<typename T>
class DynamicArray {
    private:
        int totalCapacity;
        int size;
        T *arr;
        void expandCapacity(int index) {
            int newCapacity = index * 2 + 1; 
            cout << "New Capacity: " << newCapacity << endl;
            T *newArr = new T[newCapacity];
            for (int i = 0; i < size; ++i) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            totalCapacity = newCapacity;
        }

    public:
        DynamicArray(int initCapacity): totalCapacity{initCapacity}, size{0} {
            arr = new T[initCapacity];
        }
        
        ~DynamicArray() {
            delete[] arr;
        }
        
        void add(int index, T value){
            if (index < 0) {
                cout << "Index out of bounds" << endl;
                return;
            }
            if (index >= totalCapacity) {
                expandCapacity(index);
            }
            for (int i = size; i > index; --i) {
                arr[i] = arr[i - 1];
            }
            arr[index] = value;
            size++;
        }
        
        T get(int index) const{
            if(index < this->totalCapacity)
                return arr[index];
            else {
                cerr << "Error: Index out of bounds" << endl;
            }
        }
        
        bool operator<(const DynamicArray& a){
            return this->size < a.size;
        }
        
        T operator[](int index) const{
            return get(index);   
        }
        
        friend ostream& operator<<(ostream& out,const DynamicArray& arrArg){
            for(int i = 0; i < arrArg.totalCapacity; i++){
                out << arrArg[i] << endl;
            }
            return out;
        }
        
        void clear(){
            this->size=0;
        }
};

class A {
    public:
        ~A(){
            cout<<"A's destructor"<<endl;
        }
};

int main() {
	DynamicArray<int> numbers{3};
	DynamicArray<int> newNumbers{3};
	
	int a = 10;
	int b = 20;
	
	numbers.add(0, a);
	numbers.add(1, b);

	newNumbers.add(0, a);
	
	double x = 10.1;
	double y = 20.2;
	
	DynamicArray<double> doubleNumbers{3};
	
	doubleNumbers.add(0, x);
	doubleNumbers.add(1, y);
	
	if(newNumbers < numbers){
	    cout << "new numbers array is smaller than numbers array" << endl;  
	}
	
	cout<<numbers.get(1)<<endl;
	
	cout<<numbers[1]<<endl;
	cout<<numbers<<endl;

	numbers.clear();
	
    A *a1, *a2;
    a1 = new A();
    a2 = new A();
    
    DynamicArray<A*> classArray{3};
    classArray.add(0, a1);
    classArray.add(1, a2);
    
    delete a1;
    delete a2;

	return 0;
}