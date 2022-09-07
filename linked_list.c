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
    printf("%d]\n", tmp->data);    
}

node *new_node(int data) {
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

node *add_node(node *head, int data) {
    node *last = head;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = new_node(data);
    return head;
}

node *delete_node(node **head, int index) {
    if(index == 0) {
        node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return *head;
    }

    node *prev = *head;
    for(int i = 1; i < index; i++){
        prev = prev->next;
    }

    node *tmp = prev->next;
    prev->next = prev->next->next;
    free(tmp);
    return *head;
}

node *delete_data(node **head, int data) {
    if((*head)->data == data) {
        node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return *head;
    }

    node *tmp = *head;
    node *prev = *head;
    while(tmp->data != data){
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = tmp->next;
    free(tmp);
    return *head;
}

node *edit_data(node *head, int index, int new_data) {
    node *current = head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    current->data = new_data;
    return head;
}

node *reverse(node **head) {
    node *prev = NULL;
    node *current = *head;
    node *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return *head;
}

void destroy_list(node *head) {
    node *current = head;
    while (current != NULL)
    {
        node *tmp = current;
        current = current->next;
        free(tmp);
    }
}