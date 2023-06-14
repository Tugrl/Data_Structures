#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char name[100];
  char gender[10];
  struct node *next;
};

struct node *head = NULL;

void insert(char name[], char gender[]) {
  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  strcpy(new_node->name, name);
  strcpy(new_node->gender, gender);
  new_node->next = NULL;

  if (head == NULL || (strcmp(gender, "Female") == 0 && strcmp(head->gender, "Female") != 0)) {
    new_node->next = head;
    head = new_node;
  } else {
    struct node *current = head;
    while (current->next != NULL && ((strcmp(current->next->gender, "Female") == 0) || (strcmp(gender, "Female") != 0 && strcmp(current->next->gender, "Male") == 0))) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

void print_list() {
  struct node *current = head;
  while (current != NULL) {
    printf("%s (%s)\n", current->name, current->gender);
    current = current->next;
  }
}

int main() {
  insert("Alice", "Female");
  insert("Bob", "Male");
  insert("Eve", "Female");
  insert("Charlie", "Male");
  insert("Diana", "Female");
  insert("Frank", "Male");

  print_list();

  return 0;
}
