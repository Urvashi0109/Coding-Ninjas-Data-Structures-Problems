#include <iostream>
#include "base.cpp"
using namespace std;

void mirror(node<int>*& root) {
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

int main() {

    node<int>* root = takeInput();
    display(root);
    cout << endl;
    mirror(root);
    display(root);


    return 0;

}
