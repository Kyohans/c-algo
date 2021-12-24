#ifndef _LIST_H
#define _LIST_H

typedef struct LinkedList * linked_list;
typedef int item_type;

linked_list new_list();
void destroy_list(linked_list);

void list_insert(linked_list, item_type);
int list_search(linked_list, item_type);
void list_delete(linked_list, item_type);

void list_print(linked_list);

#endif
