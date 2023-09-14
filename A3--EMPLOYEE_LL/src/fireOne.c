#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne){

    //vars
    struct employee * ptr;
    int num=countEmployees(*headLL);

    /*set ptr to headLL pointer*/
    ptr=*headLL;
    
    /*if user input is to fire last employee cycle through LL
    until the second last index. Then, make the last index NULL*/
    if (whichOne==num){
        while(ptr->nextEmployee->nextEmployee!=NULL){
            ptr=ptr->nextEmployee;
        }
        ptr->nextEmployee=NULL;
    /*If user input if head of LL, just set headLL to the next node*/
    }else if (whichOne==1){
        *headLL=ptr->nextEmployee;
    /*If the user selects and in between value cycle from second node
    until desired node.Once reached made next node equal to next next node to nullify */
    }else{
        for (int i=2;i<whichOne;i++){
            if (ptr->nextEmployee!=NULL){
                ptr=ptr->nextEmployee;
        
            }
        }
        ptr->nextEmployee=ptr->nextEmployee->nextEmployee;
    }

    

}