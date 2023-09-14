#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100]){

    /*Vars*/
    int counter=1;
    struct employee * ptr;
    char fname[MAX_LENGTH];
    char lname[MAX_LENGTH];
    char * token;
    int cmp1;
    int cmp2;
    
    /*tokenize user inputed name and copy into fname and lname variables*/
    token=strtok(whichName," ");
    strcpy(fname,token);
    token=strtok(NULL," ");
    strcpy(lname,token);
    lname[strlen(lname)-1]='\0';
    
    /*cycle through LL comparing first and last names with the nodes
    until they both match. Then, return counter (index of node) back to main*/
    ptr=headLL;
    while (ptr!=NULL){
        cmp1=strcmp(fname,ptr->fname);
        cmp2=strcmp(lname,ptr->lname);
        if (cmp1==0 &&cmp2==0){
            return counter;
        }else{
            counter++;
            ptr=ptr->nextEmployee;
        }
    }
    
    return -1;

    
}