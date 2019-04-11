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
  int k[4];
  int count;
  struct btree_tag *p[5];
  struct dblist *db[5];
}btree_node;

btree_node * give_empty_btree_node()
{
  int i;
  btree_node * new;
  new =(btree_node *)malloc(sizeof(btree_node));
  new->count=0;
  for(i=0;i<4;i++)
  {
    new->k[i]=-1;
    new->db[i]=NULL;
    new->p[i]=NULL;
  }
  new->db[4]=NULL;
  new->p[4]=NULL;
  return new;
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
  int i,done,flag=0;
  btree_node *ptr,*temp;
  dblist_type *ret_val;
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
          if ((new->data)<ptr->k[i])              //stoping when key is less than array(key) of i
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
    for(i=0;i<4&&done==0;i++)  //at most we are cheacking next  4 record from bottom list
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
  }
}

int main()
{
  btree_node * root;
  root=NULL;

  return 0;
}
