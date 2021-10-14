#include <iostream>
#include "base.cpp"
using namespace std;

node* reverse(node* head) {
    node* curr = head;
    node* next = NULL, * prev = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Recursive
node* reverseR(node*& head) {
    if (!head || !head->next) return head;
    node* res = reverseR(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}

int main() {
    node* head = takeInput();
    display(head);
    head = reverse(head);
    display(head);

    return 0;

}
