#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spotibad.h"


struct song_node *table[26];

void add_song_node(struct song_node *track) {
  char first_letter = track->artist[0];
  int i = first_letter >= 97 ? first_letter - 97 : first_letter - 65; // Getting the index of the alphabet[] array
  table[i] = insert_order(track->name, track->artist, table[i]);
  printf("Added song: %s - %s \n", track->artist, track->name);
}

struct song_node * song_search(char song[], char artist[]) {
  int i = artist[0]; // Getting the index of the alphabet[] array
  i = i >= 97 ? i - 97 : i - 65; // Getting the index of the alphabet[] array
  return locate_song(song, artist, table[i]);
}

struct song_node * artist_search (char artist[]){
  int i = artist[0]; // Getting the index of the alphabet[] array
  i = i >= 97 ? i - 97 : i - 65; // Getting the index of the alphabet[] array
  return locate_artist(artist, table[i]);
}

void print_letter(char directory){
  //If Directory is a lowercase letter, returns it as an uppercase
  int i = directory >= 97 ? directory - 97 : directory - 65; // Getting the index of the alphabet[] array
  print_list(table[i]);

}

void print_artists_songs(char artist[]){
  int i = artist[0]; // Getting the index of the alphabet[] array
  i = i >= 97 ? i - 97 : i - 65; // Getting the index of the alphabet[] array
  struct song_node* head = locate_artist(artist, table[i]);
  while(head && (! strcmp(head->artist, artist))) {
    print_song(head);
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

/* WILL NOT WORK IF THE PRNG HAS NOT BEEN SEEDED.
*/
void shuffle(int val) {
  int i;

  while (val--) {
    i = rand() % 26;

    if (table[i]) {
      print_song(rand_song(table[i]));
    } else {
      val++;
    }
  }
}

void delete_song(struct song_node *song){
  char first_letter = song->artist[0];
  int i = first_letter >= 97 ? first_letter - 97 : first_letter - 65; // Getting the index of the alphabet[] array
  table[i] = remove_node(table[i], song);
}

void clear_all(){
  int i;
  for(i = 0; i < 26; i++){
    free_list(table[i]);
  }
}

