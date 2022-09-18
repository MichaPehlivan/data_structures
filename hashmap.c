#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

#define DEFAULT_SIZE 16

struct hashmap {
    struct bucket **array;
    int size;
};

typedef struct bucket {
    int key;
    int value;
    struct bucket *next;
} bucket;

int hash_key(int key, int modulo) {
    return key % modulo;
}

hashmap *new_hashmap() {
    hashmap *new = (hashmap *)malloc(sizeof(hashmap));
    new->size = DEFAULT_SIZE;
    new->array = (bucket **)calloc(DEFAULT_SIZE, sizeof(bucket *));
    return new;
}

void print_hashmap(hashmap *hashmap) {
    printf("[");
    bucket **first = hashmap->array;
    for(int i = 0; i < hashmap->size; i++) {
        bucket *current = *(first + i);
        if(current != NULL) {
            printf("{%d, %d}, ", current->key, current->value);
            while(current->next != NULL) {
                current = current->next;
                printf("{%d, %d}", current->key, current->value);
            }
        }
    }
    printf("]\n");
}

hashmap *add_item_hashmap(hashmap *hashmap, int key, int value) {
    int n = hash_key(key, hashmap->size);
    bucket *new_bucket = (bucket *)malloc(sizeof(bucket));
    new_bucket->key = key;
    new_bucket->value = value;
    new_bucket->next = NULL;
    if(*(hashmap->array + n) == NULL) {
        *(hashmap->array + n) = new_bucket;
        return hashmap;
    }
    else {
        bucket *last_in_line = *(hashmap->array + n);
        while((*(hashmap->array + n))->next != NULL) {
            last_in_line = last_in_line->next;
        }
        last_in_line->next = new_bucket;
        return hashmap;
    }
}

int get_item(hashmap *hashmap, int key);
hashmap *delete_item_hashmap(hashmap *hashmap, int key);
void delete_hashmap(hashmap *hashmap);