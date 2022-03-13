#include <stdio.h> 
#include <limits.h> 
#include <stdlib.h> 
 
typedef enum menu {ch_exit, ch_create, ch_display, ch_insert, ch_delete} menu_t; 
 
menu_t menu() { 
  menu_t choice = ch_delete + 1; 
  do { 
    printf("Enter your choice:\n"); 
    printf("\t %u - Create Array\n", ch_create); 
    printf("\t %u - Display Array Elements\n", ch_display); 
    printf("\t %u - Insert Element at a Position\n", ch_insert); 
    printf("\t %u - Delete an Element at a Position\n", ch_delete); 
    printf("\t %u - for Exit\n", ch_exit); 
    printf("\t choice: "); 
    scanf("%u", & choice); 
  } while (choice >= ch_delete + 1); 
  getchar(); 
  return choice; 
} 
//------------------------------------------------------------------------
int* fn_create(size_t arrsize) { 
  int* arr = calloc(arrsize, sizeof(int)); 
  if(arr!=NULL){ 
    for (size_t i=0; i<arrsize; i++) { 
      arr[i] = INT_MIN; 
    } 
  } 
  return arr; 
} 
//------------------------------------------------------------------------ 
void fn_display(size_t arrsize, int arr[arrsize]) { 
  for(size_t i=0; i<arrsize; i++) { 
    if(arr[i]!=INT_MIN) { 
      printf("Element location: %lu, Element vlaue: %d\n", i, arr[i]); 
    } 
  } 
} 
//------------------------------------------------------------------------ 
void fn_insert(size_t arrsize, int arr[arrsize]) { 
  size_t location; 
  int val; 
  printf("Enter the location at which value is to be inserted(0-%lu): ", arrsize); 
  scanf("%zu", &location); 
  if(location>=arrsize) { 
    printf("Entered location exceeds the array size\n"); 
  } 
  else if(arr[location] != INT_MIN) { 
    printf("Element already exists at location %zu\n", location); 
  } 
  else { 
    printf("Enter the value to be inserted at location %zu: ", location); 
    scanf("%d", &val); 
    arr[location] = val; 
    printf("Vlaue %d has been inserted at the location %zu\n", val, location); 
  } 
} 
//------------------------------------------------------------------------ 
void fn_delete(size_t arrsize, int arr[arrsize]) { 
  size_t location; 
  printf("Enter the location at which value is to be deleted(0-%lu): ", arrsize); 
  scanf("%zu", &location); 
  if(location>=arrsize) { 
    printf("Entered location exceeds the array size\n"); 
  } 
  else if(arr[location] == INT_MIN) { 
    printf("No value exists at location %zu\n", location); 
  } 
  else { 
    arr[location] = INT_MIN; 
    printf("Vlaue has been deleted at location %zu\n", location); 
  } 
} 
//------------------------------------------------------------------------ 
void fn_exit(int* array){ 
  if(array != NULL) { 
    free(array); 
  } 
} 
//------------------------------------------------------------------------ 
int main() { 
  size_t arrsize = 0; 
  int* array = NULL;; 
  menu_t choice; 
   
  while(1) { 
    choice = menu(); 
    switch (choice) { 
      case ch_create: 
        if(array!=NULL) { 
          printf("Array arleady created\n"); 
          continue; 
        } 
        else{ 
          printf("Enter the size of the array: "); 
          scanf("%lu", &arrsize); 
          array = fn_create(arrsize); 
          printf("Array created of size %lu\n", arrsize);
        } 
        break; 
      case ch_display: 
        if(array==NULL) { 
          printf("Array not created\n"); 
          continue; 
        } 
        else{ 
          fn_display(arrsize, array); 
        } 
        break; 
      case ch_insert: 
        if(array==NULL) { 
          printf("Array not created\n"); 
          continue; 
        } 
        else{ 
          fn_insert(arrsize, array); 
          break; 
        } 
      case ch_delete: 
        if(array==NULL) { 
          printf("Array not created\n"); 
          continue; 
        } 
        else{ 
          fn_delete(arrsize, array); 
          break; 
        } 
      case ch_exit: 
      default: 
        fn_exit(array); 
        exit(0); 
    } 
  } 
}
//------------------------------------------------------------------------
