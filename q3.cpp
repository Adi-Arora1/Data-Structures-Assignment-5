#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertEnd(int val) {
    Node* n = new Node();
    n->data = val; n->next = NULL;
    if (!head) head = n;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}
void findMiddle() {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow) cout << slow->data << endl;
}

int main() {
    int n, val;
    cin >> n;
    for (int i=0;i<n;i++) { cin >> val; insertEnd(val); }
    findMiddle();
}
