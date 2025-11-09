#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next,*prev;
    Node(int v){ data=v; next=prev=NULL; }
};

Node* reverseK(Node* head,int k){
    if(!head) return NULL;
    Node *cur=head,*prev=NULL,*nxt=NULL;
    int c=0;
    while(cur && c<k){
        nxt=cur->next;
        cur->next=prev;
        cur->prev=nxt;
        prev=cur;
        cur=nxt;
        c++;
    }
    if(nxt){
        head->next=reverseK(nxt,k);
        if(head->next) head->next->prev=head;
    }
    return prev;
}

int main(){}
