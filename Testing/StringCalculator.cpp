#include "StringCalculator.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <cctype>

int StringCalculator::addNumbers(string numbers) {
    if (numbers.empty() || numbers == "0")
        return 0;

    vector<int> numbersArr = extractNumbers(numbers);

    int sum = calculateSum(numbersArr);

    cout << sum << endl;
    return sum;
}

vector<int> StringCalculator::extractNumbers(const string& numbers) {
    vector<int> numbersArr;
    istringstream ss(numbers);
    string token;

    while (getline(ss, token, ',')) {
        if (!token.empty()) {
            int num = stoi(token);
            if (num < 0) {
                throw invalid_argument("Negatives are not allowed.");
            }
            else if (num < 1000) {
                numbersArr.push_back(num);
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
