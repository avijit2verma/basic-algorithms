#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int source, destination, weight;
};
struct Graph
{
    int V,E;
    struct Edge* edge;
};
struct Graph* create_graph(int V, int E)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->E=E;
    
    graph->edge= (struct Edge*)malloc(graph->E * sizeof(struct Edge));
    return graph;
}
struct subset
{
    int parent, rank;
};
int find(struct subset Subsets[], int i)
{
    if(Subsets[i].parent != i)
          Subsets[i].parent=find(Subsets, Subsets[i].parent);
    return Subsets[i].parent;
}
void Union(struct subset Subsets[], int x, int y)
{
     int xroot= find(Subsets,x);
     int yroot= find(Subsets,y);
     
     if(Subsets[xroot].rank<Subsets[yroot].rank)
            Subsets[xroot].parent=yroot;
     else if(Subsets[xroot].rank>Subsets[yroot].rank)
            Subsets[yroot].parent=xroot;
     else 
     {
           Subsets[yroot].parent=xroot;      
           Subsets[xroot].rank++;
     }
}

int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
void kruskal(struct Graph* graph)
{
       int V=graph->V;
       struct Edge results[V];
       int e=0,i=0;
       int v;
       qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); // in built

       struct subset* Subsets=(struct subset*)malloc(V * sizeof(struct subset)); 
       for(v=0;v<V;v++)
       {
            Subsets[v].parent=v;
            Subsets[v].rank=0;
       }
       while(e<V-1)
       {
            struct Edge new_edge=graph->edge[i++];
            int x= find(Subsets, new_edge.source);
            int y= find(Subsets, new_edge.destination);
            
            if(x != y)
            {
                 results[e++]=new_edge;
                 Union(Subsets,x,y);
            }
       }
       printf("The minimum spanning tree is :\n");
       for(i=0;i<e;i++)
       {

               printf("Edge: %d-%d with weight = %d\n",results[i].source,results[i].destination,results[i].weight);
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

    struct Graph* graph = create_graph(V, E);
    
    printf("Enter the graph edges(source,destination,weight)\n");
    for(i=0; i<E; i++)
    {
        printf("Edge %d:\n",i+1);
        printf("source = ");
        scanf("%d",&graph->edge[i].source);
    
        printf("destination = ");
        scanf("%d",&graph->edge[i].destination);
        
        printf("weight = ");
        scanf("%d",&graph->edge[i].weight);
        printf("\n");
    }  
      
    /*/ add edge 0-1
    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = 10;
 
    // add edge 0-2
    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 6;
 
    // add edge 0-3
    graph->edge[2].source = 0;
    graph->edge[2].destination = 3;
    graph->edge[2].weight = 5;
 
    // add edge 1-3
    graph->edge[3].source = 1;
    graph->edge[3].destination = 3;
    graph->edge[3].weight = 15;
 
    // add edge 2-3
    graph->edge[4].source = 2;
    graph->edge[4].destination = 3;
    graph->edge[4].weight = 4;*/
 
    kruskal(graph);
}         
     
