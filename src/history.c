#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int idx = 1;

/* Initialize the linked list to keep the history. */
List* init_history() {
  List *history = (List*)malloc(sizeof(List*));
  history -> root = NULL;
  return history;				
}
				

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *curr;
  curr = list -> root;
  if (list -> root == NULL) {
    list -> root = (Item*)malloc(sizeof(Item));
    list -> root -> id = idx++;
    list -> root -> str = str;
    list -> root -> next = NULL;
  }
  else {
    while (curr -> next != NULL) {
      curr = curr -> next;
    }
    curr -> next = (Item*)malloc(sizeof(Item));
    curr -> next -> id = idx;
    curr -> next -> str = str;
    curr -> next -> next = NULL;
  }
}
				
/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {
  Item *curr = list -> root;
  while (curr != NULL) {
    if (curr -> id == id) {
      return curr -> str;
    }
    curr = curr -> next;
  }
}

/*Print the entire contents of the list. */      void print_history(List *list) {
  Item *curr = list -> root;
  while (curr != NULL) {
    printf("%d: %s", curr -> id, curr -> str);
    curr = curr -> next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *curr = list -> root;
  while (curr != NULL) {
    free(curr);
    curr = curr -> next;
  }
  free(list);
}
