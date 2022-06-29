#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char data;
	struct Node* next;
	struct Node* pre;
}Node;

int main()
{
	int n;
	scanf("%d",&n);
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	head->pre = NULL;
	Node* pos = head;
	
	for(int i=0;i<n;i++)
	{
		char C[1000009];
		scanf("%[^\n]s",C);
		int l = strlen(C);
		for(int j=0;j<l;j++)
		{
			if(C[j]=='<')
			{
				if(pos->pre!=NULL)	pos = pos->pre;
			}
			else if(C[j]=='>')
			{
				if(pos->next!=NULL)	pos = pos->next;
			}
			else if(C[j]=='-')
			{
				if(pos!=head)
				{
					Node* TmpNode = pos;
					TmpNode->pre->next = TmpNode->next;
					TmpNode->next->pre = TmpNode->pre;
					free(TmpNode);
				}
			}
			else
			{
				Node* NewNode = (Node*)malloc(sizeof(Node));
				NewNode->data = C[j];
				NewNode->next = pos->next;
				NewNode->pre = pos;
				pos->next->pre = NewNode;
				pos->next = NewNode;
			}
		}
		pos = head;
		while(pos)
		{
			pos = pos->next;
			printf("%c",pos->data);
		}
		printf("\n");
	}
	return 0;
}
