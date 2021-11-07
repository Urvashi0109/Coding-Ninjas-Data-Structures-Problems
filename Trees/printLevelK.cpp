#include <iostream>
#include "TreeNode.cpp"
using namespace std;

void displayLevelK(TreeNode<int>* root, int k) {
    if (!root) return;
    if (k == 0) {
        cout << root->data << " ";
        return;
    }
    for (int i = 0;i < root->children.size();++i) {
        displayLevelK(root->children[i], k - 1);
    }
}


int main() {

    TreeNode<int>* root = takeInputLevelWise();
    // 20 5 2 34 50 60 70 2 15 20 1 30 3 40 100 20 0 0 0 2 25 50 0 0 0 0 0 0
    displayLevelWise(root);
    cout << "--------------" << endl;
    for (int i = 0;i < 4;++i) {
        cout << "At Lvl" << i << ": ";
        displayLevelK(root, i);
        cout << endl;
    }

    return 0;

}