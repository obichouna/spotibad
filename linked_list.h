struct song_node { char name[256]; char artist[256]; struct song_node *next; };

struct song_node *insert_front(struct song_node *, char[], char[]);
struct song_node *insert_order(char [], char[]);

void print_list(struct song_node *list);

struct song_node *locate_song(char *name, char *artist);
struct song_node *locate_artist(char *artist);

struct song_node *rand_song();
struct song_node *remove_node(struct song_node *node);
struct song_node * free_list(struct song_node * front);;

