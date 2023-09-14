#include "../include/headerA3.h"

int main(){

    //Variables
    struct employee * headLL=NULL;
    char filename[25]="proFile.txt";
    int choice;
    int whichOne;
    int whichOne2;
    int flag=0;
    int whichEmpId;
    char whichName [100];
    int numEmp1;
    int numEmp2;
    int check2;
    char choice2[10];
    int cmp1;

    int lookOnIdReturn;
    int lookOnFullNameReturn;
    int countEmployeesReturn;

    /*run loadEmpData to gather info from file*/
    loadEmpData(&headLL,filename);
    
     do {
    /*print menu*/
    printf ("\n\nHere is the menu \n\n");
    printf ("1.    Function 1 – Add a new employee | recruitEmployee\n");
    printf ("2.    Function 2 – Print data of all employees | printAll\n");
    printf ("3.    Function 3 – Print employee data at position n in the LL | printOne\n");
    printf ("4.    Function 4 – View employee data based on empId | lookOnId\n");
    printf ("5.    Function 5 – View employee data based on full name | lookOnFullName\n");
    printf ("6.    Function 6 – Count number of employees | countEmployees\n");
    printf ("7.    Function 7 – Sort employee data in ascending order of empId | sortEmployeesId\n");
    printf ("8.    Function 8 – Fire the nth employee | fireOne\n");
    printf ("9.    Function 9 – Fire all employees | fireAll\n");
    printf ("10.   Function 10 – EXIT PROGRAM\n");

    /*get user input*/
    printf ("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        /*Cases*/
        /*call respective functions, and prompt user input 
        or display info as needed*/
        case 1:

            recruitEmployee(&headLL);
            break;
      
        case 2:
        
            printAll(headLL);
            break;
      
        case 3:

            check2=countEmployees(headLL);
            while (flag==0){            
                printf("\nEnter a position: ");
                scanf("%d",&whichOne);
                if (whichOne<0 || whichOne>check2){
                    printf("Invalid input, please enter a number between 1 and %d",check2);
                    flag=0;
                }else{
                    flag=1;
                }
            }
            
            printOne(headLL,whichOne);

            break;
      
        case 4:
                   
            printf("\nEnter an Employee ID: ");
            scanf("%d",&whichEmpId);

            lookOnIdReturn=lookOnId(headLL,whichEmpId);

            if (lookOnIdReturn!=-1){
                printOne(headLL,lookOnIdReturn);
            }else{
                printf("\nID not found");
            }
            
            break;

        case 5:
            
            getchar();
            printf("\nEnter full name of an employee: ");
            fgets(whichName,100,stdin);

            lookOnFullNameReturn=lookOnFullName(headLL,whichName);

            if (lookOnFullNameReturn!=-1){
                printOne(headLL,lookOnFullNameReturn);
            }else{
                printf("\nName not found");
            }
            
            break;
        
        case 6:
        
            countEmployeesReturn=countEmployees(headLL);
            printf("\nTotal number of employees: %d",countEmployeesReturn);
            
            break;
      
        case 7:
        
            sortEmployeesId(headLL);
            break;
      
        case 8:
            numEmp1=countEmployees(headLL);
            printf("\nThere are currently %d employees",numEmp1);
            printf("\nWhich employee do you want to fire-- Enter a number between 1 and %d: ",numEmp1);
            scanf("%d",&whichOne2);
            fireOne(&headLL,whichOne2);
            numEmp2=countEmployees(headLL);
            printf("\nThere are currently %d employees",numEmp2);
            break;

        case 9:
            printf("\nAre you sure you want to fire everyone (y/n):");
            scanf("%s",choice2);
            choice2[strlen(choice2)]='\0';
            cmp1=strcmp(choice2,"y");
            if (cmp1==0){
                fireAll(&headLL);
                printf("\nAll Fired. Linked List is now Empty.");
            }
            break;
        
        case 10:
            printf("\nEXITING...\n");
            fireAll(&headLL);
            exit(0);
            break;
      
      /*Defualt to exit*/
        default:
            printf ("Invalid Input");
        }
    /*conditional*/
    } while (choice>0 && choice<10);
    return 0;
}
