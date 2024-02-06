#include <string>
#include <vector>
using namespace std;
#pragma once
class StringCalculator
{
public:
	static int addNumbers(string numbers);
	static vector<int> extractNumbers(const string& numbers, char delimiter);
	static int calculateSum(const vector<int>& numbersArr);
	static char getDelimiter(const string& numbers);
	static string removeDelimiterSpecifier(string numbers);
};

