/*  mordern febonn aci 0,1,1 are first three digit and next turm is sum oof pervious three turm
*/ 
#include<stdio.h>
int fibonaci(int n )
{
 int first ,second ,third,retval ;
 if(n==1)
 {
  retval=0;
 }
 else if(n==2)
 {
  retval=1;
  }
 else if (n==3)
 {
   retval=1;
 }
else
{
retval= fibonaci(n-1)+fibonaci(n-2)+fibonaci(n-3);
}
return retval;
}



int main()
{
 int i,n,j,first=0,second=1 ,third=1,sum=2;
 printf("enter the value of n\n");
 scanf("%d",&n );
  sum= fibonaci(n);
 printf("value of nnth term is %d ", sum);
}
