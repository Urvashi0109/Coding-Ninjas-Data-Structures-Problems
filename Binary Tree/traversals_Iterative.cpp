#include <iostream>
#include <stack>
#include "base.cpp"
using namespace std;

void preorder(node<int>* root) {
    if (!root) return;
    node<int>* curr = root;
    stack<node<int>*> st;
    st.push(curr);
    while (!st.empty()) {
        while (curr) {
            cout << curr->data << " ";
            if (curr->right) st.push(curr->right);
            curr = curr->left;
        }
        if (!st.empty()) {
            curr = st.top();
            st.pop();
        }
    }
}

void inorder(node<int>* root) {
    if (!root) return;
    stack<node<int>*> st;
    node<int>* curr = root;
    while (!st.empty() || curr) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();

        cout << curr->data << " ";
        curr = curr->right;

    }
}

void postorder(node<int>* root) {
    if (!root) return;
    node<int>* curr = root;
    stack<node<int>*> st;
    while (curr || !st.empty()) {
        if (curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            node<int>* temp = st.top()->right;
            if (temp == NULL) {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            } else {
                curr = temp;
            }
        }
    }
}

int main() {

    node<int>* root = takeInput();
    display(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;

}