#include <stdio.h>
#include <stdlib.h>
#include "spotibad.h"

struct song_node *table[27];

void add_song_node(struct song_node track){
  char first_letter = track.artist[0];
  int i = first_letter - 65; // Getting the index of the alphabet[] array


}

struct song_node * song_search(char song[], char artist[]) {
  int i = artist[0];
  i = i - 65; // Getting the index of the alphabet[] array




}

struct song_node * artist_search (char artist[]){
  int i = artist[0];
  i = i - 65; // Getting the index of the alphabet[] array
}
