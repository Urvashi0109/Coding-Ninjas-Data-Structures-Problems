#include <iostream>
#include "TreeNode.cpp"
using namespace std;

int sumNodes(TreeNode<int>* root) {
    int res = root->data;
    for (int i = 0;i < root->children.size();++i) {
        res += sumNodes(root->children[i]);
    }
    return res;
}

int main() {

    TreeNode<int>* root = takeInputLevelWise();
    displayLevelWise(root);
    cout << "Sum: " << sumNodes(root) << endl;

    return 0;

}
