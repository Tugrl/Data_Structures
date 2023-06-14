#include<stdio.h>
#include<stdlib.h>

struct node {
struct node * prev;
struct node * next;
int data;
};
struct node * head;
struct node * tail;
void deletefrombeginnging() {
    struct node * temp;
    if(head==NULL) {
        printf("linked list is empty.");
    }
    else {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}
void deletefromend() {
    struct node * temp;
    if(tail==NULL) {
        printf("sonda eleman yok.");
    }
    else {
        temp=tail;
        tail->prev->next=NULL;
        tail=tail->prev;
        free(temp);
    }
}
void create() {
    
    struct node * newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=3;
    if(head==NULL) {
        head=tail=newnode;
    }
    else {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void insertend(int a) {
  

    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
   


        newnode->data=a;
        tail->next= newnode;
        newnode->prev=tail;
        tail=newnode;
}
void insertbeginning() {
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=4;
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}
void deletefrompos(int n) {
    struct node * temp;
    temp=head;
    int i=1;
    while(i<n) {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}
void print() {
    struct node * temp;
    temp=head;
    printf("düz\n");
    while (temp!=NULL) {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("ters\n");
    struct node * temp2;
  
    while(temp!=NULL) {
        printf("%d\n",temp->data);
        temp=temp->prev;
    }
}

int main() {
    head=NULL;
    create();
insertbeginning();
insertend(5);
print();
//deletefrombeginnging();
//print();
//deletefromend();
//print();
printf("new list\n");
insertend(9);
insertend(11);
print();
//printf("silinen\n");
//deletefrompos(4);
//sprint();
}