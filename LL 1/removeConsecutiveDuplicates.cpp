#include <iostream>
#include "base.cpp"
using namespace std;

void removeDuples(node*& head) {
    node* p1 = head, * p2 = head->next;
    while (p2) {
        if (p1->data == p2->data) {
            node* todelete = p2;
            p2 = p2->next;
            delete todelete;
        } else {
            p1->next = p2;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    p1->next = p2;
}

void removeDuples2(node*& head) {
    node* p1 = head, * p2 = head->next;
    while (p2) {
        if (p1->data == p2->data) {
            p1->next = p2->next;
            node* todelete = p2;
            p2 = p2->next;
            delete todelete;
        } else {
            p1 = p1->next;
            p1->next = p2;
        }
    }
    p1->next = p2;
}

int main() {

    node* head = takeInput();
    display(head);
    removeDuples(head);
    display(head);


    return 0;

}