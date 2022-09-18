#include <stdio.h>
#include "linked_list.h"
#include "doubly_linked_list.h"
#include "arraylist.h"
#include "hashmap.h"

int main() {
    //singly linked list
    node *head = new_node(0);
    for(int i = 1; i < 30; i++) {
        add_node(head, i);
    }
    delete_node(&head, 15);
    delete_data(&head, 20);
    edit_data(head, 5, 69);
    reverse(&head);
    printf("singly linked list: ");
    print_list(head);
    destroy_list(head);

    //doubly linked list
    d_node *d_head = new_d_node(0);
    for(int i = 1; i < 30; i++) {
        add_d_node(d_head, i);
    }
    delete_d_node(&d_head, 15);
    delete_data_d(&d_head, 20);
    edit_data_d(d_head, 5, 69);
    reverse_d(&d_head);
    printf("doubly linked list: ");
    print_double_list(d_head);
    destroy_d_list(d_head);

    //arraylist
    arraylist *arraylist = new_arraylist();
    for(int i = 0; i < 30; i++) {
        add_item_al(arraylist, i);
    }
    delete_item_al(arraylist, 15);
    delete_data_al(arraylist, 20);
    edit_data_al(arraylist, 5, 69);
    reverse_al(arraylist);
    printf("arraylist: ");
    print_arraylist(arraylist);
    destroy_arraylist(arraylist);

    //hashmap
    hashmap *hashmap = new_hashmap();
    add_item_hashmap(hashmap, 69, 420); 
    add_item_hashmap(hashmap, 2, 3); 
    add_item_hashmap(hashmap, 5, 4); 
    add_item_hashmap(hashmap, 200, 323); 
    add_item_hashmap(hashmap, 555, 12); 
    add_item_hashmap(hashmap, 10, 15);
    delete_item_hashmap(hashmap, 69);
    delete_item_hashmap(hashmap, 200);
    printf("hashmap: ");
    print_hashmap(hashmap);
    delete_hashmap(hashmap);
    
    return 0;
}