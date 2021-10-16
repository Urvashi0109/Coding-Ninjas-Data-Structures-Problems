#include <iostream>
using namespace std;

int stringToInt(string str) {
    if (str == "") return 0;
    return str[str.length() - 1] - '0' + stringToInt(str.substr(0, str.length() - 1)) * 10;
}

int main() {

    cout << stringToInt("12345");

    return 0;

}
