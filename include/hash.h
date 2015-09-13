typedef struct hashnode_s {
  char *key;
  void *value;
  struct hashnode_s *next;
} hashnode_s;

typedef struct hashtable_s {
  int size;
  struct hashnode_s **nodes;
  } hashtable_s;

struct hashtable_s *create_table(int size);
int hash(struct hashtable_s *hashtable, char *key);
void insert(struct hashtable_s *hashtable, char *key, char *value);
char *get(struct hashtable_s *hashtable, char *key);
struct hashnode_s *new_pair(char *key, char *value);
