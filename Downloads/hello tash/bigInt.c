#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node_tag
	{
		short int data;
		struct node_tag *next;
	}node_type;
	void initialize(node_type **lpptr)
	{
		*lpptr=NULL;
	}
	node_type *insertAtStart(node_type *list_ptr,short int d)
	{
		node_type *nptr;
		nptr=(node_type *)malloc(sizeof(node_type));
		nptr->data=d;
		nptr->next=list_ptr;
		list_ptr=nptr;
		return list_ptr;
	}	
	node_type *insertAtEnd(node_type *list_ptr,short int d)
	{
		node_type *nptr,*ptr;
		nptr=(node_type *)malloc(sizeof(node_type));
		nptr->data=d;
		nptr->next=NULL;
		ptr=list_ptr;
		if(list_ptr==NULL)
		{
			list_ptr=nptr;
		}	
		else
		{
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=nptr;
		}
		return list_ptr;
	}
	node_type *createList(node_type *list_ptr,char num[])
	{
		short int d,i=0;
		while(num[i]!='\0')
		{		
			d=(short int)num[i]-48;
			i++;
			list_ptr=insertAtStart(list_ptr,d);
			
		}
		return list_ptr;
	}
	node_type *traverseList(node_type *list_ptr)
	{
		node_type *nptr;
		nptr=list_ptr;
		while(nptr!=NULL)
		{
			printf("%hd",nptr->data);
			nptr=nptr->next;
		}
		printf("\n");
		return list_ptr;
	}
	node_type *addtion_of_number(node_type *n1,node_type *n2)
	{
		node_type *p1,*p2,*sum;
		short int s=0,c=0;
		initialize(&sum);
		p1=n1;
		p2=n2;
		while(p1!=NULL && p2!=NULL)
		{
			s=(p1->data)+(p2->data)+c;
			c=s/10;
			s=s%10;
			sum=insertAtEnd(sum,s);
			p1=p1->next;
			p2=p2->next;
		}
		while(p1!=NULL)
		{
			s=p1->data+c;
			c=s/10;
			s=s%10;
			sum=insertAtEnd(sum,s);
			p1=p1->next;
		}
		while(p2!=NULL)
		{
			s=p2->data+c;
			c=s/10;
			s=s%10;
			sum=insertAtEnd(sum,s);
			p2=p2->next;
		}
		if(c==1)
		{
			sum=insertAtEnd(sum,c);
		}
		return sum;
	}
	node_type *reverse(node_type *lptr)
	{
		node_type *ptr,*retval=NULL;
		if(lptr->next==NULL)
		{
			retval=lptr;
		}
		else if(lptr!=NULL&&lptr->next!=NULL)
		{
			retval=reverse(lptr->next);
			ptr=lptr->next;
			ptr->next=lptr;
			lptr->next=NULL;
			
		}
		
		return retval;
	}
	node_type *multiplcation(node_type *n1,node_type *n2)
	{
		node_type *p1,*p2,*prod,*ret;
		short int x=0,s=0,c=0;
		initialize(&prod);
		initialize(&ret);
		p1=n1;
		p2=n2;
		short int i=0,j;
		while(p1!=NULL)
		{
			p2=n2;
			initialize(&prod);
			x=p1->data;
			while(p2!=NULL)
			{
				s=(x*p2->data)+c;
				c=s/10;
				s=s%10;
				prod=insertAtEnd(prod,s);
				p2=p2->next;
			}
			while(c==1)
			{
				prod=insertAtEnd(prod,c%10);
				c=c/10;
			}
			p1=p1->next;
			for( j=0;j<i;j++)
			{
				prod=insertAtStart(prod,0);
			}
			i++;
			ret=addtion_of_number(ret,prod);
		}
		return ret;
		
	}
	node_type *subtract(node_type *n1,node_type *n2)
	{
		node_type *p1,*p2,*diff;
		short int d,b=0;
		initialize(&p1);
		initialize(&p2);
		initialize(&diff);
		p1=n1;
		p2=n2;
		while (p1 !=NULL&& p2!=NULL)
		{
			d=(p1->data)-(p2->data)-b;
			
			if(d<0)
			{
				d=d+10;
				b=1;
			}
			else
			{
				b=0;
			}
			diff=insertAtEnd(diff,d);
			p1=p1->next;
			p2=p2->next;
		}
		while(p1!=NULL)
		{
			d=p1->data+b;
			b=d/10;
			d=d%10;
			diff=insertAtEnd(diff,d);
			p1=p1->next;
		}
		return diff;
	}
int main()
{	short int i;
	node_type *num1_ptr,*num2_ptr,*sum,*prod,*diff;
	short int flag=1;
	initialize(&num1_ptr);
	initialize(&num2_ptr);
	initialize(&sum);
	initialize(&prod);
	initialize(&diff);
	char num1[309],num2[309];
	printf("enter  first number ");
	gets(num1);
	num1_ptr=createList(num1_ptr,num1);
	printf("enter second number ");
	gets(num2);
	num2_ptr=createList(num2_ptr,num2);
	
	printf("\n what action perform on number:_\n1.ADD\n2.MULTIPLY\n3.SUBTRACT\n0.EXIT\n");
	while(flag==1)
	{	
		scanf("%hd",&i);
		switch(i)
		{
			
		case 1:	sum=addtion_of_number(num1_ptr,num2_ptr);
			sum=reverse(sum);
			traverseList(sum);
			break;
		case 2:	prod=multiplcation(num1_ptr,num2_ptr);
			prod=reverse(prod);
			traverseList(prod);
			break;
		case 3:	if(strlen(num1)>strlen(num2))
			{
				diff=subtract(num1_ptr,num2_ptr);
				diff=reverse(diff);
				traverseList(diff);
			}
			else if(strlen(num1)==strlen(num2))
			{
				if(num1[0]>num2[0])
				{
					diff=subtract(num1_ptr,num2_ptr);
					diff=reverse(diff);
					traverseList(diff);
				}
				else{
					diff=subtract(num2_ptr,num1_ptr);
					diff=reverse(diff);
					printf("-");
					traverseList(diff);
					}
				}
				else{
					diff=subtract(num2_ptr,num1_ptr);
					diff=reverse(diff);
					printf("-");
					traverseList(diff);
				}
				break;
		case 0:	flag=0;
				break;
			
				
		}
	}
		
}


