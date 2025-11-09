#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int v){ data=v; next=NULL; }
};

void splitList(Node* head, Node** head1, Node** head2){
    if(!head) return;
    Node *slow=head, *fast=head;
    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    *head1=head;
    if(head->next==head){ *head2=NULL; return; }
    *head2=slow->next;
    slow->next=head;
    if(fast->next==head) fast->next=*head2;
    else fast->next=head;
}

int main(){
    Node* h=new Node(10);
    h->next=new Node(4);
    h->next->next=new Node(9);
    h->next->next->next=h;
    Node *h1=NULL,*h2=NULL;
    splitList(h,&h1,&h2);
}
