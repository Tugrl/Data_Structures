#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char gender;
    char name[100];
    struct Node* next;
};

struct Node* insertNode(char* name, char gender, struct Node* list)
{
    struct Node* s;
    //Allocate memory for node (malloc operation)
    s = malloc(sizeof(struct Node));
    if (s == NULL)
    {
        printf("Memory allocation failed.");
        return list;
    }
    strcpy(s->name, name);
    s->gender = gender;
    s->next = list; //list is the start of the list
    list = s;

    return list;
}
void printList(struct Node* list)
{
    while (list != NULL)
    {
        printf("%s\t%c\n", list->name, list->gender);
        list = list->next;
    }
}



// İki kişi arasındaki sıralamayı belirler
int compare(struct Node* a, struct Node* b) {
    // Kadınlar önce gelirse, a önce gelir
    if (a->gender == 'F' && b->gender == 'M')
        return -1;
    // Erkekler önce gelirse, a önce gelir
    if (a->gender == 'M' && b->gender == 'F')
        return 1;
    // Aynı cinsiyetteki kişiler için, isimlerine göre sıralama yap
    if (a->gender == b->gender) {
        if (a->gender == 'M') {
            return strcmp(b->name, a->name);
        }
        return strcmp(a->name, b->name);
    }
    // Diğer durumlarda, sıralama yapma
    return 0;
}
// Linked list'i sıralar
struct Node* sortList(struct Node* head_ref) {
    // Linked list boşsa, işlem yapma
    if (head_ref == NULL || (head_ref)->next == NULL) {
        return;
    }

    // Linked list'in ilk iki düğümünü al
    struct Node* prev = head_ref;
    struct Node* cur = prev->next;

    // Linked listin ilk elemanını sıralı olarak işaretle
    prev->next = NULL;

    while (cur != NULL) {
        // Geçici düğümü oluştur ve cur'ü işaret eden düğümü al
        struct Node* temp = cur;
        cur = cur->next;


        // Linked list'in en başına ekle
        if (compare(temp, head_ref) < 0) {
            temp->next = head_ref;
            head_ref = temp;
            printf("1.if\n");
        }
        // Linked list'in ortasına ekle
        else {
            struct Node* p = head_ref;
            while (p->next != NULL && compare(temp, p->next) > 0) {
                p = p->next;
            }
            temp->next = p->next;
            p->next = temp;
          printf("2.if\n");
        }
       
    }
    return head_ref;
}

int main() {

    //Creating an Initial Node Variable
    struct Node* head = NULL;
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
    printf("Siralanmamis kisi listesi\n");
    printList(head);
    printf("--------\n");
    head= sortList(head);
    printf("--------\n");
    printf("--------\n");
    printList(head);
    //call to sorting function 
    //head = sortList(head);
    return 0;
}
// Linked lis