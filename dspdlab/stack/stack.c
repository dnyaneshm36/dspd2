#include<stdio.h>
#include<stdlib.h>
typedef enum {FAILURE,SUCCESS}status_code;
typedef struct node_tab
{
   int data;
   struct node_tab* next ;
}node_type;
 typedef struct stack_tag 
 {
   node_type* top;
 }stack_type;
 
 
 void initialization(stack_type *sptr)
 {
   sptr->top=NULL;
 }
  
  status_code push (stack_type *sptr,int d)
  {
   node_type * nptr;
   status_code ret_val=SUCCESS;
   nptr= (node_type *)malloc(sizeof(node_type));
	   if(nptr==NULL)
	   {
		 ret_val= FAILURE;  
	   }
	   else
	   {
	      	if(sptr->top==NULL)
	      	{
			 nptr->data=d;
			 sptr->top=nptr;	      	
	      	}
	      	else
	      	{
	          nptr->data=d;
	          nptr->next=sptr->top;
	          sptr->top=nptr;
	      	}
	      ret_val=SUCCESS;
	   }
	 return ret_val;
  }
  
  
  status_code pop(stack_type *sptr,int *dptr)
  {
   node_type *nptr;
   status_code ret_val=SUCCESS;
   	   if(nptr==NULL)
	   {
		 ret_val= FAILURE;  
	   }
	   else
	   {
	      	if(sptr->top==NULL)
	      	{
	      	 printf("\nstack is empty\n");
	      	}
	      	else
	      	{
	      		nptr=sptr->top;
			    *dptr=(sptr->top)->data;
			 	sptr->top=(sptr->top)->next;
			 	free(nptr);
	      	}
	      ret_val=SUCCESS;
	   }
	 return ret_val;
   
  }
  	node_type *traverseList(node_type *list_ptr)
	{
		node_type *nptr;
		nptr=list_ptr;
		while(nptr!=NULL)
		{
			printf("%d \t",nptr->data);
			nptr=nptr->next;
		}
		return list_ptr;
	}
int main()
{
	int data,i,n,j;
	status_code sc;
	stack_type stack1;
	initialization(&stack1);
	printf("enter how many data push in stack \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("enter the value to push in stack \n");
	scanf("%d",&data);
	sc=push(&stack1,data);
	printf("status of push is %d\nand stack is\n",sc);
	stack1.top=traverseList(stack1.top);
	}
	 printf("\n1)for push \n2)for pop");
	 scanf("%d",&i);
	 switch(i)
	 {
	  case 1:
	  	printf("enter the value to push in stack \n");
		scanf("%d",&data);
		sc=push(&stack1,data);
		printf("status of push is %d\nand stack is\n",sc);
		stack1.top=traverseList(stack1.top);
		break;
		
	  case 2:
	  	printf("we are poping value from stack \n");
		sc=pop(&stack1,&data);
		printf("status of pop is %d\nand data pop is %d\n",sc,data);
		stack1.top=traverseList(stack1.top);
	  break;
	 }
	 printf("\nnow we are checking nuumber is palindrome or not\nenter the number\n");
	 
	scanf("%d",&n);
	j=0;
	while(n!=0)
	{
	 n=n/10;
	 j++;
	}
	if(n%2==0)
	{
	
	}
}
