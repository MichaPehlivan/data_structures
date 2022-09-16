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
    printf("%d]\n", tmp->data);
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

int indexof_d(d_node *head, int data) {
    d_node *tmp = head;
    int index = 0;
    while(tmp->data != data || tmp == NULL) {
        tmp = tmp->next;
        index++;
    }
    return index;
}

d_node *delete_d_node(d_node **head, int index) {
    if(index == 0) {
        d_node *tmp = *head;
        *head = tmp->next;
        (*head)->prev = NULL;
        free(tmp);
        return *head;
    }

    d_node *tmp = *head;
    for(int i = 0; i < index; i++) {
        tmp = tmp->next;
    }

    if(tmp->next == NULL) {
        tmp->prev->next = NULL;
        free(tmp);
        return *head;
    }

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
    return *head;
}

d_node *delete_data_d(d_node **head, int data) {
    if((*head)->data == data) {
        d_node *tmp = *head;
        *head = tmp->next;
        (*head)->prev = NULL;
        free(tmp);
        return *head;
    }

    d_node *tmp = *head;
    while(tmp->data != data || tmp == NULL) {
        tmp = tmp->next;
    }

    if(tmp->next == NULL) {
        tmp->prev->next = NULL;
        free(tmp);
        return *head;
    }

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
    return *head;
}

d_node *edit_data_d(d_node *head, int index, int new_data) {
    d_node *tmp = head;
    for(int i = 0; i < index; i++) {
        tmp = tmp->next;
    }
    tmp->data = new_data;
    return head;
}

d_node *reverse_d(d_node **head) {
    d_node *tmp = *head;
    while(tmp->next != NULL) {
        d_node *next = tmp->next;
        tmp->next = tmp->prev;
        tmp->prev = next;
        tmp = next;
    }
    tmp->next = tmp->prev;
    tmp->prev = NULL;
    *head = tmp;
    return *head;
}

void destroy_d_list(d_node *head) {
    d_node *current = head;
    while(current != NULL) {
        d_node *tmp = current;
        current = current->next;
        free(tmp);
    }
}
