#include<stdio.h>
#include<stdlib.h>
typedef struct node_tag
{
	int data;
	struct node_tag *next;
}node_type;
typedef struct set_tag
{
	node_type *setptr;
}set;
//-----------------------------------------------------------------------------
	node_type *insertAtStart(node_type *list_ptr,int d)
	{
		node_type *nptr;
		nptr=(node_type *)malloc(sizeof(node_type));
		nptr->data=d;
		nptr->next=list_ptr;
		list_ptr=nptr;
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
		printf("\n");
		return list_ptr;
	}
	node_type *deleteNode(node_type *lptr,node_type *dltptr)
	{
		node_type *nptr;
		nptr=lptr;
		if(dltptr==lptr)
		{
			lptr=nptr->next;
			free(nptr);
		}
		else{
			while(dltptr!=nptr->next)
			{
				nptr=nptr->next;
			}
			nptr->next=dltptr->next;
			free(dltptr);
		}
		return lptr;
	}
//-------------------------------------------------------------
	set create()
	{
		set S;
		S.setptr=NULL;
		return S;
	}
	node_type *check(set S,int n)
	{
		node_type *elptr=NULL;
		node_type *nptr;
		nptr=S.setptr;
		while(nptr!=NULL&&elptr==NULL)
		{
			if(nptr->data==n)
			{
				elptr=nptr;
			}
			else{
				nptr=nptr->next;
			}
		}
		return elptr;
	}
	set add(set S,int n)
	{
		node_type *lptr,*nptr;
		lptr=S.setptr;
		nptr=check(S,n);
		if(nptr==NULL)
		{
			lptr=insertAtStart(lptr,n);
		}
		else{
			printf("element already present in the set\n");
		}
		S.setptr=lptr;
		return S;
	}
	set removeElement(set S,int n)
	{
		node_type *dltptr;
		dltptr=check(S,n);
		if(dltptr==NULL)
		{
			printf("given element is not present in the set\n");
		}
		else{
			S.setptr=deleteNode(S.setptr,dltptr);
		}
		return S;
	}
	void is_element_of(set S,int n)
	{
		if(check(S,n)!=NULL)
		{
			printf("%d is element of given set\n",n);
		}
		else{
			printf("%d is not an element of given set\n",n
			);
		}
	}
	void isEmpty(set S)
	{
		if(S.setptr==NULL)
		{
			printf("Given set is empty\n");
		}
		else{
			printf("Given set is not empty\n");
		}
	}
	void size(set S)
	{
		int len=0;
		node_type *nptr;
		nptr=S.setptr;
		while(nptr!=NULL)
		{
			len++;
			nptr=nptr->next;
		}
		printf("size of given set is %d\n",len);
	}
	void enumerate(set S)
	{
		traverseList(S.setptr);
	}
	set build(set X)
	{
		int n,d,i;
		X.setptr=NULL;
		printf("number of elements to be added into set:");
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			printf("enter a number:");
			scanf("%d",&d);
			X=add(X,d);
		}
		return X;
	}
	set unionSet(set S,set T)
	{
		set U=create();
		node_type *sptr,*tptr;
		sptr=S.setptr;
		tptr=T.setptr;
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
	set intersection(set S,set T)
	{
		set U=create();
		node_type *sptr;
		sptr=S.setptr;
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
	set difference(set S,set T)
	{
		set U=create();
		node_type *uptr,*sptr,*tptr;
		sptr=S.setptr;
		tptr=T.setptr;
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
	int subset(set S,set T)
	{
		int retval=1;
		node_type *sptr;
		sptr=S.setptr;
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
	set S=create(),T=create(),U=create();
	int n,flag=1,choice;
	printf("1.create empty set S\n2.add element in S\n3.remove element from S\n4.is element of S\n5.is S empty\n6.size of S\n7.enumerate S\n8.build S\n9.union with T\n10.intersection with T\n11.difference\n12.subset\n0.exit\n");
	while(flag==1)
	{	
		printf("-----------------------------------------------\n\t\tenter your choice:");
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
				is_element_of(S,n);
				break;
			case 5:	isEmpty(S);
				break;
			case 6:	size(S);
				break;
			case 7:	enumerate(S);
				break;
			case 8:	S=build(S);
				break;
			case 9:	printf("enter data for set T:\n");
				T=build(T);
				U=unionSet(S,T);
				printf("\t\tset of union S and T\n");
				enumerate(U);		
				break;
			case 10:printf("enter data for set T:\n");
				T=build(T);
				U=intersection(S,T);
				printf("\t\tset of intersection S and T\n");
				enumerate(U);		
				break;
			case 11:printf("enter data for set T:\n");
				T=build(T);
				U=difference(S,T);
				printf("\t\tset of difference between S and T\n");
				enumerate(U);		
				break;
			case 12:printf("enter data for set T:\n");
				T=build(T);
				if(subset(S,T))
				{
					printf("\t\tS is subset of T\n");
				}
				else
				{
					printf("\t\tS is not a subset of T\n");
				}
				break;
			default:flag=0;
				break;
			
		}
	}
	return 0;
}


