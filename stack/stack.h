#ifndef _STACK_H
#define _STACK_H

typedef char item;
typedef struct Stack * stack;

stack create_stack();
void destroy_stack(stack);

void stack_push(stack, item);
void stack_pop(stack);
item * stack_multi_pop(stack, int);
item stack_peek(stack);

int stack_is_empty(stack);
int stack_size(stack);
void stack_clear(stack);
void stack_print(stack);

#endif

