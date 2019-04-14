#include<stdio.h>
#include<stdlib.h>
typedef enum {FAILURE,SUCCESS}status_code;

typedef struct dblist
{
  int data;
  struct dblist *prev;
  struct dblist *next;
}dblist_type;
typedef struct btree_tag
{
  int k[5];
  int count;
  int count_record;
  struct btree_tag *p[6];
  struct dblist *db[6];
}btree_node;

//all funtion defintion
btree_node * give_empty_btree_node();
status_code insert_betn_dbnodes(dblist_type *temp,dblist_type *newnode);
int give_no_of_records_in_list(dblist_type *start,dblist_type *nextstart);
void display(btree_node * root,int count);
btree_node * split_btreenode_when_5node_are_there(btree_node *root,int key);
dblist_type * search_for_record(btree_node * root ,int key);
btree_node* insert_record(btree_node * root ,dblist_type* newnode);
btree_node * adject_btree_node_when1(btree_node *root,int key);
void delete_db_node(dblist_type * target);
btree_node * manage_btree_just_replacing(btree_node *root,int old,int new);
btree_node * delete(btree_node * root,int key);

btree_node * give_empty_btree_node()
{
  int i;
  btree_node * new;
  new =(btree_node *)malloc(sizeof(btree_node));
  new->count=0;
  new->count_record=0;
  for(i=0;i<5;i++)
  {
    new->k[i]=-1;
    new->db[i]=NULL;
    new->p[i]=NULL;
  }
  new->db[5]=NULL;
  new->p[5]=NULL;
  return new;
}
status_code insert_betn_dbnodes(dblist_type *temp,dblist_type *newnode)
 {
  /*this code is add newnode before temp*/
  status_code sc=SUCCESS;
    dblist_type *before;
  if (temp==NULL||newnode==NULL)
  {
    sc=FAILURE;
  }
  else
  {
      if(temp->prev==NULL)
      {
        newnode->next=temp;
        newnode->prev=NULL;
        temp->prev=newnode;
      }
      else
      {
        before =temp->prev;
        newnode->next=temp;
        newnode->prev=before;
        before->next=newnode;
        temp->prev=newnode;
      }
  }
        return sc;
}
int give_no_of_records_in_list(dblist_type *start,dblist_type *nextstart)
{
  int count=0;
  dblist_type *temp=start;
  while(temp!=nextstart&&(temp->data<=nextstart->data)) //no nead to give second condition
  {                                       //but still for extra protection lol.
    count++;
    temp=temp->next;
  }
  return count;
}
void display(btree_node * root,int count)
{
   int i;
   printf("[");
   for(i=0;i<root->count;i++)
   {
   printf("%d|",root->k[i]);
  }
   printf("]\n");
   if(root->db[0]!=NULL)
   {
     for(i=0;i<root->count+1;i++)
     {
       display(root->p[i],count*10);
     }
   }
   else
   {

   }
}
btree_node * split_btreenode_when_5node_are_there(btree_node *root,int key)
{
  int i,j,done,flag=0;
  btree_node *ptr=root;
  btree_node *new_root,*new_right,*previous;
  new_right=give_empty_btree_node();
  if(ptr->count==5)    //root node is full
  {
        new_root=give_empty_btree_node();
        new_root->k[0]=ptr->k[2];   //new root value
        new_root->p[0]=ptr;
        new_root->p[1]=new_right;
        root=new_root;
/*just spleatting the ptr and new_right*/
        for(i=3;i<5;i++)     //coping key to new_right only 2 keys
        {
          new_right->k[i-3]=ptr->k[i];
          ptr->k[i]=-1;         //unessery are intillized
        }
        ptr->k[2]=-1;       //unnessery
        if(ptr->db[0]!=NULL)   //btree_tag at just abouve the root level
        {
            for(i=3;i<6;i++)   //3 pointer for db are copyed
            {
                new_right->db[i-3]=ptr->db[i];
                ptr->db[i]=NULL;   //those are copyed they are intillized
            }
        }
        else     //same above thing with the pointer of btree_tag
        {
          for(i=3;i<6;i++)   //b
          {
              new_right->p[i-3]=ptr->p[i];
              ptr->db[i]=NULL;
          }
        }
  }
  else   //not dealing with root node
  {
      previous=NULL;
      while (flag==0)
      {
          if(ptr->count==5)   //stop when count means that node have to split
          {
            flag=1;
          }
          else       //this for goto apporait ptr means btree_node
          {
              done=0;
              for(i=0;i<4&&done==0&&(ptr->k[i])!=-1&&i<(ptr->count);i++)     //tavaling in key array of size 4
              {                                     //stoping when we get empty space which is -1
                  if (key<ptr->k[i])              //stoping when key is less than array(key) of i
                  {                               //count element to extra protection
                    done=1;
                  }
              }                                     //exiting loop i++ is perform
              if(done==1)                          //decrease beacause of lesserkeys
              {                                   //found at pointer array of btree_tag
                i--;
              }
              if(ptr->p[0]!=NULL)          //to check weather this btree_node is not last
              {
                previous=ptr;       //travaling way such that prev is get
                ptr=ptr->p[i];
              }
          }
      }
/*just spleatting the ptr and new_right*/
      for(i=3;i<5;i++)     //coping key to new_right only 2 keys
      {
        new_right->k[i-3]=ptr->k[i];
        ptr->k[i]=-1;         //unessery are intillized
      }
      ptr->k[2]=-1;       //unnessery
      if(ptr->db[0]!=NULL)   //btree_tag at just abouve the root level
      {
          for(i=3;i<6;i++)   //3 pointer for db are copyed
          {
              new_right->db[i-3]=ptr->db[i];
              ptr->db[i]=NULL;   //those are copyed they are intillized
          }
      }
      else     //same above thing with the pointer of btree_tag
      {
        for(i=3;i<6;i++)   //b
        {
            new_right->p[i-3]=ptr->p[i];
            ptr->db[i]=NULL;
        }
      }
//end the spleatting
//just remaining to put key in previous btree_node and check weather the previous count ==5
        for(i=0;done=0&&i<previous->count&&i<4&&previous->k[i]!=-1;i++)
        {
              if(key<previous->k[i])
              {
                  done=1;
              }
        }
        if(done==1)
        {
          i--;
        }
        previous->count++;
        for(j=previous->count;j>i;j--)   //pushing data one location ahead
        {                         //j can reach upto i+1 there a[i]copyed
          previous->k[j]=previous->k[j-1];     //form j max is count so a[last bit not val(-1)copyed]
        }
        previous->k[i]=key;       //at i positiion we bring key
        if(previous->p[0]!=NULL)   //most almost this thing happed on safeside i check
        {
              for(j=(previous->count)+1;j>i+1;j--)   //similiry pointer form
              {                                 //i+1pointer copyed to i+2 loca
                previous->p[j]=previous->p[j-1];    //  last p[count] copyed to p[count+1]
              }
          previous->p[i+1]=new_right;        //at i+1 pointer listed to madian or middle
        }
            if(previous->count==5)
            {
              //code for spliatint btree nodes
              root=split_btreenode_when_5node_are_there(root,previous->k[2]);
            }
  }
return root;
}
dblist_type * search_for_record(btree_node * root ,int key)
{
  int i,done,flag=0;
  btree_node *ptr=root;
  dblist_type *ret_val;
  while (flag==0)
  {
      done=0;
      for(i=0;i<4&&done==0&&(ptr->k[i])!=-1&&i<(ptr->count);i++)     //tavaling in key array of size 4
      {                                     //stoping when we get empty space which is -1
        if (key<ptr->k[i])              //stoping when key is less than array(key) of i
        {                               //count element to extra protection
          done=1;
        }
      }                                     //exiting loop i++ is perform
      if(done==1)                          //decrease beacause of lesserkeys
      {                                   //found at pointer array of btree_tag
        i--;
      }
      if(ptr->p[0]!=NULL)          //to check weather this btree_node is not last
      {
        ptr=ptr->p[i];
      }
      else                       //going for dblist_type list
      {                          //that mean record nodes
        flag=1;
      }
  }
    ret_val=ptr->db[i];
    for(i=0;i<4&&done==0;i++)  //at most we are cheacking next  4 record
    {
      if(ret_val->data==key)
      {
        done=1;              //got it what i want
      }
      else if(key>ret_val->data&&ret_val->next!=NULL) //key should greater current record
      {                                           // beacause chances geting record
        ret_val=ret_val->next; //
      }
    }
    if(done==0) //we not found in next 4 record
    {
      printf("\nerror :-not found element or tree is not remain bst tree\n" );
      ret_val=NULL;
    }
    return ret_val;
}
btree_node* insert_record(btree_node * root ,dblist_type* newnode)
{
  int i,j,done,flag=0,light;
  btree_node *ptr,*temp;
  dblist_type *ret_val,*start,*end;
  int no_list_node;
  ptr=root;
  if(ptr==NULL) //empty tree
  {
    temp=give_empty_btree_node(); //give empty btree_node
    temp->k[0]=newnode->data;
    temp->db[0]=newnode;
    root= temp;       //root changes to btree_node
  }
  else
  {
    while (flag==0)
    {
        done=0;
        for(i=0;i<4&&done==0&&(ptr->k[i])!=-1&&i<(ptr->count);i++)     //tavaling in key array of size 4
        {                                     //stoping when we get empty space which is -1
          if ((newnode->data)<ptr->k[i])              //stoping when key is less than array(key) of i
          {                               //count element to extra protection
            done=1;
          }
        }                                     //exiting loop i++ is perform
        if(done==1)                          //decrease beacause of lesserkeys
        {                                   //found at pointer array of btree_tag
          i--;
        }
        if(ptr->p[0]!=NULL)          //to check weather this btree_node is not last
        {
          ptr=ptr->p[i];
        }
        else                       //going for dblist_type list
        {                          //that mean record nodes
          flag=1;
          start=ptr->db[i];           //both start and end need leter for counting node
          end=ptr->db[i+1]; //in the dblist. nextstartof node_dblist
        }
    }
    ret_val=ptr->db[i];                 //start of node_dblist
    no_list_node=give_no_of_records_in_list(start,end);  //it seding start and start of new list
    for(i=0;i<no_list_node&&done==0;i++)  //at most we are cheacking next  4 record from bottom list
    {
      if((newnode->data)>ret_val->data&&ret_val->next!=NULL) //node data should greater current record
      {                                           // beacause chances geting record
        ret_val=ret_val->next; //
      }
    }
    light=insert_betn_dbnodes(ret_val,newnode); //this fun insert newnode before ret_val
    no_list_node++;     //one is added
    if (no_list_node==5)
    {
      //code for spleatting db list
      ret_val=ptr->db[i];  //starting for sublist
      ret_val=ret_val->next;
      ret_val=ret_val->next;   //reached at median or middle
      ptr->count++;            //count of on of nodes are ++
      for(j=ptr->count;j>i;j--)   //pushing data one location ahead
      {                         //j can reach upto i+1 there a[i]copyed
        ptr->k[j]=ptr->k[j-1];     //form j max is count so a[last bit not val(-1)copyed]
      }
      ptr->k[i]=ret_val->data;       //at i positiion we bring key
      for(j=(ptr->count)+1;j>i+1;j--)   //similiry pointer form
      {                                 //i+1pointer copyed to i+2 loca
        ptr->db[j]=ptr->db[j-1];    //  last db[count] copyed to db[count+1]
      }
      ptr->db[i+1]=ret_val;        //at i+1 pointer listed to madian or middle
          if(ptr->count==5)
          {
            //code for spliatint btree nodes
            root=split_btreenode_when_5node_are_there(root,ptr->k[2]);
          }
    }
  }
}


int magic_number(btree_node *ptr)
{
    int x,done=0;
    while(!done)
    {
       if(ptr->p[0]!=NULL)
       {
         ptr=ptr->p[0];
       }
       else
       {
         done=1;
       }
    }
    return ptr->db[0]->data;
}
btree_node * adject_btree_node_when1(btree_node *root,int key)
{
// real quick information what it do just node where key key is present
//there is 1 elemnt situation happen so
//if there is key in root them to it ok
//nothing to do

//if left_bro has enough broght from present of parant
//try for same thing from right_bro
// merge them see what will done
  int i,j,k,done,flag=0,light,new,old;
  btree_node *ptr,*temp,*father,*left_bro,*right_bro;
  dblist_type *ret_val,*start,*end;
  int no_list_node,father_ith_child;
  int no_ofnode_inleft_list,no_ofnode_inright_list;
  if(ptr->count==0) //empty tree
  {
// revemove  two  figerout leter
        printf("\n \n");
  }
  else if(ptr->count==1)
  {
      while (flag==0)
      {
        if(ptr->k[0]==key)
        {
          flag=1;
        }
        else
        {
            done=0;
            for(i=0;i<4&&done==0&&(ptr->k[i])!=-1&&i<(ptr->count);i++)     //tavaling in key array of size 4
            {                                     //stoping when we get empty space which is -1
              if ((key)<ptr->k[i])              //stoping when key is less than array(key) of i
              {                               //count element to extra protection
                done=1;
              }
            }                                     //exiting loop i++ is perform
            if(done==1)                          //decrease beacause of lesserkeys
            {                                   //found at pointer array of btree_tag
              i--;
            }
            if(ptr->p[0]!=NULL)          //to check weather this btree_node is not last
            {
              father_ith_child=i;
              father=ptr;
              ptr=ptr->p[i];
            }
        }
      }
      if(father_ith_child==0)  //left most ptr
      {
        //take form try to take righ with pointer
        //if it had take it form it means copy in right_bro->[0]
        // to ptr->[1]
        right_bro=father->p[father_ith_child+1];
          if(right_bro!=NULL&&right_bro->count>2)
          {
            //try form right
            right_bro=father->p[father_ith_child+1];
            if(ptr->p[0]!=NULL)   //not second last most leaf
            {
               ptr->k[1]=right_bro->k[0];
               ptr->p[2]=right_bro->p[0];
               old=magic_number(right_bro); ///
               new=magic_number(right_bro->p[1]);
               for(j=0;j<right_bro->count;j++)
               {
                 right_bro->k[j]=right_bro->k[j+1];
               }
               for(j=0;j<right_bro->count+1;j++)
               {
                 right_bro->p[j]=right_bro->p[j+1];
               }
               root=manage_btree_just_replacing(root,old,new);
            }
            else if(ptr->db[0]!=NULL)  //second last leaf
            {
               ptr->k[1]=right_bro->k[0];
               ptr->db[2]=right_bro->db[0];
               old=magic_number(right_bro); ///
               new=right_bro->db[1]->data;
               for(j=0;j<right_bro->count;j++)
               {
                 right_bro->k[j]=right_bro->k[j+1];
               }
               for(j=0;j<right_bro->count+1;j++)
               {
                 right_bro->db[j]=right_bro->db[j+1];
               }
               root=manage_btree_just_replacing(root,old,new);
            }
          }
          else
          {
             //merge into right_bro
             ptr->k[1]=father->k[father_ith_child];
             ptr->k[2]=right_bro->k[0];
             ptr->k[3]=right_bro->k[1];
                if(ptr->p[0]!=NULL)
                {
                  ptr->p[2]=right_bro->p[0];
                  ptr->p[3]=right_bro->p[1];
                  ptr->p[4]=right_bro->p[2];
                }
                else
                {
                  ptr->db[2]=right_bro->db[0];
                  ptr->db[3]=right_bro->db[1];
                  ptr->db[4]=right_bro->db[2];
                }
             for(k=father_ith_child;k<father->count;k++)
             {
               father->k[k]=father->k[k+1];
               father->p[k+1]=father->p[k+2];
             }
             father->count--;
             free(right_bro);
             right_bro=NULL;
              if(father->count<2)
              {
                  root=adject_btree_node_when1(root,father->k[0]);
              }
          }
      }
      else if(father_ith_child==father->count) //right most node right_bro=N
      {
         // check for left left_bro it had take it form left_bro
         //if not then take merge with left
         left_bro=father->p[father_ith_child-1];
           if(left_bro!=NULL&&left_bro->count>2)
           {
             //take form left
             if(ptr->p[0]!=NULL)   //not second last most leaf
             {
                for(j=ptr->count;j>0;j--)
                {
                  ptr->k[j+1]=ptr->k[j];
                }
                for(j=ptr->count+1;j>0;j--)
                {
                  ptr->p[j]=ptr->p[j+1];
                }
                ptr->k[0]=left_bro->k[left_bro->count];
                ptr->p[0]=left_bro->p[left_bro->count+1];
             }
             else if(ptr->db[0]!=NULL)  //second last leaf
             {
               for(j=ptr->count;j>0;j--)
               {
                 ptr->k[j+1]=ptr->k[j];
               }
               for(j=ptr->count+1;j>0;j--)
               {
                 ptr->db[j]=ptr->db[j+1];
               }
               root=manage_btree_just_replacing(root,ptr->k[0],left_bro->k[left_bro->count]);
               ptr->k[0]=ptr->db[2]->data;
               ptr->db[0]=left_bro->db[left_bro->count+1];
             }
           }
           else
           {
             //merge with left
             left_bro->k[2]=father->k[father_ith_child];
             left_bro->k[3]=ptr->k[0];
             if(ptr->p[0]!=NULL)
             {
               left_bro->p[3]=ptr->p[0];
               left_bro->p[4]=ptr->p[1];
             }
             else
             {
               left_bro->db[3]=ptr->db[0];
               left_bro->db[4]=ptr->db[1];
             }

             for(k=father_ith_child;k<father->count;k++)
             {
               father->k[k]=father->k[k+1];
               father->p[k+1]=father->p[k+2];
             }
             father->count--;
             free(ptr);
             ptr=NULL;
              if(father->count<2)
              {
                  root=adject_btree_node_when1(root,father->k[0]);
              }
           }
      }
      else  // to easy  left_bro&right_bro both ! NULL
      {   // first left_bro then right_bro else merge with left
        left_bro=father->p[father_ith_child-1];
        right_bro=father->p[father_ith_child+1];
            if(left_bro!=NULL&&left_bro->count>2)
            {
              //take form left
              if(ptr->p[0]!=NULL)   //not second last most leaf
              {
                 for(j=ptr->count;j>0;j--)
                 {
                   ptr->k[j+1]=ptr->k[j];
                 }
                 for(j=ptr->count+1;j>0;j--)
                 {
                   ptr->p[j]=ptr->p[j+1];
                 }
                 ptr->k[0]=left_bro->k[left_bro->count];
                 ptr->p[0]=left_bro->p[left_bro->count+1];
              }
              else if(ptr->db[0]!=NULL)  //second last leaf
              {
                for(j=ptr->count;j>0;j--)
                {
                  ptr->k[j+1]=ptr->k[j];
                }
                for(j=ptr->count+1;j>0;j--)
                {
                  ptr->db[j]=ptr->db[j+1];
                }
                root=manage_btree_just_replacing(root,ptr->k[0],left_bro->k[left_bro->count]);
                ptr->k[0]=ptr->db[2]->data;
                ptr->db[0]=left_bro->db[left_bro->count+1];
              }
            }
            else if(right_bro!=NULL&&right_bro->count>2)
            {
              //take form right
              if(ptr->p[0]!=NULL)   //not second last most leaf
              {
                 ptr->k[1]=right_bro->k[0];
                 ptr->p[2]=right_bro->p[0];
                 light=right_bro->k[0];
                 for(j=0;j<right_bro->count;j++)
                 {
                   right_bro->k[j]=right_bro->k[j+1];
                 }
                 for(j=0;j<right_bro->count+1;j++)
                 {
                   right_bro->p[j]=right_bro->p[j+1];
                 }
                 root=manage_btree_just_replacing(root,light,right_bro->k[0]);
              }
              else if(ptr->db[0]!=NULL)  //second last leaf
              {
                 ptr->k[1]=right_bro->k[0];
                 ptr->db[2]=right_bro->db[0];
                 light=right_bro->k[0];
                 for(j=0;j<right_bro->count;j++)
                 {
                   right_bro->k[j]=right_bro->k[j+1];
                 }
                 for(j=0;j<right_bro->count+1;j++)
                 {
                   right_bro->db[j]=right_bro->db[j+1];
                 }
                 root=manage_btree_just_replacing(root,light,right_bro->k[0]);
              }
            }
            else
            {
              //merge into left_bro
              left_bro->k[2]=father->k[father_ith_child];
              left_bro->k[3]=ptr->k[0];
              if(ptr->p[0]!=NULL)
              {
                left_bro->p[3]=ptr->p[0];
                left_bro->p[4]=ptr->p[1];
              }
              else
              {
                left_bro->db[3]=ptr->db[0];
                left_bro->db[4]=ptr->db[1];
              }

              for(k=father_ith_child;k<father->count;k++)
              {
                father->k[k]=father->k[k+1];
                father->p[k+1]=father->p[k+2];
              }
              father->count--;
              free(ptr);
              ptr=NULL;
               if(father->count<2)
               {
                   root=adject_btree_node_when1(root,father->k[0]);
               }

            }
      }

  }
  return root;
}
void delete_db_node(dblist_type * target)
{
  dblist_type * left;
  dblist_type * right;
  if(target->prev!=NULL&&target!=NULL)
  {
     left=target->prev;
     right=target->next;
     left->next=right;
     right->prev=left;
     free(target);
  }
  else if(target->prev!=NULL)
  {
    left=target->prev;
    left->next=NULL;
    free(target);
  }
  else if (target->next!=NULL)
  {
    right=target->next;
    right->prev=NULL;
    free(target);
  }
}
btree_node * manage_btree_just_replacing(btree_node *root,int old,int new)
{
    int i,flag=0,done=0;
    btree_node * ptr;
    ptr=root;
    if(ptr==NULL) //empty tree
    {
          printf("error:- tree is empty\n");
    }
    else
    {
  	    while (flag==0)
  	    {
  	        done=0;
  	        for(i=0;i<4&&(ptr->k[i])!=-1&&i<(ptr->count);i++)     //tavaling in key array of size 4
  	        {                                     //stoping when we get empty space which is -1
  	          if ((old)==ptr->k[i])              //stoping when key is less than array(key) of i
  	          {                               //count element to extra protection
  	            ptr->k[i]=new;
  	          }
  	        }                                     //exiting loop i++ is perform
  	        if(ptr->p[0]!=NULL)          //to check weather this btree_node is not last
  	        {
  	          ptr=ptr->p[i];
  	        }

        }
      }
  return root;
}
btree_node * delete(btree_node * root,int key)
{
  int i,j,k,done,flag=0,light;
  btree_node *ptr,*temp,*father,*left_bro,*right_bro;
  dblist_type *ret_val,*start,*end;
  int no_list_node,father_ith_child;
  int no_ofnode_inleft_list,no_ofnode_inright_list;
  ptr=root;
  father=NULL;
  if(ptr==NULL) //empty tree
  {
        printf("error:- tree is empty\n");
  }
  else
  {
	    while (flag==0)
	    {
	        done=0;
	        for(i=0;i<4&&done==0&&(ptr->k[i])!=-1&&i<(ptr->count);i++)     //tavaling in key array of size 4
	        {                                     //stoping when we get empty space which is -1
	          if ((key)<ptr->k[i])              //stoping when key is less than array(key) of i
	          {                               //count element to extra protection
	            done=1;
	          }
	        }                                     //exiting loop i++ is perform
	        if(done==1)                          //decrease beacause of lesserkeys
	        {                                   //found at pointer array of btree_tag
	          i--;
	        }
	        if(ptr->p[0]!=NULL)          //to check weather this btree_node is not last
	        {
            father_ith_child=i;
            father=ptr;
	          ptr=ptr->p[i];
	        }
	        else                       //going for dblist_type list
	        {                          //that mean record nodes
	          flag=1;
	          start=ptr->db[i];           //both start and end need leter for counting node
	          end=ptr->db[i+1]; //in the dblist. nextstartof node_dblist
	        }
	    }
      ret_val=ptr->db[i];                 //start of node_dblist
      no_list_node=give_no_of_records_in_list(start,end);  //it seding start and start of new list
      for(j=0;j<no_list_node&&done==0;j++)  //at most we are cheacking next  4 record from bottom list
      {
        if((key)==ret_val->data&&ret_val->next!=NULL) //node data should greater current record
        {                                           // beacause chances geting record
            if(no_list_node>2)
            {
                if(j==0&&i!=0)   //first node_dblist and i means it just above tree node
                {
                  ptr->k[i-1]=(ret_val->next)->data;
                }
                else if(i==0&&j==0)  //this means first list  & list first from above
                {                   //btree_node need to replace just where old key with new
                    root=manage_btree_just_replacing(root,key,(ret_val->next)->data);
                    //this just replace old key with new one
                }
                ptr->db[i]=ret_val->next;  //node deleted so next should pointed by dbpointer
                delete_db_node(ret_val);
            }
            else if(no_list_node==2)  //this become < than min ele.
            {
              // in this trafering record will happen so we have to know left_bro &right_bro (of ptr)
              //this list check the first left list if >2 record  take from left list
              //else if cheack right list >2 record take it from them.
              //else only condition remaining that left&right has 2 of record
              //in this condion megin will happed. and we will talk leter.
              left_bro=father->p[father_ith_child-1];
              right_bro=father->p[father_ith_child+1];
              //may any one of them are null so use just what you need
              //don't rush in null pointer error
              //just check i and figerout what to do
                  if(i==0) //use left_bro
                  {
                      no_ofnode_inleft_list=give_no_of_records_in_list(left_bro->db[left_bro->count+1],ptr->db[i]);
                      no_ofnode_inright_list=give_no_of_records_in_list(ptr->db[i],ptr->db[i+1]);
                      if(no_ofnode_inleft_list>2)
                      {
                        //taking form  max form left list
                        ptr->db[i]=(ptr->db[i])->prev;
                        //mix record is add in the list & we can easilly delete record
                        if(j==0&&i!=0)   //first node_dblist and i means it just above tree node
                        {
                          ptr->k[i-1]=(((ptr->db[i])->prev)->data); //i==0 not dont
                        }                                            //worry about any thing
                        else if(i==0&&j==0)  //this means first list  & list first from above
                        {                   //btree_node need to replace just where old key with new
                            root=manage_btree_just_replacing(root,(ret_val)->data,((ptr->db[i])->prev)->data);
                            //this just replace old key with new one
                        }
                        delete_db_node(ret_val);
                      }
                      else if(no_ofnode_inright_list>2)
                      {
                        //taking form right list min element
                        ptr->db[i+1]=ptr->db[i+1]->next;
                        //just move next pointer form array take it to forwared
                        //min record is added in the sublist
                        if(j==0&&i!=0)   //first node_dblist and i means it just above tree node
                        {
                          ptr->k[i-1]=(ret_val->prev)->data; //i==0
                        }
                        else if(i==0&&j==0)  //this means first list  & list first from above
                        {                   //btree_node need to replace just where old key with new
                            root=manage_btree_just_replacing(root,(ret_val)->data,(ret_val->next)->data);
                            //this just replace old key with new one
                        }
                        delete_db_node(ret_val);
                      }
                      else
                      {
                        //mean left tree and right tree noodes ==2
                        //mering in left list i==0
                        light=ret_val->data;
                        delete_db_node(ret_val);
                        ptr->count--;
                        for(k=i;k<ptr->count;k++)
                        {
                          ptr->db[k]=ptr->db[k+1];
                        }
                        for(k=i;k<ptr->count;k++)
                        {
                          ptr->k[k]=(ptr->db[k+1])->data;
                        }

                        if(j==0&&i!=0)   //first node_dblist and i means it just above tree node
                        {
                          ptr->k[i-1]=(ptr->db[0])->data; //i==0
                        }
                        else if(i==0&&j==0)  //this means first list  & list first from above
                        {                   //btree_node need to replace just where old key with new
                            root=manage_btree_just_replacing(root,light,(ptr->db[0])->data);
                            //this just replace old key with new one
                        }
                        if(ptr->count<2)
                        {
                          root=adject_btree_node_when1(root,ptr->k[0]);
                        }
                      }
                  }
                  else if(i==ptr->count+1)  //right_bro
                  {
                    no_ofnode_inright_list=give_no_of_records_in_list(ptr->db[i],right_bro->db[0]);
                    no_ofnode_inleft_list=give_no_of_records_in_list(ptr->db[i-1],ptr->db[i]);
                    if(no_ofnode_inleft_list>2)
                    {
                      //taking form  max form left list
                      ptr->db[i]=(ptr->db[i])->prev;
                      //max record is add in the list & we can easilly delete record
                      if(j==0&&i!=0)   //first node_dblist and i means it just above tree node
                      {
                        ptr->k[i-1]=(((ptr->db[i])->prev)->data);
                      }
                      else if(i==0&&j==0)  //this means first list  & list first from above
                      {                   //btree_node need to replace just where old key with new
                          root=manage_btree_just_replacing(root,(ret_val)->data,((ptr->db[i])->prev)->data);
                          //this just replace old key with new one
                      }
                      delete_db_node(ret_val);
                    }
                    else if(no_ofnode_inright_list>2)
                    {
                      //taking form right list min element
                      right_bro->db[0]=right_bro->db[0]->next;
                      if(j==0&&i!=0)   //first node_dblist and i means it just above tree node
                      {
                        ptr->k[i-1]=(ptr->db[0]->next)->data;
                      }
                      else if(i==0&&j==0)  //this means first list  & list first from above
                      {                   //btree_node need to replace just where old key with new
                          root=manage_btree_just_replacing(root,(ret_val)->data,(ret_val->next)->data);
                          //this just replace old key with new one
                      }
                      delete_db_node(ret_val);
                    }
                    else
                    {
                      //mean left tree and right tree noodes ==2
                      //mering in left list i==max
                      light=(ret_val->next)->data;
                      delete_db_node(ret_val);
                      ptr->count--;
                      for(k=i;k<ptr->count;k++)
                      {
                        ptr->db[k]=ptr->db[k+1];
                      }
                      for(k=i;k<ptr->count;k++)
                      {
                        ptr->k[k-1]=(ptr->db[k])->data;
                      }

                      if(j==0&&i!=0)   //first node_dblist and i means it just above tree node
                      {
                        ptr->k[i-1]=light; //i==max
                      }
                      else if(i==0&&j==0)  //this means first list  & list first from above
                      {                   //btree_node need to replace just where old key with new
                          root=manage_btree_just_replacing(root,light,(ptr->db[0])->data);
                          //this just replace old key with new one
                      }
                      if(ptr->count<2)
                      {
                        root=adject_btree_node_when1(root,ptr->k[0]);
                      }
                    }
                  }
                  else //that mean left &right list with in ptr that easy
                  {
                    no_ofnode_inright_list=give_no_of_records_in_list(ptr->db[i],ptr->db[i+1]);
                    no_ofnode_inleft_list=give_no_of_records_in_list(ptr->db[i-1],ptr->db[i]);
                    if(no_ofnode_inleft_list>2)
                    {
                      //taking form  max form left list
                      ptr->db[i]=(ptr->db[i])->prev;
                      //max record is add in the list & we can easilly delete record
                      if(j==0&&i!=0)   //first node_dblist and i means it just above tree node
                      {
                        ptr->k[i-1]=(((ptr->db[i])->prev)->data);
                      }
                      else if(i==0&&j==0)  //this means first list  & list first from above
                      {                   //btree_node need to replace just where old key with new
                          root=manage_btree_just_replacing(root,(ret_val)->data,((ptr->db[i])->prev)->data);
                          //this just replace old key with new one
                      }
                      delete_db_node(ret_val);
                    }
                    else if(no_ofnode_inright_list>2)
                    {
                      //taking form right list min element
                      ptr->db[i+1]=ptr->db[i+1]->next;
                      if(j==0&&i!=0)   //first node_dblist and i means it just above tree node
                      {
                        ptr->k[i]=(ptr->db[i])->data;
                      }
                      else if(i==0&&j==0)  //this means first list  & list first from above
                      {                   //btree_node need to replace just where old key with new
                          root=manage_btree_just_replacing(root,(ret_val)->data,(ret_val->next)->data);
                          //this just replace old key with new one
                      }
                      delete_db_node(ret_val);
                    }
                    else
                    {
                      //mean left tree and right tree noodes ==2
                      //mering in left list i!=0 not max
                      light=(ret_val->next)->data;
                      delete_db_node(ret_val);
                      ptr->count--;
                      for(k=i;k<ptr->count;k++)
                      {
                        ptr->db[k]=ptr->db[k+1];
                      }
                      for(k=i;k<ptr->count;k++)
                      {
                        ptr->k[k-1]=(ptr->db[k])->data;
                      }

                      if(j==0&&i!=0)   //first node_dblist and i means it just above tree node
                      {
                        ptr->k[i-1]=light; //i==0
                      }
                      else if(i==0&&j==0)  //this means first list  & list first from above
                      {                   //btree_node need to replace just where old key with new
                          root=manage_btree_just_replacing(root,light,(ptr->db[0])->data);
                          //this just replace old key with new one
                      }
                      if(ptr->count<2)
                      {
                        root=adject_btree_node_when1(root,ptr->k[0]);
                      }
                    }
                  }
            }
        }
        else
        {
          ret_val=ret_val->next; //
        }
      }
  }
  return root;
}
int main()
{
  btree_node * root;
  root=NULL;

  return 0;
}
