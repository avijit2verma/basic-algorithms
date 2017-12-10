#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int c=0;
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};
struct AdjList
{
    struct AdjListNode* head;
};
struct Graph
{
    int V;
    struct AdjList* array;
};
struct AdjListNode* create_new_node(int dest,int weight)
{
    struct AdjListNode* newNode;
    newNode=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest=dest;
    newNode->weight=weight;
    newNode->next=NULL;
    return newNode;
}
struct Graph* create_graph(int V)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->array=(struct AdjList*)malloc(V*sizeof(struct AdjList));
    int i;
    for(i=1;i<=V;i++)
    {
        graph->array[i].head=NULL;
    }
    return graph;
}
void add_edge(struct Graph* graph, int src, int dest, int weight)
{
    struct AdjListNode* newNode=create_new_node(dest,weight);
    newNode->next=graph->array[src].head;
    graph->array[src].head=newNode;

    newNode = create_new_node(src,weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 1; v <= graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
int parent(int i)
{
    return ((i)/2); c++;
}
int left(int i)
{
    return (i*2); c++;
}
int right(int i)
{
    return ((i*2)+1); c++;
}
void min_heapify(int A[],int h,int i)
{
     int l,r,smallest,temp;

     l=left(i); c++;
     r=right(i); c++;
     
     if((l<=h)&&(A[l]<A[i]))
     {
          smallest=l; c++;
     }
     else
     {
          smallest=i; c++;
     }
     if((r<=h)&&(A[r]<A[smallest]))
     {
          smallest=r; c++;
     }
     if(smallest!=i)
     {
          temp=A[i];                   c++;
          A[i]=A[smallest];             c++;
          A[smallest]=temp;             c++;
          min_heapify(A,h,smallest);    c++;
     }
}
void build_minheap(int A[],int n)
{
    int h;
    h=n; c++;
    int i;
    int start=(n/2); c++;
    for(i=(start);i>=1;i--)
    {
         min_heapify(A,h,i); c++;
    }
}
int heap_min(int A[])
{
   return A[1];
}
int heap_extract_min(int A[],int h)
{
   if (h<1)
   {  
        printf("Error: Heap Underflow\n");
        return -1;
   }
   int max;
   max=A[1];
   A[1]=A[h];
   h--;
   min_heapify(A,h,1);
   return max;
}
int heap_decrease_key(int A[],int i,int key)
{
   if (key>A[i])
   {
       
       return -1;
   }
   int temp;
   A[i]=key;
   while((i>1)&&(A[parent(i)]>A[i]))
   {
       temp=A[i];
       A[i]=A[parent(i)];
       A[parent(i)]=temp;
       i=parent(i);
   }
   return 0;
}
int min_heap_insert(int A[], int h, int key)
{
   int w;
   h++;
   A[h]=5000;
   w=heap_decrease_key(A,h,key);
   if (w==0)
     return h;
}          
int IsInMinHeap(int A[],int h, int ele)
{
    int i;
    for(i=1;i<=h;i++)
    {
         if (A[i]==ele)
            return 1;
    }
    return 0;
} 
void PrimMST(struct Graph* graph)
{
    int V = graph->V;// Get the number of vertices in graph
    int parent[V];   // Array to store constructed MST
    int key[V];      // Key values used to pick minimum weight edge in cut
 
    // minHeap represents set E
    int Q[V]; 
    int v;
    // Initialize min heap with all vertices. Key value of
    // all vertices (except 0th vertex) is initially infinite
    for (v = 2; v <= V;v++)
    {
        parent[v] = -1;
        key[v] = INT_MAX;
        Q[v] = v;
        
    }
 
    // Make key value of 0th vertex as 0 so that it
    // is extracted first
    key[1] = 0;
    Q[1] = 1;
    
 
    // Initially size of min heap is equal to V
   
    v=V;
    // In the followin loop, min heap contains all nodes
    // not yet added to MST.
    while (v>1)
    {
        // Extract the vertex with minimum key value
        int u=heap_extract_min(Q,v);
 
        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their key values
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int x = pCrawl->dest;
            // If v is not yet included in MST and weight of u-v is
            // less than key value of v, then update key value and
            // parent of v
            if ((IsInMinHeap(Q,v,x)) && (pCrawl->weight < key[x]))
            {
                
                parent[x] = u;
                heap_decrease_key(Q, x, pCrawl->weight);
            }
            pCrawl = pCrawl->next;
        }
        v--;
    }
 
    // print edges of MST
    int i;
    for (i=2;i<=V;i++)
    {
        printf("%d - %d\n", parent[i], i);
    }
}
 
void main()
{
    int V;  // Number of vertices in graph
    int E;  // Number of edges in graph
    int i;
    printf("Enter the number of vertices\n");
    scanf("%d",&V);
    printf("Enter the number of edges\n");
    scanf("%d",&E);
    
    struct Graph* graph=create_graph(V);
    int src,dest,weight;
    printf("Enter the graph edges(source,destination,weight)\n");
    for(i=0; i<E; i++)
    {
        printf("Edge %d:\n",i+1);
        printf("source = ");
        scanf("%d",&src);
        printf("destination = ");
        scanf("%d",&dest);
        printf("weight = ");
        scanf("%d",&weight);
        add_edge(graph,src,dest,weight);
        printf("\n"); 
    }
    printf("The graph is:\n");
    printGraph(graph);
    printf("The minimum spanning tree is:\n"); 
    PrimMST(graph);
}
