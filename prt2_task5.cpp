#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

const unordered_map<char, string> digit_to_letters = {{'2', "ABC"}, {'3', "DEF"}, {'4', "GHI"}, {'5', "JKL"},{'6', "MNO"}, {'7', "PQRS"}, {'8', "TUV"}, {'9', "WXYZ"}};
vector<string> letter_combinations(const string& digits) {
    if (digits.empty()) return {};
    vector<string> result = {""};
    for (char digit : digits) {
        vector<string> temp;
        const string& letters = digit_to_letters.count(digit) ? digit_to_letters.at(digit) : string(1, digit);
        for (const string& s : result) {
            for (char letter : letters) {
                temp.push_back(s + letter);
            }
        }
        result = move(temp);
    }

    return result;
}

int main() {
    string phone_number;
    cout << "Enter phone number: ";
    cin >> phone_number;

    const auto combinations = letter_combinations(phone_number);

    cout << "All possible combinations of letters:\n";
    for_each(combinations.begin(), combinations.end(), [](const string& s) {
        cout << s << '\n';
    });
}