#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
    int Data;
    struct tagNode* next;
}Node;

Node* head = NULL;

Node* create_node(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = data;
    newNode->next = NULL;

    return newNode;
}

void insert_node_front(Node** head, Node* newnode){
    
    if(*head==NULL){
        newnode = *head;
        return;
    }
    
    newnode->next = *head;
    *head = newnode;
}

int main(){
    Node* newNode;
    Node* List;

    newNode = create_node(1);
    insert_node_front(&List, newNode);
    newNode = create_node(2);
    insert_node_front(&List, newNode);
    newNode = create_node(3);
    insert_node_front(&List, newNode);

    return 0;

}