#include <iostream>
#include "base.cpp"
using namespace std;

void split(node*& head, node*& a, node*& b) {
    node* slow = head;
    node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    a = head;
    b = slow->next;
    slow->next = NULL;
}

node* merge(node* h1, node* h2) {
    if (!h1) return h2;
    else if (!h2) return h1;
    node* res;
    if (h1->data < h2->data) {
        res = h1;
        res->next = merge(h1->next, h2);
    } else {
        res = h2;
        res->next = merge(h1, h2->next);
    }
    return res;
}

node* mergeSort(node* head) {
    if (head->next == NULL) {
        return head;
    }
    node* first = NULL, * second = NULL;
    split(head, first, second);
    first = mergeSort(first);
    second = mergeSort(second);
    return merge(first, second);
}

int main() {

    node* head = takeInput();
    node* sorted = mergeSort(head);
    display(sorted);

    return 0;

}

