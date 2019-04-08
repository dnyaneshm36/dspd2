
#include<stdio.h>
#include<stdlib.h>
typedef enum {FAILURE,SUCCESS}stutus_code;
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
/*	stutus_code insertAfterNode(node_type *p ,node type* q)
	{
	 stutus_code sc;
	 
	}*/
	int length_of_link_list(node_type *list_ptr)
	{
		 node_type *nptr;
		 int count=0;
		 nptr=list_ptr;
		while(nptr!=NULL)
		{
		  count++;
		  nptr=nptr->next;
		}
	 return count;
	}
	int main()
	{	
		node_type *list_ptr,*nptr;
		int n,var=0,i;
		int data;
		printf("first we are creating the list \n ");
		printf("enter the number  of nodes \n");
		scanf("%d",&n);
		list_ptr=NULL;
	/*	list_ptr=createList1(list_ptr,n);	
		list_ptr=traverseList(list_ptr);
		printf( "Choose the any one");
		printf("1) for deleting list node by node from starting \n");
		printf("2) for deleting list node by node from ending  \n");
		printf("3) traverse through list \n");
		printf("4) insert node at start  \n");
		printf("5) delete node from start \n");
		printf("6) insert node at end   \n");
		printf("7) delete node at end  \n");
                scanf("%d",&var);
		switch(var)
		{
		case 1:
		printf("showing which node going to delete\n");
		list_ptr=deleteList1(list_ptr);
		break;
		case 2 :
		printf("showing which node going to delete\n");
		list_ptr=deleteList2(list_ptr);
		break;
		case 3:
	  	list_ptr=traverseList(list_ptr);
		break;
		case 4:
		printf("enter the data you want to insert\n");
		scanf("%d",&i);
		list_ptr=insertAtStart(list_ptr,i);
	  	list_ptr=traverseList(list_ptr);
		break;
		case 5:
			
			list_ptr=deleteAtStart(list_ptr,&data);
			printf("deleted node data is %d",data);
		break;
		case 6 :
		printf("enter the data you want to insert\n");
		scanf("%d",&i);
		list_ptr=insertAtEnd(list_ptr,i);
	  	list_ptr=traverseList(list_ptr);
		break;
		case 7:
			list_ptr=deleteAtEnd(list_ptr,&data);
			printf("deleted node data is %d",data);
		break;
		}*/
	
	printf("we are creating list from insert start put element in order\n");
	for(var=0;var<n;var++)
	{
		printf("enter the data you want to insert\n");
		scanf("%d",&i);
		list_ptr=insertAtStart(list_ptr,i);
	  	list_ptr=traverseList(list_ptr);
	  	
	}
	node_type *preptr,*freeptr;
	preptr=list_ptr;
	nptr=list_ptr->next;
		while(nptr!=NULL)
		{
		 	if((nptr->data)==(preptr->data))
		 	{
		 	 freeptr=nptr;
		 	 nptr=nptr->next;
		 	 preptr->next=nptr;
		 	 free(freeptr);
		 	}
		 	else
		 	{
		 	 nptr=nptr->next;
		 	 preptr=preptr->next;
		 	}
		}
		printf("\nremovel duplicate list is  \n");
		list_ptr=traverseList(list_ptr);
		printf("\nnow finding midle element \n");
	/*	n=length_of_link_list(list_ptr);
		nptr=list_ptr;
		i=0;
		if(n%2==1)
		{
		 	while(i!=n/2)
		 	{
		 	 i++;
		 	 nptr=nptr->next;
		 	}
		 	printf("middle element is %d \n",nptr->data);
		}
		else
		{
		 	while(i!=(n/2)-1)
		 	{
		 	 i++;
		 	 nptr=nptr->next;
		 	}
		 	printf("there are two middle elements are %d and %d \n",nptr->data,(nptr->next)->data);
		}
		*/
		nptr=list_ptr;
		freeptr=list_ptr;
		var=1;
		while(nptr!=NULL&&var!=0)
		{
		 nptr=nptr->next;
		 
		 if(nptr!=NULL)
		 {
		  freeptr=freeptr->next;
		 nptr=nptr->next;
		 }
		 else
		 {
		  var=0;
		 }
		 
		}
		printf("middle element is %d \n",freeptr->data);
		return 0;
		
	}


