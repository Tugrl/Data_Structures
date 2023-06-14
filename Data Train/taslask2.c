#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char gender;
  char name[100];
  struct Node* next;
};

// İki kişi arasındaki sıralamayı belirler
int compare(struct Node* a, struct Node* b) {
  // Kadınlar önce gelirse, a önce gelir
  if (a->gender == 'F' && b->gender == 'M')
    return -1;
  // Erkekler önce gelirse, a önce gelir
  if (a->gender == 'M' && b->gender == 'F')
    return 1;
  // Aynı cinsiyetteki kişiler için, isimlerine göre sıralama yap
  if (a->gender == b->gender)
    return strcmp(a->name, b->name);
  // Diğer durumlarda, sıralama yapma
  return 0;
}

// Linked list'i sıralar
void sortList(struct Node** head_ref) {
  // Linked list boşsa, işlem yapma
  if (*head_ref == NULL || (*head_ref)->next == NULL)
    return;

  // Linked list'in ilk iki düğümünü al
  struct Node* prev = *head_ref;
  struct Node* cur = prev->next;

  // Linked listin ilk elemanını sıralı olarak işaretle
  prev->next = NULL;

  while (cur != NULL) {
    // Geçici düğümü oluştur ve cur'ü işaret eden düğümü al
    struct Node* temp = cur;
    cur = cur->next;

    // Linked list'in en başına ekle
    if (compare(temp, *head_ref) < 0) {
      temp->next = *head_ref;
      *head_ref = temp;
    }
    // Linked list'in ortasına ekle
    else {
      struct Node* p = *head_ref;
      while (p->next != NULL && compare(temp, p->next) > 0)
        p = p->next;
      temp->next = p->next;
      p->next = temp;
    }
  }
}

// Linked list'