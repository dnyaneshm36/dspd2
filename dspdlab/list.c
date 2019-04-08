
#include<stdio.h>
#include<stdlib.h>
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
node_type * rotatelist(node_type * list_ptr, int k)
{
  node_type * ptr,*nptr;
  int count=1;
  ptr=list_ptr;

	  while(count<k)
	  {
	   ptr=ptr->next;
	   count++;
	  }
	  nptr=ptr->next;
	 ptr->next =NULL;
	 ptr=nptr;
	 while(ptr->next!=NULL)
	 {
	 ptr=ptr->next;
	 }
	 ptr->next=
	 list_ptr=nptr;

	 return list_ptr;
}
node_type* reverserecurtion(node_type *head , node_type* mid ,node_type *tail)
{
    node_type * ptr;
	    if(head!=NULL)
	    {
	      mid->next=tail;
	      tail=mid;
	      mid=head;
	      head=head->next;
	      ptr=reverserecurtion(head,mid,tail);
	    }
	    else
	    {

		 mid->next=tail;
		 ptr=mid;
	    }
	    return ptr;
}
void addtionofnumber( int i, int j)
{
  int p,q,r,carry=0;
  node_type *list1,*list2,*list3,*ptr1,*ptr2;
  list1=NULL;
  list2=NULL;
  list3=NULL;

  while(i!=0)
  {
    list1=insertAtEnd(list1,i%10);
    i=i/10;
  }
  while(j!=0)
  {
    list2=insertAtEnd(list2,j%10);
    j=j/10;
  }
  list1=traverseList(list1);
  printf("\nlist are rever order\n");
  list2=traverseList(list2);
    printf("\nans\n");
  ptr1=list1;
  ptr2=list2;
  	while(ptr1!=NULL&&ptr2!=NULL)
  	{
  	  list3=insertAtStart(list3,(ptr1->data+ptr2->data+carry)%10);
  	  carry=(ptr1->data+ptr2->data+carry)/10;
  	  ptr1=ptr1->next;
  	  ptr2=ptr2->next;
  	}
  	if(ptr1!=NULL)
  	{
  	  list3=insertAtStart(list3,(ptr1->data+carry)%10);
  	  carry=(ptr1->data+carry)/10;
  	  ptr1=ptr1->next;
  	}
  	if(ptr2!=NULL)
  	{
  	  list3=insertAtStart(list3,(ptr2->data+carry)%10);
  	  carry=(ptr2->data+carry)/10;
  	  ptr2=ptr2->next;
  	}
  	if(carry==1)
  	{
  	 list3=insertAtStart(list3,carry);
  	}
  	list3=traverseList(list3);
}
void nthfromlast(node_type *list_ptr,int k)
{
  node_type *ptr, *preptr;
  int count1 ,count2;
  preptr=list_ptr;
  ptr=list_ptr;
  	while(ptr!=NULL)
  	{
  	count1=1;
  	 	while(count1<=k&&ptr!=NULL)
  	 	{
  	 	 ptr=ptr->next;
  	 	 count1++;
  	 	}
  	 	preptr=ptr;
  	 	count1=1;
  	}

}
node_type * alternateNodelist(node_type * list1,node_type * list2)
{
	 node_type *ptr3,* ptr1,*ptr2,*temp,*list3;
	 ptr1=list1;
	 ptr2=list2;
	 list3=ptr1;
	 ptr3=list3;
	 ptr1=ptr1->next;

	 while(ptr1!=NULL&&ptr2!=NULL)
	 {
	   ptr3->next=ptr2;
	   ptr2=ptr2->next;
	   ptr3=ptr3->next;
	   ptr3->next=ptr1;
	   ptr1=ptr1->next;
	   ptr3=ptr3->next;
	 }
	 if(ptr1!=NULL)
	 {
	  ptr3->next=ptr1;
	 }
	 if(ptr2!=NULL)
	 {
	  ptr3->next=ptr2;
	 }
	 return list3;

}
node_type * deletenodediviblek(node_type * list1,int k)
{
	node_type *ptr,*prev,*retlist;
	if(k==0)
	{
	 printf("can not divibe by 0\n");
	}
	else if(k==1)
	{
	 printf("list must be null\n");
	 retlist=NULL;

	}
	else
	{

	 	ptr=list1;
	 	while((list1->data)%k==0)
		{

			prev=list1;
			list1=list1->next;
			free(prev);
		}
		ptr=list1->next;
		prev=list1;
	 	while(ptr->next!=NULL)
	 	{

	 	 	if((ptr->data)%k==0)
			{
			prev->next=ptr->next;
			free(ptr);
			 ptr=ptr->next;

			}
			else
			{
			prev=ptr;
			 ptr=ptr->next;

			}
	 	}
	 	retlist=list1;

	}


  return retlist;

}

node_type *addtion_of_number(node_type *n1,node_type *n2)
{
	node_type *p1,*p2,*sum;
	int s=0,c=0;

	sum=NULL;
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

node_type *multiplcation(node_type *n1,node_type *n2)
{
	node_type *p1,*p2,*prod,*ret;
	int x=0,s=0,c=0;
	prod=NULL;
	ret=NULL;
	p1=n1;
	p2=n2;
	int i=0;
	while(p1!=NULL)
	{
		p2=n2;
		prod=NULL;
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
		for(int j=0;j<i;j++)
		{
			prod=insertAtStart(prod,0);
		}
		i++;
		ret=addtion_of_number(ret,prod);
	}
	return ret;

}

	int main()
	{
		node_type *list_ptr,*nptr,*list1,*list2,*list3;
	node_type *num1_ptr,*num2_ptr,*sum,*prod,*diff;
		int n,var=0,i,k,j;
		int data;
		int loop=1;
		/*printf("first we are creating the list \n ");
		printf("enter the value of nodes \n");
		scanf("%d",&n);
		list_ptr=NULL;
		list_ptr=createList1(list_ptr,n);
		list_ptr=traverseList(list_ptr);*/
 	  while(loop!=0)
         {
		printf( "Choose the any one\n");
		printf("1) for deleting list node by node from starting \n");
		printf("2) for deleting list node by node from ending  \n");
		printf("3) traverse through list \n");
		printf("4) insert node at start  \n");
		printf("5) delete node from start \n");
		printf("6) insert node at end   \n");
		printf("7) delete node at end  \n");
		printf("10)for addtion of number\n" );
		printf("12) alternativer node's list   \n");
                scanf("%d",&var);

		switch(var)
		{
		case 1:
		printf("showing which node going to delete\n");
		list_ptr=deleteList1(list_ptr);
		loop=1;
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
		case 8:
		printf("we are rotating list \nentter the value of k\n");
		scanf("%d",&k);
		list_ptr=rotatelist(list_ptr,k);
		break;
		case 9:
		list_ptr=reverserecurtion(list_ptr->next,list_ptr,NULL);
		break;
		case 10:
		printf("enter two number \n");
		scanf("%d %d",&i,&k);
		addtionofnumber(i,k);
		break;
		case 11:
		printf("enter  value of n \n");
				scanf("%d",&k);
		nthfromlast(list_ptr,k);
		break;
		case 12:
		list1=NULL;
		list2=NULL;
		list3=NULL;
		printf("you have to enter two list\n enter no of node list 1and 2\n");
		scanf("%d %d",&i,&k);
		printf("we are enter at start list enter list 1\n");
		for(j=0;j<i;j++)
		{
		printf("enter the data you want to insert\n");
		scanf("%d",&data);
		list1=insertAtStart(list1,data);
		}
		list1=traverseList(list1);
		printf("\nwe are enter at start list enter list 2\n");
		for(j=0;j<k;j++)
		{
		printf("enter the data you want to insert\n");
		scanf("%d",&data);
		list2=insertAtStart(list2,data);
		}
		list2=traverseList(list2);
		printf("required list is\nwwwww");
		 list3=alternateNodelist(list1,list2);
		 list3=traverseList(list3);
		break;
		case 13:
		list1=NULL;
		printf("how many element\n");
		scanf("%d",&i);
		printf("we are enter at start list enter list 1\n");
		for(j=0;j<i;j++)
		{
		printf("enter the data you want to insert\n");
		scanf("%d",&data);
		list1=insertAtStart(list1,data);
		}
		list1=traverseList(list1);

		printf("enter the  number \n");
		scanf("%d",&i);
		list1=deletenodediviblek(list1,i);
		printf("deleted list is given\n");
		list1=traverseList(list1);

		break;
		case 14:
		printf("enter two number \n");
		scanf("%d %d",&i,&j);
		num1_ptr=NULL;
		num2_ptr=NULL;
		list1=NULL;
	  list2=NULL;
	  list3=NULL;

	  while(i!=0)
	  {
	    list1=insertAtEnd(list1,i%10);
	    i=i/10;
	  }
	  while(j!=0)
	  {
	    list2=insertAtEnd(list2,j%10);
	    j=j/10;
	  }
	  list1=traverseList(list1);
	  printf("\nlist second is \n");
	  list2=traverseList(list2);
		printf("\nanswer is :- \n");
		list3=multiplcation(list1,list2);
		list3=traverseList(list3);
		break;
		case 0:
		loop=0;
		break;

		}
	   }


		return 0;
	}
