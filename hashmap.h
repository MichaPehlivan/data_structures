#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct hashmap hashmap;

hashmap *new_hashmap();
void print_hashmap(hashmap *hashmap);
hashmap *add_item_hashmap(hashmap *hashmap, int key, int value);
int get_item(hashmap *hashmap, int key);
hashmap *delete_item_hashmap(hashmap *hashmap, int key);
void delete_hashmap(hashmap *hashmap);

#endif