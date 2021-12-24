#include <stdio.h>
#include <stdlib.h>
#include "linkedlist/linkedlist.h"

struct LinkedList {
  item_type val;
  linked_list next;
};

linked_list new_list(item_type val) {
  linked_list list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
  if(list == NULL) abort();

  list->val = val;
  list->next = NULL;

  return list;
}

void destroy_list(linked_list list) {
  if(list == NULL) return;

  free(list);
}

void list_insert(linked_list tail, item_type val) {
  if(tail == NULL) return;


  tail->next = new_list(val);
  tail = tail->next;
}

int list_search(linked_list head, item_type val) {
  linked_list curr = head;

  while(curr) {
    if(curr->val == val) return 1;

    curr = curr->next;
  }

  return 0;
}

void list_delete(linked_list head, item_type val) {
  linked_list curr = head;

  while(curr && curr->next) {
    if(curr->next->val == val) {
      curr->next = curr->next->next;
    }

    curr = curr->next;
  }
}

void list_print(linked_list head) {
  linked_list curr = head;

  while(curr) {
    printf("%d", curr->val);

    if(curr->next) printf(", ");
    
    curr = curr->next;
  }
}

int main(void) {
  linked_list head = new_list(1);
  linked_list tail = head;

  list_print(head);
}
