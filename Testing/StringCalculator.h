#include <string>
#include <vector>
using namespace std;
#pragma once
class StringCalculator
{
public:
	static int addNumbers(string numbers);
	static vector<int> extractNumbers(const string& numbers);
	static int calculateSum(const vector<int>& numbersArr);
};

