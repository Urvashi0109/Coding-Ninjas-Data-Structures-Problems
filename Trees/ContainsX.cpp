#include <iostream>
#include "TreeNode.cpp"
using namespace std;

bool isPresent(TreeNode<int>* root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;
    for (int i = 0;i < root->children.size();++i) {
        if (isPresent(root->children[i], key)) return 1;
    }
    return 0;
}

int main() {

    TreeNode<int>* root = takeInputLevelWise();
    displayLevelWise(root);
    int key;
    cout << "Enter key: ", cin >> key;
    cout << endl << boolalpha << isPresent(root, key);

    return 0;

}
