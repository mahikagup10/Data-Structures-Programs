#include<stdio.h>
 // best case and average - nlogn
 // worst case - n^2
 // partitions subarray by using first element as pivot
 // partition function - returns split position

void quicksort(int* a, int l, int r);
int partition(int* a, int l, int r);


int main()
{
    int a[100];
    int r = 8;
    quicksort(a,0,r);
}

void quicksort(int* A,int l,int r)
{
    int s;
    if(l<r)
    {
        s = partition(A,l,r);           
        quicksort(A,l,s-1);
        quicksort(A,s+1,r);

    }
}

int partition(int* A,int l,int r)
{
    int p;
    p = A[l];
    int i,j;
    i = l;
    j=r+1;
    do
    {
        do
        {
            i = i+ 1;
        } while (A[i]<p);
        do
        {
            j = j - 1;
        } while (A[i]>p);
        
    }while(i<j);

}