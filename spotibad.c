#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "spotibad.h"


struct song_node *table[26];

void add_song_node(struct song_node *track) {
  char first_letter = track->artist[0];
  if (first_letter >= 97){
    first_letter -= 32;
  }
  int i = first_letter - 65; // Getting the index of the alphabet[] array
  struct song_node* head = table[i];
  insert_order(track->name, track->artist, head);
  printf("Added song: %s - %s \n", track->artist, track->name);
}

struct song_node * song_search(char song[], char artist[]) {
  int i = artist[0] - 65; // Getting the index of the alphabet[] array
  return locate_song(song, artist, table[i]);
}

struct song_node * artist_search (char artist[]){
  int i = artist[0] - 65; // Getting the index of the alphabet[] array
  return locate_artist(artist, table[i]);
}

void print_letter(char directory){
  //If Directory is a lowercase letter, returns it as an uppercase
  int i = directory >= 97 ? directory - 97 : directory - 65; // Getting the index of the alphabet[] array
  print_list(table[i]);

}

void print_artists_songs(char artist[]){
  int i = artist[0] - 65; // Getting the index of the alphabet[] array
  struct song_node* head = locate_artist(artist, table[i]);
  while(head && (! strcmp(head->artist, artist))) {
    printf("%s - %s", head->artist, head->name);
    head = head->next;
  }
}

void print_library(){
  int i;
  for(i = 0; i < 26; i++){
    struct song_node * head = table[i];
    print_list(head);
  }
}

void shuffle(int val) {
  while (val--) {
    srand(time(NULL));
    int i = rand() % 26;
    if (table[i]) {
      val++;
    } else {
      print_song(rand_song(table[i]));
    }
  }
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

void clear_all(){
  int i;
  for(i = 0; i < 26; i++){
    free_list(table[i]);
  }
}

