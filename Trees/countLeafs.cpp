#include <iostream>
#include "TreeNode.cpp"
using namespace std;

int leafs(TreeNode<int>* root) {
    if (!root) return 0;
    if (root->children.size() == 0) return 1;
    int res = 0;
    for (int i = 0; i < root->children.size();++i) {
        res += leafs(root->children[i]);
    }
    return res;
}

int main() {

    TreeNode<int>* root = takeInputLevelWise();
    displayLevelWise(root);
    cout << "Total Leafs: " << leafs(root) << endl;

    return 0;

}
