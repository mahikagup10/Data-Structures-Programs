#include<stdio.h>
#include<stdlib.h>
int flag=1; //checking if path exists or not
typedef struct node
{
    int vertex;
    int vid; //vertex_id
    int row;
    int col;
    struct node* next;
}NODE;