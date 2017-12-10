#include<stdio.h>
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
    int start=(n/2); c++;
    for(i=(start);i>=1;i--)
    {
         max_heapify(A,h,i); c++;
    }
}
int heap_max(int A[])
{
   return A[1];
}
int heap_extract_max(int A[],int h)
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
   max_heapify(A,h,1);
   return max;
}
int heap_increase_key(int A[],int i,int key)
{
   if (key<A[i])
   {
       printf("new key smaller then current key\n");
       return -1;
   }
   int temp;
   A[i]=key;
   while((i>1)&&(A[parent(i)]<A[i]))
   {
       temp=A[i];
       A[i]=A[parent(i)];
       A[parent(i)]=temp;
       i=parent(i);
   }
   return 0;
}
int max_heap_insert(int A[], int h, int key)
{
   int w;
   h++;
   A[h]=-5000;
   w=heap_increase_key(A,h,key);
   if (w==0)
     return h;
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
    build_maxheap(A,n);
    x=1;
    while(x)
    {
    printf("Select one of the following options:\n 1. Maximum\n 2. Extract Max\n 3. Increase Key\n 4. Insert\n 5. Print Max-Priority Queue\n");
    scanf("%d",&z);
    switch(z)
    {
        case 1: max=heap_max(A);
                 printf("The maximum element is = %d\n",max);
                 break;
        case 2: ex=heap_extract_max(A,n);
                 if(ex!=-1)
                 {
                 printf("The extracted element is = %d\n",ex);
                 n--;
                 }
                 break;
        case 3: printf("Enter the index of element whose priority is to be increased:\n");
                 scanf("%d",&j);
                 printf("Enter the new prority\n");
                 scanf("%d",&key);
                 f=heap_increase_key(A,j,key);
                 if(f==0)
                 {
                     printf("Operation successful\n");
                 }
                 break;
        case 4: printf("Enter the key to be inserted\n");
                 scanf("%d",&k);
                 n=max_heap_insert(A,n,k);
                 
                 break;
        case 5: printf("The Max-Priority queue is:\n");
                 for (i=1;i<=n;i++)
                 {
                     printf("%d\t",A[i]);
                 }
                 printf("\n");
                 break;
       }
       printf("Do you want to continue(1 for yes/ 0 for no)?\n");
       scanf("%d",&x);
       } 

                
    
}

