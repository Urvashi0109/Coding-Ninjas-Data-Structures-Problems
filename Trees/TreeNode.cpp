#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(int data) {
        this->data = data;
    }
    ~TreeNode() {
        for (int i = 0;i < children.size();++i) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInput() {
    int data, c;
    cout << "Enter data: ", cin >> data;
    cout << "Enter num of children: ", cin >> c;
    TreeNode<int>* root = new TreeNode<int>(data);
    for (int i = 0;i < c;++i) {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int>* takeInputLevelWise() {
    int data;
    cout << "Enter data: ", cin >> data;
    TreeNode<int>* root = new TreeNode<int>(data);
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while (pending.size()) {
        TreeNode<int>* front = pending.front();
        pending.pop();
        int n;
        cout << "Enter num of children for " << front->data << ": ", cin >> n;
        for (int i = 0; i < n; ++i) {
            int cData;
            cout << "Enter " << i + 1 << "th child of " << front->data << ": ", cin >> cData;
            TreeNode<int>* child = new TreeNode<int>(cData);
            front->children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}

void display(TreeNode<int>* root) {
    cout << root->data << ": ";
    for (int i = 0;i < root->children.size();++i) {
        cout << root->children[i]->data << ",";
    } cout << endl;
    for (int i = 0;i < root->children.size();++i) {
        display(root->children[i]);
    }
}

void displayLevelWise(TreeNode<int>* root) {
    if (!root) return;
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while (pending.size()) {
        TreeNode<int>* front = pending.front();
        pending.pop();
        cout << front->data << ": ";
        for (int i = 0;i < front->children.size();++i) {
            cout << front->children[i]->data << ",";
            pending.push(front->children[i]);
        }cout << endl;
    }
}