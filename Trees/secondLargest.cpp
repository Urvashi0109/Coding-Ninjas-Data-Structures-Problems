#include <iostream>
#include "TreeNode.cpp"
using namespace std;

void helper(TreeNode<int>* root, TreeNode<int>*& first, TreeNode<int>*& second) {
    if (!root) return;
    if (!first) {
        first = root;
    } else if (first->data < root->data) {
        second = first;
        first = root;
    } else if (second->data < root->data) {
        second = root;
    }
    for (TreeNode<int>* i : root->children) helper(i, first, second);
}

TreeNode<int>* secondLargest(TreeNode<int>* root) {
    TreeNode<int>* first = NULL, * second = NULL;
    helper(root, first, second);
    if (!second || first->data == second->data) return NULL;
    return second;
}

int main() {

    TreeNode<int>* root = takeInputLevelWise();
    cout << endl << secondLargest(root)->data << endl;

    return 0;

}
