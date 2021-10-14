#include <iostream>
using namespace std;

bool helper(string s, int start, int end) {
    if (start >= end) return true;
    if (s[start] != s[end]) return false;
    return helper(s, start + 1, end - 1);
}

bool isPalin(string s) {
    return helper(s, 0, s.length() - 1);
}

int main() {

    cout << boolalpha << isPalin("racecar") << endl;
    cout << boolalpha << isPalin("mom") << endl;
    cout << boolalpha << isPalin("madam") << endl;
    cout << boolalpha << isPalin("apple") << endl;

    return 0;

}
