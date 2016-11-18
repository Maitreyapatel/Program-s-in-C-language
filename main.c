#include <stdio.h>
#include <stdlib.h>
int com(int m,int n)
{
    int c;
    if(m==n)
        return 1;
    else if(n==1)
        return m;
    else
    {
        return com(m-1,n-1)+com(m-1,n);
    }
}

int main()
{
    int m,n,c;

    printf("Enter base and celling of combination:\n");
    scanf("%d %d",&m,&n);

    c=com(m,n);

    printf("\n\nAnswer=%d",c);
    return 0;
}
