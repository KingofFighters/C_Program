#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node.
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data.
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST.
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node.
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recursively insert into the left or right subtree.
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;  // Return the unchanged root pointer.
}

// Function to search for a node in the BST.
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    // Search in the left or right subtree based on data comparison.
    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}

// Function to find the minimum value node in the BST.
struct Node* findMin(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to find the maximum value node in the BST.
struct Node* findMax(struct Node* root) {
    struct Node* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Function to delete a node from the BST.
struct Node* delete(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    // Recur down the tree to find the node to be deleted.
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        // If the node to be deleted has one or no child.
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // If the node to be deleted has two children, get the inorder successor (smallest in the right subtree).
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node.
        root->data = temp->data;

        // Delete the inorder successor.
        root->right = delete(root->right, temp->data);
    }

    return root;
}

// Function to perform inorder traversal (left, root, right).
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform preorder traversal (root, left, right).
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform postorder traversal (left, right, root).
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to free the memory used by the BST.
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    // Search for a node
    int searchKey = 40;
    struct Node* searchResult = search(root, searchKey);
    if (searchResult != NULL) {
        printf("Node with data %d found in the tree.\n", searchKey);
    } else {
        printf("Node with data %d not found in the tree.\n", searchKey);
    }

    // Delete a node
    int deleteKey = 20;
    printf("Deleting node with data %d...\n", deleteKey);
    root = delete(root, deleteKey);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    // Find the minimum and maximum nodes
    struct Node* minNode = findMin(root);
    struct Node* maxNode = findMax(root);
    if (minNode != NULL) {
        printf("Minimum node: %d\n", minNode->data);
    }
    if (maxNode != NULL) {
        printf("Maximum node: %d\n", maxNode->data);
    }

    // Free the tree memory
    freeTree(root);
    
    return 0;
}
