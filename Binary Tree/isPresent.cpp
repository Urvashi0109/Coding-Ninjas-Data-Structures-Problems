#include <iostream>
#include "base.cpp"
using namespace std;

bool isPresent(node<int>* root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;
    if (isPresent(root->left, key)) return 1;
    if (isPresent(root->right, key)) return 1;
    return 0;
}

int main() {

    node<int>* root = takeInput();
    int key;
    cout << "\nEnter key: ", cin >> key;
    display(root);
    cout << boolalpha << isPresent(root, key) << endl;

    return 0;

}
