#include <stdio.h>
#include <stdlib.h>

//Linked List

struct node{
  int something;
  int another;
  struct node *next; // This is a pointer to the next node
};

void print_list(struct node * list){
  int count = 0;
  while (list != NULL){
    printf("Node %d: %d, %d \n", count, list->something, list->another);
    list= list->next;
    count++;
  }
}


// This function could basically be used to insert front but I made it after
// I made the insert_front so thats not important
struct node *make_node(int val1, int val2, struct node * another_one){
  struct node * new_node = (struct node*)malloc(sizeof(struct node));
  new_node->something = val1;
  new_node->another = val2;
  new_node->next = another_one;
  return new_node;

}

struct node * insert_front(struct node * front, int val1, int val2){
  //Creates a new front node 
  
  struct node * new_front = (struct node*)malloc(sizeof(struct node));
  if(new_front == NULL){
        printf("Error\n");
        exit(0);
    }
  new_front->something = val1;
  new_front->another = val2;
  new_front->next = front;
  // printf("Success! \n");
  return new_front;
}

struct node * free_list(struct node * front){
  struct node *temp;
  while(front != NULL){
    temp = front->next;
    free(front);
    front = temp;
    printf("Memory freed! \n");
  }
  return front;
}
