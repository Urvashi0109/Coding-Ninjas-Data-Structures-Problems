#include <iostream>
#include "base.cpp"
using namespace std;

node* reverse(node* head) {
    if (!head || !head->next) return head;
    node* res = reverse(head->next);
    node* tail = head->next;
    tail->next = head;
    head->next = NULL;
    return res;
    /*
        if (!head || !head->next) return head;
        node* res = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return res;
    */
}

int main() {

    node* head = takeInput();
    node* res = reverse(head);
    display(res);

    return 0;

}
