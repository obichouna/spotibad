struct song_node { char name[256]; char artist[256]; struct song_node *next; };
struct song_node *make_song_node(char name[], char artist[]);

struct song_node insert_front(struct song_node *front, struct song_node new_front);
struct song_node* insert_order(char song[], char artist[], struct song_node* head);

void print_list(struct song_node *list);

struct song_node *locate_song(char *name, char *artist, struct song_node *head);
struct song_node *locate_artist(char *artist, struct song_node *head);

struct song_node *rand_song(struct song_node *head);
char remove_node(struct song_node *head, struct song_node *node);
void free_list(struct song_node * front);

