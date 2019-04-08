#include<stdio.h>
int fact(int i)
{
	int j,retval=1;
  for(j=1;j<=i;j++)
	{
	retval=retval*j;
	}
 return retval;
}
