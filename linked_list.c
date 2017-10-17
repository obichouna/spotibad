#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

//Linked List

struct song_node { char name[256]; char artist[256]; struct song_node *next; };

void print_list(struct song_node * list){
  int count = 0;
  while (list != NULL){
    printf("Node %d: %d, %d \n", count, list->something, list->another);
    list= list->next;
    count++;
  }
}


// This function could basically be used to insert front but I made it after
// I made the insert_front so thats not important
struct song_node *make_song_node(int val1, int val2, struct song_node * another_one){
  struct song_node * new_song_node = (struct song_node*)malloc(sizeof(struct song_node));
  new_song_node->something = val1;
  new_song_node->another = val2;
  new_song_node->next = another_one;
  return new_song_node;

}

struct song_node * insert_front(struct song_node * front, int val1, int val2){
  //Creates a new front song_node

  struct song_node * new_front = (struct song_node*)malloc(sizeof(struct song_node));
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

struct song_node * free_list(struct song_node * front){
  struct song_node *temp;
  while(front != NULL){
    temp = front->next;
    free(front);
    front = temp;
    printf("Memory freed! \n");
  }
  return front;
}
