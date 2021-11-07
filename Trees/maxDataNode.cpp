#include <iostream>
#include "TreeNode.cpp"
using namespace std;

TreeNode<int>* maxNode(TreeNode<int>* root) {
    TreeNode<int>* res = new TreeNode<int>(root->data);
    for (int i = 0;i < root->children.size();++i) {
        res->data = max(res->data, maxNode(root->children[i])->data);
    }
    return res;
}

int main() {

    TreeNode<int>* root = takeInputLevelWise();
    display(root);
    cout << "Max: " << (maxNode(root)->data) << endl;

    return 0;

}
