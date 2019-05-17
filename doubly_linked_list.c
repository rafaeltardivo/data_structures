#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char name[20 + 1];
    struct node* previous;
    struct node* next;
}node;

void main(){
    int option = 0;
    node* front = NULL;
    node* rear = NULL;

    do{
        printf(
            "\nDoubly linked list menu\n"
            "\n1 - is empty?"
            "\n2 - insert"
            "\n3 - delete"
            "\n4 - list"
            "\n5 - clear"
            "\n0 - exit"    
        );
        
        switch(option){
            case 0:
              break;
        }

    }while(option != 0);
}