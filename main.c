#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;



struct Node* createNode(int data){
    struct Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
}


void insertNode(struct Node** tree, int data){
    if (*tree == NULL){
        struct Node* new_node = createNode(data);
        *tree = new_node;
    }
    else{
        int root_value = (*tree)->data;
        if (data < root_value){
            insertNode(&(*tree)->left, data);
        }
        else{
            insertNode(&(*tree)->right, data);
        }
    }
}


void printTree(struct Node* tree, int counter){
    if (tree == NULL){
        return;
    }
    else{
        printTree(tree->right, counter+=1);
        for (int i = 0; i < counter; ++i){
            printf("\t");
        }
        printf("(%d)\n", tree->data);
        
        printTree(tree->left, counter+=1);
        
    }
}

int main() {
    struct Node* root = NULL;
    int counter = 0;
    insertNode(&root, 8);
    insertNode(&root, 3);
    insertNode(&root, 1);
    insertNode(&root, 6);
    insertNode(&root, 5);
    insertNode(&root, 7);
    
    printTree(root, counter);


    return 0;
}
