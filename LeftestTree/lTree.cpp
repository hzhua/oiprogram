#include<stdio.h>
#include<stdlib.h>
#include<cstring>
struct Node
	{
	int v,dist;
	Node *left;
	Node *right;
	};
Node mem[100000];
int useN;
Node *makeTree(int x)
	{
	mem[++useN].v=x;
	mem[useN].dist=0;
	mem[useN].left=mem[useN].right=NULL;
	return &mem[useN];
	}
Node *merge(Node *x,Node *y)
	{
	if(x == NULL) return y;
	if(y == NULL) return x;
	if(y->v < x->v)
		{Node *tmp=x;x=y;y=tmp;}
	x->right = merge(x->right,y);
	if(x->left == NULL || x->left->dist < x->right->dist)
		{Node *tmp=x->left;x->left=x->right;x->right=tmp;}
	if(x->right == NULL)
		x->dist=0;
	else 
		{
		x->dist = x->right->dist+1;
		}
	return x;
	}
Node *insert(int x,Node *root)
	{
	Node *nx=makeTree(x);
	return merge(nx,root);
	}
Node *pop(Node *root)
	{
	Node *l=root->left;
	Node *r=root->right;
	return merge(l,r);
	}
void output(Node *p)
	{
	if(p==NULL)return;
	printf("%d",p->v);
	printf("(");
	output(p->left);
	printf(")");
	printf("(");
	output(p->right);
	printf(")");
	}
int main()
	{
	Node *x1=makeTree(7);
	x1=insert(8,x1);
	x1=insert(346,x1);
	x1=insert(15,x1);
	x1=insert(32,x1);
	
	Node *x2=makeTree(4);
	x2=insert(8,x2);
	x2=insert(96,x2);
	
	printf("x2 min:%d\n",x2->v);
	printf("x1 min:%d\n",x1->v);
	x1=merge(x1,x2);
	printf("merge min:%d\n",x1->v);
	x1=pop(x1);
	x1=pop(x1);
	x1=pop(x1);
	x1=pop(x1);
	x1=pop(x1);
	printf("merge min:%d\n",x1->v);
	
	output(x1);
	return 0;
	} 
