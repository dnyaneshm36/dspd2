#include<stdio.h>
#include<stdlib.h>
typedef enum{FAILURE,SUCCESS}status_code;
typedef struct passenger_tag
{
	char name[50];
	int count;
	char address;
	int phone_no;
	int age;
	char preference[50];
	int preference_seat;
	struct passenger_tag *prev;
	struct passenger_tag *next;
}passenger_type;
typedef struct seat_tag
{
	int booked;
	int count;
	int id;
}seat_type;
typedef struct coach_tag
{
	int count;
	seat_type lower[10];
	seat_type middle[10];
	seat_type upper[10];
	seat_type side_lower[5];
	seat_type side_upper[5];
	passenger_type* passenger_ptr;
	struct coach_tag *next;
	struct coach_tag *prev;
}coach_type;
typedef struct train_tag
{
	int count;
	struct train_tag * prev;
	struct train_tag * next;
	coach_type * coach_ptr;
}train_type;
void intitialise_seat(coach_type * ptr)
{
	int i;
	for(i=0;i<10;i++)
	{
		ptr->lower[i].booked=0;
		ptr->middle[i].booked=0;
		ptr->upper[i].booked=0;
	}
	for(i=0;i<5;i++)
	{
		ptr->side_lower[i].booked=0;
		ptr->side_upper[i].booked=0;	
	}
		for(i=0;i<10;i++)
		{
			ptr->lower[i].count=0;
			ptr->middle[i].count=0;
			ptr->upper[i].count=0;
		}
		for(i=0;i<5;i++)
		{
			ptr->side_lower[i].count=0;
			ptr->side_upper[i].count=0;	
		}
		for(i=0;i<10;i++)
		{
			ptr->lower[i].count=0;
			ptr->middle[i].count=0;
			ptr->upper[i].count=0;
		}
		for(i=0;i<5;i++)
		{
			ptr->side_lower[i].count=0;
			ptr->side_upper[i].count=0;	
		}
		for(i=0;i<10;i++)
		{
			ptr->lower[i].id=0;
			ptr->middle[i].id=0;
			ptr->upper[i].id=0;
		}
		for(i=0;i<5;i++)
		{
			ptr->side_lower[i].id=0;
			ptr->side_upper[i].id=0;	
	    }
}
coach_type *makecoach()
{
	coach_type* newnode;
	newnode=(coach_type*)malloc(sizeof(coach_type));
	newnode->count=-1;
	intitialise_seat(newnode);
	newnode->passenger_ptr=NULL;
	newnode->next=NULL;
	newnode->prev=NULL;
}
status_code addCouch(train_type* train_ptr,int train_count)
{
	status_code sc=SUCCESS;
	train_type *tptr;
	coach_type *ptr,*newnode;
	tptr=train_ptr;
	int count=1;

	if(tptr!=NULL)
	{

		printf("\n\ttrain is %d",tptr->count);
			while(tptr!=NULL&&tptr->count!=train_count)
			{
				tptr=tptr->next;
				printf("----train is %d",tptr->count);
			}
		newnode=makecoach();
		
		ptr=tptr->coach_ptr;
		if(ptr==NULL)
		{
			newnode->count=count;
			ptr=newnode;
			tptr->coach_ptr=ptr;
			printf("----couch is %d",newnode->count);
		}
		else
		{
			count++;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
				count++;
			}
			newnode->count=count;
			printf("----couch is %d",newnode->count);
			ptr->next=newnode;
			newnode->prev=ptr;
		}
	}
	else
	{
		sc=FAILURE;
	}	
	return sc;
}
train_type *generatetrain()
{
	train_type *newnode;
	newnode=(train_type *)malloc(sizeof(train_type));
	newnode->count=0;
	newnode->coach_ptr=NULL;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}
train_type* addTrain(train_type *train_ptr)
{
	train_type* newnode,*tptr=train_ptr;
	int count=1;
	if(tptr!=NULL)
	{
		count++;
		while(tptr->next!=NULL)
		{
			tptr=tptr->next;
			count++;
		}
		newnode=generatetrain();
		newnode->count=count;
		newnode->coach_ptr=NULL;
		tptr->next=newnode;
		newnode->prev=tptr;
	}
	else
	{
		newnode=generatetrain();
		newnode->count=count;
		newnode->coach_ptr=NULL;
		train_ptr=newnode;
	}
	return train_ptr;
}
train_type* displaytrain(train_type* tptr)
{
	train_type* ptr;
	ptr=tptr;
	while(ptr!=NULL)
	{
		printf("\ntrain_no %d",ptr->count);
		if(ptr->next!=NULL)
		{
			printf("\tnext train no is %d",ptr->next->count);
		}
		if(ptr->prev!=NULL)
		{
			printf("\tprev train no is %d",ptr->prev->count);
		}
		ptr=ptr->next;
	}
	return tptr;
}
int main()
{
	int i;
	 train_type* train_ptr=NULL;
	 train_ptr=addTrain(train_ptr);
	 train_ptr=addTrain(train_ptr);
	 train_ptr=addTrain(train_ptr);
	 train_ptr=displaytrain(train_ptr);
	 i=addCouch(train_ptr,01);
	 if(i==1)
	 {
	 printf("\n%d= success",i);
	 }
	 i=addCouch(train_ptr,01);
	 if(i==1)
	 {
	 printf("\n%d= success",i);
	 }
	 i=addCouch(train_ptr,2);
	 if(i==1)
	 {
	 printf("\n%d= success",i);
	 }
	 i=addCouch(train_ptr,2);
	 if(i==1)
	 {
	 printf("\n%d= success",i);
	 }
	 
	 
	 return 0; 
}
