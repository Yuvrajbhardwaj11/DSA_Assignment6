#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char v) { data = v; next = prev = NULL; }
};

int main() {
    Node* a = new Node('r');
    Node* b = new Node('a');
    Node* c = new Node('d');
    Node* d = new Node('a');
    Node* e = new Node('r');
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    c->next = d;
    d->prev = c;
    d->next = e;
    e->prev = d;
    Node* left = a;
    Node* right = e;
    bool pal = true;
    while (left != right && right->next != left) {
        if (left->data != right->data) { pal = false; break; }
        left = left->next;
        right = right->prev;
    }
    cout << (pal ? "True" : "False") << endl;
}
