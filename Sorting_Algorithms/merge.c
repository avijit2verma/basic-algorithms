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
   
   
void main()
{
   int A[50];
   int m,n;
   printf("Enter the size of first array\n");
   scanf("%d",&m);
   printf("Enter the size of the second array\n");
   scanf("%d",&n);
   printf("Enter the first array\n");
   int i,j;
   for (i=0;i<m;i++)
       scanf("%d",&A[i]);
   printf("Enter the second array\n");
   for (j=m;j<m+n;j++)
       scanf("%d",&A[j]);
   
   merge(A,0,m-1,m+n-1);   c++;
   
   printf("The merged array is\n");
   for (i=0;i<m+n;i++)
       printf("%d\t",A[i]);
   printf("\n");
   printf("No. of instructions = %d\n",c);
}
