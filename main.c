#define TASK 2
#if TASK == 1
#include <stdio.h>
int main() {
    printf("Enter integer number\n");
    int test;
    scanf_s("%d",&test);
    test=test>>3;
    printf("The number is less than the original 8 times:\t%d",test);
    return 0;
}
#endif
#if TASK == 2


#include <stdio.h>
#include "Func.h"
#include "time.h"
int main() {
    setbuf(stdout, 0);
    srand(time(NULL));
    struct series *sList=NULL;
    int kol_vo=0;
    do {
        printf("Enter series number:\n");
        scanf_s("%d",&kol_vo);
    } while (kol_vo<=0);
    sList=generate(sList,kol_vo);
    for(;;){
        int ch;
        printf("Menu:\n1) Print all data\n2) Print brief data\n3) Find series\n4) Delete series\n5) New series list\n6) Exit\n");
        scanf_s("%d",&ch);
        switch (ch) {
            case 1:
                print_list(sList,kol_vo);
                break;
            case 2:
                print_br_list(sList,kol_vo);
                break;
            case 3:
                printf("Enter parameter:\t");
                int par;
                scanf_s("%d",&par);
                printf("Number of series:\t%d\n", find_by_ep(sList,kol_vo,par));
                break;
            case 4:
                printf("Enter name:\t");
                char name[30];
                getc(stdin);
                gets(name);
                do {
                    struct series* temp= find_by_fullname(sList,kol_vo,name);
                    if(temp==NULL) break;
                    delete_element(sList,&kol_vo,temp);
                } while (kol_vo>0);
                break;
            case 5:
                free(sList);
                do {
                    printf("Enter series number:\n");
                    scanf_s("%d",&kol_vo);
                } while (kol_vo<=0);
                sList=generate(sList,kol_vo);
                break;
            case 6:
                free(sList);
                return 0;
            default:
                printf("Incorrect input, please repeat\n");

        }
    }

}
#endif