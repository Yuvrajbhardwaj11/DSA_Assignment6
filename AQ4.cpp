#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next,*prev,*random;
    Node(int v){ data=v; next=prev=random=NULL; }
};

void fixRandom(Node* head){
    Node* cur=head;
    while(cur){
        cur->random = cur->next;
        cur=cur->next;
    }
}

int main(){}
