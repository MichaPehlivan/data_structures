#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct arraylist arraylist;

arraylist *new_arraylist();
void print_arraylist(arraylist *list);
arraylist *add_item_al(arraylist *list, int data);
int indexof_al(arraylist *list, int data);
arraylist *delete_item_al(arraylist *list, int index);
arraylist *delete_data_al(arraylist *list, int data);
arraylist *edit_data_al(arraylist *list, int index, int new_data);
arraylist *reverse_al(arraylist *list);
void destroy_arraylist(arraylist *list);


#endif