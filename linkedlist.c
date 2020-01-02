#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
  int data;
  struct listNode* next;
} Node;

Node * createnode(int data){
  Node * newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

List * emptylist(){
  List * list = malloc(sizeof(List));
  list->head = NULL;
  return list;
}

void display(List * list) {
  Node * current = list->head;
  if(list->head == NULL) 
    return;
  while(current->next != NULL){
    printf("%d,", current->data);
    current = current->next;
  }
  printf("%d\n", current->data); 
}

void add(int data, List * list){
  Node * current = NULL;
  if(list->head == NULL){
    list->head = createnode(data);
  }
  else {
    current = list->head; 
    while (current->next!=NULL){
      current = current->next;
    }
    current->next = createnode(data);
  }
}

void delete(int data, List * list){
  Node * current = list->head;            
  Node * previous = current;           
  while(current != NULL){           
    if(current->data == data){      
      previous->next = current->next;
      if(current == list->head)
        list->head = current->next;
      free(current);
      return;
    }                               
    previous = current;             
    current = current->next;        
  }                                 
}                                   

void reverse(List * list){
  Node * reversed = NULL;
  Node * current = list->head;
  Node * temp = NULL;
  while(current != NULL){
    temp = current;
    current = current->next;
    temp->next = reversed;
    reversed = temp;
  }
  list->head = reversed;
}

void destroy(List * list){
  Node * current = list->head;
  Node * next = current;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

int main() {

  node* list = NULL;   //empty list
//   list = addFront(5, list);
  list = add(6, list);
  list = add(5, list);   
//   list = addFront(1, list);
  list = add(4, list);
//   list = addFront(4, list);
//   list = addFront(3, list);
//   list = addFront(1, list);
  list = add(2, list);
  display(list);
//   isSorted(list);
//   freeList(list);
}