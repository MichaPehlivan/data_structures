#include <stdio.h>
#include "linked_list.h"

int main() {
    node *head = new_node(0);
    
    for(int i = 1; i < 30; i++) {
        add_node(head, i);
    }

    print_list(head);

    delete_node(&head, 15);
    edit_data(head, 5, 69);
    printf("deleted 15 and changed 5 to 69: ");
    print_list(head);

    reverse(&head);
    printf("reversed list: ");
    print_list(head);
    
    return 0;
}