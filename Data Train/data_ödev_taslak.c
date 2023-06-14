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
int compare(struct Student * female,struct Student * male,struct Student * head){
	
	while(head!=NULL){
	if(female->gender=='F'&& male->gender=='M'){
		return -1;
	}
	else if(male->gender=='M' && female->gender=='F'){
		return 1;
	}
	else if(female->gender == male->gender){
		return strcmp(female->name,male->name);
	}
	else{

	return 0;
	}
	head=head->next;
	}
}

struct Student * sortList(struct Student * head) { 
	
	struct Student * prev=head;
	struct Student * now = prev->next;
if(head==NULL || head->next==NULL) {
	printf(	"list is empty.");
	return head;
} 
	prev->next=NULL;
	
	while(now!=NULL){
		struct Student * temp=now;
		
		if(compare(temp , head, head )< 0) {
             temp->next=head;
              head=temp;
			  return head;
			  head=head->next;
		}
		else {
			
			while(head->next!=NULL && (compare(temp , head->next , head ) > 0) ) {
				temp=temp->next;
				temp->next=head->next;
				head->next=temp;
				return head;
                head=head->next;
			}
			
		}
         now=now->next;
	}
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
	head=sortList(head);
	printlist(head);
}
