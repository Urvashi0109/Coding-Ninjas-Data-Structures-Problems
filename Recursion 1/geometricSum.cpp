#include <iostream>
using namespace std;

long pow(int x, int n) {
    if (n == 0) return 1;
    return x * pow(x, n - 1);
}

double gSum(int n) {
    if (n == 0) return 1;
    return 1 / (double)pow(2, n) + gSum(n - 1);
}

int main() {

    cout << gSum(3) << endl;
    cout << gSum(4) << endl;

    return 0;

}
