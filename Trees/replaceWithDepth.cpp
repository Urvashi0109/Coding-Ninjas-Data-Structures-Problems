#include <iostream>
#include "TreeNode.cpp"
using namespace std;

void replaceWithDepth(TreeNode<int>*& root, int depth = -1) {
    if (!root) return;
    root->data = depth + 1;
    cout << root->data << endl;
    for (TreeNode<int>*& i : root->children) {
        replaceWithDepth(i, depth + 1);
    }
}

int main() {

    TreeNode<int>* root = takeInputLevelWise();
    replaceWithDepth(root);
    cout << endl;
    displayLevelWise(root);

    return 0;

}
