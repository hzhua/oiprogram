#include<stdio.h>
#include<stdlib.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define needswap(p) if(p->type==3&&p->v1>p->v2){int tmp=p->v1;p->v1=p->v2;p->v2=tmp;}
struct tttree
	{
	tttree *left,*right,*mid;
	int v1,v2;
	int type;
	tttree *extra;
	tttree *par;
	tttree(int num)
		{
		left=right=mid=extra=NULL;
		v1=num;v2=0;
		type=2;
		}
	};
tttree *root;
bool isleaf(tttree *cur){if(cur->left==NULL&&cur->mid==NULL&&cur->right==NULL)return true;return false;}
void sort(tttree *cur)
	{
	tttree *arr[4]={cur->left,cur->mid,cur->right,cur->extra};
	rep(i,0,3)
		rep(j,i,3)
			if(arr[i]->v1>arr[j]->v1)
				{tttree *x=arr[i];
				arr[i]=arr[j];arr[j]=x;
				}
	cur->left=arr[0];
	cur->mid=arr[1];
	cur->right=arr[2];
	cur->extra=arr[3];
	}
int min(int a,int b,int c){int t=a>b?b:a;return t>c?c:t;}
int max(int a,int b,int c){int t=a>b?a:b;return t>c?t:c;}
void split(tttree *cur,int num)
	{
	tttree *n1=new tttree(min(cur->v1,num,cur->v2));
	tttree *n2=new tttree(max(cur->v1,num,cur->v2));
	int x=cur->v1+num+cur->v2-n1->v1-n2->v1;
	
	tttree *p=NULL;
	if(cur->par==NULL)
		{
		p=new tttree(x);
		root=p;
		}
	else
		p=cur->par;
	n1->par=p;
	n2->par=p;
	if(x<p->v1)
		{
		p->left=n1;
		p->extra=n2;
		}
	else if((p->type==2&&x>p->v1)||(p->type==3&&x>p->v2))
		{
		p->right=n2;
		p->extra=n1;
		}
	else if(x!=p->v1)
		{
		p->mid=n1;
		p->extra=n2;
		}
	
	if(!isleaf(cur))
		{
		sort(cur);
		cur->left->par=n1;n1->left=cur->left;
		cur->mid->par=n1;n1->right=cur->mid;
		cur->right->par=n2;n2->left=cur->right;
		cur->extra->par=n2;n2->right=cur->extra;
		}
	delete cur;
	if(p->v1==x)
		{
		p->left=n1;  //!!!!FORGET
		p->right=n2; //!!!!FORGET
		return;
		}
	if(p->type==2)
		{
		p->mid=p->extra;  //!!!FORGET
		p->type=3;
		p->v2=x;
		needswap(p);
		}
	else
		split(p,x);
	}
void insert(tttree *cur,int num)
	{
	if(cur==NULL)
		{
		cur=new tttree(num);
		root=cur;
		return;
		}
	if(num==cur->v1||(cur->type==3&&cur->v2==num))return;
	if(isleaf(cur))
		{
		if(cur->type==2)
			{
			cur->v2=num;
			cur->type=3;
			needswap(cur);
			}
		else if(cur->type==3)
			split(cur,num);
		return;
		}
	if(num<cur->v1)insert(cur->left,num);
	else if(cur->type==2&&num>cur->v1)insert(cur->right,num);
	else if(cur->type==3&&num>cur->v2)insert(cur->right,num);
	else	if(cur->type==3)insert(cur->mid,num);
	}
void inorder(tttree *cur)
	{
	if(cur==NULL)return;
	inorder(cur->left);
	printf("%d ",cur->v1);
	if(cur->type==3)
		{
		inorder(cur->mid);
		printf("%d ",cur->v2);
		}
	inorder(cur->right);
	}
int main()
	{
	rep(i,1,20000)
		{
		int x=rand();
		insert(root,x);
		}
	inorder(root);
	return 0;
	}
