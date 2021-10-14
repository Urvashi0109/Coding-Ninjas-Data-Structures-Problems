#include <iostream>
#include "base.cpp"
using namespace std;

int numNodes(node<int>* root) {
    if (!root) return 0;
    return 1 + numNodes(root->left) + numNodes(root->right);
}

int main() {

    node<int>* root = takeInput();
    display(root);
    cout << "Total num of nodes: " << numNodes(root) << endl;

    return 0;

}
