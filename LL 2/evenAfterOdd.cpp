#include <iostream>
#include "base.cpp"
using namespace std;

node* evenAfterOdd(node* head) {
    if (!head) {
        return NULL;
    }
    // For odd and even value nodes
    node* temp = head, * oddHead = NULL, * oddTail = NULL, * evenHead = NULL, * evenTail = NULL;
    while (temp) {
        if (temp->data % 2 == 0) {
            if (!evenHead) evenHead = evenTail = temp;
            else {
                evenTail->next = temp;
                evenTail = temp;
            }
        } else {
            if (!oddHead) oddHead = oddTail = temp;
            else {
                oddTail->next = temp;
                oddTail = temp;
            }
        }
        temp = temp->next;
    }
    if (!oddHead) return evenHead;
    oddTail->next = NULL;
    if (evenTail) evenTail->next = NULL;
    oddTail->next = evenHead;
    return oddHead;


    // As per odd and even positions
    // node* oddFirst = head, * odd = head, * evenFirst = head->next, * even = head->next;
    // while (1) {
    //     if (!odd || !even || !even->next) {
    //         break;
    //     }
    //     odd->next = even->next;
    //     odd = odd->next;
    //     if (!odd->next) {
    //         even->next = NULL;
    //         break;
    //     }
    //     even->next = odd->next;
    //     even = even->next;
    // }
    // odd->next = evenFirst;
    // return oddFirst;        
}

int main() {

    node* head = takeInput();
    node* res = evenAfterOdd(head);
    display(res);

    return 0;

}
