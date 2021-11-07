#include <iostream>
using namespace std;

int checkR(int arr[], int n) {
    for (int i = 0;i < n - 1;++i) {
        if (arr[i] > arr[i + 1]) {
            return i + 1;
        }
    }
    return 0;
}

int main() {

    int arr[] = { 10,20,30,1 };
    cout << checkR(arr, 4) << endl;

    return 0;

}
