#include<stdlib.h>
#include "header.h"
#include<limits.h>

// ANY STATIC FUNCTIONS ARE UP HERE


static void swap(airport_t* a, airport_t* b)
{
    airport_t t;
    t = *a;
    *a = *b;
    *b = t;
}

static int partition(int n,int (*predicate_func)(const airport_t *, const airport_t *),airport_t airport_list[n],int low,int high)
{
    int i = low-1;
    airport_t pivot = airport_list[high];

    for(int j= low; j<=high-1; j++)
    {
        if(predicate_func(&airport_list[j],&pivot))
        {
            i++;
            swap(&airport_list[i],&airport_list[j]);
        }
    }

    swap(&airport_list[i + 1], &airport_list[high]);
    return (i + 1);
}

static void quicksort(int n,int (*predicate_func)(const airport_t *, const airport_t *),airport_t airport_list[n], int low, int high)
{
    int p;
    if(low<high)
    {
        p = partition(n,predicate_func, airport_list, low, high);
        quicksort(n,predicate_func, airport_list,low,p-1);
        quicksort(n,predicate_func,airport_list,p+1,high);
    }
}


static int find_path(int s, int d, int* v, int n, const connection_t connections[n][n], int* flights)
{
    v[s] = 1;
	for(int k = 0; k<n; k++)
	{
		if(connections[s][k].distance!=INT_MAX && connections[s][k].time!=INT_MAX && connections[s][k].distance!=0 && connections[s][k].time!=0 && !v[k])
		{
            flights++;
			if((k==d) || find_path(k,d,v,n,connections,flights))
				return 1;	
		}
	}
    --flights;
	return 0;
}


static int* shift_table(const char* p)
{
    int size = 256;
    int* table = malloc(size*sizeof(int));
    int i=0,length =0;
    while(p[i]!='\0')
    {
        length++;
        i++;
    }   

    for(int j=0; j<size; j++)
        table[j] = length;

    for(int k=0; k<length-1; length++)
        table[p[k]] = length-1-k;

    return table;
}

static void create_edgelist(int n,const connection_t connections[n][n],pair_t elist[],int* edgecount)
{
    // pair_t* elist[n-1];
    // int edgecount = 0;
    for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(connections[i][j].time!=INT_MAX)
			{
				elist[*edgecount].first=i;
				elist[*edgecount].second=j;
				//elist[edgecount].weight=wt[i][j];
				(*edgecount)++;
			}
		}
	}
    //return elist[n-1];
}

static void sortedges(int n, pair_t elist[],const connection_t connections[n][n],int edgecount)
{
	for(int i=0;i<edgecount-1;i++)
		for(int j=0;j<edgecount-i-1;j++)
			if(connections[elist[j].first][elist[j].second].time > connections[elist[j+1].first][elist[j+1].second].time)//(elist[j]>elist[j+1])
			{
				pair_t temp;
				temp=elist[j];
				elist[j]=elist[j+1];
				elist[j+1]=temp;
			}
       // return elist;
}

static int find(int parent[],int i)
{
	while(i!=parent[i])
		i=parent[i];
	return i;
}

static int unionf(int parent[],int u,int v)
{
	if(u!=v)
	{
		if(u<v)
			parent[v]=u;
		else
			parent[u]=v;
		return 1;
	}
	return 0;
}

static int kruskal(int n, pair_t elist[], int et[][2],const connection_t connections[n][n])
{
    int k=-1;
	int edgecount=0;
	int u,v;
	int parent[n];
	
	int treeWeight=0;
	
	for(int i=0;i<n;i++)
		parent[i]=i;
	
	while(edgecount<n-1)
	{
		k++;
		u=find(parent,elist[k].first);
		v=find(parent,elist[k].second);
		
		if(unionf(parent,u,v))
		{
			et[edgecount][0]=elist[k].first;
			et[edgecount][1]=elist[k].second;
			treeWeight+=connections[elist[k].first][elist[k].second].time;
			edgecount++;
		}	
	}
	return treeWeight;
}

static int minDistance(int n,int dist[], int sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int i = 0; i < n; i++)
        if (sptSet[i] == 0 && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }   
 
    return min_index;
}


// YOUR SOLUTIONS BELOW

int q1(int n, const connection_t connections[n][n])
{
    int flights=0;
    int i=0,j=0,t;
    int v[n];
    for(int k=0; k<n; k++)
        v[k] = 0;

    while(i<n)
    {
        while(j<n)
        {
            if(i!=j)
            {
                t = find_path(i,j,v,n,connections,&flights);
                    if(t==0)
                        return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}



int q2(const airport_t *src, const airport_t *dest, int n, int k,
       const connection_t connections[n][n])
{
    int flights=0;
    int t;
    int v[n];
    for(int k=0; k<n; k++)
        v[k] = 0;

    t = find_path(src->num_id,dest->num_id,v,n,connections,&flights);
    if(t)
	{
        if(flights>k)
            return 0;
        else
            return 1;
    }
    else 
        return 0;
}

int q3(const airport_t *src, int n, const connection_t connections[n][n])
{
    int flights=0;
    int i=0,j=0,t;
    int v[n];
    for(int k=0; k<n; k++)
        v[k] = 0;

    while(i<n)
    {
        while(j<n)
        {
            if(i!=j)
            {
                t = find_path(j,i,v,n,connections,&flights);
                    if(t==0)
                        return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *),airport_t airport_list[n])
{
    int low = 0, high = n-1;
    quicksort(n,predicate_func,airport_list,low,high);
}

pair_t q5(int n, airport_t airports[n])
{
    pair_t ans = {-1, -1};
    int length = 0;
    int temp_length = 0;
    int m,l;

    for(int i=0; i<n-1; i++)
    {    for(int j=i+1; j<n; j++)
        {
            temp_length = 0;
            for(int k=0; airports[i].airport_name[k]==airports[j].airport_name[k] && airports[i].airport_name[k]!=0 && airports[j].airport_name[k]!=0; k++)
                temp_length++;
            if(temp_length>length)
            {
                length = temp_length;
                m = i;
                l = j;
            }
                
        }    
    }
    if(length==0)
        return ans;

    ans.first = airports[m].num_id;
    ans.second = airports[l].num_id;
    return ans;
}

int q6(int n, int amount, const int entry_fee[n])
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid = (low+high)/2;

        if (entry_fee[mid] == amount)
            return mid+1;

        if (entry_fee[mid] < amount)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(amount>entry_fee[high])
        return n;
    else
        return 0;
}


void q7(int n, const char *pat, int contains[n], const airport_t airports[n])
{
    int* table = shift_table(pat);
    int k=0,lp=0,lt,j,m;   //lp - length of pattern string
    for(int i=0;i<n;i++)    //initialise contains array
        contains[i] = 0;
    while(pat[k]!='\0')
    {
        lp++;
        k++;
    }   
    
    for(int i=0; i<n; i++)
    {
        lt=0;
        j=0;
        while(airports[i].airport_name[j]!='\0')
        {
            ++lt;
            j++;
        }   
        int l=lp-1;
        while(l<lt)
        {
            m=0;
            while(m<=l && airports[i].airport_name[l-m]==pat[lp-1-m])
                m++;
            if(m==lp)
            {
                //int p = l-lp+1;
                contains[i] = 1;
                l = lt;
            }
            else
                l = l + table[airports[i].airport_name[l]];
        }
    }
}

int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{
    int cost=0;
    int length=INT_MAX;
    for(int i=0; i<n-1;i++)
        trip_order[i] = -1;
    for(int i=0; i<n; i++)
    {    for(int j=0; j<n; j++)
        {    if(connections[i][j].distance!=INT_MAX && connections[i][j].distance!=0 && connections[j][i].distance!=INT_MAX && connections[j][i].distance!=0)
            {
                
                for(int k=0; k<n; k++)
                {
                    if(k!=i && k!=j && connections[k][j].distance!=INT_MAX && connections[k][j].distance!=0 && connections[i][k].distance!=INT_MAX && connections[i][k].distance!=INT_MAX)
                    {
                        length = connections[k][j].distance;
                        if(connections[k][j].distance<=length)
                        {
                            length = connections[k][j].distance;
                            trip_order[i] = i;
                            trip_order[j] = j;
                            trip_order[k] = k;
                        }
                        
                    }

                }
            }
        }

    }
    for(int i=0; i<n-2; i++)
    {
        if(trip_order[i]=-1)
        {
            return -1;
        }
        else
            cost= cost+ connections[i][i+1].distance;
    }
        
    return cost;
}

int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
    int edgecount = 0;
    create_edgelist(n,connections,edges,&edgecount);
    sortedges(n,edges,connections,edgecount);
    int treeWeight;
    int et[n-1][2];
    treeWeight=kruskal(n,edges,et,connections);

    return treeWeight;
}

void q10(int n, int k, const airport_t *src,
const connection_t connections[n][n], const int destinations[k],
         int costs[k])
{
    int dist[n];    //shortest dist from src to i
    int sptSet[n];  //1 if node is included in shortest path, 0 otherwise
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src->num_id] = 0;

    for(int j=0; j<n-1; j++)
    {
        int u = minDistance(n,dist, sptSet);  //minimum distance vertex
        sptSet[u] = 1;
        for (int k = 0; k < n; k++)
            if (!sptSet[k] && connections[u][k].time && dist[u] != INT_MAX && dist[u] + connections[u][k].time < dist[k])
                dist[k] = dist[u] + connections[u][k].time;
    }
    
    for(int i=0; i<k; i++)
        costs[i] = dist[destinations[i]];

}

