#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

#define STARTING_SIZE 1

struct arraylist
{
    int *array;
    int size;
    int count;
};


arraylist *new_arraylist() {
    arraylist *new = (arraylist *)malloc(sizeof(arraylist));
    new->array = (int *)malloc(STARTING_SIZE * sizeof(int));
    new->size = STARTING_SIZE;
    new->count = 0;
    return new;
}

void print_arraylist(arraylist *list) {
    printf("[");

    int last_index = 0;
    for(int i = 0; i < (list->count - 1); i++) {
        printf("%d, ", list->array[i]);
        last_index = i;
    }  

    printf("%d]\n", list->array[last_index + 1]);
}

arraylist *add_item_al(arraylist *list, int data) {
    if(list->count == list->size) {
        list->size *= 2;
        list->array = realloc(list->array, list->size * sizeof(int));
    }

    list->array[list->count] = data;
    list->count++;
    return list;
}

//TODO
int indexof_al(arraylist *list, int data) {
    for(int i = 0; i < list->count; i++) {
        if(list->array[i] == data) {
            return i;
        }
    }
    return -1;
}

arraylist *delete_item_al(arraylist *list, int index) {
    int *ptr = list->array;
    for(int i = 0; i <= index; i++) {
        ptr++;
    }

    for(int i = index + 1; i < list->count; i++) {
        list->array[i - 1] = list->array[i];
    }
    list->count--;
    return list;
}

arraylist *delete_data_al(arraylist *list, int data) {
    int *ptr = list->array;
    int index = 0;
    while(*ptr != data && index < list->count) {
        ptr++;
        index++;
    }
    for(int i = index + 1; i < list->count; i++) {
        list->array[i-1] = list->array[i];
    }
    list->count--;
    return list;
}

//TODO
arraylist *edit_data_al(arraylist *list, int index, int new_data);
arraylist *reverse_al(arraylist *list);
void destroy_arraylist(arraylist *list);