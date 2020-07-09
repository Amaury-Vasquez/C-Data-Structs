#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include "pacient.h"

typedef struct NODE {
    pacient pacient_data;
    struct NODE *next;
} node;

typedef struct LINKED_NODE {
    pacient pacient_data;
    struct LINKED_NODE *next;
    struct LINKED_NODE *prev;
} linked_node;

typedef struct TREE_NODE {
    pacient pacient_data;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
} tree_node;

node *create_node() {
    node *new_node = (node *) malloc (sizeof(node));
    if(new_node != NULL)
        return new_node;
    exit(-1);
}

linked_node *create_linked_node() {
    linked_node *new_node = (linked_node *) malloc (sizeof(node));
    new_node->next = new_node->prev = NULL;
    if(new_node != NULL)
        return new_node;
    exit(-1);
}

tree_node *create_tree_node() {
    tree_node *new_node = (tree_node *) malloc (sizeof(node));
    if(new_node != NULL)
        return new_node;
    exit(-1);
}

void print_node(node* pacient_data) {
    print_pacient(pacient_data->pacient_data);
}
#endif