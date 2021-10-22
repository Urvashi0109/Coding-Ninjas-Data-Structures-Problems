#include <iostream>
#include "base.cpp"
using namespace std;

void rotate(node*& head, int k) {
    if (!head) return;
    node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head;
    for (int i = 0;i < k;++i) {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
}

int main() {

    node* head = takeInput();
    rotate(head, 3);
    display(head);

    return 0;

}
