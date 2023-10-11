// with sentinel
#include<stdio.h>
#include<stdlib.h>

int sequentialsearch(int* a, int n, int key);

int main()
{
    int a[100];
    int n, key, ans;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nArray is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    //a = {5,3,9,7,5,13,6};
    printf("\nEnter element to search: ");
    scanf("%d",&key);
    ans = sequentialsearch(a,n,key);
    if(ans==1)
        printf("\nFound.");
    else
        printf("\nNot Found.");
    printf("\nArray after searching:");
    for(int i=0; i<=n; i++)
    {
        printf("%d\t",a[i]);
    }

}

int sequentialsearch(int* a, int n, int key)
{
    a[n] = key; 
    int i = 0;
    while(a[i]!=key)
        i++;
    if(i<n)
        return 1;
    else 
        return 0;
    // for(int i=0; i<n; i++)
    // {
    //     if(a[i]==key)
    //         return 1;
    // }
    // return 0;
}