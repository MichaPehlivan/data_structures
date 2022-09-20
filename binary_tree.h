#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct tree_node tree_node;

tree_node *create_node(int value);
void print_tree(tree_node *root);
tree_node *add_tree_node(tree_node *root, int value);
tree_node *delete_tree_node(tree_node *root, int target);
void delete_binary_tree(tree_node *root);

#endif