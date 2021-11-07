#include <bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

int height(TreeNode<int>* root) {
    if (root == NULL) return 0;
    int res = 0;
    for (int i = 0;i < root->children.size();i++) {
        res = max(res, height(root->children[i]));
    }
    return res + 1;
}

int main() {

    TreeNode<int>* root = takeInputLevelWise();
    displayLevelWise(root);
    cout << "Height: " << height(root) << endl;

    return 0;

}
