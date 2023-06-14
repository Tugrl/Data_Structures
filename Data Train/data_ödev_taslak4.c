#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
struct Student {
	char name[50];
	char gender;
	struct Student* next;
};
struct Student* insertNode(char* name, char gender, struct Student* list) {
	struct Student* s;
	s = malloc(sizeof(struct Student));
	if (s == NULL) {
		printf("Memory allocation failed. ");
		return list;
	}
	strcpy(s->name, name);
	s->gender = gender;
	s->next = list;
	list = s;
    
}


struct Student * sortList(struct Student * head) { 
	
    struct Student * prev;
    struct Student * cur;
    prev=head;
    cur=prev->next;
    prev->next=NULL;
//struct Student * p =head;
    while(cur!=NULL) {
       //while (head!=NULL) {
		//struct Student * p =head;
       struct Student * temp =cur;
       cur=cur->next;
       if(head->gender=='M' && temp->gender=='F') {
        printf("1. if\n");
        temp->next=head;
        head=temp;
       }
       if(head->gender=='F' && temp->gender=='F' && strcmp(head->name,temp->name) > 0) {
        printf("2. if\n");
        temp->next=head;
        head=temp;
       }
	 //  while (p->next!=NULL) {
       if(head->gender=='M' && temp->gender=='M' && strcmp(head->name,temp->name) < 0) {
        printf("3. if\n");
        temp->next=head;
        head=temp;
       }
	  // }        //}
    }
	return head;
}
void printlist(struct Student* list) {
	while (list != NULL) {
		printf("%s\t%c\n", list->name, list->gender);
		list = list->next;
	}
}
int main() {
	struct Student* head = NULL;
	head = insertNode("Cenk", 'M', head);
	head = insertNode("Ceyda", 'F', head);
	head = insertNode("Esra", 'F', head);
	head = insertNode("Okan", 'M', head);
	head = insertNode("Tugce", 'F', head);
	head = insertNode("Mehmet", 'M', head);
	head = insertNode("Ayse", 'F', head);
	head = insertNode("Merve", 'F', head);
	head = insertNode("Sedat", 'M', head);
	head = insertNode("Ahmet", 'M', head);
	printlist(head);
	printf("\n");
	head=sortList(head);
	printlist(head);
}