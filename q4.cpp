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
void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    while (curr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}
void display() {
    Node* t = head;
    while (t) {
        cout << t->data;
        if (t->next) cout << "->";
        t = t->next;
    }
    cout << "->NULL" << endl;
}

int main() {
    int n, val;
    cin >> n;
    for (int i=0;i<n;i++) { cin >> val; insertEnd(val); }
    reverseList();
    display();
}
