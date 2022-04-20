#include<stdio.h>

typedef struct Node{
	int data;
	Node* left;
	Node* right;
};

void addTree(Node** p, int value)
{
	if((*p)==NULL)
	{
		(*p) = (Node*)malloc(sizeof(Node));
		(*p)->data = value;
		(*p)->leftChild = NULL;
		(*p)->rightChild = NULL;
	}
	else if((*p)->data>value)	addTree(&((*p)->left),value);
	else	addTree(&((*p)->right),value);
}

void printTreePostorder(Node* pNode)
{
	if (pNode == NULL)	return;
	
	printTreePostorder(pNode->leftChild);
	printTreePostorder(pNode->rightChild);
	printf("%d",pNode->data);
}

int main()
{
	
}
