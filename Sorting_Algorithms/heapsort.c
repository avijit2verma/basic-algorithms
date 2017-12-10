#include <stdio.h>
#include <stdlib.h>
int c=0;
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
void max_heapify(int A[],int h,int i)
{
     int l,r,largest,temp;

     l=left(i); c++;
     r=right(i); c++;
     
     if((l<=h)&&(A[l]>A[i]))
     {
          largest=l; c++;
     }
     else
     {
          largest=i; c++;
     }
     if((r<=h)&&(A[r]>A[largest]))
     {
          largest=r; c++;
     }
     if(largest!=i)
     {
          temp=A[i];                   c++;
          A[i]=A[largest];             c++;
          A[largest]=temp;             c++;
          max_heapify(A,h,largest);    c++;
     }
}
void build_maxheap(int A[],int n)
{
    int h;
    h=n; c++;
    int i;
    int start=(n+1/2); c++;
    for(i=(start);i>=0;i--)
    {
         max_heapify(A,h,i); c++;
    }
}
void heapsort(int A[], int n)
{
    build_maxheap(A,n);c++;
    int i,temp;
    for(i=n;i>0;i--)
    {
        temp=A[1];c++;
        A[1]=A[i];c++;
        A[i]=temp;c++;
    
        n=n-1;c++;
        max_heapify(A,n,1);c++;
    }
}
void main()
{
    int A[100];
    int i,n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
         scanf("%d",&A[i]);
    }
    /*int j;
    for(j=0;j<n;j++)
    {
         A[j]=n-j;
    }*/
    heapsort(A,n);
    printf("The sorted array is:\n");
    for(i=1;i<n+1;i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\n");
    printf("Number of instructions= %d\n",c);
}
