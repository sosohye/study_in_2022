#include<stdio.h>
int DP[1009];
int revDP[1009];
int A[1009];
int N,max;

int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf(" %d",A+i);
    }
    for(int i=1;i<=N;i++)
    {
        DP[i] = 1;
        for(int j=1;j<i;j++)
        {
            if( A[j] < A[i] && DP[j]+1 > DP[i]) DP[i] = DP[j] + 1;
        }
    }
    for(int i=N;i>=1;i--)
    {
        revDP[i] = 1;
        for(int j=N;j>i;j--)
        {
            if( A[j] < A[i] && revDP[j]+1 > revDP[i]) revDP[i] = revDP[j] + 1;
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(DP[i]+revDP[i] > max)    max = DP[i] + revDP[i];
    }
    printf("%d",max-1);
    return 0;
}
