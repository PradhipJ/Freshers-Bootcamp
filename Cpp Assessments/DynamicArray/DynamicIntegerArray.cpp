#include<iostream>

using namespace std;

class DynamicIntegerArray {
    private:
        int totalCapacity;
        int size;
        int *arr;
        void expandCapacity(int index) {
            totalCapacity = index * 2 + 1; 
            int *newArr = new int[totalCapacity];
            for (int i = 0; i < size; ++i) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
    public:
        DynamicIntegerArray(int initCapacity): totalCapacity{initCapacity}, size{0} {
            arr = new int[initCapacity];
        }
        
        ~DynamicIntegerArray() {
            delete[] arr;
        }
        
        void add(int index, int value){
            if (index < 0 || index > size) {
                cout << "Index out of bounds" << endl;
                return;
            }
            if (size >= totalCapacity) {
                expandCapacity(index);
            }
            for (int i = size; i > index; --i) {
                arr[i] = arr[i - 1];
            }
            arr[index] = value;
            size++;
        }
        
        int get(int index){
            if(index < size)
                return arr[index];
            else {
                cout << "Index out of bounds" << endl;
                return -1;
            }
        }
        
        void clear(){
            size=0;
        }
};

int main() {
	DynamicIntegerArray numbers{3};
	numbers.add(0, 10);
	numbers.add(1, 20);
	numbers.add(2, 30);
	numbers.add(3, 40);

	cout<<numbers.get(2)<<endl;

	numbers.clear();

	return 0;
}
