#include<stdio.h>
#include<stdlib.h>
typedef enum {FAILURE,SUCCESS}status_code;
typedef struct tree_tag
{
	int data ;
	struct tree_tag * left;
	struct tree_tag * right;
}tree_node;
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
tree_node * insert(tree_node *root,tree_node *node)
{
	tree_node *p=root;
	int done;
		if(p=NULL)
		{
			root=node;
		}
		else
		{
			done=0;
				while (!done)
				 {
						if (node->data<p->data)
						{
								if (p->left==NULL)
								{
									p->left=node;
									done=1;
								}
								else
								{
									p=p->left;
								}
						}
						else if (node->data>p->data)
						{
							if (p->right==NULL)
							{
								p->right=node;
								done=1;
							}
							else
							{
								p=p->right;
							}
						}
						else if (node->data!=p->data)
						{
							printf("error\n");
							done=1;
						}
				}
		}
}
status_code delete_reachingthat_node(tree_node *root ,int d)
{
	status_code sc=SUCCESS;
	tree_node * p=root;
	tree_node * prev=NULL;
		while ((p!=NULL&&p->data==d))
		{
				if(p->data<d)
				{
					prev= p;
					p=p->left;
				}
				else
				{
					prev=p;
					p=p->right;
				}
		}
		if(p==NULL)
		{
			sc=FAILURE;
		}
		else
		{
			if(prev==NULL)
			{
				delete_node(root);
			}
			else
			{
					if (p=prev->left)
					{
						delete_node(&prev->left);
					}
					else
					{
						delete_node(&prev->right);
					}
			}
		}
		return sc;
}
delete_node(tree_node **pptr)
{
	 tree_node *temp,*p,*prev;
	 p=*pptr;
		if(p->right==NULL)
		{
			*pptr=p->left;
			free(p);
		}
		else if(p->left==NULL)
		{
			*pptr=p->right;
			free(p);
		}
		else
		{
			temp=p->left;
			if(temp->right==NULL)
			{
				*pptr=temp;
				temp->right=p->left;
				free(p);
			}
			else
			{
				while(temp->right!=NULL)
				{
					prev=temp;
					temp=temp->right;
				}
				prev->right=temp->left;
				*pptr=temp;
				temp->left=p->left;
				temp->right=p->right;
				free(p);
			}

		}
}
int main ()
{
	return 0;
}
