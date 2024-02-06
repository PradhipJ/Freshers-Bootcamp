#include "StringCalculator.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <cctype>

int StringCalculator::addNumbers(string numbers) {
    if (numbers.empty() || numbers == "0")
        return 0;

    char delimiter = getDelimiter(numbers);

    numbers = removeDelimiterSpecifier(numbers);

    vector<int> numbersArr = extractNumbers(numbers, delimiter);

    int sum = calculateSum(numbersArr);

    cout << sum << endl;
    return sum;
}

char StringCalculator::getDelimiter(const string& numbers) {
    char delimiter = ',';
    size_t delimiterIndex = numbers.find("//");
    if (delimiterIndex != string::npos) {
        delimiter = numbers[delimiterIndex + 2];
    }
    return delimiter;
}

string StringCalculator::removeDelimiterSpecifier(string numbers) {
    size_t delimiterIndex = numbers.find("//");
    if (delimiterIndex != string::npos) {
        numbers = numbers.substr(delimiterIndex + 4);
    }
    return numbers;
}

vector<int> StringCalculator::extractNumbers(const string& numbers, char delimiter) {
    vector<int> numbersArr;
    istringstream ss(numbers);
    string token;

    while (getline(ss, token, delimiter)) {
        istringstream tokenStream(token);
        string subToken;
        while (getline(tokenStream, subToken, '\n')) {
            if (!subToken.empty()) {
                int num = stoi(subToken);
                if (num < 0) {
                    throw invalid_argument("Negatives are not allowed.");
                }
                else if (num < 1000) {
                    numbersArr.push_back(num);
                }
            }
        }
    }

    return numbersArr;
}

int StringCalculator::calculateSum(const vector<int>& numbersArr) {
    int sum = 0;
    for (int num : numbersArr) {
        sum += num;
    }
    return sum;
}
