#include <bits/stdc++.h>
using namespace std;

void printIntersect(int arr1[], int arr2[], int n, int m) {
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            ++i;
        } else if (arr2[j] < arr1[i]) {
            ++j;
        } else if (arr2[j] == arr1[i]) {
            cout << arr1[i] << " ";
            ++i;
            ++j;
        }
    }
    cout << endl;
}

int main() {

    int n;
    cout << "Enter arr1 size: ", cin >> n;
    int m;
    cout << "Enter arr2 size: ", cin >> m;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; ++i) cin >> arr1[i];
    for (int i = 0; i < m; ++i) cin >> arr2[i];
    printIntersect(arr1, arr2, n, m);

    return 0;

}
