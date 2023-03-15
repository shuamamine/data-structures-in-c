#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node Node;
Node* create_node(int data) {
    Node* node1 = (Node*) malloc(sizeof(Node)); 
    node1->data = data;
    node1->next = NULL;
    return node1;
}
