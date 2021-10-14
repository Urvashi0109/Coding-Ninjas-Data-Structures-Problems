#include <iostream>
using namespace std;

void print(int n) {
    if (n == 0) return;
    print(n - 1);
    cout << n << " ";
}

int main() {

    print(6);
    cout << endl;
    print(10);
    cout << endl;
    print(100);

    return 0;

}
