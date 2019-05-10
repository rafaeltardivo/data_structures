#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    char ra[13 + 1];
    struct node* next;
}node;

bool is_empty(node* front);
node* create_node();
bool insert(node** first, node** rear);
void display_items(node* front);
bool delete(node** front, node** rear);
bool clear_list(node** front, node** rear);

void main(){
    int option = 0;
    node* front = NULL;
    node* rear = NULL;

    do{
        printf(
            "\nSingly likend list MENU\n"
            "\n1 - is empty?"    
            "\n2 - insert"
            "\n3 - delete"
            "\n4 - list items"
            "\n5 - clear list"
            "\n0 - EXIT"
        );

        printf("\n\noption: ");
        scanf("%d", &option);

        switch(option){

            case 1:
                printf(is_empty(front) ?  "\nTrue!\n" : "\nFalse!\n");
                break;

            case 2:
                printf(insert(&front, &rear) ?  "\nInserted!\n" : "\nSomething went wrong!\n");
                break;

            case 3:
                printf(delete(&front, &rear) ?  "\nDeleted!\n" : "\nSomething went wrong!\n");
                break;

            case 4:
                display_items(front);
                break;
            
            case 5:
                printf(clear_list(&front, &rear) ?  "\nCleared!\n" : "\nSomething went wrong!\n");
                break;

            case 0:
                clear_list(&front, &rear);
                break;

            default:
                printf("\nInvalid option!");
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
        printf("\nInsert your RA: ");
        scanf("%s", new_node->ra);
        new_node->next = NULL;
    }

    return new_node;
}

void display_items(node* front){

    if(is_empty(front)){
        printf("\nThe list is empty!\n");
        return;
    }

    node* temp = front;

    printf("\nFront -> ");
    while(temp != NULL){
        printf(" %s ", temp->ra);
        temp = temp->next;
    }
    printf(" <- Rear\n");
}

bool insert(node** front, node** rear){

    int option = 0;
    bool is_front = false;
    char ra[13 + 1];
    node* new_node = NULL;
    node* temp = NULL;
    node* reference = NULL;

    new_node = create_node();

    if(new_node == NULL)
        return false;

    if((*rear) == NULL){
        (*rear) = (*front) = new_node;
    }else{
        printf(
            "\nDo you want to:"
            "\n1 - Insert first"
            "\n2 - Insert last"
            "\n3 - Insert after"
        );
        printf("\n\noption: ");
        scanf("%d", &option);

        switch(option){

            case 1:
                temp = (*front);
                (*front) = new_node;
                new_node->next = temp;
                break;

            case 2:
                (*rear)->next = new_node;
                (*rear) = new_node;
                break;

            case 3:
                display_items((*front));
                printf("\nInsert the ra you want to insert after: ");
                scanf("%s",ra);

                temp = (*front);

                while(temp != NULL){
                    if(strcmp(temp->ra, ra) == 0){
                        reference = temp;
                        break;
                    }
                    temp = temp->next;
                }

                if(reference != NULL){
                    temp = reference->next;
                    reference->next = new_node;
                    new_node->next = temp;
                }else{
                    printf("\nInvalid option!\n");
                    return false;
                }
                break;
        }
    }
    return true;
}

bool delete(node** front, node** rear){

    char ra[13 + 1];
    node* temp = NULL;
    node* reference = NULL;

    if(is_empty((*front))){
        printf("\nThe list is already empty!\n");
        return false;
    }

    display_items((*front));
    printf("\nInsert the ra you want to insert delete: ");
    scanf("%s",ra);

    if(strcmp((*front)->ra, ra) == 0){
        reference = (*front)->next;
        free((*front));
        (*front) = reference;
    }else{
        temp = (*front);

        while(temp->next != NULL){
            if(strcmp(temp->next->ra, ra) == 0){
                reference = temp;
                break;
            }
            temp = temp->next;
        }

        if(reference != NULL){

            if(reference->next == (*rear)){
                (*rear) = reference;    
            }

            temp = reference->next->next;
            free(reference->next);
            reference->next = temp;
        }else{
            printf("\nInvalid option!\n");
            return false;
        }
    }
    return true;

}

bool clear_list(node ** front, node** rear){

    node* temp = NULL;

    while((*front) != NULL){
        temp = (*front);
        free((*front));
        (*front) = temp->next;
    }
    free((*rear));

    return is_empty((*front));
}