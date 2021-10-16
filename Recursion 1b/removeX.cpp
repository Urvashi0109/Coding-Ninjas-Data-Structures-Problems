#include <iostream>
using namespace std;

string removeX(string str) {
    if (str.size() == 0) return "";
    if (str[0] == 'x') return removeX(str.substr(1));
    return str[0] + removeX(str.substr(1));
}

int main() {

    string str;
    cout << "Enter string: ", getline(cin >> ws, str);
    cout << removeX(str) << endl;

    return 0;

}
