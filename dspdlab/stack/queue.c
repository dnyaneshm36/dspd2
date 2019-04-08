#include<stdio.h>
#include<stdlib.h>
typedef enum {FAILURE,SUCCESS}status_code;
typedef struct node_tab
{
   int data;
   struct node_tab* next ;
}node_type;
 typedef struct queue_tag 
 {
   node_type* font;
   node_type *rear;  
 }queue_type;
 
void *traverseQueue(queue_type * qptr)
	{
		if((qptr->font)==NULL && (qptr->rear)==NULL)
		{
		 printf("queque is empty ");
		}
		else
		{
			node_type *nptr;
			nptr=qptr->font;
			while(nptr!=NULL)
			{
				printf("%d \t",nptr->data);
				nptr=nptr->next;
			}
		}
	} 
 void intialization(queue_type * qptr)
 {
 	qptr->font =NULL;
 	qptr->rear =NULL;	
 }

int isQueueIsEmpty(queue_type tempqueue)
{
 int retval=0;
	if((tempqueue.font)==NULL && (tempqueue.rear)==NULL)
	{
		retval=1;
	}
	else
	{
	 retval=0;
	}
 return retval;
}
status_code insertInQueue(queue_type * qptr, int d)
{
	node_type * nptr;
	status_code sc=SUCCESS;
	nptr=(node_type*)malloc(sizeof(node_type));
	if(nptr==NULL)
	{
	 sc=FAILURE;
	}
	else
	{
	 	if(isQueueIsEmpty(*qptr)==1)
	 	{
	 	 nptr->data=d;
	 	 qptr->rear=nptr;
	 	 qptr->font=nptr;
	 	 (qptr->rear)->next=NULL;
	 	}
	 	else
	 	{
	 	 nptr->data=d;
	 	 nptr->next=NULL;
	 	 ((qptr->rear)->next)=nptr;
	 	 qptr->rear=nptr;
	 	}
	 sc=SUCCESS;
	}
 return sc;
}
status_code deleteFromQueue(queue_type *qptr,int *dptr)
{
 	node_type * nptr;
 	status_code sc=SUCCESS;
 	if(nptr==NULL)
 	{
 	 sc=FAILURE;
 	}
 	else
 	{
 	 	if(isQueueIsEmpty(*qptr)==1)
 	 	{
 	 		printf("you can't delete form empty queue\n");
 	 		 sc=FAILURE;	
 	 		
 	 	}
 	 	else
 	 	{
 	 	 nptr=(qptr->font);
 	 	 *dptr=(qptr->font)->data;
 	 	 qptr->font=nptr->next;
 	 	 free(nptr);
 	 	 	if(qptr->font==NULL)
 	 	 	{
 	 	 	 qptr->rear= NULL;
 	 	 	}
 	 	  sc=SUCCESS;	
 	 	}
	
 	}
 return sc;
}
int main()
{
	int data,i,n;
	status_code sc;
	queue_type queue;
	intialization(&queue);
  	printf("enter how many element in queue \n");
  	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the value\n");
		scanf("%d",&data);
		sc=insertInQueue(&queue,data);
		printf("status of push is %d\nand stack is\n",sc);
		traverseQueue(&queue);
	}
	
	printf("\n1) for inserting \n2) for delete ");
	scanf("%d",&i);
	switch(i)
	 {
	  case 1:
		printf("enter the value\n");
		scanf("%d",&data);
		sc=insertInQueue(&queue,data);
		printf("status of push is %d\nand stack is\n",sc);
		traverseQueue(&queue);
		break;
		
	  case 2:
	  	printf("we are delete from queue \n");
		sc=deleteFromQueue(&queue,&data);
		printf("status of delete is %d\nand data deleted  is %d\n",sc,data);
		traverseQueue(&queue);
		break;
	 }
	printf("\n1) for inserting \n2) for delete ");
	scanf("%d",&i);
	switch(i)
	 {
	  case 1:
		printf("enter the value\n");
		scanf("%d",&data);
		sc=insertInQueue(&queue,data);
		printf("status of push is %d\nand stack is\n",sc);
		traverseQueue(&queue);
		break;
		
	  case 2:
	  	printf("we are delete from queue \n");
		sc=deleteFromQueue(&queue,&data);
		printf("status of delete is %d\nand data deleted  is %d\n",sc,data);
		traverseQueue(&queue);
		break;
	 }
  
}





