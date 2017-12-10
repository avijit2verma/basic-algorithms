#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
void main()
{
    int A[50];
    int n,i,z,x;
    int max;int ex; int f,j,key; int k;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&A[i]);
    }
    build_minheap(A,n);
    int pot,y;
    x=1;
    while(x)
    {
    printf("Select one of the following options:\n 1. Maximum\n 2. Extract Max\n 3. Increase Key\n 4. Insert\n 5. Print Max-Priority Queue\n 6. Is in min heap\n");
    scanf("%d",&z);
    switch(z)
    {
        case 1: max=heap_min(A);
                 printf("The min element is = %d\n",max);
                 break;
        case 2: ex=heap_extract_min(A,n);
                 if(ex!=-1)
                 {
                 printf("The extracted element is = %d\n",ex);
                 n--;
                 }
                 break;
        case 3: printf("Enter the index of element whose priority is to be decreased:\n");
                 scanf("%d",&j);
                 printf("Enter the new prority\n");
                 scanf("%d",&key);
                 f=heap_decrease_key(A,j,key);
                 if(f==0)
                 {
                     printf("Operation successful\n");
                 }
                 break;
        case 4: printf("Enter the key to be inserted\n");
                 scanf("%d",&k);
                 n=min_heap_insert(A,n,k);
                 
                 break;
        case 5: printf("The Min-Priority queue is:\n");
                 for (i=1;i<=n;i++)
                 {
                     printf("%d\t",A[i]);
                 }
                 printf("\n");
                 break;
        case 6:  printf("Enter the element\n");
                 scanf("%d",&y);
                 pot=IsInMinHeap(A,n,y);
                 if(pot==1)
                      printf("It is\n");
                 else if(pot==0)
                      printf("It is not\n");
                 break;
       }
       printf("Do you want to continue(1 for yes/ 0 for no)?\n");
       scanf("%d",&x);
       } 

                
    
}










