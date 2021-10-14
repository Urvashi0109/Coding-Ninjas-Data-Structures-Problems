#include <iostream>
using namespace std;

int pow(int x, int n) {
    if (n == 0) return 1;
    return x * pow(x, n - 1);
}

int main() {

    cout << pow(2, 0) << endl;
    cout << pow(2, 3) << endl;
    cout << pow(3, 5) << endl;
    cout << pow(5, 7) << endl;

    return 0;

}
