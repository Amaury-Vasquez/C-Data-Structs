#ifndef TREE_H
#define TREE_H

#include "node.h"
#include "utilities.h"
#include "pacient.h"

typedef tree_node * tree;

tree create_tree(pacient new_element) {
    tree aux = create_tree_node();
    aux->left = NULL;
    aux->right = NULL;
    aux->pacient_data = new_element;
    return aux;
}

void left_ins(tree head, pacient new_element) {
    if(head == NULL)
        printf("Memory error, empty insert\n");
    else if(head->left != NULL) 
        printf("Element not defined as NULL value\n");
    else {
        tree q = create_tree(new_element);
        head->left = q;
    }
}

void right_ins(tree head, pacient new_element) {
    if(head == NULL)
        printf("Memory error, empty insert\n");
    else if(head->right != NULL) 
        printf("Element not defined as NULL value\n");
    else {
        tree q = create_tree(new_element);
        head->right = q;
    }
}

void ins_tree_el(tree *head, pacient new_element) {
    if(*head == NULL)
        *head = create_tree(new_element);
    else {
        tree p, q = *head;
        while(q != NULL) {
            p = q;
            if(new_element.id < p->pacient_data.id)
                q = p->left;
            else
                q = p->right;
        }
        if(new_element.id < p->pacient_data.id)
            left_ins(p, new_element);
        else
            right_ins(p, new_element);
    }
}

void preorder(tree head) {
    if(head != NULL) {
        print_pacient(head->pacient_data);
        preorder(head->left);
        preorder(head->right);
    }
}

void order(tree head) {
    if(head != NULL) {
        order(head->left);
        print_pacient(head->pacient_data);
        order(head->right);
    }
}

void postorder(tree head) {
    if(head != NULL) {
        postorder(head->left);
        postorder(head->right);
        print_pacient(head->pacient_data);
    }
}

pacient tree_search(tree head, long long int id) {
    if(head == NULL)
        return empty_pacient();
    else if(head->pacient_data.id == id)
        return head->pacient_data;
    else if(id < head->pacient_data.id)
        tree_search(head->left, id);
    else 
        tree_search(head->right, id);
}

void print_tree(tree head, int option) {
    switch (option) {
    case -1:
        preorder(head);
        break;
    
    case 0:
        order(head);
        break;
    
    case 1:
        postorder(head);
        break;
    }
}

void free_tree(tree *head) {
    if(*head != NULL) {
        tree p = *head;
        free_tree(&p->left);
        free_tree(&p->right);
        free(p);
    }
}
#endif