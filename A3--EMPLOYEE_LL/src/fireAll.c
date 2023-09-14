#include "../include/headerA3.h"

void fireAll (a3Emp ** headLL){

    /*vars*/
    struct employee * ptr; 
    
    /*while the head of LL isn't null make ptr equal to 
    the head and then set head to next node. Then free ptr*/
    while(*headLL!=NULL){
        ptr=*headLL;
        *headLL=ptr->nextEmployee;
        for (int i = 0; i < ptr->numDependents; i++){

            free(ptr->dependents[i]);
        }
        free(ptr->dependents);
        free(ptr);

    }
}