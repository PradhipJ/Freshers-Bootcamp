#include<iostream>
#include<string>
#include "mathMacros.h"

using namespace std;

int main()
{
	int a = 10, b = -30;
	a = ABS(a);
	b = ABS(b);
	int max = MAX(a,b);
	cout<<"Max number = "<<max<<endl;
}