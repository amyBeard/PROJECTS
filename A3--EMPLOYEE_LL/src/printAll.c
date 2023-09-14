#include "../include/headerA3.h"

void printAll (struct employee * headLL){

    //vars
    struct employee * ptr;
    int counter=1;
    ptr=headLL;

    /*cycle through LL and print all data for each node*/
    while (ptr!=NULL){

        printf("\n\nEmployee #%d",counter);
        printf("\n\tEmployee Id: %d", ptr->empId);
        printf("\n\tFirst Name: %s", ptr->fname);
        printf("\n\tLast Name: %s", ptr->lname);
        printf("\n\tDependents [%d]: ",ptr->numDependents);
        for (int i=0;i<ptr->numDependents;i++){
            if (i!=ptr->numDependents-1){
                printf("%s, ",ptr->dependents[i]);
            }else{
                printf("%s",ptr->dependents[i]);
            }
        }

        ptr=ptr->nextEmployee;
        counter++;
    }
    
}