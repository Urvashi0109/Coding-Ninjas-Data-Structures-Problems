#include <iostream>
#include "TreeNode.cpp"
using namespace std;

// By use of an extra loop to get the sum of the child node
TreeNode<int>* MAX1(TreeNode<int>* root) {
    if (!root) return NULL;
    TreeNode<int>* res = root;
    int sum = root->data;
    for (TreeNode<int>* i : root->children) sum += i->data;
    for (TreeNode<int>* i : root->children) {
        TreeNode<int>* temp = MAX1(i);
        int tempSum = temp->data;
        for (TreeNode<int>* j : temp->children) tempSum += j->data;
        if (tempSum > sum) {
            sum = tempSum;
            res = temp;
        }
    }
    return res;
}

// By using pair to get rid of extra loop

pair<TreeNode<int>*, int> helper(TreeNode<int>* root) {
    pair<TreeNode<int>*, int> res;
    res.first = root;
    int sum = 0;
    for (TreeNode<int>* i : root->children) sum += i->data;
    res.second = sum;
    for (TreeNode<int>* i : root->children) {
        pair<TreeNode<int>*, int> temp = helper(i);
        if (temp.second > res.second) {
            res.first = temp.first;
            res.second = temp.second;
        }
    }
    return res;
}

TreeNode<int>* MAX2(TreeNode<int>* root) {
    if (!root) return NULL;
    pair<TreeNode<int>*, int> res = helper(root);
    return res.first;
}

int main() {

    TreeNode<int>* root = takeInputLevelWise();
    displayLevelWise(root);
    TreeNode<int>* res = MAX2(root);
    cout << endl << res->data << endl;

    return 0;

}
