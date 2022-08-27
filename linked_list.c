#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct node {
    int data;
    struct node *next;
};

void print_list(node *head) {
    printf("[");

    node *tmp = head;
    while(tmp->next != NULL) {
        printf("%d, ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d]", tmp->data);    
}

node *new_node(int data) {
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

node *add_node(node *head, int data) {
    node *new = new_node(data);
    head->next = new;
    return new;
}

//TODO
node *delete_node(node *head, int index);

node *edit_data(node *head, int index, int new_data);

node *reverse(node *head);

void destroy_list(node *head);