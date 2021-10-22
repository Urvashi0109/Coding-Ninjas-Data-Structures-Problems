#include <iostream>
#include "base.cpp"
using namespace std;

/*
node* swapNodes(node* head, int i, int j) {
    node* temp = head, * prev = NULL;
    node* c1 = NULL, * p1 = NULL; //current 1 ,previous 1
    node* c2 = NULL, * p2 = NULL;//current 2 ,previous 2

    int count = 0;
    while (temp != NULL) {
        if (count == i) {
            c1 = temp;
            p1 = prev;

        } else if (count == j) {
            c2 = temp;
            p2 = prev;
        }
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (p1 != NULL) p1->next = c2;
    else head = c2;

    if (p2 != NULL) p2->next = c1;
    else head = c1;

    node* p = c2->next;
    c2->next = c1->next;
    c1->next = p;

    return head;
}
*/

void swapNodes(node* head, int p1, int p2) {
    node* n1 = head, * n2 = head;
    for (int i = 0;i < p1;++i) {
        n1 = n1->next;
    }
    for (int i = 0;i < p2;++i) {
        n2 = n2->next;
    }
    int temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
}

int main() {

    node* head = takeInput();
    display(head);
    swapNodes(head, 1, 3);
    display(head);
    swapNodes(head, 0, 3);
    display(head);
    swapNodes(head, 0, 1);
    display(head);
    swapNodes(head, 2, 3);
    display(head);

    return 0;

}
