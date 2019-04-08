#include<stdio.h>
#include<stdlib.h>
typedef enum {FAILURE,SUCCESS}status_code;
typedef struct node_tag
	{
		int data;
		struct node_tag *next;
	}node_type;
	node_type *insertAtStart(node_type *list_ptr,int d)
	{
		node_type *nptr;
		nptr=(node_type *)malloc(sizeof(node_type));
		nptr->data=d;
		nptr->next=list_ptr;
		list_ptr=nptr;
		return list_ptr;
	}
	node_type *insertAtEnd(node_type *list_ptr,int d)
	{
		node_type *nptr,*lptr;
		nptr=(node_type *)malloc(sizeof(node_type));
		nptr->data=d;
		nptr->next=NULL;
		if(list_ptr==NULL)
		{
			list_ptr=nptr;
		}	
		else
		{
			lptr=list_ptr;
			while(lptr->next!=NULL)
			{
			 lptr=lptr->next;
			}
			
			lptr->next=nptr;
		}
		return list_ptr;
	}
	node_type *createList1(node_type *list_ptr,int num)
	{
		int i;
		for(i=0;i<num;i++)
		{
			list_ptr=insertAtStart(list_ptr,i);
		}
		return list_ptr;
	}
	node_type *createList2(node_type *list_ptr,int num)
	{
		int i;
		for(i=0;i<num;i++)
		{
			list_ptr=insertAtEnd(list_ptr,i);
		}
		return list_ptr;
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
	node_type *deleteAtStart(node_type *list_ptr,int *dptr)
	{
		node_type *nptr;
		nptr=list_ptr;
		if(list_ptr!=NULL)
		{
			*dptr=nptr->data;
			list_ptr=list_ptr->next;
			free(nptr);
		}
		return list_ptr;
	}
	node_type *deleteAtEnd(node_type *list_ptr,int *dptr)
	{
		node_type *nptr,*prev;
		if(list_ptr!=NULL)
		{
			if(list_ptr->next==NULL)
			{
				*dptr=list_ptr->data;
				free(list_ptr);
				list_ptr=NULL;
			}
			else{
				nptr=list_ptr;
				while((nptr->next)!=NULL){
					prev=nptr;
					nptr=nptr->next;
				}
				prev->next=NULL;
				*dptr=nptr->data;
				free(nptr);
			}
		}
		return list_ptr;
	}
	node_type *deleteList1(node_type *list_ptr)
	{
		int data;
		while(list_ptr!=NULL)
		{
			printf("deleted node .");
			list_ptr=deleteAtStart(list_ptr,&data);
			printf("%d\n",data);
		}
		return list_ptr;
	}
	node_type *deleteList2(node_type *list_ptr)
	{
		int data;
		while(list_ptr!=NULL)
		{
			list_ptr=deleteAtEnd(list_ptr,&data);
			printf("deleted node %d\n",data);
		}
		return list_ptr;
	}

 status_code Element(node_type *list_ptr,int m,int n)
{
	status_code sc= SUCCESS;
	node_type *ptr,*freeptr;
	ptr=list_ptr;
	int counter;
	while(counter<=m&&sc==SUCCESS)
	{
	  counter++;
	  	if(ptr==NULL)
	  	{
	  	 sc=FAILURE;
	  	}
	  	ptr=ptr->next;
	 }
	  	
	while(counter<=m+n&&sc==SUCCESS)
	{
	 	if(ptr==NULL)
	 	{
	 	 sc=FAILURE;
	 	}
	 	freeptr=ptr->next;
	 	ptr->next=(ptr->next)->next;
	 	free(ptr);
	 	counter++;
	}
	return sc;
}
int main()
{

 return 0;
}
