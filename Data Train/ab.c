#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node * prev;
struct node * next;
};
struct node * head;
struct node * tail;
void create (int n) {
struct node * newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=n;

if(head==NULL) {
    head=tail=newnode;
    head->prev=head;
    head->next=head;
}
else {
    tail->next=newnode;
    newnode->prev=tail;
    newnode->next=head;
    head->prev=newnode;
    tail=newnode;
}
}
void insertbeg(int n) {
struct node * newnode=(struct node * )malloc(sizeof(struct node));
newnode->data=n;

if(head==NULL) {
        head=tail=newnode;
        newnode->prev=tail;
      newnode->next=head;
}
else {
    newnode->next=head;
    head->prev=newnode;
    newnode->prev=tail;
    tail->next=newnode;
    head=newnode;
}
}
void print() {
    struct node * temp=head;
    while(temp!=head) {
    printf("%d",temp->data);
    temp=temp->next;
    }
}

int main() {
create(5);
insertbeg(4);
print();
}