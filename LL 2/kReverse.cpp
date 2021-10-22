#include <iostream>
#include "base.cpp"
using namespace std;

node* kReverse(node* head, int k) {
    if (!head || k == 0) return head;
    node* curr = head, * prev = NULL, * next = NULL;
    int cnt = 0;
    while (curr && cnt < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        ++cnt;
    }
    if (next) {
        head->next = kReverse(next, k);
    }
    return prev;
}

int main() {

    node* head = takeInput();
    node* res = kReverse(head, 4);
    display(res);

    return 0;

}
