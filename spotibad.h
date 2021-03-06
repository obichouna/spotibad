#include "linked_list.h"

void add_song_node(struct song_node *);
struct song_node * song_search(char song[], char artist[]);
struct song_node * artist_search(char artist_name[]);
void print_letter(char directory);
void print_artists_songs(char artist[]);
void print_library();
void shuffle(int);
void delete_song(struct song_node *song);
void clear_all();
