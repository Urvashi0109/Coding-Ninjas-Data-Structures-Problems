#include <iostream>
#include "base.cpp"
using namespace std;

int height(node<int>* root) {
    if (!root) return 0;
    int LH = 1, RH = 1;
    LH += height(root->left);
    RH += height(root->right);
    return max(LH, RH);
}

int main() {

    node<int>* root = takeInput();
    display(root);
    cout << "Height: " << height(root) << endl;

    return 0;

}
