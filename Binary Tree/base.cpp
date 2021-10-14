#include <iostream>
#include <queue>
using namespace std;

template<typename T>
struct node {
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = right = NULL;
    }
    ~node() {
        delete left;
        delete right;
    }
};

node<int>* takeInput() {
    int data;
    cout << "Enter root data: ", cin >> data;
    if (data == -1) return NULL;
    queue<node<int>*> pending;
    node<int>* root = new node<int>(data);
    pending.push(root);
    while (pending.size()) {
        node<int>* front = pending.front();
        pending.pop();
        cout << "Enter left child data for " << front->data << ": ", cin >> data;
        node<int>* temp;
        if (data != -1) {
            temp = new node<int>(data);
            front->left = temp;
            pending.push(temp);
        }
        cout << "Enter right child data for " << front->data << ": ", cin >> data;
        if (data != -1) {
            temp = new node<int>(data);
            front->right = temp;
            pending.push(temp);
        }
    }
    return root;
}

node<int>* takeInputBekar() {
    int data;
    cout << "Enter data: ", cin >> data;
    if (data == -1) return NULL;
    node<int>* root = new node<int>(data);
    node<int>* left = takeInputBekar();
    node<int>* right = takeInputBekar();
    root->left = left;
    root->right = right;
    return root;
}

void displayBekar(node<int>* root) {
    if (root == NULL) return;
    cout << root->data << ": ";
    if (root->left) cout << "L( " << root->left->data << " ) , ";
    if (root->right) cout << "R( " << root->right->data << " )";
    cout << endl;
    displayBekar(root->left);
    displayBekar(root->right);
}

void display(node<int>* root) {
    if (!root) return;
    queue<node<int>*> pending;
    pending.push(root);
    while (pending.size()) {
        node<int>* front = pending.front();
        pending.pop();
        cout << front->data << ": ";
        if (front->left) {
            cout << "L( " << front->left->data << " ) , ";
            pending.push(front->left);
        }
        if (front->right) {
            cout << "R( " << front->right->data << " )";
            pending.push(front->right);
        }
        cout << endl;
    }
}

// int main() {

//     node<int>* root = takeInput();
//     display(root);

//     return 0;

// }
