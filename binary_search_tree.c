#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* create_node(int value);
node* insert_node(node* root, int value);
node* delete_node(node* root, int value);
node* find_min(node* root);
bool is_empty(node* root);
bool search_node(node* root, int value);
void pre_order(node* root);
void in_order(node* root);
void post_order(node* root);
node* clear(node* root);

int main(void){
    int op = 0;
    node* root = NULL;
    int value = 0;

     do{
        printf(
            "\n\nBinary tree MENU\n"
            "\n1 - Is empty?"    
            "\n2 - Insert"
            "\n3 - Delete"
            "\n4 - List pre order"
            "\n5 - List in order"
            "\n6 - List post order"
            "\n7 - Search"
            "\n8 - Clear"
            "\n0 - EXIT\n"
        );

        printf("\nChoose your option: ");
        scanf("%d", &op);

        switch(op){

            case 1:
                printf(is_empty(root)? "\nThe tree is empty!" : "\nNot empty.");
                break;

            case 2:
                printf("\nInsert a value for the new node: ");
                scanf("%d", &value);
                root = insert_node(root, value);
                printf("\nInserted!");
                break;

            case 3:
                printf("\nInsert a value for deletion: ");
                scanf("%d", &value);
                root = delete_node(root, value);
                printf("\nDeleted!");
                break;
            
            case 4:
                pre_order(root);
                break;

            case 5:
                in_order(root);
                break;

            case 6:
                post_order(root);
                break;

            case 7:
                printf("\nInsert a value to search: ");
                scanf("%d", &value);
                printf(search_node(root, value) ? "\nFound!" : "\nNot found.");
                break;
            
            case 8:
                printf(clear(root) == NULL? "\nCleared!" : "\nSomething went wrong.");
                break;

            default:
                printf("\nInvalid option!");
                break;
        }

     }while(op != 0);

}

node* create_node(int value){
    node* new_node = (node*) malloc(sizeof(node));

    if(new_node == NULL){
        printf("\nCouldn't allocate memory!");
        exit(1);
    }

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

node* insert_node(node* root, int value){
    bool inserted = false;
    node* new_node = NULL;

    if(is_empty(root)){
        new_node = create_node(value);
        root = new_node;
    }else if(value <= root->data){
        root->left = insert_node(root->left, value);
    }else{
        root->right = insert_node(root->right, value);
    }
    return root;
}

node* delete_node(node* root, int value){

    if(is_empty(root)){
        return root;
    }else if (value < root->data){
        root->left = delete_node(root->left, value);
    }else if (value > root->data){
        root->right = delete_node(root->right, value);
    }else{

        if(root->right == NULL && root->left == NULL){
            free(root);
            root = NULL;
        }else if(root->left == NULL){
            node* temp = root;
            root = root->right;
            free(temp);
        }else if(root->right == NULL){
            node* temp = root;
            root = root->left;
            free(temp);
        }else{
            node* temp = find_min(root->right);

            if(temp != NULL){
                root->data = temp->data;
                root->right = delete_node(root->right, temp->data);
            }else{
                printf("\nInvalid search!");
            }
        }
    }

    return root;
}

bool is_empty(node* root){
    return root == NULL;
}

bool search_node(node* root, int value){

    if(is_empty(root)){
        return false;
    }

    if(root->data == value){
        return true;
    }else if (value <= root->data){
        return search_node(root->left, value);
    }else{
        return search_node(root->right, value);
    }
}

void pre_order(node* root){

    if(root == NULL){
        return;
    }

    printf(" %d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(node* root){

    if(root == NULL){
        return;
    }
    
    in_order(root->left);
    printf(" %d ", root->data);
    in_order(root->right);
}

void post_order(node* root){

    if(root == NULL){
        return;
    }
    
    post_order(root->left);
    post_order(root->right);
    printf(" %d ", root->data);
}

node* find_min(node* root){
    node* temp = root;
    if(temp == NULL) return NULL;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

node* clear(node* root){

    if(is_empty(root) == false){
        root->left = clear(root->left);
        root->right = clear(root->right);
        free(root);
    }

    return NULL;
}