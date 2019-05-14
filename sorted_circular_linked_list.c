#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    char name[20 + 1];
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
        printf("\nInsert your name: ");
        scanf("%s", new_node->name);
        new_node->next = NULL;
    }

    return new_node;
}

bool insert(node** front, node** rear){

    int option = 0;
    bool is_front = false;
    char name[20 + 1];
    node* new_node = NULL;
    node* temp = NULL;
    node* reference = NULL;

    new_node = create_node();

    if(new_node == NULL)
        return false;

    if((*rear) == NULL){
        (*rear) = (*front) = new_node;
        (*rear)->next = (*front);
    }else{
        node* temp = (*front);
        node* aux = NULL;
        int result = 0;

        if(strcmp(new_node->name, (*front)->name) <= 0){
            aux = (*front);
            (*front) = new_node;
            new_node->next = aux;

            (*rear)->next = (*front);
        }
        else{
            do{
                result = strcmp(new_node->name, temp->next->name);

                if(result <= 0){
                    aux = temp->next;
                    temp->next = new_node;
                    new_node->next = aux;
                    break;

                }else if(temp->next == (*front)){
                    (*rear)->next = new_node;
                    (*rear) = new_node;
                    new_node->next = (*front);
                    break;
                }
                temp = temp->next;

            }while(temp != (*front));
        }
    }
    return true;
}

bool delete(node** front, node** rear){

    char name[20 + 1];
    node* temp = NULL;
    node* reference = NULL;

    if(is_empty((*front))){
        printf("\nThe list is already empty!\n");
        return false;
    }

    display_items((*front));
    printf("\nInsert the name you want to insert delete: ");
    scanf("%s",name);

    if(strcmp((*front)->name, name) == 0){
        reference = (*front)->next;
        free((*front));
        (*front) = reference;
    }else{
        temp = (*front);

        do{
            if(strcmp(temp->next->name, name) == 0){
                reference = temp;
                break;
            }
            temp = temp->next;
        }while(temp->next != (*front));

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

bool clear_list(node** front, node** rear){

    if(is_empty((*front))){
        printf("\nThe list is already empty!\n");
        return false;
    }

    node* temp = NULL;
    node* initial = (*front);

    do{
        temp = (*front)->next;
        free((*front));
        (*front) = temp;
    }while(temp !=  initial);
    *front = NULL;

    return is_empty((*front));
}

void display_items(node* front){
    node* temp = front;

    if(is_empty(front) == true){
        printf("\nThe list is empty!\n");
        return;
    }
        
    printf("\n FRONT -> ");
    do{
        printf(" %s ", temp->name);
        temp = temp->next;
    }while(temp != front);
    printf(" <- REAR \n");
}