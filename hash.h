#ifndef HASH_H
#define HASH_H

#include "pacient.h"
#include "list.h"
#include <stdlib.h>

#define TABLE_SIZE 100

int set_key(long long int id) {
    return id % TABLE_SIZE;
}

void insert_centinel(list map[]) {
    pacient aux = empty_pacient();
    int i;
    for(i = 0; i < TABLE_SIZE; i++) {
        map[i] = NULL;
        insert_list_element(&map[i], aux);
    }
}

void insert_hash_element(list map[], pacient pacient_data) {
    int key = set_key(pacient_data.id);
    insert_list_element(&map[key], pacient_data);
}

void delete_hash_element(list map[], long long int id) {
    int key = set_key(id);
    pacient backup = delete_list_element(&map[key], id), empty = empty_pacient();
    if(compare_pacients(backup, empty) == TRUE)
        printf("Element not found\n\n");
    else {
        print_pacient(backup);
        printf("Element deleted\n\n");
    }
}

void find_hash_element(list map[], long long int id) {
    int key = set_key(id);
    list aux = map[key];
    pacient backup, empty;
    backup = empty = empty_pacient();
    if (aux->next != NULL) 
        backup = find_list_element(aux->next, id);
    if(compare_pacients(backup, empty) == TRUE)
        printf("Element not found\n\n");
    else {
        print_pacient(backup);
        printf("\n");
    }
}

void print_map(list map[]) {
    int i, empty = TRUE;
    char key_number[10];
    for(i = 0; i < TABLE_SIZE; i++) {
        if(map[i]->next != NULL) {
            sprintf(key_number, "key #%d", i);
            print_title(key_number, 150);
            print_list(map[i]->next);
            empty = FALSE;
        }
    }
    if(empty == TRUE)
        printf("map is empty\n\n");
}

void free_map(list map[]) {
    int i;
    for(i = 0; i < TABLE_SIZE; i++)
        free_list(&map[i]);
}
#endif