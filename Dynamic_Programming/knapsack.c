#include<stdio.h>
int max(int a, int b)
{
    if(a>=b)
       return a;
    else 
       return b;
}
int knapsack(int W,int val[],int wt[],int n)
{
    int i,w;
    int store[n+1][W+1];
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=W;w++)
        {
             if(i==0||w==0)
                store[i][w]=0;
             else if (w[i-1]<W)
                 store[i][w]=max(val[i-1]+store[i-1][w-wt[i-1]],store[i-1][w]);
             else 
                 store[i][w]=store[i-1][w];
        }
    }
    return store[n][W];
}
void main()
{
   int n,val[20],wt[20],

