#include <stdio.h>
#include <stdlib.h>

struct _command {
    int (*callback)(int);
    struct _command *next;
};

int add5(int a){return a+5;}
int sub4(int a){return a-4;}
int mul3(int a){return a*3;}
int div2(int a){return a/2;}

/* Init a null struct pointer  */

struct _command * initCommandList()
{
    return NULL; 
}


void insertCommand(struct _command **list, int (*callback)(int)) {
    struct _command *p;
    /*Create a newnode    */
    struct _command *newnode = (struct _command *)malloc(sizeof(struct _command));
    newnode->callback = callback;
    newnode->next = NULL;
    
    p = *list;
    /*If the list is empty, list is newnode */
    if (*list == NULL){
        *list = newnode;
        return; 
    }

    /*Append the newnode to the tail of the list */
    
    while(p->next){
        p = p->next;
    }
    p->next = newnode;

         
}

int calculate(int a, struct _command *orderOfFunctions)
{
    int result = a; 
    
    while(orderOfFunctions){
        result = orderOfFunctions->callback(result);
        orderOfFunctions = orderOfFunctions->next;
    }

    return result;
}

int main()
{
    struct _command *orderOfFunctions = initCommandList();
    insertCommand(&orderOfFunctions, &add5);
    insertCommand(&orderOfFunctions, &sub4);
    insertCommand(&orderOfFunctions, &mul3);
    insertCommand(&orderOfFunctions, &div2);

    printf("%d\n",calculate(5, orderOfFunctions));

    return 0;
}