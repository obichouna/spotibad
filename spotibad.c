#include <stdio.h>
#include <stdlib.h>
#include "spotibad.h"
#include "linked_list.h"

int main(){

  printf("  ___ ___  ___ _____ ___ ___   _   ___  \n");
  printf(" / __| _ \\/ _ \\_   _|_ _| _ ) /_\\ |   \\ \n");
  printf(" \\__ \\  _/ (_) || |  | || _ \\/ _ \\| |) |\n");
  printf(" |___/_|  \\___/ |_| |___|___/_/ \\_\\___/ \n");
  printf("                                        \n");
  printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");

 }


void add_song_node(struct song_node track){
  char first_letter = track.artist[0];
  first_letter = first_letter + 32;
  int i = first_letter - 97;
  
  
}

struct song_node * song_search(char[] song, char[] artist){
  int i = artist[0];
  



}

struct song_node * artist_search (char[] artist_name){
  int i = artist[0];

}
