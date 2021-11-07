#include <iostream>
#include "TreeNode.cpp"
using namespace std;

TreeNode<int>* nextLarger(TreeNode<int>* root, int key) {
    if (!root) return NULL;
    if (root->data > key) return root;
    for (TreeNode<int>* i : root->children) {
        if (i->data > key) {
            return i;
        }
    }
    for (TreeNode<int>* i : root->children) {
        nextLarger(i, key);
    }
    return NULL;

    /*
    Approach 2
    if(!root) return NULL;
    TreeNode<int>* res =NULL;

    if(root->data > n) res=root;

    for(int i=0;i<root->children.size();i++) {
        TreeNode<int>*childmax= nextLarger(root->children[i], n);
        if(childmax==NULL) {continue;}

        else {
            if(res==NULL)
                res=childmax;
            else if(childmax->data > n  && childmax->data < res->data)
                res= childmax;
        }
    }

    return res;
    */
}

int main() {

    TreeNode<int>* root = takeInputLevelWise();
    int key;
    cout << "Enter key: ", cin >> key;
    cout << endl << nextLarger(root, key)->data << endl;

    return 0;

}
