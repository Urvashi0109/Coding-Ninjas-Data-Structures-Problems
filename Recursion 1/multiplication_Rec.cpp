#include <iostream>
using namespace std;

int multi(int n, int m) {
    if (m == 0) return 0;
    return n + multi(n, m - 1);
}

int main() {

    int n, m;
    cin >> n >> m;
    cout << multi(n, m) << endl;

    return 0;

}
