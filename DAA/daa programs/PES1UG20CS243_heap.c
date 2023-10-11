// Name: Mahika Gupta
// SRN: PES1UG20CS243
#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header
 *as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size) 
{
    heap->size = 0;
    heap->max_size = max_size;
    heap->arr = (int*)malloc(max_size*sizeof(int)); 
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr) 
{
    if(heap->size==0)
    {
        heap->arr[heap->size] = key;
        heap->size++;
    }
    else
    {
        while(heap->size<heap->max_size)
        {
            heap->size++;
            heap->arr[heap->size] = key;
            while(heap->arr[(heap->size-1)/2]<key && ++*count_ptr)
            {
                int c = heap->size;
                int p = (c-1)/2;
                heap->arr[c] = heap->arr[p];
                heap->arr[p] = key;
                c = p;
                p = (c-1)/2;
                //*++count_ptr;
            }
        }
    }
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr) 
{
    if(heap->size==0)
    {
        return -1;
    }
    else
    {
        int max = heap->arr[0];
        heap->arr[0] = heap->arr[heap->size];
        heap->size--;
        int p,c,ele;
        for(int i = 1; i< heap->size; i++)
        {
            ele = heap->arr[i];
            c = i;
            p = (c-1)/2;
            while(c>0 && heap->arr[p]<ele && ++*count_ptr)
            {
                //++*count_ptr;
                heap->arr[c] = heap->arr[p];
                c = p;
                p = (c-1)/2;
            }
            heap->arr[c] = ele;

        }
        return max;
    }
}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr) 
{
    if(heap->size ==0)
        return -1;
    else
    {
        int p;
        for(int i = 0; i< heap->size; i++)
        {
            
            p = heap->arr[i];
            if(p==key && ++*count_ptr)
            {
                //++*count_ptr;
                return key;
            }
                
        }
    }
    return -1;
}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr) 
{
    if(heap->size==0)
        return -1;
    int max = heap->arr[0];
    for(int i=1; i<5; i++)
    {
        if(heap->arr[i]>max && ++*count_ptr)
        {
            max = heap->arr[i];
            //++*count_ptr;
        }
    }
    //printf("%d",min);
    return max;
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr) 
{
    if(heap->size==0)
        return -1;
    int min = heap->arr[0];
    for(int i=1; i<5; i++)
    {
        if(heap->arr[i]<min && ++*count_ptr)
        {
            min = heap->arr[i];
            //++*count_ptr;
        }
    }
    //printf("%d",min);
    return min;
}

// Clears the heap for reuse
void clear_heap(heap_t *heap) 
{
    heap->size = 0;
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap) 
{
    heap->arr = NULL;
    free(heap->arr);
}

