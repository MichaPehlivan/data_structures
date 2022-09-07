#include <stdio.h>
#include "linked_list.h"

int main() {
    //singly linked list
    node *head = new_node(0);
    for(int i = 1; i < 30; i++) {
        add_node(head, i);
    }
    delete_node(&head, 15);
    edit_data(head, 5, 69);
    reverse(&head);
    printf("singly linked list: ");
    print_list(head);
    
    return 0;
}