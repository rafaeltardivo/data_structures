#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char name[20 + 1];
    struct node* previous;
    struct node* next;
}node;

bool is_empty(node* front);
node* create_node();

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

            case 1:
                printf(is_empty(front) ? "\nThe list is empty!\n" : "\nThe list is not empty!\n");
                break;
        }

    }while(option != 0);
}

bool is_empty(node* front){
    return front == NULL;
}

node* create_node(){

    node* new_node = (node*) malloc(sizeof(node));

    if(new_node != NULL){
        printf("\nInsert your name: ");
        scanf("%s", new_node->name);
        new_node->previous = NULL;
        new_node->next = NULL;
    }

    return new_node;
}