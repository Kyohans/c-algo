#ifndef _QUEUE_H
#define _QUEUE_H

typedef int item_type;
typedef struct Queue * deque;

deque create_queue(int);
void destroy_queue(deque);

void queue_push(deque, item_type);
void queue_popleft(deque);
void queue_popright(deque);

item_type queue_peekleft(deque);
item_type queue_peekright(deque);

int queue_is_empty(deque);
int queue_size(deque);

#endif
