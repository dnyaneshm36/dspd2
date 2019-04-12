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
  struct btree_tag *p[6];
  struct dblist *db[6];
}btree_node;

btree_node * give_empty_btree_node()
{
  int i;
  btree_node * new;
  new =(btree_node *)malloc(sizeof(btree_node));
  new->count=0;
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
btree_node * split_btreenode_when_5node_are_there(btree_node *root,int key)
{
  int i,done,flag=0;
  btree_node *ptr=root;
  if(ptr->count==5)
  {
        new_right=give_empty_btree_node;
        new_root=give_empty_btree_node;
        new_root->k[0]=ptr->k[2];
        new_root->p[0]=ptr;
        new_root->p[1]=new_right;
        for(i=3,i<5,i++)
        {
          new_right[i-3]=ptr->k[i];
          ptr->k[i]=-1;
        }
        ptr->k[2]=-1;
        if(ptr->db[0]!=NULL)
        {
            for(i=3;i<6;i++)
            {
                new_right->db[i-3]=ptr->db[i];
                ptr->db[i]=NULL;
            }
        }
        else
        {
          for(i=3;i<6;i++)
          {
              new_right->p[i-3]=ptr->p[i];
              ptr->db[i]=NULL;
          }
        }
  }
  else
  {
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
    }  }








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
  int i,done,flag=0,light;
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
      a[i]=ret_val->data;       //at i positiion we bring key
      for(j=(ptr->count)+1;j>i+1;j--)   //similiry pointer form
      {                                 //i+1pointer copyed to i+2 loca
        ptr->db[j]=ptr->db[j-1];    //  last db[count] copyed to db[count+1]
      }
      ptr->db[i+1]=ret_val;        //at i+1 pointer listed to madian or middle
          if(ptr->count==5)
          {
            //code for spliatint btree nodes
            root=split_btreenode_when_5node_are_there(root,ptr->k[2])
          }
    }
  }
}

int main()
{
  btree_node * root;
  root=NULL;

  return 0;
}
