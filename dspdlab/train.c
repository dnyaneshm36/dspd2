#include<stdio.h>
#include<stdlib.h>
typedef struct coach_tag
{
 	int lower[10];
 	int middle[10];
 	int upper[10];
 	int side_lower[5];
 	int side_upper[5];
 	struct couch_tag *next;
 	struct couch_tag *pre;
 	
}couch_type;
typedef struct passenger_tag
{
	int pass_id;
	char name[100];
	char address[100];
	long int phoneno;
	int age;
	//berth prefrence   
	int train_id;
	int train_class;
	struct passenger_tag *next;
	struct passenger_tag *pre;	
}passenger_type;


