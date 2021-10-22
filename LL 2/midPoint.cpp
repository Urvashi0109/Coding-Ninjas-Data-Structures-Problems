#include <iostream>
#include "base.cpp"
using namespace std;

node* mid(node* head) {
    if (!head) return NULL;
    node* slow = head;
    node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {

    node* head = takeInput();
    display(head);
    cout << "Mid: " << mid(head)->data << endl;

    return 0;

}
