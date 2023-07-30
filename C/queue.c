#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int *arr;
    int front;
    int rear;
    int count; // 저장된 원소의 개수
    int capacity;
} queue;

void queueInit(queue* pQue, int size);
void enqueue(queue* pQue, int data);

int main()
{
    queue que;
    queueInit(&que, 5);

    enqueue(&que, 1);
    enqueue(&que, 2);
    enqueue(&que, 3);



}

void queueInit(queue* pQue, int size){
    pQue->arr = (int*)malloc(sizeof(int)* size);
    pQue->front = 0;
    pQue->rear = 0;
    pQue->count = 0;
    pQue->capacity = size;
}

void enqueue(queue* pQue, int data){
    
}