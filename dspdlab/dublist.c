#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node_tag
{
 int data;
 struct node_tag *next;
}node_type;
typedef struct db_node_tag
{
 int data;
 struct db_node_tag *prev;
 struct db_node_tag *next;
}db_node_type;




	node_type *insertAtStart(node_type *list_ptr,int d)
	{
		node_type *nptr;
		nptr=(node_type *)malloc(sizeof(node_type));
		nptr->data=d;
		nptr->next=list_ptr;
		list_ptr=nptr;
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
	node_type *traverseList(node_type *list_ptr)
	{
		node_type *nptr;
		nptr=list_ptr;
		printf("singly link list is\n");
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
	
db_node_type *initiliazation(db_node_type* db_list)
{
 return NULL;
}

db_node_type *displaydblist(db_node_type* db_list)
{
		db_node_type *nptr;
		nptr=db_list;
		printf("\ndubbly link list is\n");
		while(nptr!=NULL)
		{
			printf("%d \t",nptr->data);
			nptr=nptr->next;
		}
		return db_list;
}
db_node_type * displaydblistreverse(db_node_type * list)
{
    		db_node_type *ptr;
    		ptr=list;
    		while(ptr->next)
    		{
    		ptr=ptr->next;
    		}
    		printf("\n reverce dubbly link list is\n");
		while(ptr!=NULL)
		{
			printf("%d \t",ptr->data);
			ptr=ptr->prev;
		}
		return list;
}
db_node_type *db_insertAtEnd(db_node_type *list_ptr,int d)
{
		db_node_type *nptr,*lptr;
		nptr=(db_node_type *)malloc(sizeof(db_node_type));
		nptr->data=d;
		nptr->next=NULL;
		nptr->prev=NULL;
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
			nptr->prev=lptr;
		}
		return list_ptr;
}

db_node_type *convert(node_type* list)
{
 node_type* slptr;
 db_node_type* dbptr;
 dbptr=NULL;
 slptr=list;
	 if(list==NULL)
	 {
	   printf("list in null");
	   dbptr=NULL;
	 }
	 else
	 {
	 	while(slptr!=NULL)
	 	{
	 	 dbptr=db_insertAtEnd(dbptr,slptr->data);
	 	 slptr=slptr->next;
	 	}
	 }
 return dbptr;
}

int product_of_prime_node(db_node_type* db_list)
{
  int prod=1,temp;
  int i,j,k;
  db_node_type* nptr;
  nptr=db_list;
		while(nptr!=NULL)
		{
			temp=nptr->data;
			if(temp==2)
			{
			 prod=prod*temp;
			}
			else if(temp>2)
			{
			  k=1;
			  	for(i=2;i<=temp/2 && k==1;i++)
			  	{
			  	     	if(temp%i==0)
			  	     	{
			  	     	k=0;
			  	     	}
			  	}
			  	if(k==1)
			   	{
			   	 prod=prod*temp;
			   	}
			   	
			}

			nptr=nptr->next;
		}
		
  return prod;
}
void noofcommonelement(db_node_type* list1,db_node_type* list2)
{
  int count=0;
  db_node_type* ptr1,*ptr2;
    for(ptr1=list1;ptr1;ptr1=ptr1->next)
    {
     		for(ptr2=list2;ptr2;ptr2=ptr2->next)
     		{
     		 	if( ptr1->data==ptr2->data)
     		 	{
     		 	 count++;
     		 	}
     		}
    }
    	printf("\nthe count is %d",count);
}
 void pairofproduct(db_node_type* list1,int x)
 {
   db_node_type *ptr1,*ptr2;
   ptr1=list1;
   int prod;
   while(ptr1->next)
   {
    ptr1=ptr1->next;
   }
   	ptr2=ptr1;
   	ptr1=list1;
   		while(ptr1!=ptr2)
   		{	
   			prod=(ptr1->data)*(ptr2->data);
   		 	if(prod<x)
   		 	{
   		 	 ptr1=ptr1->next;
   		 	 
   		 	}
   		 	else if(prod>x)
   		 	{
   		 	 ptr2=ptr2->prev;
   		 	 
   		 	}
   		 	else if(prod=x)
   		 	{
   		 	 printf("\n(%d,%d)",ptr1->data,ptr2->data);
   		 	 ptr1=ptr1->next;
   		 	 ptr2=ptr2->prev;
   		 	}
   		}
   		prod=(ptr1->data)*(ptr2->data);
   		if(prod=x)
   		 	{
   		 	 printf("\n(%d,%d)",ptr1->data,ptr2->data);
   		 	 
   		 	
   		 	}
 }
 
int main()
{	
		node_type *list_ptr,*nptr,*list1,*list2,*list3;
		db_node_type *db_list=NULL,*db_list2=NULL;
		int n,var=0,i,k,j;
		int data;
		int loop=1;
		printf("first we are creating the list \n ");
		printf("enter the value of nodes \n");
		scanf("%d",&n);
		list_ptr=NULL;
		list_ptr=createList1(list_ptr,n);	
		list_ptr=traverseList(list_ptr);
 	  while(loop!=0)
         {
		printf( "\nChoose the any one\n");
		printf("1) change list singly into dubbuly linklist \n");
		printf("2) product of prime  \n");
		printf("3) make a dublist  \n");
		printf("4) for no of common element\n");
		printf("5) pair of product  of  integer\n");
		printf("6) reverse of dubbely link list\n");
                scanf("%d",&var);

		switch(var)
		{
		case 1:
		printf("Converting to dubbuly link list\n");
		db_list=initiliazation(db_list);
		db_list=convert(list_ptr);
		
		db_list=displaydblist(db_list);
		break;
		case 2 :
		printf("product of prime\n");
		data=product_of_prime_node(db_list);
		printf("\nproduct is %d\n",data);
		break;
		case 3:
		printf("how many element\n");
		scanf("%d",&i);
		printf("we are enter at start list enter list 1\n");
		for(j=0;j<i;j++)
		{
		printf("enter the data you want to insert at the end\n");
		scanf("%d",&data);
		db_list=db_insertAtEnd(db_list,data);
		}
		db_list=displaydblist(db_list);
		  
		  
		break;
		case 4 :
		printf("using the 3 no case to make two list \n");
		db_list=NULL;
		printf("how many element\n");
		scanf("%d",&i);
		printf("we are enter at start list enter list 1\n");
		for(j=0;j<i;j++)
		{
		printf("enter the data you want to insert at the end\n");
		scanf("%d",&data);
		db_list=db_insertAtEnd(db_list,data);
		}
		db_list=displaydblist(db_list);	
		db_list2=db_list;
		db_list=NULL;
		printf("we are entering second dub list\n");
		printf("how many element\n");
		scanf("%d",&i);
		printf("we are enter at start list enter list 1\n");
		for(j=0;j<i;j++)
		{
		printf("enter the data you want to insert at the end\n");
		scanf("%d",&data);
		db_list=db_insertAtEnd(db_list,data);
		}
		db_list=displaydblist(db_list);
		noofcommonelement(db_list,db_list2);			
		break;
		case 5:
		printf("how many element & list should be in sorted order\n");
		scanf("%d",&i);
		printf("we are enter at start list enter list 1\n");
		for(j=0;j<i;j++)
		{
		printf("enter the data you want to insert at the end\n");
		scanf("%d",&data);
		db_list=db_insertAtEnd(db_list,data);
		}
		db_list=displaydblist(db_list);
		printf(" enter the number\n");
		scanf("%d",&i);
		pairofproduct(db_list,i);
		break;
		case 0:
		case 6:
		printf("we are revering the dubbuly link list\n");
		db_list=NULL;
		printf("how many element\n");
		scanf("%d",&i);
		printf("we are enter at start list enter list 1\n");
		for(j=0;j<i;j++)
		{
		printf("enter the data you want to insert at the end\n");
		scanf("%d",&data);
		db_list=db_insertAtEnd(db_list,data);
		}
		db_list=displaydblist(db_list);
		db_list=displaydblistreverse(db_list);
		break;
		
		loop=0;
		break;

		}
	   }

		
return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
