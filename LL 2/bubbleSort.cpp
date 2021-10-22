#include <iostream>
#include "base.cpp"
using namespace std;

node* bubbleSort(node* head, int count) {
    int n = len(head) - 1;
    while (n--) {
        node* prev = NULL;
        node* cur = head;
        while (cur->next != NULL) {
            if (cur->data >= cur->next->data) {
                if (prev == NULL) {
                    node* nxt = cur->next;
                    cur->next = nxt->next;
                    nxt->next = cur;
                    prev = nxt;
                    head = prev;
                } else {
                    node* nxt = cur->next;
                    prev->next = nxt;
                    cur->next = nxt->next;
                    nxt->next = cur;
                    prev = nxt;
                }
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
    }
    return head;

}

int main() {

    node* head = takeInput();
    head = bubbleSort(head, 5);
    display(head);

    return 0;

}
