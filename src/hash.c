#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ULONG_MAX  4294967295UL

typedef struct hashnode_s {
  char *key;
  void *value;
  struct hashnode_s *next;
} hashnode_s;

typedef struct hashtable_s {
  int size;
  struct hashnode_s **nodes;
  } hashtable_s;

hashtable_s *create_table(int size){
  hashtable_s *hashtable = NULL;
  int i;

  if (size < 1) return NULL;

  // Space for table
  if(( hashtable = malloc(sizeof(hashtable_s))) == NULL){
    return NULL;
  }
  //space for nodes, buckets
  if((hashtable->nodes = malloc(sizeof(hashnode_s *) * size)) == NULL ){
    return NULL;
  }

  for(i = 0; i < size; i++){
    hashtable->nodes[i] = NULL;
  }

  hashtable->size = size;

  return hashtable;
}

int hash(hashtable_s *hashtable, char *key){
  int hashval = 1;
  int len = strlen(key);
  int i;
  for(i=0; i<len; i++){
    hashval += key[i] * (i+1);
  }
  if(hashval < 0){
    hashval = hashval * -1;
  }
  return hashval % hashtable->size;
}

hashnode_s *new_pair(char *key, char *value){
  hashnode_s *newpair;

  if((newpair = malloc(sizeof(hashnode_s))) == NULL){
    return NULL;
  }
  if((newpair->key = strdup(key)) == NULL){
    return NULL;
  }
  if((newpair->value = strdup(value)) == NULL){
    return NULL;
  }
  newpair->next = NULL;
  return newpair;
}

void insert(hashtable_s *hashtable, char *key, char *value){
  int bin = 0;
  hashnode_s *newpair = NULL;
  hashnode_s *next = NULL;
  hashnode_s *last = NULL;

  bin = hash(hashtable, key);
  next = hashtable->nodes[bin];

  while(next != NULL && next->key != NULL && strcmp( key, next->key) > 0){
    last = next;
    next = next->next;
  }

  if(next != NULL && next->key != NULL && strcmp(key, next->key) == 0){
    free(next->value);
    next->value = strdup(value);
  }
  else{
    newpair = new_pair(key, value);
    // Beginning of bucket
    if(next == hashtable->nodes[bin]){
      newpair->next = next;
      hashtable->nodes[bin] = newpair;
    }else if (next == NULL){
      last->next = newpair;
    }else{
      newpair->next = next;
      last->next = newpair;
    }
  }
}

char *get(hashtable_s *hashtable, char *key){
  int bin = 0;
  hashnode_s *pair;

  bin = hash(hashtable, key);
  pair = hashtable->nodes[bin];
  while(pair != NULL && pair->key != NULL && strcmp(key, pair->key) > 0){
    pair = pair->next;
  }
  if(pair == NULL || pair->key == NULL || strcmp(key, pair->key) != 0){
    return NULL;
  }else{
    return pair->value;
  }
}
