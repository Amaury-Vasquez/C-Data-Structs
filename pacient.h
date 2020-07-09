#ifndef PACIENT_H
#define PACIENT_H

#include <stdio.h>
#include <string.h>
#include "utilities.h"

typedef struct PACIENT {
    char* name;
    char* sickness;
    long long int id;
    long int price;
    unsigned long long phone_number;
} pacient;

pacient create_pacient(char *name, char* sickness, long long int id, long int price, unsigned long long phone_number) {
    pacient new_pacient;
    new_pacient.name = copy_string(name);
    new_pacient.sickness = copy_string(sickness);
    new_pacient.id = id;
    new_pacient.price = price;
    new_pacient.phone_number = phone_number;
    return new_pacient;
}

pacient get_pacient() {
    fflush(stdin);
    char name[50], sickness[50];
    long long int id;
    long int price;
    unsigned long long phone_number;

    do {
        printf("Insert name: ");
        fgets(name, 50, stdin);
        clean_input(&name[0]);
    } while (validate_string(name) != TRUE);
    do {
        printf("Insert sickness: ");
        fgets(sickness, 50, stdin);
        clean_input(&sickness[0]);
    } while (validate_string(sickness) != TRUE);

    printf("Insert id: ");
    scanf("%lld", &id);
    printf("Insert price: ");
    scanf("%ld", &price);
    printf("Insert phone number: ");
    scanf("%llu", &phone_number);
    getchar();
    pacient new_element = create_pacient(name, sickness, id, price, phone_number);
    return new_element;
}
int compare_pacients(pacient a, pacient b) {
    if(a.id == b.id)
        return TRUE;
    return FALSE;
}

pacient empty_pacient() {
    return create_pacient("", "", 0, 0, 0);
}

int is_empty(pacient data) {
    pacient aux = empty_pacient();
    if(compare_pacients(data, aux) == TRUE)
        return TRUE;
    return FALSE;
}

void print_pacient(pacient data) {
    printf("||");
    print_string(data.name, 40);
    print_string(data.sickness, 30);
    print_long_long(data.id, 20);
    print_long_int(data.price, 16);
    print_unsigned(data.phone_number, 20);
    printf("\n");
}

void merge(pacient arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    pacient L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i].id <= R[j].id) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void merge_sort(pacient arr[], int l, int r) { 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        merge_sort(arr, l, m); 
        merge_sort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

pacient *copy_array(pacient array[], int array_size) {
    pacient *new_array = (pacient *) malloc (sizeof(pacient) * array_size);
    int i;
    for(i = 0; i < array_size; i++)
        *(new_array + i) = array[i];
    return new_array;
}

#endif