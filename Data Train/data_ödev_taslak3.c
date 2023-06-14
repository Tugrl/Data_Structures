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

    while(cur!=NULL) {
        struct Student * temp= cur;
        cur=cur->next;
        if(head->gender=='F'&& temp->gender=='M')  {
            printf("ilk if\n");
            temp->next =head;
            head=temp;
			
        }
        if(head->gender=='F'&& temp->gender=='F' && strcmp(temp,head) < 0) {
         printf("2. if\n");
         
             temp->next =head;
            head=temp;
			
        }
		
        if (head->gender=='M'&& temp->gender=='F') {
			printf("3. if\n");
            
            temp->next= head->next;
            head->next=temp;
			 
        }/*
		if(head->gender=='M'&&temp->gender=='M' && strcmp(head,temp) > 0) {
			temp->next= head->next;
            head->next=temp;
		}*/
      //  if(temp->gender=='M'&&head->gender=='F') {
		//	printf("4. if");
           // return ;
        //}
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