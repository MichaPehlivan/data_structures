#include <stdio.h>
#include "linked_list.h"

int main() {
    node *head = new_node(0);
    
    for(int i = 1; i < 30; i++) {
        add_node(head, i);
    }

    print_list(head);

    delete_node(&head, 0);
    print_list(head);
    delete_node(&head, 28);
    print_list(head); 
    delete_node(&head, 4);
    print_list(head); 
    delete_node(&head, 20);
    print_list(head); 
    delete_node(&head, 7);
    print_list(head); 
    delete_node(&head, 14);
    print_list(head); 
    
    return 0;
}