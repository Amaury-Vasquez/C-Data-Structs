#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdlib.h>
#include <string.h>

#define SIZE 50
#define TRUE 1
#define FALSE 0

char *copy_string(char *str) {
    char *new_string = (char *) malloc (sizeof(char) * strlen(str));
    strcpy(new_string, str);
    return new_string;
}

void clean_input(char string[]) {
    // using fgets to read from keyboard sets \n before \0
    string[strlen(string) - 1] = 0;
}

void copy_string_array(char dest[][30], char src[][30], int len) {
    int i;
    for(i = 0; i < len; i++) 
        strcpy(dest[i], src[i]);
}

void concat_string_array(char dest[][30], char string[], int len) {
    int i;
    for(i = 0; i < len; i++)
        strcat(dest[i], string);
}

int validate_string(char name[]) {
    int i;
    for(i = 0; i < strlen(name); i++) {
        if(!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' ')) {
            printf("%c", name[i]);
            printf("Entrada no valida, ingrese solo letras o espacios\n");
            return FALSE;
        }
    }
    return TRUE;
}

int get_index(char commands[][30], char src[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        if(strcmp(commands[i], src) == 0)
            return i;
    }
    return -1;
}
void print_spaces(int spaces) {
    while(spaces--)
        printf(" ");
}

void print_long_long(long long int id, int line_len) {
    long long int aux = id;
    int spaces, i;
    for(i = 1; aux / 10 > 0; i++, aux /= 10);
        spaces = (line_len - i) / 2;
    print_spaces(spaces);
    if(i % 2 != 0)
        spaces++;
    printf("%lld", id);
    print_spaces(spaces);
    printf("||");
}

void print_long_int(long int price, int line_len) {
    long int aux = price;
    int spaces, i;
    for(i = 1; aux / 10 > 0; i++, aux /= 10);
        spaces = (line_len - i) / 2;
    print_spaces(spaces);
    if(i % 2 != 0)
        spaces++;
    printf("$%ld", price);
    print_spaces(spaces);
    printf("||");
}

void print_unsigned(unsigned long long phone_number, int line_len) {
    unsigned long long aux = phone_number;
    int spaces, i;
    for(i = 1; aux / 10 > 0; i++, aux /= 10);
        spaces = (line_len - i) / 2;
    print_spaces(spaces);
    if(i % 2 != 0)
        spaces++;
    printf("%lld", phone_number);
    print_spaces(spaces);
    printf("||");
}

void print_string(char string[], int line_len) {
    int i, size = strlen(string);
    int spaces = (line_len - size) / 2;
    print_spaces(spaces);
    printf("%s", string);
    if(size % 2 != 0)
        spaces++;
    print_spaces(spaces);
    printf("||");
}

void print_title(char string[], int line_len) {
    int i;
    for(i = 0; i < line_len / 2; i++)
        printf(" ");
    printf("%s", string);
    for(i = 0; i < line_len / 2; i++)
        printf(" ");
    printf("\n");
}

int abs(int n) {
    if(n < 0)
        return n * -1;
    return n;
}
#endif