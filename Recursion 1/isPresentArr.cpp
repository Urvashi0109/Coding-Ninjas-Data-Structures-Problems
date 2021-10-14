#include <iostream>
using namespace std;

bool isPresent(int arr[], int size, int k) {
    if (size == 0) return false;
    if (arr[0] == k) return true;
    return isPresent(arr + 1, size - 1, k);
}

int main() {

    int arr[] = { 0, 1, 2, 3, 4, 5 };
    cout << boolalpha << isPresent(arr, 6, 6) << endl;
    cout << boolalpha << isPresent(arr, 6, 3) << endl;
    cout << boolalpha << isPresent(arr, 6, 0) << endl;
    cout << boolalpha << isPresent(arr, 6, -1) << endl;

    return 0;

}
