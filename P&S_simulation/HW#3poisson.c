#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main()
{
    int count = 0, A[1009]={};
    srand(time(NULL));
    
    
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            int random = rand() % 500; // 1000/lamda
            if(!random)
            {
                count++;
            }
        }
        A[count]++;
        count = 0;
    }

    for(int i=0;i<200;i++) printf("%d\n",A[i]);
    
    return 0;
}