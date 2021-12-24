#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "stack.c"

int main(void) {
  stack s;
  s = create_stack(64);

  stack_push(s, 'a');
  stack_print(s);
}
