#ifndef STACK_MENU_H
#define STACK_MENU_H

#include "list.h"
#include "utilities.h"
#include <string.h>
#include <stdio.h>



void stk_help(char commands[][30], int size) {
    // prints command info
    int i;
    for(i = 0; i < size; i++)
        printf("%s\t", commands[i]);
    printf("\n");
}

void stk_create_queue(stack *head, pacient pacient_data[], int array_size) {
    int i;
    for(i = 0; i < array_size; i++)
        insert_stack_element(head, pacient_data[i]);
    printf("queue created\n\n");
}

void stk_add_element(stack *head) {
    pacient new_element = get_pacient();
    insert_stack_element(head, new_element);
    printf("element added\n\n");
}

void stk_find_element(stack head) {
    printf("id: ");
    long long int id;
    scanf("%lld", &id);
    pacient aux = find_stack_element(head, id), b = empty_pacient();

    if(compare_pacients(aux, b) == TRUE)
        printf("Pacient %lld does not exist\n", id);
    else
        print_pacient(aux);
    printf("\n");
    getchar();
}

void stk_call_option(stack *head, int n, pacient pacient_data[], char commands[][30], int array_size) {
    long long int id;
    switch (n) {
    case 0:
        stk_help(commands, 7);
        break;

    case 1:
        stk_create_queue(head, pacient_data, array_size);
        break;

    case 2:
        stk_add_element(head);
        break;

    case 3:
        stk_find_element(*head);
        break;

    case 4:
        printf("id: ");
        scanf("%lld", &id);
        pacient aux = delete_stack_element(head, id);
        print_pacient(aux);
        printf("\n");
        getchar();
        break;
        
    case 5:
        print_stack(*head);
        printf("\n");
        break;
    }
}

void stk_command_info(int n) {
    switch (n) {
    case 0:
        printf("shows available commands\n");
        break;
    
    case 1:
        printf("create queue reading from file, if it is already created just adds file info\n");
        break;

    case 2:
        printf("add element to queue (keyboard input)\n");
        break;

    case 3:
        printf("find element according to id\n");
        break;
    
    case 4:
        printf("find and delete element according to id\n");
        break;

    case 5:
        printf("print current elements in queue\n");
        break;

    case 6:
        printf("exit queue menu\n");
        break;
    }
}

void stack_menu(pacient pacient_data[], int array_size) {
    char option[100], commands_help[7][30], commands[7][30] = {
        "--help", "--create-queue", "--add-element", "--find-element", "--delete-element",
        "--show", "--exit"
    };
    copy_string_array(commands_help, commands, 7);
    concat_string_array(commands_help, " --help", 7);
    stack head = NULL;
    int escape = FALSE, i;

    printf("type --help to see commands available\n");
    printf("type '--command' --help to see command info\n\n");
    while (escape != TRUE) {
        fgets(option, 50, stdin);
        clean_input(option);
        if(strcmp(option, "--exit") == 0)
            escape = TRUE;
        else {
            int index, size = (int)(sizeof(commands) / sizeof(commands[0]));
            index = get_index(commands, option, size);
            if(index >= 0)
                stk_call_option(&head, index, pacient_data, commands, array_size);
            else {
                size = (int)(sizeof(commands_help) / sizeof(commands_help[0]));
                index = get_index(commands_help, option, size);
                if(index >= 0)
                    stk_command_info(index);
                else 
                    printf("command '%s' not found\n", option);
            }
        }
    }
    free_stack(&head);
}
#endif