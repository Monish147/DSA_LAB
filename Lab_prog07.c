#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Menu {CH_EXIT, CH_CREATE, CH_DISPLAY, CH_INSERT_FRONT, CH_DELETE_FRONT, CH_INSERT_END, CH_DELETE_END} menu_t;

typedef struct listnode {
  char USN[10];
  char name[50];
  char programme[10];
  char sem[5];
  char phone_no[10];
  struct listnode* next;
} listnode_t;
//-----------------------------------------------------------------
menu_t menu() {
  menu_t choice = CH_DELETE_END;
  do {
    printf("Enter your choice:\n");
    printf("\t%u for Create SLL\n", CH_CREATE);
    printf("\t%u for Display\n", CH_DISPLAY);
    printf("\t%u for Insert at front\n", CH_INSERT_FRONT);
    printf("\t%u for Delete at front\n", CH_DELETE_FRONT);
    printf("\t%u for Insert at end\n", CH_INSERT_END);
    printf("\t%u for Delete at end\n", CH_DELETE_END);
    printf("\t%u for Exit.\n", CH_EXIT);
    printf("\tchoice: ");
    scanf("%u", & choice);
  } while (choice >CH_DELETE_END);
  getchar();
  return choice;
}
//-----------------------------------------------------------------
listnode_t* create(listnode_t* node) {
  if(node == NULL) {
    node = malloc(sizeof(listnode_t));
    printf("\n\tEnter USN of the student: ");scanf("%s", node->USN);
    printf("\n\tEnter the name of the student: ");scanf("%s", node->name);
    printf("\n\tEnter the programme of the student: ");scanf("%s", node->programme);
    printf("\n\tEnter the sem of the student studing at present: ");scanf("%s", node->sem);
    printf("\n\tEnter the contact number of the student: ");scanf("%s", node->phone_no);
    node->next = NULL;
  }
  return node;
}
//-----------------------------------------------------------------
void display(listnode_t* node) {
  listnode_t* temp = node;
  int num = 1;
  while(temp!=NULL) {
    printf("\n  student %d \n", num);
    printf("\tUSN: %s\n", temp->USN);
    printf("\tName: %s\n", temp->name);
    printf("\tProgramme: %s\n", temp->programme);
    printf("\tSem: %s\n", temp->sem);
    printf("\tPhone Number: %s\n", temp->phone_no);
    temp = temp->next;
    num++;
  }
}
//-----------------------------------------------------------------
listnode_t* insert_end(listnode_t* node) {
  listnode_t* temp = node;
  listnode_t* end = NULL;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  end = malloc(sizeof(listnode_t));
  printf("\n\tEnter USN of the student: ");scanf("%s", end->USN);
  printf("\n\tEnter the name of the student: ");scanf("%s", end->name);
  printf("\n\tEnter the programme of the student: ");scanf("%s", end->programme);
  printf("\n\tEnter the sem of the student studing at present: ");scanf("%s", end->sem);
  printf("\n\tEnter the contact number of the student: ");scanf("%s", end->phone_no);
  end->next = NULL;
  temp->next = end;
  return node;
}
//-----------------------------------------------------------------
listnode_t* insert_front(listnode_t* node) {
  listnode_t* temp = NULL;
  temp = malloc(sizeof(listnode_t));
  printf("\n\tEnter USN of the student: ");scanf("%s", temp->USN);
  printf("\n\tEnter the name of the student: ");scanf("%s", temp->name);
  printf("\n\tEnter the programme of the student: ");scanf("%s", temp->programme);
  printf("\n\tEnter the sem of the student studing at present: ");scanf("%s", temp->sem);
  printf("\n\tEnter the contact number of the student: ");scanf("%s", temp->phone_no);
  temp->next = node;
  node = temp;
  return node;
}
//-----------------------------------------------------------------
listnode_t* delete_front(listnode_t* node) {
  listnode_t* ptr;
  ptr = node;
  node = node->next;
  free(ptr);
  return node;
}
//-----------------------------------------------------------------
listnode_t* delete_end(listnode_t* node) {
  listnode_t* cur = node;
 listnode_t* del;
    
  while(cur->next->next != NULL) {
    cur = cur->next;
  }
  del = cur->next;
  cur->next = NULL;
  free(del);
  cur = node;
  return node;
}
//-----------------------------------------------------------------
void fn_exit(listnode_t* node) {
  free(node);
  exit(0);
}
//-----------------------------------------------------------------
int main(int argc, char* argv[]) {
  listnode_t* node = NULL;
  menu_t choice;

  while (1) {
    choice = menu();
      switch (choice) {
        case CH_CREATE:
          if(node != NULL) {
            printf("\n\tLinked list already created\n");
            continue;
          }
          node = create(node);
          break;

        case CH_DISPLAY:
          if(node != NULL) {
            display(node);
            continue;
          }
          printf("\t\tLinked list not created\n");
          break;

        case CH_INSERT_FRONT:
          if(node == NULL) {
            printf("\n\tLinked list not created\n");
            continue;
          }
          node  = insert_front(node);
          printf("\n\tNode inserted at front\n");
          break;

        case CH_INSERT_END:
          if(node == NULL) {
            printf("\n\tLinked list not created\n");
            continue;
          }
          node  = insert_end(node);
          printf("\n\tNode inserted at end\n");
          break;

        case CH_DELETE_FRONT:
          if(node == NULL){
            printf("\n\tLinked list not created\n");
            continue;
          }
          node = delete_front(node);
          printf("\n\tNode deleted at front\n");
          break;

        case CH_DELETE_END:
          if(node == NULL){
            printf("\n\tLinked list not created\n");
            continue;
          }
          node = delete_end(node);
          printf("\n\tNode deleted at end\n");
          break;

        case CH_EXIT:
        default:
          fn_exit(node);
          break;
    }
  }
}

