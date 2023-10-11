#include<stdio.h>
#include<time.h>
#include<limits.h>

void insertion_sort(int* a,int n);
double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = end.tv_sec - start.tv_sec;
    t = t + (end.tv_nsec-start.tv_nsec)*0.000000001;
    return t;
}


int main()
{
    struct timespec start,end;
    int n;
    int a[100];
    printf("enter size of array\n");
    scanf("%d",&n);
    //read_arr(a[10], n);
    a[0] = INT_MIN;
    for(int i=1; i<=n; i++)
    {
        printf("enter element %d: ", i);
        scanf("%d", &a[i]);
        //printf("\n");
    }
    printf("\n before sorting:\n");
    for(int i=1; i<=n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    //insertion_sort(a[100],n);
    //printf("\n after sorting:\n");

    clock_gettime(CLOCK_REALTIME, &start);
    
    //printf("\n after sorting:\n");
    insertion_sort(a,n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Time elapsed: %lf\n", time_elapsed(start,end));


    return 0;
    
}

void insertion_sort(int* a,int n)
{
    
    for(int i=1; i<=n; i++)
    {
        int ele = a[i];
        int j = i-1;

        while(a[j]>ele)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = ele;
    }
    //printf("\n after sorting:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", a[i]);
    }
    
}