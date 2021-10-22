#include <iostream>
#include "base.cpp"
using namespace std;

int find(node* head, int key, int res = 0) {
    if (!head) return -1;
    if (head->data == key) return res;
    return find(head->next, key, ++res);
}

int main() {

    node* head = takeInput();
    cout << boolalpha << find(head, 1) << endl;
    cout << boolalpha << find(head, 5) << endl;
    cout << boolalpha << find(head, 7) << endl;

    return 0;

}
