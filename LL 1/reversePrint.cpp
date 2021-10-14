#include <iostream>
#include "base.cpp"
using namespace std;

void printReversed(node* head){
    if(!head) return;
    printReversed(head->next);
    cout<<head->data<<" ";
}

int main() {

    node* head = takeInput();
    printReversed(head);


    return 0;

}
