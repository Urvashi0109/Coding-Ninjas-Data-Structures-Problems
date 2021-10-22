// Circular LinkedList
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node*& head, int data) {
    node* nodeX = new node(data);
    if (head == NULL) {
        nodeX->next = nodeX;
        head = nodeX;
        return;
    }
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = nodeX;
    nodeX->next = head;
    head = nodeX;
}

void insertAtTail(node*& head, int data) {
    if (head == NULL) {
        insertAtHead(head, data);
        return;
    }
    node* nodeX = new node(data);
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = nodeX;
    nodeX->next = head;
}

void deleteAtHead(node*& head) {
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    node* todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}

void deleteAt(node*& head, int pos) {
    if (pos == 1) {
        deleteAtHead(head);
    }
    int i = 1;
    node* temp = head;
    while (i < pos - 1) {
        temp = temp->next;
        ++i;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void reverse(node*& head) {
    if (head == NULL) {
        return;
    }
    node* curr = head, * prev = NULL, * next = NULL;
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;


    } while (curr != head);
    head->next = prev;
    head = prev;
}

void display(node* head) {
    node* temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << "(head)" << endl;
}

int main() {

    node* head = NULL;
    for (int i = 1;i < 6;++i) {
        insertAtTail(head, i);
    }
    insertAtHead(head, 777);
    display(head);
    deleteAt(head, 6);
    display(head);
    reverse(head);
    display(head);

    return 0;

}
