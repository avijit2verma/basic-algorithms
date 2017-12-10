#include<stdio.h>
int partition(int A[], int p,int r)
{
    int x;
    x=A[r];
    int i,j,temp1,temp2;
    i=p-1;
    for(j=p;j<r;j++)
    {
        if(A[j]<=x)
        {
            i++;
            temp1=A[i];
            A[i]=A[j];
            A[j]=temp1;
        }
   }     
   temp2=A[i+1];
   A[i+1]=A[r];
   A[r]=temp2;
   return (i+1);
}
void quicksort(int A[], int p, int r)
{
    int q;
    if(p<r)
    {
         q=partition(A,p,r);
         quicksort(A,p,q-1);
         quicksort(A,q+1,r);
    }
}
void main()
{
    int A[50];
    int n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
       scanf("%d",&A[i]);
    }
    quicksort(A,0,n-1);
    printf("The sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\n");
}   
