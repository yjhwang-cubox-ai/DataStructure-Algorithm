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

Node* GetNodeAt(Node* head, int Location){
    Node* current = head;
    while(current != NULL && (--Location) >=0){
        current = current->next;
    }
    return current;
}

void RemoveNode(Node** head, Node* remove){
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
        }
    }
}

void insertAfter(Node* current, Node* newNode){
    newNode->next = current->next;
    current->next = newNode;
}

int Count(Node* node){
    int count = 0;
    Node* current = node;
    while(current != NULL){
        current = current->next;
        count ++;
    }
    return count;
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
    Node* a = GetNodeAt(List, 1);    
    printf("%d\n", a->Data);
    RemoveNode(&List, a);
    Node* b = GetNodeAt(List, 0);
    newNode = CreateNode(100);
    insertAfter(b, newNode);

    int aa = Count(List);
    printf("%d\n",aa);

    return 0;
}