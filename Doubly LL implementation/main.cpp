// Double Linked List   

#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

node* head = NULL;
node* tail = NULL;


node* takeInput();
void insertAtHead(node*& head, int val);
void insertAtTail(node*& head, int val);
void insertAt(node*& head, int pos, int val);
void deleteAtHead(node*& head);
void deleteAt(node*& head, int pos);
void display(node* head);
void displayR(node* head);
node* reverse(node* head);

void init() {
    head = takeInput();
    display(head);
    displayR(head);
}

node* takeInput() {
    cout << "Enter -1 to end the input process" << endl;
    node* res = NULL;
    int i = 1;
    int val;
    cout << "Enter " << i << " element: ", cin >> val;
    while (val != -1) {
        node* nodeX = new node(val);
        if (res == NULL) {
            res = nodeX;
            tail = nodeX;
        } else {
            tail->next = nodeX;
            nodeX->prev = tail;
            tail = nodeX;
        }
        ++i;
        cout << "Enter " << i << " element: ", cin >> val;
    }
    return res;
}

node* takeInput(int len) {
    node* res = NULL;
    for (int i = 0; i < len;++i) {
        int val;
        cout << "Enter " << (i + 1) << " element: ", cin >> val;
        node* nodeX = new node(val);
        if (res == NULL) {
            res = nodeX;
            tail = nodeX;
        } else {
            tail->next = nodeX;
            nodeX->prev = tail;
            tail = nodeX;
        }
    }
    return res;
}

void insertAtHead(node*& head, int val) {
    node* nodeX = new node(val);
    nodeX->next = head;
    if (head != NULL) {
        head->prev = nodeX;
    }
    head = nodeX;
}

void insertAtTail(node*& head, int val) {
    if (head == NULL) {
        insertAtHead(head, val);
        return;
    }
    node* nodeX = new node(val);
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nodeX;
    nodeX->prev = temp;
}

void insertAt(node*& head, int pos, int val) {
    if (pos == 1) {
        insertAtHead(head, val);
        return;
    }
    node* nodeX = new node(val);
    node* temp = head;
    int cnt = 1;
    while (cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }
    if (temp->next != NULL) {
        nodeX->next = temp->next;
        nodeX->next->prev = nodeX;
    }
    temp->next = nodeX;
    temp->next->prev = temp;
}

void deleteAtHead(node*& head) {
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}

void deleteAt(node*& head, int pos) {
    if (pos == 1) {
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int cnt = 1;
    while (temp != NULL && cnt != pos) {
        temp = temp->next;
        cnt++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

node* reverse(node* head) {
    node* curr = head;
    node* res = NULL;
    while (curr) {
        res = curr->prev;
        curr->prev = curr->next;
        curr->next = res;
        curr = curr->prev;
    }
    return res->prev;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void displayR(node* head) {
    node* temp = head;
    cout << endl;
    while (temp != NULL) {
        if (temp->prev == NULL) {
            cout << "Prev data: " << "NULL" << endl;
        } else {
            cout << "Prev data: " << temp->prev->data << endl;
        }
        cout << "Data: " << temp->data << endl;
        if (temp->next == NULL) {
            cout << "Next data: " << "NULL" << endl;
        } else {
            cout << "Next data: " << temp->next->data << endl;
        }
        cout << endl;
        temp = temp->next;
    }
}

int main() {

    init();
    insertAtHead(head, 777);
    display(head);
    insertAt(head, 2, 77);
    display(head);
    deleteAtHead(head);
    deleteAt(head, 5);
    display(head);

    return 0;

}