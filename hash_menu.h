#ifndef HASH_MENU_H
#define HASH_MENU_H

#include <stdio.h>
#include "list.h"
#include "pacient.h"
#include "utilities.h"
#include "hash.h"


void hash_help(char commands[][30], int len) {
    int i;
    for(i = 0; i < len; i++)
        printf("%s\t", commands[i]);
    printf("\n\n");
}

void hash_add_file_data(list map[], pacient pacient_data[], int array_size) {
    int i, key;
    for(i = 0; i < array_size; i++)
        insert_hash_element(&map[0], pacient_data[i]);
    printf("Data added successfully\n\n");
}

void hash_add_element(list map[]) {
    pacient aux;
    aux = get_pacient();
    insert_hash_element(&map[0], aux);
    printf("Element added succesfully\n");
}

void hash_find_element(list map[]) {
    long long int id;
    printf("id: ");
    scanf("%lld", &id);
    getchar();
    find_hash_element(map, id);
}

void hash_delete_element(list map[]) {
    long long int id;
    printf("id: ");
    scanf("%lld", &id);
    getchar();
    delete_hash_element(&map[0], id);
}

void hash_call_option(int option, list map[], pacient pacient_data[], int array_size, char commands[][30], int command_len) {
    switch(option) {
    case 0:
        hash_help(commands, command_len);
        break;
    case 1:
        hash_add_file_data(&map[0], pacient_data, array_size);
        break;
    case 2:
        hash_add_element(&map[0]);
        break;
    case 3:
        hash_find_element(map);
        break;
    case 4:
        hash_delete_element(&map[0]);
        break;
    case 5:
        print_map(map);
        break;
    }
}
void hash_command_info(int option) {
    switch(option) {
    case 0:
        printf("Shows available commands");
        break;
    case 1:
        printf("Add elements previously readed from file");
        break;
    case 2:
        printf("Add element (keyboard input)");
        break;
    case 3:
        printf("Finds element (id search)");
        break;
    case 4:
        printf("Delete element (id search)");
        break;
    case 5:
        printf("Shows current data in map");
        break;
    case 6:
        printf("Exit menu");
    }
    printf("\n\n");
}

void hash_menu(pacient pacient_data[], int array_size) {
    list map[TABLE_SIZE];
    insert_centinel(&map[0]);
    char option[100], commands_help[7][30], commands[7][30] = {
        "--help", "--add-file-elements", "--add-element", "--find-element", "--delete-element",
        "--show", "--exit"
    };
    copy_string_array(commands_help, commands, 7);
    concat_string_array(commands_help, " --help", 7);
    
    int exit = FALSE;
    printf("Type --help to see available commands\n");
    printf("Type 'command' --help to see command info\n\n");
    while(exit != TRUE) {
        fgets(option, 100, stdin);
        clean_input(option);
        if(strcmp(option, "--exit") == 0)
            exit = TRUE;
        else {
            int index = get_index(commands, option, 7);
            if(index >= 0)
                hash_call_option(index, &map[0], pacient_data, array_size, commands, 7);
            else {
                index = get_index(commands_help, option, 7);
                hash_command_info(index);
            }
        }
    }
    free_map(&map[0]);
}
#endif