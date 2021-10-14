#include <iostream>
using namespace std;

// from first
int lastIndex1(int arr[], int size, int k) {
    if (size == 0) return -1;
    int res = lastIndex1(arr + 1, size - 1, k);
    if (res != -1) return res + 1;

    return arr[0] == k ? 0 : -1;
}

// from last
int lastIndex2(int arr[], int size, int k) {
    if (size == 0) return -1;
    if (arr[size - 1] == k) return size - 1;
    return lastIndex2(arr, size - 1, k);
}

int main() {

    int arr[] = { 0,0,1,2,5,5,5,5,2,1 };
    cout << lastIndex1(arr, 10, 0) << endl;
    cout << lastIndex1(arr, 10, 1) << endl;
    cout << lastIndex1(arr, 10, 2) << endl;
    cout << lastIndex1(arr, 10, 5) << endl;
    cout << lastIndex1(arr, 10, 7) << endl;
    cout << "----------------" << endl;
    cout << lastIndex2(arr, 10, 0) << endl;
    cout << lastIndex2(arr, 10, 1) << endl;
    cout << lastIndex2(arr, 10, 2) << endl;
    cout << lastIndex2(arr, 10, 5) << endl;
    cout << lastIndex2(arr, 10, 7) << endl;

    return 0;

}
