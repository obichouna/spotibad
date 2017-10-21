#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

/** Print a song.
 * @param song: the song to print
 */
void print_song(struct song_node *song) {
    printf("%s - %s \n", song->artist, song->name);
}

/** Print the contents of a given list, formatted "Artist - Title" until it
 * reaches the end.
 * @param list: the list to print from
 */
void print_list(struct song_node *list) {
  while (list != NULL) {
    print_song(list);
    list = list->next;
  }
}

/** Make a song node.
 * @param name: the name of the song
 * @param artist: the artist of the song
 * @return: the created node
 */
struct song_node *make_song_node(char name[], char artist[]){
  struct song_node *new_song_node = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(new_song_node->name, name);
  strcpy(new_song_node->artist, artist);
  return new_song_node;
}

/** Insert a song at the front of the list.
 * @param front: the front of the list
 * @param new_front: the new front of the list
 * @return: the new list, with the added node in front
 */
struct song_node insert_front(struct song_node *front, struct song_node new_front) {
  new_front.next = front;
  return new_front;
}

/** Insert a song in the proper location in a list. Assumes it has been given
 * the correct list.
 * @param song: the name of the song
 * @param artist: the artist of the song
 * @param head: the beginning of the list
 * @return: the head, whether or not it was changed
 */
struct song_node * insert_order(char song[], char artist[], struct song_node* head){
  struct song_node *new_node = make_song_node(song, artist);
  struct song_node *current = head;
  struct song_node *prev = NULL;

  int val;
  while (1) {
    if (! current) {
      prev->next = new_node;
      return new_node;
    }

    val = strcmp(current->artist, new_node->artist);

    // between prev and current
    if (val < 0) {
      prev->next = new_node;
      new_node->next = current;
      return new_node;
    }

    // same artist
    if (! val) {
      if (strcmp(current->name, new_node->name) <= 0) {
        prev->next = new_node;
        new_node->next = current;
        return new_node;
      }
    }

    prev = current;
    current = current->next;
  }
}

/** Free a list.
 * @param front: the beginning of the list to free
 */
void free_list(struct song_node * front){
  struct song_node *temp;
  while(front) {
    temp = front->next;
    free(front);
    front = temp;
  }
}

/** Find node in a list based on artist and song name.
 * @param name: the name of the song
 * @param artist: the artist of the song
 * @param head: the beginning of the list
 * @return: pointer to the node if found, NULL otherwise
 */
struct song_node *locate_song(char *name, char *artist, struct song_node *head) {
  while (head) {
    if (! (strcmp(head->name, name) && strcmp(head->artist, artist)) ) {
      return head;
    }

    head = head->next;
  }

  return NULL;
}

/** Find node in a list based on artist.
 * @param artist: the artist of the song
 * @param head: the beginning of the list
 * @return: pointer to the first node if found, NULL otherwise
 */
struct song_node *locate_artist(char *artist, struct song_node *head) {
  while (head) {
    if (! strcmp(head->artist, artist)) {
      return head;
    }

    head = head->next;
  }

  return NULL;
}

/** Find a random song.
 * @param head: the beginning of the list
 * @return: a random node from the list
 */
struct song_node *rand_song(struct song_node *head) {
  unsigned int i = 0;
  struct song_node *tmp = head;
  while (tmp) {
    i++;
    tmp = tmp->next;
  }

  srand(time(NULL));
  i = rand() % i;

  while (i--) {
    head = head->next;
  }

  return head;
}

/** Remove a node from a list.
 * @param head: the beginning of the list
 * @param node: the node to remove
 * @return: 0 if song removed, 1 otherwise
 */
char remove_node(struct song_node *head, struct song_node *node) {
  struct song_node *prev = NULL;
  while (head) {
    if (! (strcmp(head->name, node->name) && strcmp(head->artist, node->artist)) ) {
      prev->next = head->next;
      free(head);
      return 0;
    }

    prev = head;
    head = head->next;
  }

  return 1;
}

