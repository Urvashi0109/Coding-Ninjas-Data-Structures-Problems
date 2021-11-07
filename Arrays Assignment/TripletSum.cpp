#include <bits/stdc++.h>
using namespace std;

int cntPairs(int arr[], int n, int sum) {
    int res = 0;
    for (int i = 0;i < n - 1;++i) {
        vector<int> v;
        for (int j = i + 1;j < n;++j) {
            if (find(v.begin(), v.end(), sum - (arr[i] + arr[j])) != v.end()) {
                ++res;
            } else {
                v.push_back(arr[j]);
            }
        }
    }
    return res;
}

int main() {
    int arr[] = { 2, -5, 8, -6, 0, 5, 10, 11, -3 };
    cout << cntPairs(arr, 9, 10);
    return 0;
}