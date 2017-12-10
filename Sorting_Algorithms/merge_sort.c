#include<stdio.h>
int c=0;
void merge(int A[], int p,int q,int r)
{
   int i,j,n1,n2;       
   n1=q-p+1;           c++;
   n2=r-q;             c++;
   int L[n1+1];        c++;
   int R[n2+1];
   for(i=0;i<(n1);i++)  
        { L[i]=A[p+i]; c++; }
   for(j=0;j<(n2);j++)
        { R[j]=A[q+1+j]; c++;}
   i=0; j=0;             
   L[n1]=25000;          c++;
   R[n2]=25000;          c++;
   int k;
   for(k=p;k<=r;k++)
   {     c++;
         if(L[i]<=R[j])
         {
              A[k]=L[i]; c++;
              i++;       c++;
         }
         else if(L[i]>R[j])
         {
              A[k]=R[j]; c++;
              j++;       c++;
         }
   }
}

void merge_sort(int A[], int p, int r)
{
    int q;               c++;
    if(p<r)             
    {     c++;
          q=(p+r)/2;     c++; 
          merge_sort(A,p,q);    c++;
          merge_sort(A,q+1,r);  c++;
          merge(A,p,q,r);       c++;
    }
}
void main()
{
    int A[100];
    int i,n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the array\n");
    for (i=0;i<n;i++)
          scanf("%d",&A[i]);
    
    merge_sort(A,0,n-1);        
    
    printf("The sorted array is\n");
    for (i=0;i<n;i++)
        printf("%d\t",A[i]);
    printf("\n");
    printf("No. of instructions = %d\n",c);
    
}
