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
    struct bucket *prev;
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
                printf("{%d, %d}, ", current->key, current->value);
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
    new_bucket->prev = NULL;
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
        new_bucket->prev = last_in_line;
        return hashmap;
    }
}

int get_item(hashmap *hashmap, int key) {
    int n = hash_key(key, hashmap->size);
    bucket *data = *(hashmap->array + n);
    while(data->key != key) {
        data = data->next;
    }
    return data->value;
}

hashmap *delete_item_hashmap(hashmap *hashmap, int key) {
    int n = hash_key(key, hashmap->size);
    bucket *data = *(hashmap->array + n);
    if(data->next == NULL) {
        free(data);
        *(hashmap->array + n) = NULL;
        return hashmap;
    }
    else if(data->key == key) {
        data->next->prev = NULL;
        *(hashmap->array + n) = data->next;
        free(data);
        return hashmap;
    }
    else {
        while(data->key != key) {
            data = data->next;
        }
        data->prev->next = data->next;
        free(data);
        return hashmap;
    }
}

void delete_hashmap(hashmap *hashmap) {
    for(int i = 0; i < hashmap->size; i++) {
        if(*(hashmap->array + i) != NULL) {
            bucket *data = *(hashmap->array + i);
            if(data->next != NULL) {
                while(data->next != NULL) {
                    data = data->next;
                }
                while(data->prev != NULL) {
                    bucket *current = data;
                    data = data->prev;
                    free(current);
                }
            }
            else{
                free(data);
            }
        } 
    }
    free(hashmap);
}