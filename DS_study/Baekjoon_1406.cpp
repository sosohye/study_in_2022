#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char S[100009];
char com[10];

typedef struct Node{
	char data;
	struct Node* next;
	struct Node* pre;
}Node;

int main()
{
	scanf("%s",S);
	Node *head = (Node*)malloc(sizeof(Node));
	Node *tail = (Node*)malloc(sizeof(Node));
	head->pre = NULL;
	head->next = tail;
	tail->pre = head;
	tail->next = NULL;
	int n = strlen(S);
	Node* pos = head;
	
	for(int i=0;i<n;i++)
	{
		Node *TmpNode = (Node*)malloc(sizeof(Node));
		TmpNode->data = S[i];
		pos->next = TmpNode;
		TmpNode->pre = pos;
		TmpNode->next = tail;
		tail->pre = TmpNode;
		pos = TmpNode;
	}
	
	scanf("%d",&n);
	
	while(n--)
	{
		while(getchar()=='\n')break;
		scanf("%[^\n]s",&com);
		if(com[0]=='L')
		{
			if(pos!=head)	pos = pos->pre;
		}
		if(com[0]=='D')
		{
			if(pos->next!=tail)	pos = pos->next;
		}
		if(com[0]=='B')
		{
			if(pos!=head)
			{
				Node* TmpNode = pos;
				TmpNode->pre->next = TmpNode->next;
				TmpNode->next->pre = TmpNode->pre;
				pos = pos->pre;
				free(TmpNode);
			}
		}
		if(com[0]=='P')
		{
			char addC = com[2];
			//printf("%c\n",com[2]);
			Node *TmpNode = (Node*)malloc(sizeof(Node));
			TmpNode->data = addC;
			TmpNode->next = pos->next;
			TmpNode->pre = pos;
			pos->next->pre = TmpNode;
			pos->next = TmpNode;
			pos = pos->next;
		}
	}
	
	pos = head;
	while(pos!=tail)
	{
		pos = pos->next;
		printf("%c",pos->data);
	}
	return 0;
}
