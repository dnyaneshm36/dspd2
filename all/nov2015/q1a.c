/* fjnd sum upto n th term such that 1+2*3+4*5*6+.......upto n th turm;d*/
#include<stdio.h>
int main()
{
 int i=1, n, j=1 , count=1,sum=0,term;
printf (" enter the value of n \n ");
scanf("%d",&n);

	 for (i=1;i<=n ;i++)
	{
	  
		term=1;
		for(j=0 ; j< i; j++)
		{
		 term=count*term;
		 count++;

		}
	  sum=sum+term;
	}
printf("value of sum is %d and term is %d",sum , term);
}
