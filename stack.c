#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}*node_ptr;

bool is_empty(node_ptr top);
bool push(node_ptr* top, int value);
bool pop(node_ptr* top);
void show_top(node_ptr top);
void display_elements(node_ptr top);
bool clear_stack(node_ptr* top);

int main(void){
    int opt = 0, value = 0;
    node_ptr top = NULL;

    do{
        printf("\nSTACK Menu\n"
			   "\n1 - Is Empty?"
			   "\n2 - Push"
			   "\n3 - Pop"
			   "\n4 - Show Top"
			   "\n5 - Display elements"
			   "\n6 - Clear stack"
			   "\n\n0 - EXIT\n\n");

		printf("option: ");
		scanf("%d", &opt);

        switch(opt){
            case 1:
              printf(is_empty(top) ? "\nTrue\n": "\nFalse\n");
              break;

            case 2:
              printf("\nInsert a integer value to push: ");
			  scanf("%d", &value);
              printf(push(&top, value) ? "\nPushed\n" : "\nFailed\n");
              break;

            case 3:
                printf(pop(&top) ? "\nPopped\n" : "\nFailed");
                break;

            case 4:
                show_top(top);
                break;

            case 5:
              display_elements(top);
              break;

            case 6:
              clear_stack(&top);
              break;

            case 0:
              clear_stack(&top);
              break;

            default:
              printf("\nInvalid value!\n");
        }

    }while(opt != 0);
}

bool is_empty(node_ptr top){
  return top == NULL;
}

bool push(node_ptr* top, int value){
    node_ptr new_node = (node_ptr) malloc(sizeof(struct node));

    if(new_node == NULL)
        return false;
    
    new_node->data = value;
    
    if((*top) == NULL){
        new_node->next = NULL;
        (*top) = new_node;
    }else{
        node_ptr temp = (*top);
        (*top) = new_node;
        new_node->next = temp;
    }

    return true;
}

bool pop(node_ptr* top){
    if(is_empty((*top))){
        printf("Stack is already empty!");
        return false;
    }

    node_ptr temp = (*top);
    (*top) = temp->next;
    free(temp);

    return true;
}

void show_top(node_ptr top){
    if(is_empty(top)){
        printf("Stack is empty!");
        return;
    }

    printf("\n top -> [%d]\n", top->data);


}

void display_elements(node_ptr top){
    if(is_empty(top)){
        printf("Stack is empty!");
        return;
    }

    node_ptr temp = top;

    printf("\n top -> ");
    while(temp != NULL){
        printf("[%d]", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool clear_stack(node_ptr* top){
    node_ptr temp = NULL;

    while((*top) != NULL){
        temp = (*top);
        (*top) = temp->next;
        free(temp);
    }

    return is_empty((*top));
}


