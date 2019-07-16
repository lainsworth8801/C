#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printNode(struct node* node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    
    printf("\n");
}

// from the front
void push(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    
    if(*head == NULL) {
        *head = newNode;
        newNode->next = NULL;
    }
    
    newNode->next = *head;
    *head = newNode;
}

// in the middle
void insert(struct node* node, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    
    newNode->next = node->next;
    node->next = newNode;
}

// from the end
void append(struct node** head, int data) {
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    
    struct node* last = *head;
    
    while(last->next != NULL) {
        last = last->next;
    }
    
    last->next = newNode;
}

void deleteNode(struct node** head, int data) {
    
    struct node* n = *head;
    if(n->data == data) {
        *head = n->next;
        free(n);
        return;
    }

    struct node* prev;
    while(n->data != data){
        prev = n;
        n = n->next;
    }
    
    prev->next = n->next;
    free(n);
}

int main(){
    
    int a = 6;
    int* ptr = &a;
    
    // Debug
    printf("*ptr should be same as a (6): %d, ptr a's address: %p\n", *ptr, ptr);
    
    a = 9;
    printf("ptr a's address does not change by changing a: %p\n", ptr);
    
    *ptr = 12;
    printf("a is changed by changing *ptr and should be 12 now: %d\n", a);
    
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data = 6;
    
    push(&n, 8);
    insert(n, 11);
    append(&n, 49);
    printNode(n);
    
    deleteNode(&n, 11);
    printNode(n);
    
    return 0;
}