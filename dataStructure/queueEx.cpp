#include <stdio.h>
#include <stdlib.h>

#define Capacity 10

typedef struct circularQueue{
    int data[Capacity];
    int front;
    int rear;
}cQueue;

cQueue* createCircularQueue();
{
    int i;
    cQueue* pCQueue = (cQueue*)malloc(sizeof(cQueue));
    pCQueue->front = 0;
    pCQueue->rear = 0;
    
    return pCQueue;
}

int isEmpty(cQueue* cQueue)
{
    return cQueue->front == cQueue->rear;
}

int isFull(cQueue* cQueue)
{
    return cQueue->front == (cQueue->rear+1)&Capacity;
}

void showQueue(cQueue* cQueue)
{
    if(isEmpty(cQueue))
    {
        printf("Circular Queue is Empty!\n");
        return;
    }
    printf("==========ShowQueue==========\n");
    for(int i = cQueue->front; i != cQueue->rear; i=(i+1)%Capacity)
        printf("[%d]\n",cQueue->data[i]);
    printf("[%d]\n",cQueue->data[i]);
    printf("=============================\n");
}

void enqueue(cQueue* cQueue, int data)
{
    if(isFull(cQueue))
    {
        printf("Circular Queue is Full!\n");
        return;
    }
    cQueue->rear = (cQueue->rear+1)%Capacity;
    cQueue->data[cQueue->rear] = data;
}


void dequeue(cQueue* cQueue)
{
    if(isEmpty(cQueue))
    {
        printf("Circular Queue is Empty!\n");
        return;
    }
    cQueue->front = (cQueue->front+1)%Capacity;
}