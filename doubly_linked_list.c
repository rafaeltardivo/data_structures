#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* previous;
}node;

void display_items(node* front, node* rear, bool reverse);
bool is_empty(node* front);
bool insert_node(node** front, node** rear);
bool delete_node(node** front, node** rear);
bool clear_items(node** front, node** rear);
node* create_node();
node* locate_node(node* front, int value);

int main(void){

    int op = 0;
    node* front = NULL;
    node* rear = NULL;

    do{
        printf(
            "\n\nDoubly likend list MENU\n"
            "\n1 - Is empty?"    
            "\n2 - Insert"
            "\n3 - Delete"
            "\n4 - List items in order"
            "\n5 - List items in reverse order"
            "\n6 - Clear items"
            "\n0 - EXIT\n"
        );

        printf("\nChoose your option: ");
        scanf("%d", &op);

        switch(op){

            case 1:
                printf(is_empty(front) ? "\nThe list is empty!" : "\nThe list is not empty!");
                break;

            case 2:
                printf(insert_node(&front, &rear) ? "\nValue inserted!" : "\nSomething went wrong!");
                break;

            case 3:
                printf(delete_node(&front, &rear) ? "\nValue deleted!" : "\nSomething went wrong!");
                break;

            case 4:
                display_items(front, rear, false);
                break;

            case 5:
                display_items(front, rear, true);
                break;

            case 6:
                printf(clear_items(&front, &rear) ? "\nCleared!" : "\nSomething went wrong!");
                break;
            
            default:
                printf("\nInvalid option!");
                break;
        }

    }while(op != 0);
}

void display_items(node* front, node* rear, bool reverse){

    node* temp = NULL;

    if(reverse == false){
        temp = front;

        printf("\nFRONT ->");
        while(temp != NULL){
            printf(" [ %d ] ", temp->data);
            temp = temp->next;
        }
        printf("<- REAR\n");
    }else{
        temp = rear;

        printf("\nREAR ->");
        while(temp != NULL){
            printf(" [ %d ] ", temp->data);
            temp = temp->previous;
        }
        printf("<- FRONT\n");
    }
}

bool is_empty(node* front){
    return front == NULL;
}

node* create_node(){

    node* new_node = (node*)malloc(sizeof(node));

    if(new_node == NULL){
        printf("\nCouldn't allocate memory!");
        exit(1);
    }

    printf("\nInsert a value: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    new_node->previous = NULL;

    return new_node;
}

node* locate_node(node* front, int value){

    node* temp = front;

    while(temp != NULL){
        if(temp->data == value){
            break;
        }else{
            temp = temp->next;
        } 
    }
    return temp;
}

bool insert_node(node** front, node** rear){

    int elem = 0, before_after = 0;
    node* new_node = create_node();
    node* temp = NULL;
    node* aux = NULL;

    if((*front) == NULL){
        (*front) = (*rear) = new_node;
    }else{
        printf("\nChoose an element: ");
        display_items((*front), (*rear), false);
        scanf("%d", &elem);

        temp = locate_node((*front), elem);
        
        if(temp != NULL){
            printf("\nInsert 0 to insert before or 1 to insert after: ");
            scanf("%d", &before_after);

            switch(before_after){
                case 0:
                    aux = temp->previous;
                    temp->previous = new_node;
                    new_node->next = temp;
                    new_node->previous = aux;

                    if(temp == (*front))
                        (*front) = new_node;

                    break;

                case 1:
                    aux = temp->next;
                    temp->next = new_node;
                    new_node->previous = temp;
                    new_node->next = aux;

                    if(temp == (*rear))
                        (*rear) = new_node;

                    break;

                default:
                    printf("\nInvalid option!");
                    return false;        
            }
        }else{
            printf("\nInvalid option!");
            return false; 
        }
    }
    return true;
}

bool delete_node(node** front, node** rear){
    if(is_empty((*front))){
        return false;
    }

    int op = 0;
    node* temp = NULL;
    node* aux = NULL;

    printf("\nInsert the node you want to delete: ");
    scanf("%d", &op);

    temp = locate_node((*front), op);

    if(temp != NULL){
        if(temp == (*front) && temp == (*rear)){
            // Only one node
            free(temp);
            (*front) = (*rear) = NULL;
        }else if(temp == (*front)){
            (*front) = temp->next;
            if((*front) != NULL) (*front)->previous = NULL;
            free(temp);
        }else if (temp == (*rear)){
            (*rear) = temp->previous;
            if((*rear) != NULL) (*rear)->next = NULL;
            free(temp);
        }else{
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            free(temp);
        }
    }else{
        printf("\nInvalid option!");
        return false; 
    }

    return true;
}

bool clear_items(node** front, node** rear){
    node* temp = NULL;
    while((*front) != NULL){
        temp = (*front);
        (*front) = temp->next;
        free(temp);
    }
    (*rear) = NULL;
    return is_empty((*front));
}