#include <iostream>
#include "TreeNode.cpp"
using namespace std;

bool isIdentical(TreeNode<int>* root1, TreeNode<int>* root2) {
    if (root1->data != root2->data || root1->children.size() != root2->children.size())
        return 0;
    for (int i = 0;i < root1->children.size();++i) {
        if (!isIdentical(root1->children[i], root2->children[i]))
            return 0;
    }
    return 1;
}


int main() {

    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    display(root1);
    display(root2);

    cout << endl << boolalpha << isIdentical(root1, root2) << endl;

    return 0;

}
