#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};
void insert(struct node * head,int n) {
struct node * temp;
temp=(struct node*)malloc(sizeof(struct node));

while(head->next!=NULL) {
    head=head->next;
}
head->next=temp;
temp->data=n;
temp->next=NULL;

}
void print(struct node * head) {
    struct node * temp=head;
    while(temp!=NULL) {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int main() {
struct node * head;
head=(struct node*)malloc(sizeof(struct node));
head->data=1;
head=NULL;    

insert(head,5);
insert(head,6);
print(head);
}