#include<stdio.h>
#include<stdlib.h>
struct n {
int data;
struct n*next;
};
typedef struct n node;
node * head;
    
void yazdir(node * r) {
    while(r!=NULL) {
        printf("\n%d\n",r->data);
        r=r->next;
    }
}
void ekle (node * r,int x) {
    while(r->next!=NULL) {
    r=r->next;
    }
    r->next=(node*)malloc(sizeof(node));
        r->next->data=x;
        r->next->next=NULL;
        
}
node * eklesirali(node * r,int x) {
if(r==NULL) {
    r = (node*)malloc(sizeof(node));
    r->data=x;
    r->next=NULL;
}
node * iter=r;
while(iter->next!=NULL && iter->next->data<x){
    iter=iter->next;
}
node * temp=(node*)malloc(sizeof(node));
temp->next=iter->next;
iter->next=temp;
temp->data=x;
 if(r->next==NULL) {
    if(r->data>x) {
    node * temp= (node*)malloc(sizeof(node));
    temp->next=NULL;
    temp->data=x;
    temp->next=r;
    return temp;
    }

else {
    node * temp =(node*)malloc(sizeof(node));
    temp->next=NULL;
    temp->data=x;
    r->next=temp;
    return r;
}
}
}
int main() {
    
    head=(node * )malloc(sizeof(node));
    head->next=NULL;
        head->data=101;   
for(int i=1;i<=5;i++){
   ekle(head,5);
}
node * iter=head;
for(int i=0;i<3;i++) {
iter=iter->next;
node * temp=(node*)malloc(sizeof(node));
temp->next=iter->next;
iter->next=temp;
temp->data=i*10;
}
//yazdir(head);
head=eklesirali(head,6);
head=eklesirali(head,50);
head=eklesirali(head,11);
head=eklesirali(head,16);
yazdir(head);
}