// Find duplicate in array

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter array size: ", cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int total = ((n - 2) * (n - 1)) / 2, temp = 0;
    for (int i : arr) temp += i;
    cout << temp - total << endl;

    return 0;

}
