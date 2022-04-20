#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main()
{
    int count = 0, A[100009]={};
    srand(time(NULL));
    
    
    for(int i=0;i<1000000;i++)
    {
        int random = rand() % 20; // 1/lamda
        if(random)
        {
            count++;
        }
        else
        {
            A[count]++;
            count = 0;
        }
    }

    for(int i=0;i<300;i++) printf("%d\n",A[i]);
    
    return 0;
}