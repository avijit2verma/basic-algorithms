#include <stdio.h>
#include <limits.h>
int minDistance(int dist[],int V,int Set[])
{
     int min=INT_MAX;
     int min_index,v;
     for(v=0;v<V;v++)
     {
         if((Set[v]==0)&&(dist[v]<=min))
         {
              min=dist[v];
              min_index=v;
         }
     }
     return min_index;
}
int printSol(int dist[],int V)
{
     int i;
     printf("Vertex --> Distance from source\n");
     for(i=0;i<V;i++)
     {
         printf("%d\t-->\t%d\n",i,dist[i]);
     }
}
void dijkstra(int graph[15][15],int V,int src)
{
     int dist[V],i,v;
     int Set[V];
     for(i=0;i<V;i++)
     {
         dist[i]=INT_MAX;
         Set[i]=0;
     }
     dist[src]=0;
     int count;
     for(count=0;count<V-1;count++)
     {
         int u=minDistance(dist,V,Set);
         Set[u]=1;
         for(v=0;v<V;v++)
         {
              if((!Set[v])&&(graph[u][v])&&(dist[u]!=INT_MAX)&&(dist[u]+graph[u][v]<dist[v]))
                     dist[v]=dist[u]+graph[u][v];
         }
      }
      printSol(dist,V);
}
void main()
{
      int V,E,i,j;
      int graph[15][15];
      
      printf("Enter the no. of vertices\n");
      scanf("%d",&V);
      printf("Enter the no. of edges\n");
      scanf("%d",&E);
      for(i=0;i<V;i++)
      {
          for(j=0;j<V;j++)
          {
               graph[i][j]=0;
          }
      }
    int src,dest;
    printf("Enter the graph edges(source,destination,weight)\n");
    for(i=0; i<E; i++)
    {
        printf("Edge %d:\n",i+1);
        printf("source = ");
        scanf("%d",&src);
        printf("destination = ");
        scanf("%d",&dest);
        printf("weight = ");
        scanf("%d",&graph[src][dest]);
        printf("\n"); 
    }
    dijkstra(graph,V,0);
}     
