#include<stdio.h>
#include<stdlib.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
struct tttree
	{
	tttree *left,*right,*mid,*extra;
	int v1,v2,type;
	tttree *par;
	void swap()
		{
		if(type==3&&v1>v2)
			{int t=v1;v1=v2;v2=t;}
		}
	tttree(int num)
		{
		left=par=right=mid=extra=NULL;
		v1=num;type=2;
		v2=0;
		}
	};
tttree *root=NULL;	
	
bool isleaf(tttree *cur){if(cur->left==NULL)return true;return false;}
void sort(tttree *cur)
	{
	tttree *arr[4]={cur->left,cur->mid,cur->right,cur->extra};
	rep(i,0,3)
		rep(j,i,3)
			if(arr[i]->v1>arr[j]->v1) //!!!!Forget v1
				{tttree *t=arr[i];arr[i]=arr[j];arr[j]=t;}
	cur->left=arr[0];
	cur->mid=arr[1];
	cur->right=arr[2];
	cur->extra=arr[3];
	}
int min(int a,int b,int c){int t=a<b?a:b;return t<c?t:c;}
int max(int a,int b,int c){int t=a>b?a:b;return t>c?t:c;}
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
	else
		p=cur->par;
	n1->par=p;
	n2->par=p;
	if(x<p->v1)
		{
		p->left=n1;
		p->extra=n2;
		}
	else if((x>p->v1&&p->type==2)||(x>p->v2&&p->type==3))
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
	delete cur;
	if(x==p->v1)
		{
		p->left=n1;
		p->right=n2;
		return;
		}
	if(p->type==2)
		{
		p->type=3;
		p->mid=p->extra;
		p->v2=x;
		p->swap();
		}
	else
		split(p,x);
	return;
	}
void insert(tttree *cur,int num)
	{
	if(cur==NULL)
		{
		root=new tttree(num);
		return;
		}
	if(num==cur->v1||(cur->type==3&&num==cur->v2))
		return;
	if(isleaf(cur))
		{
		if(cur->type==2)
			{cur->type=3;cur->v2=num;cur->swap();}
		else split(cur,num);
		return;
		}
	if(num<cur->v1)
		insert(cur->left,num);
	else if((num>cur->v1&&cur->type==2)||(num>cur->v2&&cur->type==3))
		insert(cur->right,num);
	else if(cur->type==3)
		insert(cur->mid,num);
	return;
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
	rep(i,1,10000)
		{
		int x=rand()%100000;
		insert(root,x);
		}
	inorder(root);
	return 0;
	}
