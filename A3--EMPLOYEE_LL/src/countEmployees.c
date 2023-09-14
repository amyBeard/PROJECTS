#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL){

    //vars
    struct employee * ptr;
    int counter=0;
    ptr=headLL;

    /*cycle through LL and increase counter each time
    return counter to main*/
    while (ptr!=NULL){
        if (ptr->empId!=0){
            counter++;
        }
        ptr=ptr->nextEmployee;
        
    }
    return counter;

}