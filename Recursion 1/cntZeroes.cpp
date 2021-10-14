#include <iostream>
using namespace std;

int zeroes(int n) {
    if (n == 0) return 0;
    return (n % 10 == 0 ? 1 : 0) + zeroes(n / 10);
}

int main() {

    cout << zeroes(10204) << endl;
    cout << zeroes(0) << endl;
    cout << zeroes(708000) << endl;
    cout << zeroes(200) << endl;

    return 0;

}
