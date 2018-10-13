/*
This code is not tested and incomplete
This code file was meant to be used for learning the essence of linked lists
Many functions are missing in this file just because they could be made very
easily, if the mechanics of the linked lists is clear to programmer.
*/

#include <stdio.h>
#include <stdlib.h>

// List
typedef struct node {
  int val;
  struct node * next;
} node_t;

/* Fuctions which can be done on a list */

// Append an value to the list
int list_append(node_t * list, int value) {
  node_t * last = list;
  while (last->next != NULL) {last = last->next;}

  last->next = malloc(sizeof(node_t));
  last->next->val = value;
  last->next->next = NULL;
}

// prints all the values in the list
void print_list(node_t *list) {
  node_t * current = list;
  while (current != NULL) {
    print("%d", current->val);               // printing the values
    current = current->next;
  }
}

// frees up all the memory allocated
int free_all(node_t * list) {

  if (list->next == NULL) {
    free(list);
    return 1;
  }
  node_t * current = list
  node_t * current_up = NULL;
  // this function frees up all the memory from the end
  while (current->next != NULL) {
    current_up = current
    current = current->next;
  }

  free(current);
  current_up->next = NULL;
  free_all(list);
}



int main() {
  node_t head = NULL;
  head = malloc(sizeof(node_t));

  if (head == NULL) {
    return 1;
  }

  head->val = 34;
  head->next = malloc(sizeof(node_t));
  head->next->val = 43;


  return 0;
}
