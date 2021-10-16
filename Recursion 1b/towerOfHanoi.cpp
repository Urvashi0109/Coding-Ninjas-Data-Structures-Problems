#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src = 'A', char dest = 'C', char aux = 'B') {
    if (n == 0) return;
    towerOfHanoi(n - 1, src, aux, dest);
    cout << "Move " << n << " from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, aux, dest, src);
}

int main() {

    towerOfHanoi(5);

    return 0;

}
