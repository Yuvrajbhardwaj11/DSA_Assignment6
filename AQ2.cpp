#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int v){ data=v; next=NULL; }
};

int parity(int x){
    int c=0;
    while(x){ c+=x&1; x>>=1; }
    return c;
}

Node* removeEvenParity(Node* head){
    if(!head) return NULL;
    Node *cur=head,*prev=NULL;
    do{
        if(parity(cur->data)%2==0){
            if(cur==head){
                Node* t=head;
                while(t->next!=head) t=t->next;
                if(head->next==head) return NULL;
                t->next=head->next;
                head=head->next;
                cur=head;
                continue;
            } else {
                prev->next=cur->next;
                cur=cur->next;
                continue;
            }
        }
        prev=cur;
        cur=cur->next;
    }while(cur!=head);
    return head;
}

int main(){}
