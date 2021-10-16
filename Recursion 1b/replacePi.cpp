#include <iostream>
using namespace std;

string replacePi(string str) {
    if (str.size() == 0) return "";
    if (str[0] == 'p' && str[1] == 'i') {
        return "3.14" + replacePi(str.substr(2));
    } else return str[0] + replacePi(str.substr(1));
}

int main() {

    string str;
    getline(cin >> ws, str);
    cout << replacePi(str) << endl;

    return 0;

}
