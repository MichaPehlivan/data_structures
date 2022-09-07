#include "doubly_linked_list.h"

struct d_node {
    int data;
    d_node *prev;
    d_node *next;
};

//TODO
void print_list(d_node *head);
d_node *new_node(int data);
d_node *add_node(d_node *head, int data);
d_node *delete_node(d_node **head, int index);
d_node *delete_data(d_node **head, int data);
d_node *edit_data(d_node *head, int index, int new_data);
d_node *reverse(d_node **head);
void destroy_list(d_node *head);
