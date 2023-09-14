#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId){

    /*vars*/
    int counter=1;
    struct employee * ptr;

    /*cycle through LL until you find matching empId. Then return counter*/
    ptr=headLL;
    while (ptr!=NULL){
        if (ptr->empId==whichEmpId){
            return counter;
        }else{
            counter++;
            ptr=ptr->nextEmployee;
        }
    }

    return -1;
}