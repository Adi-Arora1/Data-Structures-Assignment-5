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
void deleteBegin() {
    Node* t = head;
    head = head->next;
    delete t;
}
void display() {
    Node* t = head;
    while (t) {
        cout << t->data;
        if (t->next) cout << "->";
        t = t->next;
    }
    cout << endl;
}
void countAndDelete(int key) {
    int cnt = 0;
    while (head && head->data == key) { deleteBegin(); cnt++; }
    Node* t = head;
    while (t && t->next) {
        if (t->next->data == key) {
            Node* d = t->next;
            t->next = d->next;
            delete d;
            cnt++;
        } else t = t->next;
    }
    cout << "Count: " << cnt << ", Updated Linked List: ";
    display();
}

int main() {
    int n, val, key;
    cin >> n;
    for (int i=0;i<n;i++) { cin >> val; insertEnd(val); }
    cin >> key;
    countAndDelete(key);
}
