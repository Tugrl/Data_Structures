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
	struct Student* current=head;

    
    while (current!=NULL)
    {
        struct Student* cursor1=current;
        while (cursor1->next!= NULL)
        {
            if (strcmp(current->next->name,cursor1->next->next->name)>0)
            {
                struct Student* temp = cursor1->next->next;
				current ->next->next=cursor1->next->next->next;
				
				temp->next=current->next;
				//head->next=temp;
                current->next=temp;
               
            }
            cursor1 = cursor1->next;
        }
       // current = current->next;
		
		//head->next=current;
		
    head=current;
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