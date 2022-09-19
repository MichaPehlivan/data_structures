#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

struct tree_node {
    int data;
    struct tree_node *left_child;
    struct tree_node *right_child;
};

tree_node *new_tree(int value) {
    tree_node *new = create_node(value);
    return new;
}

tree_node *create_node(int value) {
    tree_node *new = (tree_node *)malloc(sizeof(tree_node));
    new->data = value;
    new->left_child = NULL;
    new->right_child = NULL;
    return new;
}

void print_tree(tree_node *root);
tree_node *add_node(tree_node *root, int value);
tree_node *delete_node(tree_node *root, int target);
void delete_binary_tree(tree_node *root);