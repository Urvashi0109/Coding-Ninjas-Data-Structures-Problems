#include <iostream>
using namespace std;

int firstIndex(int arr[], int size, int k) {
    if (size == 0) return -1;
    if (arr[0] == k) return 0;
    int res = firstIndex(arr + 1, size - 1, k);
    return res == -1 ? res : res + 1;
}

int main() {

    int arr[] = { 0,0,1,2,5,5,5,5,2 };
    cout << firstIndex(arr, 7, 0) << endl;
    cout << firstIndex(arr, 7, 2) << endl;
    cout << firstIndex(arr, 7, 5) << endl;
    cout << firstIndex(arr, 7, 7) << endl;

    return 0;

}
