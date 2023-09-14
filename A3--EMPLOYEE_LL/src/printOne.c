#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne){

    //vars
    int counter=1;
    struct employee * ptr;

    /*cycle through LL until you reach desired emp*/
    ptr=headLL;
    while (counter<whichOne){

        ptr=ptr->nextEmployee;
        counter++;
    }

    /*display data for emp*/
    printf("\n\tEmployee Id: %d", ptr->empId);
    printf("\n\tFirst Name: %s", ptr->fname);
    printf("\n\tLast Name: %s", ptr->lname);
    int numDependents=sizeof(ptr->dependents)/sizeof(int);
    printf("\n\tDependents [%d]: ",numDependents);
    for (int i=0;i<numDependents;i++){
        if (i!=numDependents-1){
            printf("%s, ",ptr->dependents[i]);
        }else{
            printf("%s",ptr->dependents[i]);
        }
    }
    
}