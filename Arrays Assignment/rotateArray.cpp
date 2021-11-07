#include <iostream>
using namespace std;

void rotate(int arr[], int n, int k) {
    int temp[k];
    for (int i = 0; i < k; ++i) temp[i] = arr[i];
    for (int i = 0;i < n - k;++i) {
        arr[i] = arr[i + k];
    }

    for (int i = 0;i < k;++i) {
        arr[n - k + i] = temp[i];
    }
}

int main() {

    int arr[] = { 1,2,3,4,5,6,7 };
    rotate(arr, 7, 2);
    for (int i : arr) {
        cout << i << " ";
    } cout << endl;

    return 0;

}
