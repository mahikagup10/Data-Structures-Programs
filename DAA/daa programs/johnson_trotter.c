#include<stdio.h>
#include<stdlib.h>
#define LtoR 1
#define RtoL 0
//one array of numbers
//one array to store direction
// initialize both arrays

void getpermutation()
{
    // store largest mobile element in lme
    // pos = pos of lme
    //if dir[perm[lme]] == RtoL, swap perm[pos] and perm[pos-1]
    //else swap perm[pos] and perm[pos+1]
    //for i= 1 to n , if perm[i]>lme, check direction, if LtoR, change to RtoL
    int lme = getlargestmobileelement();
    int pos = pos_largestmobile();
}

int getlargestmobileelement()
{
    //int mobile = 0; prevmobile = 0;
    //for 1 to n, check if dir[perm[i]]==LtoR && i!=1, if perm[i]>perm[i=1], mobile = perm[1], prev_mob = mobile
    //if dir[perm[i]]==LtoR && i!=n, mobile = i, prev=mobile
    //return mobile
    int premobile=0;
    int mobile=0;
    for9int i=0;i<n;i++)
    {
        if (9)
        {
            /* code */
        }
        
    }
}

int pos_largestmobile(int perm[], int n, int lme)
{
    //if lme==perm[i], return i
    for(int i=0;i<n;i++)
    {
        if(perm[i]==lme)
            return i;
    }
}

void swap(int *m, int *n)
{
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}

int fact(int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        i = i*(i+1);
    }
    return i;
}

void print_permutation(int n)
{
    int p[n+1];
    int d[n+1];
    //initialize both arrays
    //print array of permutation
    //number of permuations n = fact(n)
    //for(int i=1;i<fact(n);i++)
     //     getonepermutation()
     //     print perm array
    
    for(int i=1; i<n; i++)
    {
        p[i] = i;
        d[i] = RtoL;
        //printf("%d",p[i]);
    }
    for(int i = 1; i<n;i++)
        printf("%d",p[i]);
    printf("\n");
    for(int i=1; i<fact(n); i++)
    {
        //printf("%d",p[i]);
        getpermutation(p,d,fact(n));
        for(int i=1;i<fact(n);i++)
            printf("%d",p[i]);
        printf("\n");

    }

}


int main()
{
    // int p[100];
    // int dir[100];
    int n;
    printf("\nEnter the number of digits:");
    scanf("%d",&n);
    print_permutation(n);

    return 0;
} 