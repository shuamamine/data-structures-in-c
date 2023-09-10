#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Define the structure for a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} bst;

// Function to create a new node
bst* createNode(int data) {
    bst* newNode = (bst *)malloc(sizeof(bst));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
bst* insert(bst* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// In-order traversal to print the BST elements
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to find the minimum value node in a BST
bst* findMinNode(bst* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node from the BST
bst* deleteNode(bst* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            bst* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst* temp = root->left;
            free(root);
            return temp;
        }

        bst* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
