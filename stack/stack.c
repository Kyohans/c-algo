#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack {
  item * array;
  int maxsize;
  int top;
}; 

static stack create_stack_maxsize(int max_size) {
  if(max_size <= 0) abort();

  stack s = (stack) malloc(sizeof(struct Stack));
  if(s == NULL) abort();

  item * array;
  array = (item *) malloc(sizeof(item) * max_size);
  if(array == NULL) abort();

  s->array = array;
  s->maxsize = max_size;
  s->top = -1;

  return s;
}

stack create_stack(int size) {
  return create_stack_maxsize(size);
}

void destroy_stack(stack s) {
  if(s == NULL) return;

  free(s->array);
  free(s);
}

static void stack_doublesize(stack s) {
  if(s == NULL) abort();

  int new_size = 2 * s->maxsize;
  item * new_array = (item *) malloc(sizeof(item) * (new_size));
  if(new_array == NULL) abort();

  for(int i = 0; i <= s->top; i++) {
    new_array[i] = s->array[i];
  }

  free(s->array);
  s->array = new_array;
  s->maxsize = new_size;
}

void stack_push(stack s, item val) {
  if(s->top >= s->maxsize - 1) stack_doublesize(s);

  s->array[++s->top] = val;
}

int stack_is_empty(stack s) {
  return s->top == -1;
}

item stack_peek(stack s) {
  if(stack_is_empty(s)) return -1;

  return s->array[s->top];
}

void stack_pop(stack s) {
  if(stack_is_empty(s)) return;

  s->top--;
}

void stack_print(stack s) {
  if(stack_is_empty(s)) {
    printf("[]\n");
    return;
  }

  printf("[");
  for(int i = 0; i < s->top; i++) {
    printf("%c", s->array[i]);

    if(i < s->top - 1) printf(", ");
  }

  printf("]\n");
}

item * stack_multi_pop(stack s, int k) {
  if(k >= s->maxsize - 1) abort();

  item * poparray = (item *) malloc(sizeof(item) * (k));
  for(int i = 0; i < k; i++) {
    poparray[i] = stack_peek(s);
    stack_pop(s);
  }

  return poparray;
}

int valid_parentheses(char * s, int s_size) {
  stack st;
  st = create_stack(s_size);

  for(int i = 0; i < s_size; i++) {
    if(!stack_is_empty(st)) {
      if(stack_peek(st) == '(') {
        if(s[i] == ')') stack_pop(st);
        else stack_push(st, s[i]);
      }
    } else {
      stack_push(st, s[i]);
    }
    
    stack_print(st);
  }


  return stack_is_empty(st);
}

//int main(void) {
//  printf("%d\n", valid_parentheses("(()()())", 8));
//  //stack s;
//  //s = create_stack(6);
//
//  //for(int i = 0; i < 1000; i++) stack_push(s, i);
//
//  //int pop = stack_peek(s);
//  //stack_push(s, pop);
//  //stack_pop(s);
//
//  //int k = 10;
//  //item * poparray = stack_multi_pop(s, k);
//
//
//  //destroy_stack(s);
//  //free(poparray);
//}
