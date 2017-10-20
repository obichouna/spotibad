#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  struct song_node* head = table[i];
  int tmp;
  while(head){
    tmp = strcmp(head->artist, artist);
    if (tmp == 0){
      return head;
    }
    head = head->next;

  }
  printf("Artist not found");
  return head;
}

void print_letter(char directory){
  if(directory >= 97){
    directory -= 32;  //If Directory is a lowercase letter, returns it as an uppercase
  }
  int i = directory - 65; // Getting the index of the alphabet[] array
  struct song_node* head = table[i];
  print_list(head);

}

void print_artists_songs(char artist[]){
  int i = artist[0];
  i = i - 65; // Getting the index of the alphabet[] array
  struct song_node* head = table[i];
  int tmp;
  int val = 1;
  while(head){
    tmp = strcmp(head->artist, artist);
    if (tmp == 0){
      val = 0; // This boolean will be used to stop the while early
      printf("%s - %s", head->artist, head->name);
      head = head->next;
    }else{
      if (val == 0){
        break; // Stops the while so that it doesn't go through the entire directory
      }
      head = head->next;
    }
  }
}

void print_library(){
  int i = 0;
  for(i; i < 26; i++){
    struct song_node * head = table[i];
    print_list(head);
  }

}

void shuffle(int val){


}

void delete_song(struct song_node *song){
  char first_letter = song->artist[0];
  int i = first_letter - 65; // Getting the index of the alphabet[] array
  struct song_node* head = table[i];
  if (remove_node(head, song)) {
    printf("Song not found.\n");
  } else {
    printf("Song removed. \n");
  }
}

void * clear_all(){
  int i = 0;
  for(i; i < 26; i++){
    struct song_node * head = table[i];
    free_list(head);
  }
}
