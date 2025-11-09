#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev, *up, *down;
    Node(int v){ data=v; next=prev=up=down=NULL; }
};

Node* construct(int a[][100], int r, int c){
    Node* head=NULL;
    Node* rowPrev=NULL;
    for(int i=0;i<r;i++){
        Node* curRow=NULL;
        Node* prev=NULL;
        for(int j=0;j<c;j++){
            Node* n=new Node(a[i][j]);
            if(!curRow) curRow=n;
            if(prev){
                prev->next=n;
                n->prev=prev;
            }
            if(rowPrev){
                Node* upN=rowPrev;
                for(int k=0;k<j;k++) upN=upN->next;
                upN->down=n;
                n->up=upN;
            }
            prev=n;
        }
        if(!head) head=curRow;
        rowPrev=curRow;
    }
    return head;
}

int main(){
    int a[100][100]={{1,2,3},{4,5,6},{7,8,9}};
    Node* head=construct(a,3,3);
}
