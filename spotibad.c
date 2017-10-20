#include <stdio.h>
#include <stdlib.h>
#include "spotibad.h"


struct song_node *table[26];

void add_song_node(struct song_node track){
  char first_letter = track.artist[0];
  int i = first_letter - 65; // Getting the index of the alphabet[] array
  struct song_node* head = table[i];
  insert_order(track.name, track.artist, head);
  printf("Added song: %s - %s \n", track.artist, track.name);

}

struct song_node * song_search(char song[], char artist[]) {
  int i = artist[0];
  i = i - 65; // Getting the index of the alphabet[] array
  struct song_node* head = table[i];
  int tmp;
  int tmp2;
  while(head){
    tmp = strcmp(head->name, song);
    tmp2 = strcmp(head->artist, artist);
    if (tmp == 0 && tmp2 == 0){
      return head;
    }
    head = head->next;

  }
  printf("Song not found");
  return head;
}

struct song_node * artist_search (char artist[]){
  int i = artist[0];
  i = i - 65; // Getting the index of the alphabet[] array
}
