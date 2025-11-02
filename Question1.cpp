#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int v) { data = v; next = prev = NULL; }
};

void insertCircular(Node*& head, int v, int pos) {
    Node* n = new Node(v);
    if (!head) {
        head = n;
        head->next = head;
        return;
    }
    if (pos == 1) {
        Node* t = head;
        while (t->next != head) t = t->next;
        n->next = head;
        t->next = n;
        head = n;
    } else {
        Node* t = head;
        for (int i = 1; i < pos - 1 && t->next != head; i++) t = t->next;
        n->next = t->next;
        t->next = n;
    }
}

void deleteCircular(Node*& head, int key) {
    if (!head) return;
    Node *curr = head, *prev = NULL;
    if (head->data == key) {
        if (head->next == head) { delete head; head = NULL; return; }
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = head->next;
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            return;
        }
    } while (curr != head);
}

void searchCircular(Node* head, int key) {
    if (!head) { cout << -1 << endl; return; }
    Node* t = head;
    int pos = 1;
    do {
        if (t->data == key) { cout << pos << endl; return; }
        t = t->next;
        pos++;
    } while (t != head);
    cout << -1 << endl;
}

void displayCircular(Node* head) {
    if (!head) return;
    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << endl;
}

void insertDoubly(Node*& head, int v, int pos) {
    Node* n = new Node(v);
    if (!head) { head = n; return; }
    if (pos == 1) {
        n->next = head;
        head->prev = n;
        head = n;
        return;
    }
    Node* t = head;
    for (int i = 1; i < pos - 1 && t->next; i++) t = t->next;
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    t->next = n;
}

void deleteDoubly(Node*& head, int key) {
    if (!head) return;
    if (head->data == key) {
        Node* t = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete t;
        return;
    }
    Node* t = head;
    while (t && t->data != key) t = t->next;
    if (!t) return;
    if (t->next) t->next->prev = t->prev;
    if (t->prev) t->prev->next = t->next;
    delete t;
}

void searchDoubly(Node* head, int key) {
    int pos = 1;
    while (head) {
        if (head->data == key) { cout << pos << endl; return; }
        head = head->next;
        pos++;
    }
    cout << -1 << endl;
}

void displayDoubly(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* cHead = NULL;
    Node* dHead = NULL;
    int ch, v, pos, key;
    do {
        cin >> ch;
        switch (ch) {
            case 1: cin >> v >> pos; insertCircular(cHead, v, pos); break;
            case 2: cin >> key; deleteCircular(cHead, key); break;
            case 3: cin >> key; searchCircular(cHead, key); break;
            case 4: displayCircular(cHead); break;
            case 5: cin >> v >> pos; insertDoubly(dHead, v, pos); break;
            case 6: cin >> key; deleteDoubly(dHead, key); break;
            case 7: cin >> key; searchDoubly(dHead, key); break;
            case 8: displayDoubly(dHead); break;
        }
    } while (ch != 0);
}
