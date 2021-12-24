#include "queue.c"

int main(void) {
  deque q;
  q = create_queue(64);

  queue_push(q, 1);
  queue_push(q, 2);
  queue_push(q, 3);
  queue_push(q, 4);

  printf("%d\n", queue_peekleft(q));
}
