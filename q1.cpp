#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertBegin(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = head;
    head = n;
}
void insertEnd(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;
    if (!head) head = n;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}
void insertBefore(int key, int val) {
    if (!head) return;
    if (head->data == key) {
        insertBegin(val);
        return;
    }
    Node* t = head;
    while (t->next && t->next->data != key) t = t->next;
    if (t->next) {
        Node* n = new Node();
        n->data = val;
        n->next = t->next;
        t->next = n;
    }
}
void insertAfter(int key, int val) {
    Node* t = head;
    while (t && t->data != key) t = t->next;
    if (t) {
        Node* n = new Node();
        n->data = val;
        n->next = t->next;
        t->next = n;
    }
}
void deleteBegin() {
    if (!head) return;
    Node* t = head;
    head = head->next;
    delete t;
}
void deleteEnd() {
    if (!head) return;
    if (!head->next) { delete head; head = NULL; return; }
    Node* t = head;
    while (t->next->next) t = t->next;
    delete t->next;
    t->next = NULL;
}
void deleteValue(int val) {
    if (!head) return;
    if (head->data == val) { deleteBegin(); return; }
    Node* t = head;
    while (t->next && t->next->data != val) t = t->next;
    if (t->next) {
        Node* d = t->next;
        t->next = d->next;
        delete d;
    }
}
int search(int val) {
    Node* t = head; int pos = 1;
    while (t) {
        if (t->data == val) return pos;
        t = t->next; pos++;
    }
    return -1;
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

int main() {
    int ch, val, key;
    while (true) {
        cout << "\n1.Insert Begin 2.Insert End 3.Insert Before 4.Insert After\n";
        cout << "5.Delete Begin 6.Delete End 7.Delete Value 8.Search 9.Display 0.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> val; insertBegin(val); break;
            case 2: cin >> val; insertEnd(val); break;
            case 3: cin >> key >> val; insertBefore(key,val); break;
            case 4: cin >> key >> val; insertAfter(key,val); break;
            case 5: deleteBegin(); break;
            case 6: deleteEnd(); break;
            case 7: cin >> val; deleteValue(val); break;
            case 8: cin >> val; cout << search(val) << endl; break;
            case 9: display(); break;
            case 0: return 0;
        }
    }
}
