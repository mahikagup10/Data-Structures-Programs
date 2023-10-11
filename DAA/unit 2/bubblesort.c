#include<stdio.h>

void bubblesort(int* a, int n);

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
    bubblesort(a,n);
    
    printf("\nArray after bubble sorting: ");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }

}

void bubblesort(int* a, int n)
{
    int temp;
    for(int j=0; j< n-1; j++)
    {
        for(int i=0; i<n-1-j; i++)
        {
            if(a[i]>a[i+1])
            {
                temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
            }
        }
    }

}