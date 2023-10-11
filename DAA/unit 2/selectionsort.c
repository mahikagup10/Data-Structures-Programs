#include<stdio.h>
#include<stdlib.h>

void selectionsort(int* a, int n);

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
    selectionsort(a,n);
    
    printf("\nArray after sorting:");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }

}

void selectionsort(int* a, int n)
{
    int i,j,temp,min;
    for(i=0;i<n;i++)
    {
        min = a[i];
        for(j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                temp = min;
                min = a[j];
                a[j] = temp;
                a[i] = min;
            }
        }
        
    }
}