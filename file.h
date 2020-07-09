#ifndef FILE_H  
#define FILE_H 

#include <stdio.h>
#include <string.h>
#include "pacient.h"
#include "utilities.h"

void clean_string(char cad[]) {
    int i = strlen (cad);
    cad[i - 2] = '\0';
}

void read_file(FILE *file, pacient pacient_data[]) {
    // We will read just 50 pacients
    // In case you want to read more, read till EOF
    int i;
    long long int id;
    long int price;
    unsigned long long phone_number;
    char name[SIZE][100], sickness[SIZE][100];
    
    for(i = 0; i < SIZE && !feof(file); i++, fflush(stdin)) {
        fgets(name[i], 100, file);  
        fgets(sickness[i], 100, file);
        fscanf(file, "%lld %ld %llu\n", &id, &price, &phone_number);
        clean_string(name[i]);
        clean_string(sickness[i]);
        // At reading with fgets it is common that 
        // strings(char *) set the \n character before the \0
        pacient_data[i] = create_pacient(name[i], sickness[i], id, price, phone_number);
    }
    fclose(file);
}

#endif