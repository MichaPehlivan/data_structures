#include <stdio.h>
#include "linked_list.h"
#include "doubly_linked_list.h"
#include "arraylist.h"

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
    printf("arraylist: ");
    print_arraylist(arraylist);

    return 0;
}