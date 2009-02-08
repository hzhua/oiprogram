#include<stdio.h>
#include<stdlib.h>
struct tttree
	{
	tttree *left,*right,*mid,*extra;
	tttree *par;
	int v1,v2;
	int type;
	void needswap(){if(v1>v2&&type==3){int t=v1;v1=v2;v2=t;}}
	tttree(int a){left=right=mid=extra=par=NULL;v1=a;type=2;}
	tttree(){left=right=mid=extra=par=NULL;type=v1=v2=0;}
	};
tttree *root;
int min(int a,int b,int c){int t=a<b?a:b;return t<c?t:c;}
int max(int a,int b,int c){int t=a>b?a:b;return t>c?t:c;}
bool isleaf(tttree *x){return x->left==NULL;}
void sort(tttree *cur)
	{
	tttree *arr[]={cur->left,cur->right,cur->mid,cur->extra};
	for(int i=0;i<=3;i++)
		for(int j=i;j<=3;j++)
			if(arr[i]->v1>arr[j]->v1) //!!!FORGET
			{tttree *t=arr[i];arr[i]=arr[j];arr[j]=t;}
	cur->left=arr[0];
	cur->mid=arr[1];
	cur->right=arr[2];
	cur->extra=arr[3];
	}
void split(tttree *cur,int num)
	{
	tttree *n1=new tttree(min(cur->v1,cur->v2,num));
	tttree *n2=new tttree(max(cur->v1,cur->v2,num));
	int x=cur->v1+cur->v2+num-n1->v1-n2->v1;
	tttree *p;
	if(cur->par==NULL)
		{
		p=new tttree(x);
		root=p;
		}
	else p=cur->par;
	n1->par=p;
	n2->par=p;
	if(x<p->v1)
		{
		p->left=n1;
		p->extra=n2;
		}
	else if((p->type==3&&x>p->v2)||(p->type==2&&x>p->v1))
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
		n1->left=cur->left;
		n1->right=cur->mid;
		n2->left=cur->right;
		n2->right=cur->extra;
		cur->left->par=n1;
		cur->mid->par=n1;
		cur->right->par=n2;
		cur->extra->par=n2;
		}
	delete cur;//FORGET!
	if(x==p->v1)
		{
		p->left=n1;
		p->right=n2;
		return;
		}
	if(p->type==2)
		{
		p->type=3;
		p->v2=x;
		p->needswap();
		p->mid=p->extra;
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
			cur->needswap();
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
	for(int i=1;i<=200;i++)
		{
		int x=rand()%1000;
		insert(root,x);
		}
	inorder(root);
	return 0;
	}
