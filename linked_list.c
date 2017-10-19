#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

void print_list(struct song_node *list) {
  while (list != NULL) {
    printf("%s - %s \n", list->artist, list->name);
    list = list->next;
  }
}


struct song_node *make_song_node(char[] track, char[] band){
  struct song_node * new_song_node = (struct song_node*)malloc(sizeof(struct song_node));
  new_song_node->name = track;
  new_song_node->band = artist;
  //new_song_node->next = the_next;
  return new_song_node;

}

struct song_node * insert_front(struct song_node * front, char[] name, char[] artist){
  //Creates a new front song_node
    // (struct song_node*)malloc(sizeof(struct song_node));
    //if(new_front == NULL){
    //     printf("Error\n");
    //    exit(0);
  //  }
  // new_front->something = val1;
    // new_front->another = val2;
    // new_front->next = front;
  // printf("Success! \n");
  struct song_node * new_front = make_song_node(name, artist, front);
  new_front->next = front;
  return new_front;
}

struct song_node * insert_order(char[] track, char[] band){
  struct song_node * new_node = make_song_node(track, band);
  int i = new_node->band[0];
  struct song_node * songs = &song_array[i];
  struct song_node * prev_node = NULL;
  while (songs){
    struct song_node * song_next = songs->next;
    bool tmp = strcmp(songs->artist, band);
    if (!tmp){
      tmp = strcmp(songs->song, track); // Case where artist is the same
      if (!tmp){
	printf("Song already exists!");
	return songs;
      }else{
	if(tmp < 0){
	  prev_node->next = new_node;
	  new_node->next = song_next;
	}else{
	  prev_node = songs;
	  songs = song_next;
	}
      }
    }else{
      if (tmp < 0){
	prev_node->next = new_node;
	new_node->next = song_next;
      }else{
	prev_node = songs;
	songs = song_next;
      }
    }
  }
  return new_node;
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
