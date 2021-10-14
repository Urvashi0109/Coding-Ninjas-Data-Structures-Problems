#include <iostream>
using namespace std;

// from first
int allIndex1(int arr[], int size, int x, int out[]) {
    if (size == 0)  return 0;
    int ans = allIndex1(arr + 1, size - 1, x, out);
    if (arr[0] == x) {
        if (ans != 0) {
            for (int i = ans - 1;i >= 0;i--) {
                out[i]++;
                out[i + 1] = out[i];
            }
        }

        out[0] = 0;
        return ans + 1;
    } else {
        for (int i = ans - 1;i >= 0;i--) {
            out[i]++;
        }
        return ans;
    }
}

// from last
int allIndex2(int arr[], int size, int x, int out[]) {
    if (size == 0) return 0;
    int temp = allIndex2(arr, size - 1, x, out);
    if (arr[size - 1] == x) {
        out[temp] = size - 1;
        return temp + 1;
    } else return temp;
}

int main() {

    int arr[] = { 5,6,5,5,6,5 };

    int* out = new int[6];
    int size = allIndex2(arr, 6, 5, out);
    for (int i = 0; i < size; i++) cout << out[i] << " ";

    cout << endl;

    int* out2 = new int[6];
    size = allIndex1(arr, 6, 5, out2);
    for (int i = 0; i < size; i++) cout << out2[i] << " ";

    return 0;

}
