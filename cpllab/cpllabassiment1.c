#include<stdio.h>
#include<stdlib.h>
typedef enum {FAILURE,SUCCESS}stutus_code;
typedef enum{FALSE,TRUE} boolean;
typedef struct node_tag
{
	int data;
	struct node_tag *next;
}node_type;
typedef struct set_tag
{
	node_type * list_ptr;
}set_type;
node_type* Initialize(node_type *lptr)
{
    lptr=NULL;
    return lptr;
}
//this are from link list program
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
	node_type *deleteNode(node_type *lptr,node_type *delptr)
	{
		node_type *nptr;
		nptr=lptr;
		if(delptr==lptr)
		{
			lptr=nptr->next;
			free(nptr);
		}
		else{
			while(delptr!=nptr->next)
			{
				nptr=nptr->next;
			}
			nptr->next=delptr->next;
			free(delptr);
		}
		return lptr;
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
// from above till here
	set_type create()
	{
		set_type S;
		S.list_ptr=NULL;
		return S;
	}
	node_type *check(set_type S,int n)
	{
		node_type *findptr=NULL;
		node_type *nptr;
		nptr=S.list_ptr;
		while(nptr!=NULL&&findptr==NULL)
		{
			if(nptr->data==n)
			{
				findptr=nptr;
			}
			else
			{
				nptr=nptr->next;
			}
		}
		return findptr;
	}
	set_type add(set_type S,int n)
	{
		node_type *lptr,*nptr;
		lptr=S.list_ptr;
		nptr=check(S,n);
		if(nptr==NULL)
		{
			lptr=insertAtStart(lptr,n);
		}
		else
		{
			printf("element present in the set\n");
		}
		S.list_ptr=lptr;
		return S;
	}
	set_type removeElement(set_type S,int n)
	{
		node_type *delptr;
		delptr=check(S,n);
		if(delptr==NULL)
		{
			printf("\nthe element is not present in the set\n");
		}
		else{
			S.list_ptr=deleteNode(S.list_ptr,delptr);
		}
		return S;
	}
 stutus_code is_element_of(int d, set_type *set_ptr)
 {
   int flag=0;
   node_type *nptr;
   nptr=set_ptr->list_ptr;
   stutus_code sc=FAILURE;
   	while(nptr!=NULL&&flag==0)
   	{
   	 	if(d==nptr->data)
   	 	{flag=1;
   	 	 sc=SUCCESS;
   	 	}
   	 	else
   	 	{
   	 	 nptr=nptr->next;
   	 	}
   	}
   return sc;
 }
void is_empty(set_type *set_ptr)
 {
   stutus_code sc=FAILURE;
   		if(set_ptr->list_ptr==NULL)
		{
			printf("Given set is empty\n");
		}
		else
		{
			printf("Given set is not empty\n");
		}
 }
 
 int size(set_type *set_ptr)
 {
  int count=0;
  node_type *nptr;
     nptr=set_ptr->list_ptr;
     	while(nptr!=NULL)
   	{
		count++;
   	 	 nptr=nptr->next;
		
   	}
   return count;
 }
	void enumerate(set_type S)
	{
		traverseList(S.list_ptr);
	}
	
	set_type build(set_type s)
	{
		int n,d,i;
		
		printf("number of elements to be added into exiting set:\n");
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			printf("enter a number:\n");
			scanf("%d",&d);
			s=add(s,d);
		}
		return s;
	}
	set_type unionSet(set_type S,set_type T)
	{
		set_type U=create();
		node_type *sptr,*tptr;
		sptr=S.list_ptr;
		tptr=T.list_ptr;
		while(sptr!=NULL)
		{
			U=add(U,sptr->data);
			sptr=sptr->next;
		}
		while(tptr!=NULL)
		{
			if(check(U,tptr->data)==NULL)
			{
				U=add(U,tptr->data);
			}
			tptr=tptr->next;
		}
		return U;
	}
	set_type intersection(set_type S,set_type T)
	{
		set_type U=create();
		node_type *sptr;
		sptr=S.list_ptr;
		while(sptr!=NULL)
		{
			if(check(T,sptr->data)!=NULL)
			{
				U=add(U,sptr->data);
			}
			sptr=sptr->next;
		}
		return U;
	}
	set_type difference(set_type S,set_type T)
	{
		set_type U=create();
		node_type *uptr,*sptr,*tptr;
		sptr=S.list_ptr;
		tptr=T.list_ptr;
		while(sptr!=NULL)
		{
			if(check(T,sptr->data)==NULL)
			{
				U=add(U,sptr->data);
			}
			sptr=sptr->next;
		}
		return U;
	}
	int subset(set_type S,set_type T)
	{
		int retval=1;
		node_type *sptr;
		sptr=S.list_ptr;
		while(sptr!=NULL&&retval==1)
		{
			if(check(T,sptr->data)==NULL)
			{
				retval=0;
			}
			sptr=sptr->next;
		}
		return retval;
	}
	


int main()
{	
	set_type S=create(),T=create(),U=create();
	int n,flag=1,choice,temp;
	printf("1).create empty set S\n2).add element in S\n3).remove element from S\n4).is element of S\n5).is S empty\n6).size of S\n7).enumerate S\n8).build S\n9).union with T\n10).intersection with T\n11).difference\n12).subset\nanything except this to exit program\n");
	while(flag==1)
	{	
		printf("\n\nenter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	S=create();
				break;
			case 2:	printf("enter a number to add: ");
				scanf("%d",&n);
				S=add(S,n);
				break;
			case 3:	printf("enter a number to removed:  ");
				scanf("%d",&n);
				S=removeElement(S,n);
				break;
			case 4:	printf("enter a number: ");
				scanf("%d",&n);
				temp=is_element_of(n,&S);
				if(temp==1)
				{
				 printf("\nelement is found\n");
				}
				else
				{
				 printf("\nelement is not found\n");
				}
				break;
			case 5:	is_empty(&S);
				break;
			case 6:	temp=size(&S);
			 	printf("\nsize of set is %d",temp);
				break;
			case 7:	enumerate(S);
				break;
			case 8:	S=build(S);
				break;
			case 9:	printf("enter data for set T: that will remain for all program\n(if you dont wan't to enter no element=0)\n");
				T=build(T);
				U=unionSet(S,T);
				printf("\n\nset of union S and T\n");
				enumerate(U);		
				break;
			case 10:printf("enter data for set T:\n");
				T=build(T);
				U=intersection(S,T);
				printf("\n\nset of intersection S and T\n");
				enumerate(U);		
				break;
			case 11:printf("enter data for set T:\n");
				T=build(T);
				U=difference(S,T);
				printf("\n\nset of difference between S and T\n");
				enumerate(U);		
				break;
			case 12:printf("enter data for set T:\n");
				T=build(T);
				if(subset(S,T))
				{
					printf("\n\nS is subset of T\n");
				}
				else
				{
					printf("\n\nS is not a subset of T\n");
				}
				break;
			default:flag=0;
				break;
			
		}
	}
	return 0;
}

