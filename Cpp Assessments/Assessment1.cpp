// scope.cpp
// Accessing objects with equal names
// ---------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
int var = 0;
namespace Special { int var = 100; }
int main()
{
   int var = 10;
   cout << setw(10) << var; // 1. block scope
   {
   	int var = 20;
   	cout << setw(10) << var << endl; // 2. block scope
   	{
   		++var;
   		cout << setw(10) << var; // 3. block scope
   		cout << setw(10) << ++ ::var; // 4. file scope
   		cout << setw(10) << Special::var * 2 // 5. var of namespace special
   			<< endl;
   	}
   	cout << setw(10) << var - ::var; // 6. block scope var - file scope var
   }
   cout << setw(10) << var << endl; // 7. block scope
   return 0;
}

/* 1. 10
   2. 20
   3. 21
   4. 1
   5. 200
   6. 20
   7. 10
*/
