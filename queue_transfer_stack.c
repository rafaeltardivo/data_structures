#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
    char ra[13 + 1];
    char name[30 + 1];
    char born_at[6 + 1];
    char status;
    struct node* next;
}node;

bool is_empty(node* first, node* top);
bool insert(node** first, node** top, node** last);
bool remove_item(node** first, node** top, node** last);
bool transfer(node** first, node** top, node** last);
void display_elements(node* first, node* top);
void clean_container(node** container);
node* create_node();
node* copy_node(node* base);

void main(){

    int opt = 0, value = 0;
    node* first = NULL;
    node* last = NULL;
    node* top = NULL;

    do{
        printf("\nMenu\n"
			   "\n1 - Is Empty? "
			   "\n2 - Insert "
               "\n3 - Display items "
               "\n4 - Transfer "
               "\n5 - Remove "
			   "\n0 - EXIT\n\n");

		printf("option: ");
		scanf("%d", &opt);

        switch(opt){
            case 1:
              printf(is_empty(first, top) ? "\nTrue\n": "\nFalse\n");
              break;

            case 2:
              printf(insert(&first, &top, &last) ? "\nInserted\n": "\nSomething went wrong!\n");
              break;

            case 3:
              display_elements(first, top);
              break;

            case 4:
              printf(transfer(&first, &top, &last) ? "\nTransfered\n": "\nSomething went wrong!\n");
              break;
            case 5:
              printf(remove_item(&first, &top, &last) ? "\nItem removed\n": "\nSomething went wrong!\n");
              break;

            default:
              printf("\nInvalid value!\n");
        }

    }while(opt != 0);

}

bool is_empty(node* first, node* top){
    return first == NULL && top == NULL;
}

node* create_node(){
    node* new_node = (node*) malloc(sizeof(node));

    if(new_node == NULL){
        printf("\nCouldn't allocate mem space!\n");
        return NULL;
    }
 
    printf("\nInsert your RA: ");
    scanf("%s", new_node->ra);

    printf("\nInsert your name: ");  
    scanf("%s", new_node->name);

    printf("\nInsert your birth date (YYYYmmdd): ");
    scanf("%s", new_node->born_at);

    printf("\nInsert your status (A for active, I for inactive): ");
    scanf(" %c", &new_node->status);

    new_node->next = NULL;

    return new_node;
}

node* copy_node(node* base){
    node* new_node = (node*) malloc(sizeof(node));

    if(new_node == NULL){
        printf("\nCouldn't allocate mem space!\n");
        return NULL;
    }

    strcpy(new_node->born_at, base->born_at);
    strcpy(new_node->name, base->name);
    strcpy(new_node->ra, base->ra);
    new_node->status = base->status;

    new_node->next = NULL;

    return new_node;
}


bool insert(node** first, node** top, node** last){
    node* new_node = create_node();

    if((*top) == NULL){
        if((*last) == NULL){
            (*last) = (*first) = new_node;
        }else{
            (*last)->next = new_node;
            (*last) = new_node;
        }
    }else{
        node* temp = (*top);
        (*top) = new_node;
        (*top)->next = temp;
    }
}

void display_elements(node* first, node* top){
    node* temp = NULL;

    if(is_empty(first, top)){
        printf("\nThe container is empty!\n");
        return;
    }

    if(top == NULL){
        printf("\n| FIRST |\n");
        temp = first;
    }else{
        printf("\n| TOP |\n");
        temp = top;
    }

    while(temp != NULL){
        printf("\nName: %s\nRA: %s\nBirth Date: %s\nActive: %c\n",
               temp->name, temp->ra, temp->born_at, temp->status);
        temp = temp->next;
    }
}

bool transfer(node** first, node** top, node** last){
    node* temp_iter = NULL;
    node* temp_node = NULL;


    if(is_empty((*first), (*top))){
        printf("\nThe container is empty!\n");
        return false;
    }

    if((*top) == NULL){
        temp_iter = (*first);

        while(temp_iter != NULL){
            node* new_node = copy_node(temp_iter);

            temp_node = (*top);
            (*top) = new_node;
            new_node->next = temp_node;

            temp_iter = temp_iter->next;
        }
        (*last) = NULL;
        clean_container(first);
    }else{
        temp_iter = (*top);

        while(temp_iter != NULL){

            if((*first) == NULL){
                (*first) = (*last) = (*top);
            }else{
                node* new_node = copy_node(temp_iter);

                temp_node = (*first);
                (*first) = new_node;
                new_node->next = temp_node;
                temp_node->next = NULL;
            }
            temp_iter = temp_iter->next;
        }

        (*top) = NULL;
        clean_container(top);
    }
    return true;
}

bool remove_item(node** first, node** last, node** top){
    node* temp = NULL;

    if((*top) == NULL){
        temp = (*first);
        (*first) = temp->next;
       
    }else{
        temp = (*top);
        (*top) = temp->next;
    }
    free(temp);
   
    return true;
}

void clean_container(node** container_first){
    node* temp = NULL;

    while((*container_first) != NULL){
        temp = (*container_first)->next;
        free((*container_first));
        (*container_first) = temp;
    }
}
