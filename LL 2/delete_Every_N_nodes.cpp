#include <iostream>
#include "base.cpp"
using namespace std;

node* deleteEveryN(node* head, int M, int N) {
    if (M == 0) return NULL;
    if (!head || !head->next) return head;
    node* temp = head, * t1, * t2;
    int c1 = 0, c2 = 0;

    while (temp->next && c1 < M - 1) {
        ++c1;
        temp = temp->next;
    }
    t1 = temp;

    temp = temp->next;
    while (temp->next && c2 < N - 1) {
        ++c2;
        temp = temp->next;
    }
    t2 = temp->next;

    node* next = deleteEveryN(t2, M, N);
    t1->next = next;

    return head;
}

int main() {

    node* head = takeInput();
    node* res = deleteEveryN(head, 2, 3);
    display(res);

    return 0;

}
