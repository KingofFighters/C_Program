#include<stdio.h>
#include<stdlib.h>
//Node structure for a BST.
struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};
//Function to create a new node.
struct Node* createNode(int data)
{
    struct Node*newNode=(struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//Function to insert a node into the BST.
struct Node*insertNode(struct Node*root, int data){
    if(root==NULL)
        return createNode(data);

    if(data<root->data)
        root->left = insertNode(root->left,data);
    else if(data>root->data)
        root->right = insertNode(root->right,data);

    return root;
}
//Function to remove all leaf nodes from the BST
struct Node*removeLeafNodes(struct Node*root){
    if(root==NULL)
        return NULL;

    if(root->left==NULL && root->right==NULL){
        //Node is a leaf,free it and return NULL.
        free(root);
        return NULL;
    }
    //Recursively remove leaf nodes from left and right subtrees
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);

    return root;
}
//Function to perform an in-order traversal of the BST.
void inOrderTraversal(struct Node*root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        printf("%d",root->data);
        inOrderTraversal(root->right);
    }
}
int main(){
    struct Node*root = NULL;
    //Insert nodes into the BST.
    root= insertNode(root,50);
    insertNode(root,30);
    insertNode(root,20);
    insertNode(root,40);
    insertNode(root,70);
    insertNode(root,60);
    insertNode(root,80);

    printf("Original BST(in-order):");
    inOrderTraversal(root);
    printf("\n");

    //Remove all leaf nodes from the BST.
    root= removeLeafNodes(root);

    printf("BST after removing leaf nodes(in-order):");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}