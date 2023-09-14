#include "../include/headerA3.h"

void recruitEmployee (struct employee ** headLL){

    //vars
    struct employee * ptr;
    struct employee * ptr2;
    struct employee * tempPtr=malloc(sizeof(a3Emp));
    char tempFname[MAX_LENGTH],tempLname[MAX_LENGTH];
    char tempDependents[MAX_LENGTH][MAX_LENGTH];
    int tempId=0,tempNumD=0;
    int flag=0;
    int counter=1;
    char choice[10];
    int cmp1,cmp2;
    ptr=*headLL;
    ptr2=*headLL;
    int empIds [MAX_LENGTH];
    int counter2=0;

    /*cycle through LL and append all empIds to a list*/
    while (ptr2!=NULL){
        int id;
        id=ptr2->empId;
        empIds[counter2]=id;
        ptr2=ptr2->nextEmployee;
        counter2++;
    }
    
    strcpy(tempFname, "");
    strcpy(tempLname, "");

    /*get user input for new emps first and last name then copy 
    into repsective vars*/
    printf("\nEnter first name of employee: ");
    scanf("%s",tempFname);
    printf("\nEnter last name of employee: ");
    scanf("%s",tempLname);

    strcpy(tempPtr->fname, tempFname);
    strcpy(tempPtr->lname, tempLname);

    /*allocate space into tempPtr->dependents*/
    tempPtr->dependents = malloc(sizeof(char *) );

    /*flag acts as a truth statement
    Loop runs until n for no more dependents*/
    while (flag==0){
        /*get user input for dependent name*/
        printf("\nEnter name of dependents #%d: ",counter);
        scanf("%s",tempDependents[counter-1]);
        tempPtr->dependents[counter-1] = malloc(sizeof(strlen(tempDependents[counter-1]) + 1));
        strcpy(tempPtr->dependents[counter-1], tempDependents[counter-1]);
        /*secodndary flag loop to get input for if they wish to add more dependents*/
        int flag2=0;
        while (flag2==0){
            printf("Do you have any more dependents (y/n): ");
            scanf("%s",choice);
            choice[strlen(choice)]='\0';
            cmp1=strcmp(choice,"y");
            cmp2=strcmp(choice,"n");

            if (cmp2==0){
                flag2=1;
                flag=1;
            }else if (cmp1==0){
                flag2=1;
                counter++;
                tempPtr->dependents=realloc(tempPtr->dependents,sizeof(char*)*counter);
            }else{
                printf("\nInvalid Input, please enter y for yes or n for no\n");
            }
        }
    }

    /*calculates tempId using ASCII values and strlen of lname*/
    for (int j=0;j<strlen(tempFname);j++){
        tempId=tempId+tempFname[j];
    }
    tempId=tempId+strlen(tempLname);

    /*checks if empId already exists and changed it if it does*/
    for (int x=0;x<counter2;x++){
        if (tempId==empIds[x]){
            tempId++;
        }
            
    }
    
    /*adding all values into tempPtr*/
    tempPtr->empId=tempId;

    tempNumD=counter;
    tempPtr->numDependents = tempNumD;
    tempPtr->nextEmployee=NULL;

    /*cycle through LL until the last node, which is then replaced by tempPtr*/
    ptr=*headLL;
    while (ptr->nextEmployee!=NULL){
        ptr=ptr->nextEmployee;
    }
    ptr->nextEmployee=tempPtr;


}