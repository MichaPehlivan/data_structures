#include<stdio.h>
#include<stdlib.h>
#include "doubly_linked_list.h"

struct d_node {
    int data;
    d_node *prev;
    d_node *next;
};

void print_double_list(d_node *head) {
    printf("[");
    
    d_node *tmp = head;
    while(tmp->next != NULL) {
        printf("%d, ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d]", tmp->data);
}

d_node *new_d_node(int data) {
    d_node *new = (d_node *)malloc(sizeof(d_node));
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

d_node *add_d_node(d_node *head, int data) {
    d_node *last = head;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = new_d_node(data);
    last->next->prev = last;
    return head;
}

//TODO
d_node *delete_d_node(d_node **head, int index);
d_node *delete_data_d(d_node **head, int data);
d_node *edit_data_d(d_node *head, int index, int new_data);
d_node *reverse_d(d_node **head);
void destroy_d_list(d_node *head);
