// https://practice.geeksforgeeks.org/problems/given-a-linked-list-reverse-alternate-nodes-and-append-at-the-end/1/?category[]=Linked%20List&category[]=Linked%20List&problemStatus=unsolved&difficulty[]=1&page=1&query=category[]Linked%20ListproblemStatusunsolveddifficulty[]1page1category[]Linked%20List

#include <iostream>
#include "base.cpp"
using namespace std;

node* reverse(node*& head) {
    if (!head || !head->next) return head;
    node* res = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}

void rearrange(node*& head) {
    if (!head) return;
    node* oddFirst = head, * odd = head, * evenFirst = head->next, * even = head->next;
    while (1) {
        if (!odd || !even || !even->next) {
            break;
        }
        odd->next = even->next;
        odd = odd->next;
        if (!odd->next) {
            even->next = NULL;
            break;
        }
        even->next = odd->next;
        even = even->next;
    }
    odd->next = NULL;
    evenFirst = reverse(evenFirst);
    odd->next = evenFirst;
}

int main() {

    node* head = takeInput();
    rearrange(head);
    display(head);

    return 0;

}
