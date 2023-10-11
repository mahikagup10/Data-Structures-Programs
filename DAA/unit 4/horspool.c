#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* shifttable(char p[]);
int horspoolstringmatch(char p[], char t[]);

int main()
{
    char s[] = "JIM_SAW_ME_IN_A_BARBER_SHOP";
    char p[] = "BARBER";

    int res = horspoolstringmatch(p,s);
    if(res<0)
        printf("%s not found\n", p);
    else  
        printf("found\n");
    horspoolstringmatch(p,s);
}

char* shifttable(char p[])
{
    int size = 256;
    char* table = malloc(size*sizeof(char));
    int m = strlen(p);
    for(int i=0; i<=size-1; i++)
    {
        table[i] = m;
    }
    for(int j=0;j<=m-2;j++)
        table[p[j]] = m-1-j;
    // for(int i=0; i<=size-1;i++)
    // {
    //     if(i%20==0)
    //         print("\n");
    //     printf("%c=%d",i,table[i]);
    // }
    return table;
}

int horspoolstringmatch(char p[], char t[])
{
    char* table = shifttable(p);

    int m = strlen(p);
    int n = strlen(t);

    int i = m-1;
    while(i<=n-1)
    {
        int k=0;
        while(k<=m-1 && t[i-k]==p[m-1-k])
            k++;

        if(k==m)
        {
            free(table);
            return i-m+1;
        }
        else
            i = i +table[t[i]];

    }
    free(table);
    return -1;
}