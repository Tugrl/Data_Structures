#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Creating the struct
struct Student
{
 char name[50];
 char gender;
 struct Student * next;
};
struct Student * insertNode (char *name,
char gender, struct Student * list)
{
 struct Student *s;
 //Allocate memory for node (malloc operation)
 s = malloc (sizeof (struct Student));
 if (s == NULL)
 {
 printf ("Memory allocation failed.");
 return list;
 }
 strcpy(s->name, name);
 s->gender = gender;
 s->next = list; //list is the startof the list
 list = s;

 return list;
}
struct Student * sortList(struct Student * head) {
    if(head==NULL || head->next==NULL) {
        printf("List is empty.");
        return head;
    }

    struct Student * previous;
    struct Student * current;
    struct Student * gender1;
        struct Student * gender2;
        
    previous=head;
    current= head->next;
    previous->next==NULL;
    
    while(current!=NULL) {
        struct Student * temp=current;
        current=current->next;
        gender1->next=gender2;
        if(gender1->gender=='F'&&gender2->gender=='M'){
            temp->next=head;
            head=temp;
        }
        else if(gender1->gender=='M'&& gender2->gender=='F'){
            struct Student * temp2=head;
            while(temp2->next!=NULL) {
                temp=temp2->next;
                temp->next=temp2->next;
                temp2->next=temp;
                
            }
                       
       }
    }
   
}
void printList (struct Student * list)
{
 while (list != NULL)
 {
 printf ("%s\t%c\n", list->name, list->gender);
 list = list->next;
 }
}
int main ()
{
 //Creating an Initial Node Variable
 struct Student * head=NULL;
 //Call to functions
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
 //call to sorting function
 head = sortList(head);
 printList(head);
 
}

