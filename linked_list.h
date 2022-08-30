#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node node;

void print_list(node *head);
node *new_node(int data);
node *add_node(node *head, int data);
node *delete_node(node **head, int index);
node *edit_data(node *head, int index, int new_data);
node *reverse(node *head);
void destroy_list(node *head);

#endif