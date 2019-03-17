#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
}*node_ptr;

bool is_empty(node_ptr front);
bool enqueue(node_ptr* front, node_ptr* rear, int value);
bool dequeue(node_ptr* front);
bool show_front(node_ptr front);
bool show_rear(node_ptr front, node_ptr rear);
void display_elements(node_ptr front);
bool clear_queue(node_ptr* front);

void main(){
    
    int opt = 0, value = 0;
    node_ptr front = NULL;
    node_ptr rear = NULL;

    do{
        printf("\nQUEUE Menu\n"
			   "\n1 - Is Empty?"
			   "\n2 - Enqueue"
			   "\n3 - Dequeue"
			   "\n4 - Show FRONT"
			   "\n5 - Show REAR"
			   "\n6 - Display elements"
			   "\n7 - Clear queue"
			   "\n\n0 - EXIT\n\n");

		printf("option: ");
		scanf("%d", &opt);

        switch(opt){
            case 1:
                printf(is_empty(front) ? "\nTrue\n" : "\nFalse\n");
				break;
            case 2:
                printf("Insert the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
				break;
            case 3:
                printf(dequeue(&front) ? "\nDequeued\n" : "\nFailed\n");
				break;
            case 4:
                show_front(front);
				break;
            case 5:
                show_rear(front, rear);
				break;
            case 6:
                display_elements(front);
				break;
            case 7:
                clear_queue(&front);
				break;
            case 0:
                clear_queue(&front);
				break;
            default:
                printf("\nInvalid option!\n")
        }

    }while(opt != 0);
}

bool is_empty(node_ptr front){
    return front == NULL;
}

bool enqueue(node_ptr* front, node_ptr* rear, int value){
    node_ptr new_node = (node_ptr) malloc(sizeof(struct node));

    if(new_node == NULL)
        return false;
    
    new_node->data = value;
    new_node->next = NULL;

    if((*front) == NULL){
        (*front) = (*rear) = new_node;
        (*front)->next = NULL;
    }
    else{
        (*rear)->next = new_node;
        (*rear) = new_node;
    }

    return true;
}

bool dequeue(node_ptr* front){
    if(is_empty((*front))){
        printf("\nThe queue is already empty!\n");
        return false;
    }

    node_ptr temp = (*front);
    (*front) = temp->next;
    free(temp);

    return true;
}

bool show_front(node_ptr front){
    if(is_empty(front)){
        printf("\nThe queue is empty!\n");
        return false;
    }
    printf("\n front ->[%d]\n", front->data);
}

bool show_rear(node_ptr front, node_ptr rear){
    if(is_empty(front)){
        printf("\nThe queue is empty!\n");
        return false;
    }

    printf("\n[%d]<- rear \n", rear->data);
}

void display_elements(node_ptr front){
    node_ptr current = front;

    printf("\n front ->");
    while(current != NULL){
        printf(" [%d] ", current->data);
        current = current->next;
    }
    printf("<- rear \n");
}

bool clear_queue(node_ptr* front){

    node_ptr temp = NULL;

    while((*front) != NULL){
        temp = (*front);
        (*front) = temp->next;
        free(temp);
    }

    return is_empty((*front));
}

