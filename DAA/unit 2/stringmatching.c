#include<stdio.h>
#include<string.h>

int stringmatching(char* text, char* pattern, int n, int m);

int main()
{
    char text[100];
    char pattern[100];
    int n,m;
    printf("\nEnter the text string: ");
    gets(text);
    printf("\nEnter the pattern string: ");
    gets(pattern);
    n = strlen(text);
    m = strlen(pattern);
    printf("\nString is: ");
    puts(text);
    // for(int i=0; i<n; i++)
    // {
    //     printf("%c",text[i]);
    // }
    printf("\n");
    printf("\nPattern is: ");
    puts(pattern);
    // for(int i=0; i<m; i++)
    // {
    //     printf("%c",pattern[i]);
    // }
    printf("\n");
    //a = {5,3,9,7,5,13,6};
    int res = stringmatching(text,pattern,n,m);
    if(res!=-1)
        printf("\nPosition at which string is matched: %d",res);
    else
        printf("\nNo match.");
}

int stringmatching(char* t, char* p, int n, int m)
{
    int i,j;
    for(i=0;i<n-m;i++)
    {
        j = 0;
        while(j<m && p[j]==t[i+j])
            j++;
        if(j==m)
        {
            return i;
            break;
        } 
    }
    return -1;
}