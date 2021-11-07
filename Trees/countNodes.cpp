#include <iostream>
#include "TreeNode.cpp"
using namespace std;

int numNodes(TreeNode<int>* root) {
    if (!root) return 0;
    int res = 1;
    for (int i = 0;i < root->children.size();++i) {
        res += numNodes(root->children[i]);
    }
    return res;
}

int main() {

    TreeNode<int>* root = takeInputLevelWise();
    displayLevelWise(root);
    cout << "Total: " << numNodes(root) << endl;

    return 0;

}