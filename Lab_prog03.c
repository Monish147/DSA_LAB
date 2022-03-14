#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum Menu {ch_exit, ch_create, ch_push, ch_pop, ch_palindrome, ch_display, ch_end} menu_t;

typedef struct {
  size_t capacity;   // max capacity of stack
  int top;           // identify top element in the stack
  char* elem;         // actual storage of elements.
} stack_t;
//-----------------------------------------------------------------
menu_t menu_options() {
  menu_t choice = ch_end;
  do {
    printf("Enter your choice:\n");
    printf("\t%u to create stack\n", ch_create);
    printf("\t%u to push an element to stack\n", ch_push);
    printf("\t%u to pop an element from stack\n", ch_pop);
    printf("\t%u to check palindrome using stack\n", ch_palindrome);
    printf("\t%u to display stack elements\n", ch_display);
    printf("\t%u to exit\n", ch_exit);
    printf("\tchoice: ");
    scanf("%u", & choice);
  } while (choice >=ch_end);
  getchar();
  return choice;
}
//-----------------------------------------------------------------
 stack_t*  create(size_t size) {
  stack_t* stack = malloc(sizeof(stack_t));
  if (stack != NULL) {
    stack->capacity = size;
    stack->elem = calloc(size , sizeof(int));
    if (stack->elem != NULL) {
      stack->top = -1; // stack is empty
    }
    else {
      free(stack);
      stack = NULL;
    }
  }  
  return stack;
}
//-----------------------------------------------------------------
bool  isfull(stack_t* s){
  if (s->top == s->capacity-1) {
    return true;
  }
  else {
    return false;
  }
}
//-----------------------------------------------------------------
int  isempty(stack_t* s) {
  if (s->top == -1) {
    return true;
  }
  else {
    return false;
  }
}
//-----------------------------------------------------------------
int  push(stack_t* s, char elem) {
  if (isfull(s)){    // is stak full?
    return 0;
  }
  s->elem[++s->top]=elem;
  return 1;
}
//-----------------------------------------------------------------
int  pop(stack_t* s) {
  if (isempty(s)) { // is stack empty
      return 0;
  }
  return (s->elem[s->top--]);
}
//-----------------------------------------------------------------
void display(stack_t* s) {
  if(isempty(s)) {
    printf("No Elementsin stack\n");
    return;
  }
  printf("Elements in stack are: ");
  for(size_t i=0; i<=s->top; i++) {
    printf(" %d ", s->elem[i]);
  }
  printf("\n");
}
//-----------------------------------------------------------------
int palindrome_check(char* string) {
  stack_t* pal = NULL;
  size_t length, i=0;
  //length = strlen(string);
  while(string[i]!='\0'){
    i++;
    length++;
  }
  size_t mid = length/2;
  bool result;
  pal = create(mid);

  for(size_t i=0; i<mid; i++) {
    push(pal, string[i]);
  }
  
  if(length%2 != 0) {
    mid++;
  }
  while(pal->top>=0) {
    if(pop(pal)!=string[mid]) {
      free(pal);
      return 0;
    }
    else {
      mid++;
    }
  }
  free(pal);
  return 1;
}
//-----------------------------------------------------------------
void fn_exit(stack_t* s) {
  free(s->elem);
  free(s);
}
//-----------------------------------------------------------------
int main() {
    stack_t* stack = NULL;
    char* string;
    unsigned int value, size, choice, result;
    while(true) {
        choice = menu_options();
        switch(choice) {
        case ch_create:
          if(stack == NULL){
            printf("Enter the size of the stack to be created: ");
            scanf("%u", &size);
            stack = create(size);
            printf("Stack created of size %u\n", size);
            continue;
          }
          printf("Stack already created\n");
          
        case ch_push:
          if(stack == NULL) {
            printf("Stack not created\n");
            continue;
          }
          else if(isfull(stack)) {
            printf("Stack overflow\n");
            continue;
          }
          else{
            printf("\nEnter the element to be pushed to stack: ");
            scanf("%u", &value);
            push(stack, value);
            printf("Element %u has been pushed to the stack\n", value);
            break;
          }

        case ch_pop:
          if(stack == NULL) {
            printf("Stack not created\n");
            continue;
          }
          else if(isempty(stack)) {
            printf("Stack underflow\n");
            continue;
          }
          else {
            if(pop(stack)){
              printf ("Element has been popped from the stack\n");
              break;
            }
          }

        case ch_palindrome:
          printf("Enter the string: ");
          scanf("%s", string);
          result = palindrome_check(string);
          if(result == 1) {
            printf("The entered string is palindrome\n");
          }
          if(result == 0) {
            printf("The entered string is not palindrome\n");
          }
          break;

        case ch_display:
          if(stack == NULL) {
            printf("Stack not created\n");
            continue;
          }
          display(stack);
          break;
          
        case ch_exit:
        default:
          if(stack == NULL) {
            fn_exit(stack);
            exit(0);
            continue;
          }
          fn_exit(stack);
          exit(0);
          break;
        }
    }
    return 0;
}
