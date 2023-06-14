#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node * next;
};

struct node * insertnode(struct node * head,int n) {
	struct node * temp;
	temp=(struct node * )malloc(sizeof(struct node));
	temp->data=n;
	
	if(head==NULL) {
		head=temp;
		temp->next=temp;
	}
	else {
		struct node * iter=head;
		while(iter->next!=head) {
			iter=iter->next;
		}
		iter->next=temp;
		temp->next=head;

	}
}
void print(struct node * head) {
	struct node * temp;
	temp=head;
	
	while(temp->next!=head) {
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

int main() {
	struct node * head;
	head=NULL;
	head=insertnode(head,5);
	head=insertnode(head,6);
	head=insertnode(head,7);
	head=insertnode(head,8);
	head=insertnode(head,9);
	head=insertnode(head,10);
print(head);
	return 0;
}