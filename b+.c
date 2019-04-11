#include<stdio.h>
#includ<stdlib.h>
typedef enum {FAILURE,SUCCESS}status_code;
typedef struct tree_tag
{
  int data ;
  struct tree_tag * left;
  struct tree_tag * right;
}tree_node;
typedef struct dblist
{
  int data;
  struct dblist * prev;
  struct dblist * next;
}dblit_type;
void visit(tree_node * ptr)
{
 	if(ptr!=NULL)
 	{
 	 printf("%d",ptr->data);
 	}
}
void preorder(tree_node *root)
{
 	if(root!=NULL)
 	{
 	visit(root);
 	preorder(root->left);
 	preorder(root->right);
 	}
}
void inorder(tree_node *root)
{
 	if(root!=NULL)
 	{
 	 inorder(root->left);
 	 visit(root);
 	 inorder(root->right);
 	}
}
void postorder(tree_node * root)
{
 	if(root)
 	{
 	 postorder(root->left);
 	 postorder(root->right);
 	 visit(root);
 	}
}
int countnodes(tree_node * root)
{
	int ret_val;
	if(root)
	{
	ret_val=0;
	}
	else
	{
	 ret_val=1+countnodes(root->left)+countnodes(root->right);
	}
  return ret_val;
}
int countleaves(tree_node * root)
{
	int ret_val;
	if(root!=NULL)
	{
	 ret_val=0;
	}
	else if(root->left!=NULL&&root->right!=NULL)
	{
	ret_val=1;
	}
	else
	{
	 ret_val=countleaves(root->left)+countleaves(root->right);
	}
 return ret_val;
}
int height(tree_node* root)
{
	int ret_val,left_height,right_height;
	if(root==NULL)
	{
	 ret_val=-1;
	}
	else if(root->left==NULL||root->right==NULL) //if we make this condition as comment
	{						//it will it take many checks end of
	 ret_val=0;				 //day it will not require.
	}
	else
	{
	left_height=height(root->left);
	right_height=height(root->right);
		if(left_height<right_height)
		{
		 ret_val=1+right_height;
		}
		else
		{
		 ret_val=1+left_height;
		}
	}
 return ret_val;
}
int main()
{
  tree_node * root;
  root=NULL;
  
  return 0;
}
