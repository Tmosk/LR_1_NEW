//
// Created by Tsimophey on 21.02.2022.
//

#ifndef LR_1_NEW_FUNC_H
#define LR_1_NEW_FUNC_H

#endif //LR_1_NEW_FUNC_H
#include "stdlib.h"
#include<string.h>
#include <stdio.h>

struct data{
    char data[100];
    int sNumber;
};
struct series{
    int epNumber;
    char Name[100];
    struct data data;
};
//Generate random string at the specified address
void rand_str(char* str,int len);
//Generate array of series; requires  pointer to first element
struct series* generate(struct series* c,int size);
//Print all series fields
void print_str(struct series* c);
//Print brief series fields
void print_br_str(struct series* c);
//Print all array of series
void print_list(struct series* c,int num);
//Print all brief array of series
void print_br_list(struct series *c, int num);
//Return the number of structures that episode parameter lower than input parameter
int find_by_ep(struct series* list,int size,int parameter);
//Returns the address of a structure with the same name as the given
struct series *find_by_fullname(struct series *list, int size, const char* parameter);
//Delete element with right shifting
void delete_element(struct series *list, int *size, struct series *element);