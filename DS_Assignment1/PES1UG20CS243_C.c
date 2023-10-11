int main()
{
    FILE *dfsptr = fopen("outdfs.txt","w");
    FILE *bfsptr = fopen("outbfs.txt","w");
    FILE *pf= fopen ("input.txt", "r"); 
    if (pf == NULL)
        return 0;
    int n=10; //number of rows and columns
    int a[n][n]; //stores the layout matrix
    int b[2][2];//stores the coordinate
    int visited[n*n];
    NODE* V[n*n];
    for(int i=0;i<n*n;i++)
    {
        V[i]=NULL;
    }   
    //Reading the coordinates (start and end)
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        { 
           fscanf(pf, "%d", b[i] + j);
        }  
    }
    //Reading the matrix 
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        { 
            fscanf(pf, "%d", a[i] + j);
        }    
    }
    printf("\nGiven matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }
    //Initializing all the elements of the visited array to 0.
    for(int i=0;i<n*n;i++)
    {
        visited[i]=0;
    }
    int x = b[0][0],y = b[0][1], x1 = b[1][0], y1 = b[1][1];
    //x and y are for initial and x1 and y1 are for final
    createAdjList(V,n,a); //creating adjacency list
    printf("\nAdjacency list: \n");
    display(V,n); //displaying the adjacency list
    dfs(V,visited,y*n+x,x1,y1, dfsptr);
    for(int i=0;i<n*n;i++)
    {
        visited[i]=0;
    }
    bfs(V,n,visited,y*n+x,x1,y1,bfsptr);
    if(flag==1)
        printf("\nPath exists");
    else
        printf("\nPath does not exist");
}
