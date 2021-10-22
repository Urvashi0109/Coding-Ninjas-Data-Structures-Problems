#include <iostream>
#include "base.cpp"
using namespace std;

node* reverse(node* head) {
    if (!head || !head->next) return head;
    node* prev = NULL, * curr = head, * next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {

    node* head = takeInput();
    node* res = reverse(head);
    display(res);

    return 0;

}
