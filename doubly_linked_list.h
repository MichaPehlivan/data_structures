#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct d_node d_node;

void print_double_list(d_node *head);
d_node *new_d_node(int data);
d_node *add_d_node(d_node *head, int data);
int indexof_d(d_node *head, int data);
d_node *delete_d_node(d_node **head, int index);
d_node *delete_data_d(d_node **head, int data);
d_node *edit_data_d(d_node *head, int index, int new_data);
d_node *reverse_d(d_node **head);
void destroy_d_list(d_node *head);

#endif