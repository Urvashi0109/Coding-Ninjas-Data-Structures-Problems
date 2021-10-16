#include <iostream>
using namespace std;

string pairStar(string str) {
    if (str == "") return str;
    string temp = str[0] == str[1] ? "*" : "";
    return str[0] + temp + pairStar(str.substr(1));
}

int main() {

    cout << pairStar("hello") << endl;
    cout << pairStar("aaaa") << endl;
    cout << pairStar("") << endl;
    cout << pairStar("abcd") << endl;

    return 0;

}
