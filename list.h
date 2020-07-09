#ifndef LIST_H
#define LIST_H

#include "node.h"
#include "pacient.h"
#include "utilities.h"

typedef node* list;
typedef linked_node* stack;

int list_is_empty(list head) {
    if(head == NULL)
        return TRUE;
    return FALSE;
}

void insert_list_element(list *head, pacient pacient_data) {
    list new_element = create_node();
    new_element->pacient_data = pacient_data;
    new_element->next = NULL;

    if (list_is_empty(*head) == TRUE)
        *head = new_element;
    else {
        list p, q;
        for(p = *head, q = (*head)->next; q != NULL; p = q, q = p->next);
        p->next = new_element;
    }
}

void free_list(list *head) {
    list p = *head, q;
    while(p->next != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    free(p);
}

pacient find_list_element(list head, long long int id) {
    list p;
    pacient backup = create_pacient("", "", 0, 0, 0);
    for(p = head; p != NULL; p = p->next) {
        if(p->pacient_data.id == id) {
            backup = p->pacient_data;
            return backup;
        }
    }
    return backup;
}

pacient delete_list_element(list *head, long long int id) {
    list p = *head, q;
    pacient backup = create_pacient("", "", 0, 0, 0);
    if(p->pacient_data.id == id) {
        *head = p->next;
        backup = p->pacient_data;
    }
    else {
        for(q = p->next; q != NULL; p = q, q = p->next) {
            if(q->pacient_data.id == id) {
                backup = q->pacient_data;
                p->next = q->next;
                return backup;
            }
        }
    }
    return backup;
}
int empty_stack(stack head) {
    if(head == NULL)
        return TRUE;
    return FALSE;
}

void insert_stack_element(stack *head, pacient pacient_data) {
    stack new_element = create_linked_node();
    new_element->pacient_data = pacient_data;

    if(*head == NULL)
        *head = new_element;
    else {
        int key = pacient_data.id;
        stack p = *head, q;

        while(p->next != NULL && p->pacient_data.id < key)
            p = p->next; 

        if(key < p->pacient_data.id) {
            if(p->prev != NULL)
                p->prev->next = new_element;
            new_element->prev = p->prev;
            new_element->next = p;
            p->prev = new_element;
            if(*head == p)
                *head = new_element;
        }
        else {
            p->next = new_element;
            new_element->prev = p;
        }
    }
}

void free_stack(stack *head) {
    stack p = *head, q;
    
    if(empty_stack(p) == FALSE) {
        while(p->next != NULL) {
            q = p->next;
            free(p);
            p = q;
        }
        free(p);
    }
}

pacient find_stack_element(stack head, long long int id) {
    pacient aux = empty_pacient();
    if(empty_stack(head) == TRUE)
        printf("La cola no contiene elementos");
    else {
        stack p = head;
        while(p->next != NULL && id > p->pacient_data.id)
            p = p->next;
        if(p->pacient_data.id == id)
            aux = p->pacient_data;
    }
    return aux;
}

pacient delete_stack_element(stack *head, long long int id) {
    pacient aux = empty_pacient();
    if(empty_stack(*head) == TRUE)
        printf("La cola no contiene elementos...\n");
    else {
        stack p = *head;
        while(p->next != NULL  && id > p->pacient_data.id)
            p = p->next;
        if(p->pacient_data.id == id) {
            aux = p->pacient_data;
            if(p == *head) {
                if(p->next != NULL) {
                    p->next->prev = NULL;
                    *head = p->next;
                }
                else 
                    *head = NULL;
                free(p);
            }
            else {
                if(p->next == NULL)
                    p->prev->next = NULL;
                else {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                }
                
                free(p);
            }
            return aux;
        }
        printf("No existe el paciente\n");
    }
    return aux;
}

void print_list(list head) {
    list p;
    for(p = head; p != NULL; p = p->next)
        print_node(p);
}

void print_stack(stack head) {
    stack p;
    for(p = head; p != NULL; p = p->next)
        print_pacient(p->pacient_data);
}
#endif