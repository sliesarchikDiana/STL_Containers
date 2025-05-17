#include "prt2_task1.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string findMinWindow(const string& s, const string& t) {
    vector<int> count(128, 0);
    for (const char c : t) count[c]++;
    int left = 0, right = 0, min_len = INT_MAX, start = 0, remaining = t.size();
    while (right < s.size())
        {
        if (count[s[right++]]-- > 0) remaining--;
        while (remaining == 0) {
            if (right - left < min_len) {
                min_len = right - left;
                start = left;
            }
            if (count[s[left++]]++ == 0) remaining++;
        }
    }

    return min_len == INT_MAX ? "" : s.substr(start, min_len);
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);
    const string result = findMinWindow(text, pattern);
    cout << (result.empty() ? "No pattern found" : "Result: " + result) << endl;

    return 0;
}