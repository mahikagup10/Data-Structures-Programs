void append(NODE *V[],int source,int dest,int row,int col){
	NODE *temp=(NODE*)malloc(sizeof(NODE));
	temp->vertex=dest;
    temp->vid=row;
    temp->row=row;
    temp->col=col;
	temp->next=NULL;
    temp->next=V[source];
	V[source]=temp;	
}
void createAdjList(NODE *V[],int n,int a[n][n]){
    //function to create adjacency list
    append(V,0,0,0,0); //adding the starting point to the vertex structure
    for(int i =0;i<n;i++){
       for(int j=0;j<n;j++){
           if(i!=n-1  && a[i][j]==a[i+1][j] && a[i][j] ==0)
           {
               //i variable is for adding the vertex in the right direction
               append(V,i*n+j,(i+1)*n+j,i+1,j);
           }
           if(j!=n-1 && a[i][j]==a[i][j+1] && a[i][j]==0)
           {
               //j variable is for adding the vertex in the downward direction
               append(V,i*n+j,i*n+j+1,i,j+1);   
           }   
       }
    }
}
void dfs(NODE *V[],int visited[],int cv,int x1,int y1, FILE* dfsptr)
{    //Take vertex, visited, source node and the final coordinates
    visited[cv]=1; 
	NODE *p=V[cv];
	while(p!=NULL)
	{   if(p->row==x1 && p->col==y1){
            flag=1;
            fprintf(dfsptr,"%d %d\n",p->row,p->col);
            break;
    }
		if(visited[p->vertex]==0)
        {   fprintf(dfsptr,"%d %d\n",p->row,p->col);
			dfs(V,visited,p->vertex,x1,y1, dfsptr);  
        }
        p=p->next;
	}
}
void display(NODE *V[],int n)
{
	NODE *p;
	for(int i=0;i<n*n;i++)
	{
		p=V[i]; //vertex
		printf("%d-->",i);
		while(p!=NULL)
		{
			printf("%d->",p->vertex);
			p=p->next;
		}
		printf("NULL\n");
	}
}
void bfs(NODE* V[],int n,int visited[],int source,int col,int row, FILE *bfsptr)
{
	int q[n*n];//declaring queue
	int f=0,r=-1;//Initializing queue content
	q[++r]=source;
	visited[source]=1;
	int v;
	while(f<=r)
	{
		v=q[f++];
		NODE *p=V[v]; //initialize the vertex to a node
		while(p!=NULL){
            fprintf(bfsptr,"%d %d \n",p->row,p->col);
			if(!visited[p->vertex]){
				q[++r]=p->vertex;
				visited[p->vertex]=1;
			}
			p=p->next;
		}
	}
}