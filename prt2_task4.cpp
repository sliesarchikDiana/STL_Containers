#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    const string s1 = "cat dog bird fish";
    const string s2 = "hamster cat dog fish";

    auto extract_words = [](const string& s) {
        istringstream iss(s);
        return unordered_set<string>(istream_iterator<string>(iss), istream_iterator<string>());
    };

    unordered_set<string> words1 = extract_words(s1);
    unordered_set<string> words2 = extract_words(s2);

    const auto common = count_if(words1.begin(), words1.end(), [&words2](const string& word) {
        return words2.count(word);
    });

    const auto total_unique = words1.size() + words2.size() - common;
    cout << "Similarity: " << (common * 100) / total_unique << "%" << endl;

    return 0;
}