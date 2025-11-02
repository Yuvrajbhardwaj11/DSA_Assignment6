#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int v) { data = v; next = prev = NULL; }
};

int main() {
    Node* d1 = new Node(10);
    Node* d2 = new Node(20);
    Node* d3 = new Node(30);
    d1->next = d2;
    d2->prev = d1;
    d2->next = d3;
    d3->prev = d2;
    int count = 0;
    Node* t = d1;
    while (t) { count++; t = t->next; }
    cout << "Doubly size: " << count << endl;

    Node* c1 = new Node(5);
    Node* c2 = new Node(15);
    Node* c3 = new Node(25);
    c1->next = c2;
    c2->next = c3;
    c3->next = c1;
    count = 0;
    t = c1;
    do {
        count++;
        t = t->next;
    } while (t != c1);
    cout << "Circular size: " << count << endl;
}
