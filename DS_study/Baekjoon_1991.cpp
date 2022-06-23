#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	char data;
	struct Node* left;
	struct Node* right;
};

void printTreePreorder(Node* pNode)
{
	if (pNode == NULL)	return;
	
	printf("%c",pNode->data);
	printTreePreorder(pNode->left);
	printTreePreorder(pNode->right);
}

void printTreeInorder(Node* pNode)
{
	if (pNode == NULL)	return;
	
	printTreeInorder(pNode->left);
	printf("%c",pNode->data);
	printTreeInorder(pNode->right);
}

void printTreePostorder(Node* pNode)
{
	if (pNode == NULL)	return;
	
	printTreePostorder(pNode->left);
	printTreePostorder(pNode->right);
	printf("%c",pNode->data);
}

int main()
{
	int N;
	char C1,C2,C3;
	scanf("%d",&N);
	Node* pNode[30];
	for(int i=0;i<N;i++)
	{
		pNode[i] = (Node*)malloc(sizeof(Node));
		pNode[i]->data = 'A' + (char)i;
		pNode[i]->left = NULL;
		pNode[i]->right = NULL;
	}
	for(int i=0;i<N;i++)
	{
		while(getchar()=='\n')break;
		scanf("%c %c %c",&C1,&C2,&C3);
		int P = C1 - 'A';
		int L = C2 - 'A';
		int R = C3 - 'A';
		if(C2!='.')	pNode[P]->left = pNode[L];
		if(C3!='.')	pNode[P]->right = pNode[R];
	}
	
	
	printTreePreorder(pNode[0]);
	printf("\n");
	printTreeInorder(pNode[0]);
	printf("\n");
	printTreePostorder(pNode[0]);
	printf("\n");
	
	for(int i=0;i<N;i++)
	{
		free(pNode[i]);
	}
	return 0;
}
