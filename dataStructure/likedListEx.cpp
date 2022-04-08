// Single Linked List in Integer

// 구조체 선언
typedef struct{
    int data;
    LinkedList* next; 
}LinkedList;

int isEmpty(LinkedList L)
{
    return L->Next == NULL;
}

int isLast(LinkedList* P, LinkedList L)
{
    return P->Next == NULL;
}

LinkedList* Find(int X, LinkedList L)
{
    LinkedList* P;
    
    P = L->Next;
    while(P!=NULL && P->data != X)
        P = P->Next;
    
    return P; 
}

LinkedList* FindPrevious(int X, LinkedList L)
{
    LinkedList* P;
    
    P = L;
    while(P!=NULL && P->Next->data != X)
        P = P->Next;
    
    return P; 
}

void Delete(int X, LinkedList L)
{
    LinkedList* P, TmpCell;
    
    P = FindPrevious(X,L);
    if(!isLast(P,L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

void Insert(int X, LinkedList L, LinkedList* P)
{
    LinkedList* TmpCell;
    
    TmpCell = malloc(sizeof(LinkedList));
    if(TmpCell==NULL)
        FatalError("Out of space.");
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell; 
}

// 연결 리스트의 정렬, 탐색 구현 나중에 해보기

// 예제
int main()
{
    LinkedList* head = malloc(sizeof(struct LinkedList));   // 머리 노드 생성

    LinkedList* node1 = malloc(sizeof(struct LinkedList));  // 첫 번째 노드 생성
    head->next = node1;                                     // 첫 번째 노드 연결
    node1->data = 10;                                       // 첫 번째 노드에 저장

    LinkedList * node2 = malloc(sizeof(struct LinkedList)); // 두 번째 노드 생성
    node1->next = node2;                                    // 두 번째 노드 연결
    node2->data = 20;                                       // 두 번째 노드에 저장

    node2->next = NULL;                                     // 두 번째 노드가 끝

    // Working Anything
    
    free(node2);        // 노드 메모리 해제
    free(node1);        // 노드 메모리 해제
    free(head);         // 머리 노드 메모리 해제

    return 0;
}