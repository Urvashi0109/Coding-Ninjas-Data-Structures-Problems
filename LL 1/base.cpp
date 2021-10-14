#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int data) {
        this->data = data;
        next = NULL;
    }
};

node* takeInput() {
    node* head = NULL, * tail = NULL;
    int val;
    cin >> val;
    while (val != -1) {
        node* nodeX = new node(val);
        if (!head) {
            head = tail = nodeX;
        } else {
            tail->next = nodeX;
            tail = tail->next; // tail = nodeX;
        }
        cin >> val;
    }
    return head;
}

void insertAtHead(node*& head, int val) {
    node* nodeX = new node(val);
    nodeX->next = head;
    head = nodeX;
}

node* insertAtTailR(node*& head, int val) {
    if (!head) return (new node(val));
    head->next = insertAtTailR(head->next, val);
    return head;
}

void insertAtTail(node*& head, int val) {
    node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new node(val);
}

node* insertAt(node*& head, int pos, int val) {
    if (pos == 0) {
        node* nodeX = new node(val);
        nodeX->next = head;
        head = nodeX;
        return nodeX;
    }
    if (!head || pos < 0) return head;
    head->next = insertAt(head->next, pos - 1, val);
    return head;
}

void deleteAtHead(node*& head) {
    node* todelete = head;
    head = head->next;
    cout << head->data << endl;
    delete todelete;
}

void deleteNodeK(node*& head, int key) {
    if (head == NULL) {
        return;
    }
    if (head->data == key) {
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    while (temp->next->data != key) {
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void deleteNode(node*& head, int i) {
    if (!head) return;
    if (i == 0) {
        node* todelete = head;
        head = head->next;
        delete todelete;
        return;
    }
    int cnt = 0;
    node* temp = head;
    while (cnt < i - 1) {
        temp = temp->next;
        ++cnt;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

bool indexOf(node* head, int val) {
    node* temp = head;
    int cnt = 0;
    while (temp) {
        if (temp->data == val) return cnt;
        ++cnt;
        temp = temp->next;
    }
    return -1;
}

node* deleteNodeR(node*& head, int i) {
    if (!head || i < 0) return head;
    if (i == 0) {
        node* res = head->next;
        delete head;
        return res;
    }
    head->next = deleteNodeR(head->next, i - 1);
    return head;
}

/*
int len(node* head) {
    int res = 0;
    node* temp = head;
    while (temp) {
        ++res;
        temp = temp->next;
    } return res;
}
*/


int len(node* head) {
    return head ? (1 + len(head->next)) : 0;
}

int get(node* head, int i) {
    if (!head) return -1;
    if (i == 0) return head->data;
    return get(head->next, i - 1);
}

void display(node* head) {
    node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    } cout << "NULL" << endl;
}

// int main() {

//     node* head = takeInput();
//     display(head);
//     cout << len(head) << endl;
//     for (int i = 0;i < 7;++i) {
//         cout << get(head, i) << endl;
//     }
//     insertAtHead(head, -99);
//     insertAtTail(head, 99);
//     insertAt(head, 3, 99);
//     deleteNode(head, 0);
//     display(head);

//     return 0;

// }
