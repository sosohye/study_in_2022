#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
    int data;
    struct StackNode* next;
}

int isEmpty(StackNode* top)
{
    return top == NULL; 
}

void showLinkedStack(StackNode* top)
{
    StackNode *pNode = NULL;
    if(isEmpty(top))
    {
        printf("The Stack is Empty!\n");
        return;
    }
    
    pNode = top;
    printf("=========ShowStack==========\n");
    while(pNode!=NULL)
    {
        printf("[%d]\n",pNode->data);
        pNode = pNode->next;
    }
    printf("============================\n");
}

void pushLinkedStack(StackNode** top, int dataX)
{
    StackNode* pNode = (StackNode*)malloc(sizeof(StackNode));
    pNode->data = dataX;
    
    if(isEmpty(top))    *top = pNode
    
    else
    {
        pNode->next = *(top);
        *(top) = pNode;
    }
}

StackNode* popLinkedStack(StackNode** top)
{
    if(isEmpty(top))
    {
        printf("The Stack is Empty!\n");
        return;
    }
    
    StackNode* pNode = *(top); 
    *(top) = (*(top))->next;
    return pNode
}

StackNode* topLinkedStack(StackNode* top)
{
    StackNode* pNode = NULL;
    if(!isEmpty(top))   pNode = top;
    return pNode;
}

void deleteLinkedStack(StackNode**top)
{
    StackNode *pNode = *top, *pDelNode = NULL;
    
    while(pNode != NULL)
    {
        pDelNode = pNode;
        pNode = pNode->next;
        free(pDelNode);
    }
    *top = NULL;
}