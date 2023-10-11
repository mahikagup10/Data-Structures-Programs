#include<stdio.h>

void insertionsort(int* a, int n);

int main()
{
    int a[100];
    int n;
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
    insertionsort(a,n);
    
    printf("\nArray after insertion sorting: ");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }

}

void insertionsort(int* a, int n)
{
    int ele,i,j;
    for(i=1; i< n; i++)
    {
        ele = a[i];
        j = i-1;
        while(j>=0 && a[j]>ele)
        {
            
        }
    }

}