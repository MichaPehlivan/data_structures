#include <stdio.h>
#include "linked_list.h"

int main() {
    node *head = new_node(0);
    
    for(int i = 1; i < 30; i++) {
        add_node(head, i);
    }

    print_list(head);

    delete_node(&head, 15);
    delete_data(&head, 7);
    print_list(head);
    
    return 0;
}