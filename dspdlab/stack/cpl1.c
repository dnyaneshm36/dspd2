#include<stdio.h>
typedef enum{FAILURE,SUCCESS} status_code;
typedef enum{FALSE,TRUE} boolean;
typedef int item;
typedef struct node_tag
{
	item data;
	struct node_tag *next;

}node_type;
node_type* Initialize(node_type *lptr)
{
    lptr=NULL;
    return lptr;
}
node_type* creat_list()
{
    printf("Enter how many number of element you want to store\n");
	int i,num,d;
	scanf("%d",&num);
	node_type *lptr,*nptr;
	lptr=NULL;
	printf("Enter elements\n");
	for(i=0;i<num;i++)
	{
		nptr=(node_type*)malloc(sizeof(node_type));
		scanf("%d",&d);
		nptr->data=d;
		nptr->next=lptr;
		lptr=nptr;
	}
	printf("list created\n");
	return lptr;
}
void transverse_list(node_type *lptr)
{
	node_type *nptr;
	nptr=lptr;
	while(nptr!=NULL)
	{
		printf("%d ",nptr->data);
		nptr=nptr->next;
	}
	printf("\n");
}
boolean is_element_of_set(node_type *ptr,item d)
{
    node_type *lptr;
    lptr=ptr;
    boolean retval=FALSE;
    while(lptr!=NULL&&retval==FALSE)
    {
        if(lptr->data==d)
        {
            retval=TRUE;
        }
        else
        {
            lptr=lptr->next;
        }
    }
    return retval;
}
node_type* new_element(node_type *lptr,item num)
{
    node_type *nptr,*ptr;
    ptr=lptr;
    nptr=(node_type*)malloc(sizeof(node_type));
    int found=0;
    while(found==0&&ptr!=NULL)
    {
        if(ptr->data==num)
        {
            found=1;
        }

        ptr=ptr->next;
    }
    if(found)
    {
        printf("It already exist in set\n");
    }
    else
    {
        nptr->data=num;
        nptr->next=lptr;
        lptr=nptr;
    }
    return lptr;
}
boolean is_empty(node_type *lptr)
{
    boolean b=FALSE;
    if(lptr==NULL)
    {
        b=TRUE;
    }
    return b;
}
int size_of_set(node_type *lptr)
{
    int size=0;
    node_type *nptr;
    nptr=lptr;
    while(nptr!=NULL)
    {
        size=size+1;
        nptr=nptr->next;
    }
    return size;
}
node_type* remove_element(node_type *lptr)
{
    item num;
    printf("Enter element you want to removed\n");
    scanf("%d",&num);
    node_type *prev;
    node_type *ptr;
    int found=0;
    prev=lptr;
    if(lptr->data==num)
    {
        found=1;
        ptr=lptr;
        lptr=lptr->next;
    }
    else
    {
        ptr=lptr->next;
        while(ptr!=NULL && found==0)
        {
            if(ptr->data==num)
            {
                found=1;
            }
            else
            {
                prev=ptr;
                ptr=ptr->next;
            }
        }
    }
    if(found==1)
    {
        prev->next=ptr->next;
        free(ptr);
        printf("Deleted successfully!!!\n");
    }
    else
    {
        printf("Element is not present in set\n");
    }
    return lptr;
}
node_type* union_set(node_type *lptr,node_type *mptr)
{
    node_type *uptr,*ptr;
    boolean check;
    if(lptr==NULL)
    {
        uptr=mptr;
    }
    else if(mptr==NULL)
    {
        uptr=lptr;
    }
    else
    {
        uptr=lptr;
        ptr=mptr;
        while(ptr!=NULL)
        {
            check=is_element_of_set(uptr,ptr->data);
            if(!check)
            {
                uptr=new_element(uptr,ptr->data);
            }
            ptr=ptr->next;
        }
    }
    return uptr;
}
node_type* intersection_set(node_type *lptr,node_type *mptr)
{
    node_type *ptr,*nptr;
    boolean check;
    ptr=NULL;
    if(lptr==NULL||mptr==NULL)
    {
        ptr=NULL;
    }
    else
    {
        nptr=mptr;
        while(nptr!=NULL)
        {
            check=is_element_of_set(lptr,nptr->data);
            if(check)
            {
                ptr=new_element(ptr,nptr->data);
            }
            nptr=nptr->next;
        }
    }
    return ptr;
}
node_type* difference_set(node_type *sptr,node_type *tptr)
{
     node_type *dptr=NULL;
     boolean check;
     if(tptr==NULL)
     {
         dptr=sptr;
     }
     else
     {
         if(sptr==NULL)
         {
             dptr==NULL;
         }
         else
         {
             while(sptr!=NULL)
             {
                 check=is_element_of_set(tptr,sptr->data);
                 if(check==FALSE)
                 {
                     dptr=new_element(dptr,sptr->data);
                 }
                 sptr=sptr->next;
             }
         }
     }
     return dptr;
}
boolean is_subset(node_type *lptr)
{
    boolean retval=TRUE,check;
    node_type *nptr,*ptr;
    nptr=lptr;
    printf("Enter subset to be checked\n");
    ptr=creat_list();
    while(ptr!=NULL&&retval==TRUE)
    {
        check=is_element_of_set(nptr,ptr->data);
        if(!check)
        {
            retval=FALSE;
        }
        ptr=ptr->next;
    }
    return retval;
}
int main()
{
    node_type *tptr,*uptr,*iptr,*dptr,*sptr;
    node_type **lptr;
    int t;
    printf("How many maximum set you want to create\n");
    scanf("%d",&t);
    lptr=(node_type**)malloc(sizeof(node_type*)*t);
    boolean check;
    item num,i,n,count=0,n1,n2;
    int c=1;
    uptr=Initialize(uptr);
    iptr=Initialize(iptr);
    dptr=Initialize(dptr);
    for(i=0;i<t;i++)
    {
        lptr[i]=Initialize(lptr[i]);
    }
    while(c)
    {
        printf("Enter your choice\n");
        printf("1-Build set\n");
        printf("2-Add element to set\n");
        printf("3-Delete element from set\n");
        printf("4-Check element in set\n");
        printf("5-Check if set is empty\n");
        printf("6-To get size of set\n");
        printf("7-To get union of two sets\n");
        printf("8-To check intersection of two sets\n");
        printf("9-To get difference of two set\n");
        printf("10-To check if set is subset or not\n");
        printf("11-To print the set\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: if(count<t)
                    {
                        lptr[count]=creat_list();
                        printf("Set builded\n");
                        transverse_list(lptr[count]);
                        count++;
                    }
                    else
                    {
                        printf("Maximum limit of creation set has reached\n");
                    }
                    break;
            case 2: printf("Enter element to add\n");
                    scanf("%d",&num);
                    printf("Enter set no. in which you want to enter\n");
                    scanf("%d",&n1);
                    if(n1<=count)
                    {
                        lptr[n1-1]=new_element(lptr[n1-1],num);
                        if(lptr[n1-1]->data==num)
                        {
                            printf("The element is added successfully!!!\n");
                        }
                    }
                    else
                    {
                        printf("invalid set number\n");
                    }
                    break;
            case 3: printf("Enter set number from which you want to remove element\n");
                    scanf("%d",&n1);
                    if(n1<=count)
                    {
                        lptr[n1-1]=remove_element(lptr[n1-1]);
                    }
                    else
                    {
                        printf("invalid set number\n");
                    }
                    break;
            case 4: printf("Enter element to be checked\n");
                    scanf("%d",&num);
                    printf("Enter set number in you want to check\n");
                    scanf("%d",&n1);
                    if(n1<=count)
                    {
                        check=is_element_of_set(lptr[n1-1],num);
                        if(check)
                        {
                            printf("YES\n");
                        }
                        else
                        {
                            printf("NO\n");
                        }
                    }
                    else
                    {
                        printf("Invalid set number\n");
                    }
                    break;
            case 5: printf("Enter set number to check if empty\n");
                    scanf("%d",&n1);
                    if(n1<=t)
                    {
                        check=is_empty(lptr[n1-1]);
                        if(check)
                        {
                            printf("Set is empty\n");
                        }
                        else
                        {
                            printf("Not empty\n");
                        }
                    }
                    else
                    {
                        printf("Invalid set number\n");
                    }
                    break;
            case 6: printf("Enter set number\n");
                    scanf("%d",&n1);
                    if(n1<=t)
                    {
                        num=size_of_set(lptr[n1-1]);
                        printf("Size=%d\n",num);
                    }
                    else
                    {
                        printf("Invalid set number\n");
                    }
                    break;
            case 7: printf("Enter set numbers whom you want to take union\n");
                    scanf("%d%d",&n1,&n2);
                    if(n1<=t&&n2<=t)
                    {
                        uptr=union_set(lptr[n1-1],lptr[n2-1]);
                        if(uptr==NULL)
                        {
                            printf("Empty set\n");
                        }
                        else
                        {
                            transverse_list(uptr);
                        }
                    }
                    else
                    {
                        printf("Invalid set/sets\n");
                    }
                    break;
            case 8: printf("Enter set numbers of you want to take intersection\n");
                    scanf("%d%d",&n1,&n2);
                    if(n1<=t&&n2<=t)
                    {
                        iptr=intersection_set(lptr[n1-1],lptr[n2-1]);
                        if(iptr==NULL)
                        {
                            printf("Empty set\n");
                        }
                        else
                        {
                            transverse_list(iptr);
                        }
                    }
                    else
                    {
                        printf("Invalid set/sets\n");
                    }
                    break;
            case 9: printf("Enter set numbers of which you want to take difference\n");
                    scanf("%d%d",&n1,&n2);
                    if(n1<=t&&n2<=t)
                    {
                        dptr=difference_set(lptr[n1-1],lptr[n2-1]);
                        if(dptr==NULL)
                        {
                            printf("Empty set\n");
                        }
                        else
                        {
                            transverse_list(dptr);
                        }
                    }
                    else
                    {
                        printf("Invalid set/sets\n");
                    }
                    break;
            case 10:printf("Enter set number of super set and subset\n");
                    scanf("%d%d",&n1,&n2);
                    if(n1<=t&&n2<=t)
                    {
                        sptr=difference_set(lptr[n1-1],lptr[n2-1]);
                        if(sptr==NULL)
                        {
                            printf("Empty set\n");
                        }
                        else
                        {
                            transverse_list(sptr);
                        }
                    }
                    else
                    {
                        printf("Invalid set/sets\n");
                    }
                    break;
            case 11:printf("Enter set number which you want to print\n");
                    scanf("%d",&n1);
                    if(n1<=count)
                    {
                        transverse_list(lptr[n1-1]);
                    }
                    else
                    {
                        printf("Empty set\n");
                    }
        }
        printf("Press 1 continue else 0\n");
        scanf("%d",&c);
    }
    return 0;
}
