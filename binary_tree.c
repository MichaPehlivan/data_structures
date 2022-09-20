#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

struct tree_node {
    int data;
    struct tree_node *left_child;
    struct tree_node *right_child;
};

tree_node *create_node(int value) {
    tree_node *new = (tree_node *)malloc(sizeof(tree_node));
    new->data = value;
    new->left_child = NULL;
    new->right_child = NULL;
    return new;
}

void print_tabs(int n) {
    for(int i = 0; i < n; i++) {
        printf("\t");
    }
}

void print_tree_rec(tree_node *root, int space) {
    if (root == NULL) {
        return;
    }
    space += 10;
    print_tree_rec(root->right_child, space);
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    print_tree_rec(root->left_child, space);
}

void print_tree(tree_node *root) {
    return print_tree_rec(root, 0);
}

tree_node *add_tree_node(tree_node *root, int value) {
    if (root == NULL)
        return create_node(value);
 
    if (value <= root->data)
        root->left_child = add_tree_node(root->left_child, value);
    else if (value > root->data)
        root->right_child = add_tree_node(root->right_child, value);
 
    return root;
}

tree_node *delete_tree_node(tree_node *root, int target);
void delete_binary_tree(tree_node *root);