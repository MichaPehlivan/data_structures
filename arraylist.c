#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

//TODO
int *new_arraylist(int data);
void print_arraylist(int *list);
int *add_item_al(int *list, int data);
int *delete_item_al(int **list, int index);
int *delete_data_al(int **list, int data);
int index_of_al(int *list, int data);
int *edit_data_al(int *list, int index, int newdata);