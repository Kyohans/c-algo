#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Queue {
  item_type * queue;
  int maxsize;
  int top;
  int first;
};

static deque create_queue_maxsize(int size) {
  if(size <= 0) abort();

  deque q = (deque) malloc(sizeof(struct Queue));
  if(q == NULL) abort();

  item_type * queue = (item_type *) malloc(sizeof(item_type) * size);
  if(queue == NULL) abort();

  q->queue = queue;
  q->maxsize = size;
  q->top = -1;
  q->first = 0;

  return q;
}

deque create_queue(int size) {
  return create_queue_maxsize(size);
}

static void queue_doublesize(deque dq) {
  if(dq == NULL) abort();

  int new_size = dq->maxsize * 2;
  item_type * new_queue = (item_type *) malloc(sizeof(item_type) * new_size);
  for(int i = dq->first; i < dq->top; i++) new_queue[i] = dq->queue[i];

  dq->queue = new_queue;
  dq->maxsize = new_size;
  dq->first = 0;
}

int queue_is_empty(deque dq) {
  if(dq == NULL || dq->top == -1) return 0;

  return 1;
}

void queue_push(deque dq, int val) {
  if(dq->top >= dq->maxsize - 1) queue_doublesize(dq);

  dq->queue[++dq->top] = val;
}

item_type queue_peekleft(deque dq) {
  if(queue_is_empty(dq)) abort();

  return dq->queue[dq->first];
}

item_type queue_peekright(deque dq) {
  if(queue_is_empty(dq)) abort();

  return dq->queue[dq->top];
}

void queue_popleft(deque dq) {
  if(queue_is_empty(dq)) abort();

  dq->first++;
}

