#include <iostream>
#include<stack>
#include "base.cpp"
using namespace std;

bool isPalin(node* head) {
    node* temp = head;
    stack<int> s;
    while (temp) {
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (!s.empty()) {
        if (temp->data != s.top()) return 0;
        temp = temp->next;
        s.pop();
    }
    return 1;
}

int main() {

    node* head = takeInput();
    cout << boolalpha << isPalin(head) << endl;


    return 0;

}
