#include <iostream>
using namespace std;

int digits(int n) {
    if (n == 0) return 0;
    return 1 + digits(n / 10);
}

int main() {

    cout << digits(1000) << endl;
    cout << digits(1) << endl;
    cout << digits(0) << endl;
    cout << digits(1234567) << endl;

    return 0;

}
