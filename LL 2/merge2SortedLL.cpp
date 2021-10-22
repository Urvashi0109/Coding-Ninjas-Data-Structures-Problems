#include <iostream>
#include "base.cpp"
using namespace std;

node* merge(node* h1, node* h2) {
    node* newHead = NULL, * tail = NULL;
    if (h1->data < h2->data) {
        newHead = h1;
        h1 = h1->next;
    } else {
        newHead = h2;
        h2 = h2->next;
    }
    tail = newHead;
    while (h1 && h2) {
        if (h1->data < h2->data) {
            tail->next = h1;
            h1 = h1->next;
        } else {
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
    }
    tail->next = h1 ? h1 : h2;

    return newHead;
}

int main() {

    node* h1 = takeInput();
    node* h2 = takeInput();

    node* res = merge(h1, h2);
    display(h1);
    display(h2);
    display(res);

    return 0;

}
