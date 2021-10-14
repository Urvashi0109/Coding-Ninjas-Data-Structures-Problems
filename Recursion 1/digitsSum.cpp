#include <iostream>
using namespace std;

int digSum(int n) {
    if (n == 0) return 0;
    return (n % 10) + digSum(n / 10);
}

int main() {

    cout << digSum(12345) << endl;
    cout << digSum(9) << endl;
    cout << digSum(0) << endl;
    cout << digSum(11) << endl;

    return 0;

}
