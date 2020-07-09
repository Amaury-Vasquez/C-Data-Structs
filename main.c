#include <stdio.h>
#include <stdlib.h>

#include "hash_menu.h"
#include "file.h"
#include "stack_menu.h"

int main() {
    FILE *file = fopen("claves.txt", "r+");
    pacient pacient_data[100];
    read_file(file, &pacient_data[0]);
    hash_menu(pacient_data, 50);
    stack_menu(pacient_data, 50);
    return 0;
}