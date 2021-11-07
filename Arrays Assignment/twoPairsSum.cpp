#include <bits/stdc++.h>
using namespace std;

int cntPairs(int arr[], int n, int k) {
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(k - arr[i]) != m.end()) {
            count += m[k - arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
}

int main() {
    int arr[] = { 1,3,3,4,5,8,9,9,9,15 };
    cout << cntPairs(arr, 10, 12);
    return 0;
}