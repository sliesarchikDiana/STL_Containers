#include "prt2_task1.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
//sliding window method//
using namespace std;
string find_min_window(const string &s, const string &t) {
    unordered_map<char, int> target;
    for (char c : t) target[c]++;

    size_t left = 0, min_len = INT_MAX, start = 0;
    int remaining = t.size();

    for (size_t right = 0; right < s.size(); right++) {
        if (char c = s[right]; target[c]-- > 0) remaining--;

        while (remaining == 0) {
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                start = left;
            }
            if (++target[s[left++]] > 0) remaining++;
        }
    }
    return min_len == INT_MAX ? "" : s.substr(start, min_len);
}

int main() {
    string s, t;
    cout << "Enter the text: ";
    getline(cin, s);
    cout << "Enter the pattern: ";
    getline(cin, t);

    string result = find_min_window(s, t);
    cout << (result.empty() ? "No pattern found" : "Result: " + result) << endl;

    return 0;
}