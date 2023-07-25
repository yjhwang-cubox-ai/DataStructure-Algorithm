#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
    int Data;
    struct tagNode* next;
    
} Node;


Node* CreateNode(int data){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = data;
    NewNode->next = NULL;

    return NewNode;
}

void deleteNode(Node* node){
    free(node);
}

void appendNode(Node** head, Node* newNode){
    if ((*head)==NULL){
        *head = newNode;
    }else{
        Node* tail = *head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

int main(){
    Node* List = NULL;
    Node* newNode = NULL;
    
    newNode = CreateNode(1);
    appendNode(&List, newNode);
    newNode = CreateNode(2);
    appendNode(&List, newNode);
    newNode = CreateNode(3);
    appendNode(&List, newNode);

    return 0;
}