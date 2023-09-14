#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL){

    /*vars*/
    struct employee * ptr;
    int counter=0;
    int numEmps=countEmployees(headLL);
    
    /*to make sure sorting system runs as many times as there are emps*/
    while (counter<numEmps){
        /*cycle through LL*/
        ptr=headLL;
        while (ptr->nextEmployee!=NULL){
            /*introduce and allocate for tempPtr var*/
            struct employee * tempPtr=malloc(sizeof(a3Emp));
            /*if current empId is creater than next copy info from current node into
            tempPtr, then copy info from next node into current node. Finally, copy info from 
            tempPtr into next node*/
            if (ptr->empId>ptr->nextEmployee->empId){
                
                strcpy(tempPtr->fname, ptr->fname);
                strcpy(tempPtr->lname, ptr->lname);
                tempPtr->empId=ptr->empId;
                tempPtr->numDependents=ptr->numDependents;
                tempPtr->dependents = malloc(sizeof(char *) );
                for (int i=0;i<ptr->numDependents;i++){
                    tempPtr->dependents[i] = malloc(sizeof(strlen(ptr->dependents[i]) + 1));
                    strcpy(tempPtr->dependents[i],ptr->dependents[i]);
                }
                tempPtr->nextEmployee=NULL;

                strcpy(ptr->fname, ptr->nextEmployee->fname);
                strcpy(ptr->lname, ptr->nextEmployee->lname);
                ptr->empId=ptr->nextEmployee->empId;
                ptr->numDependents=ptr->nextEmployee->numDependents;
                for (int i=0;i<ptr->nextEmployee->numDependents;i++){
                    strcpy(ptr->dependents[i],ptr->nextEmployee->dependents[i]);
                }

                strcpy(ptr->nextEmployee->fname, tempPtr->fname);
                strcpy(ptr->nextEmployee->lname, tempPtr->lname);
                ptr->nextEmployee->empId=tempPtr->empId;
                ptr->nextEmployee->numDependents=tempPtr->numDependents;
                for (int i=0;i<tempPtr->numDependents;i++){
                    strcpy(ptr->nextEmployee->dependents[i],tempPtr->dependents[i]);
                }


            }
            ptr=ptr->nextEmployee;
            /*free tempPtr*/
            for (int i = 0; i < tempPtr->numDependents; i++){
                free(tempPtr->dependents[i]);
            }
            free(tempPtr->dependents);
            free(tempPtr);
            
            
        }
        counter++;
    }
    

}