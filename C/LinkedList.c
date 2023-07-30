#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
    int Data;
    struct tagNode* next;
} Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = data;
    newNode->next = NULL;

    return newNode;
}

void appenNode(Node** head, Node* newnode){
    if (*head == NULL){
        *head = newnode;
    }
    else{
        Node* currentnode = *head;
        while(currentnode->next != NULL){
            currentnode = currentnode->next;
        }
        currentnode->next = newnode;
    }
}

void insertNodefront(Node** head,  Node* newnode){
    
    if (*head == NULL){
        *head = newnode;
        return;
    }
    newnode->next = *head;
    *head = newnode;
}

void inserNode(Node* current, Node* newnode){
    newnode->next = current->next;
    current->next = newnode;
}

void display(Node* head){
    Node* currentNode = head;

    while(currentNode != NULL){
        printf("%d\t", currentNode->Data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void removeAllNode(Node** head){
    Node* deleteNode = NULL;

    while(*head != NULL){
        deleteNode = *head;
        *head = (*head)->next;
        free(deleteNode);
    }
}

void removeNode(Node** head, Node* remove){
    if (*head == remove){
        *head = remove->next;
    }
    else{
        Node* current = *head;
        while(current != NULL && current->next != remove){
            current = current->next;
        }
        if (current != NULL){
            current->next = remove->next;
            free(remove);
        }
    }
}

Node* getNodeAt(Node** head, int location){
    Node* currentNode = *head;
    while(currentNode != NULL && location-- != 0){
        currentNode = currentNode->next;
    }
    return currentNode;
}

void insertNodeSort(Node** head, Node* newNode){
    if(*head == NULL){
        *head = newNode;
        return;
    }
    if(newNode->Data <= (*head)->Data){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    Node* prev = NULL;
    while(current->Data <= newNode->Data){
        prev = current;
        current = current->next;
    }
    inserNode(prev, newNode);
}


int main(){
    Node* newnode = NULL;
    Node* List = NULL;

    // newnode = createNode(200);
    // insertNodefront(&List, newnode);
    // newnode = createNode(10);
    // appenNode(&List, newnode);
    // newnode = createNode(20);
    // appenNode(&List, newnode);
    // newnode = createNode(30);
    // appenNode(&List, newnode);
    // newnode = createNode(100);
    // insertNodefront(&List, newnode);
    // display(List);

    newnode = createNode(200);
    insertNodeSort(&List, newnode);
    newnode = createNode(10);
    insertNodeSort(&List, newnode);
    newnode = createNode(20);
    insertNodeSort(&List, newnode);
    newnode = createNode(30);
    insertNodeSort(&List, newnode);
    newnode = createNode(100);
    insertNodeSort(&List, newnode);
    display(List);

    
    Node* remove = getNodeAt(&List, 3);
    removeNode(&List, remove);
    display(List);

    Node* insert = getNodeAt(&List, 2);
    newnode = createNode(1000);
    inserNode(insert, newnode);
    display(List);    
   
    Node* test = getNodeAt(&List, 2);
    printf("%d\n", test->Data);

    removeAllNode(&List);
    display(List);
    
    return 0;
}