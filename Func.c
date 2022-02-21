//
// Created by Tsimophey on 21.02.2022.
//
#include "Func.h"

void rand_str(char *str, int len) {
    int i;
    for (i= 0; i < len; ++i) {
        str[i]=rand()%26+97;
    }
    str[i]='\0';
}

struct series* generate(struct series* c, int size) {
    c=(struct series*)malloc(sizeof(struct series) * size);
    printf("Enter data in format:\nName\tEpisode number\tRelease date \tSeason number\n (0 to random)\n");
    getc(stdin);
    for (int i = 0; i < size; ++i) {
        //fgets(c[i].Name, 30 * sizeof(char), stdin);
        gets(c[i].Name);
        if(c[i].Name[0]=='0'){
            rand_str(c[i].Name,10);
            c[i].epNumber=rand()%30+1;
            rand_str(c[i].data.data,10);
            c[i].data.sNumber=rand()%10+1;
        }
        else{
            scanf_s("%d",&c[i].epNumber);
            getc(stdin);
            gets(c[i].data.data);
            //fgets(c[i].data.data, 30 * sizeof(char), stdin);
            scanf_s("%d",&c[i].data.sNumber);
            scanf_s("%c");
        }
        printf("next\n");
    }
    return c;
}

void print_str(struct series *c) {
    printf("Name:\t\t%s\n",c->Name);
    printf("Episode number:\t%d\n",c->epNumber);
    printf("Release date:\t%s\n",c->data.data);
    printf("Season number:\t%d\n",c->data.sNumber);
}

void print_br_str(struct series *c) {
    printf("Name:\t\t%s\n",c->Name);
    printf("Episode number:\t%d\n",c->epNumber);
}

void print_br_list(struct series *c, int num) {
    if(c==NULL){
        printf("\tERROR\n No data\n");
        return;
    }
    for (int i = 0; i < num; ++i) {
        print_br_str(&c[i]);
        printf("\n");
    }
}

void print_list(struct series *c, int num) {
    if(c==NULL){
        printf("\tERROR\n No data");
        return;
    }
    for (int i = 0; i < num; ++i) {
        print_str(&c[i]);
        printf("\n");
    }
}
int find_by_ep(struct series *c, int size, int parameter) {
    if(c==NULL){
        printf("\tERROR\n Incorrect input\n");
        return -1;
    }
    int counter=0;
    for (int i = 0; i < size; ++i) {
        if(c[i].epNumber<parameter){
            counter++;
        }
    }
    return counter;
}
struct series *find_by_fullname(struct series *c, int size, const char* parameter) {
    if((parameter==NULL)||(c==NULL)){
        printf("\tERROR\n Incorrect input\n");
        return NULL;
    }
    for (int i = 0; i < size; ++i) {
        int j=0,flag=0;
        while (c[i].Name[j]!='\0'){
            if((c[i].Name[j]!=parameter[j])){
                flag=1;
                break;
            }
            j++;
        }
        if(flag==0){
            return (c+i);
        }
    }
    return NULL;
}
void delete_element(struct series *list, int *size, struct series *element) {
    if((element==NULL)||(list==NULL)){
        printf("\tERROR\n Incorrect input\n");
        return;
    }
    if (*size==1){
        *size=0;
        return;
    }
    do{
        *element= *(element+1);
        ++element;
    }
    while (element!=&(list[*size-1]));
    *size=*size-1;
}