// Find the Unique Element

#include <iostream>
using namespace std;

int main() {

    int arr[] = { 1,4,1,3,6,7,6,3,4 };
    int res = 0;
    for (int i = 0;i < sizeof(arr) / sizeof(arr[0]);++i) {
        res ^= arr[i];
    }
    cout << res << endl;

    return 0;

}
