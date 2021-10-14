#include <iostream>
#include "base.cpp"
using namespace std;

void appendLastN(node*& head, int n) {
    node* h1 = head;
    node* h2 = head;
    int l = len(head);
    for (int i = 0; i < l - n - 1; ++i) {
        h1 = h1->next;
    }
    for (int i = 0; i < l - 1; ++i) {
        h2 = h2->next;
    }
    h2->next = head;
    head = h1->next;
    h1->next = NULL;
}

int main() {

    node* head = takeInput();
    display(head);
    appendLastN(head, 4);
    display(head);

    return 0;

}
