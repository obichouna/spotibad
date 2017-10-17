struct song_node { char name[256]; char artist[256]; struct song_node *next; };

struct song_node *insert_front(char *name, char *artist);
struct song_node *insert_order(char *name, char *artist);

void print_list(struct song_node *list);

struct song_node *locate_song(char *name, char *artist);
struct song_node *locate_artist(char *artist);

struct song_node *rand_song();
struct song_node *remove_node(struct song_node *node);
void *free_list();

