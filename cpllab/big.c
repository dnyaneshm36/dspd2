

#include<stdio.h>
#include<stdlib.h>
typedef struct node_tag
	{
		 short int data;
		struct node_tag *next;
	}node_type;
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
			printf("%hd",nptr->data);
			nptr=nptr->next;
		}
		return list_ptr;
	}
	node_type *deleteAtStart(node_type *list_ptr,short int *dptr)
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
	node_type *deleteAtEnd(node_type *list_ptr,short int *dptr)
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
		short int data;
		while(list_ptr!=NULL)
		{
			printf("deleted node .");
			list_ptr=deleteAtStart(list_ptr,&data);
			printf("%hd\n",data);
		}
		return list_ptr;
	}
	node_type *deleteList2(node_type *list_ptr)
	{
		short int data;
		while(list_ptr!=NULL)
		{
			list_ptr=deleteAtEnd(list_ptr,&data);
			printf("deleted node %d\n",data);
		}
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

void addtionofnumber( node_type * list1, node_type * list2)
{
  short int carry=0;
  node_type *list3,*ptr1,*ptr2;

    printf("\nans\n");
  ptr1=list1;
  ptr2=list2;
  list3=NULL;
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

void subtractionofnumber( node_type * list1, node_type * list2)
{
  short int carry=0;
  node_type *list3,*ptr1,*ptr2;
    printf("\nans\n");
  ptr1=list1;
  ptr2=list2;
  list3=NULL;
  	while(ptr1!=NULL&&ptr2!=NULL)
  	{
  	  list3=insertAtStart(list3,(ptr1->data-(ptr2->data+carry))%10);
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
	int main()
	{	
		node_type *list_ptr,*nptr,*list1,*list2,*list3;
		int n,var=0,i,k,j;
		short int data;
		int loop=1;

 	  while(loop!=0)
         {
		printf( "\nChoose the any one\n");
		printf("1) for dding two numbers\n");
		printf("2) for subrating  numbers  \n");
		printf("3) traverse through list \n");

                scanf("%d",&var);

		switch(var)
		{
		case 1:
		list1=NULL;
		list2=NULL;
		list3=NULL;
		printf("\n we are adding nums\n");
		printf("you have to enter two numbers\n enter no of digit number 1 and 2\n");
		scanf("%d %d",&i,&k);
		printf("we are enter at end list enter number 1\n");
		for(j=0;j<i;j++)
		{
		printf("enter the a digit \n");
		scanf("%hd",&data);
		list1=insertAtEnd(list1,data);
		}
		list1=traverseList(list1);
		printf("\nwe are enter at end list enter number 2\n");
		for(j=0;j<k;j++)
		{
		printf("enter the a digit\n");
		scanf("%hd",&data);
		list2=insertAtEnd(list2,data);
		}
		list2=traverseList(list2);
		list1=reverserecurtion(list1->next,list1,NULL);
		list2=reverserecurtion(list2->next,list2,NULL);
		addtionofnumber(list1,list2);
		break;
		case 2 :
		 printf("\n we are subracting numbers nums\n");  
		 printf("\n you want to use same number press 1 else 0\n");
		 scanf("%d",&j);
		 if(j==1)
		 {
		 subtractionofnumber(list1,list2);
		 }
		 
		 else
		 {
		list1=NULL;
		list2=NULL;	
		printf("\n we are subtrating 2 form 1 nums\n");
		printf("you have to enter two numbers\n enter no of digit number 1 and 2\n");
		scanf("%d %d",&i,&k);
		printf("we are enter at end list enter number 1\n");
		for(j=0;j<i;j++)
		{
		printf("enter the a digit \n");
		scanf("%hd",&data);
		list1=insertAtEnd(list1,data);
		}
		list1=traverseList(list1);
		printf("\nwe are enter at end list enter number 2\n");
		for(j=0;j<k;j++)
		{
		printf("enter the a digit\n");
		scanf("%hd",&data);
		list2=insertAtEnd(list2,data);
		}
		list2=traverseList(list2);
		list1=reverserecurtion(list1->next,list1,NULL);
		list2=reverserecurtion(list2->next,list2,NULL);
		subtractionofnumber(list1,list2);
		 }
		break;


		  
		  
		case 0:
		loop=0;
		break;

		}
	   }

		
		return 0;
	}

