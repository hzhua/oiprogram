#include<stdio.h>
#include<stdlib.h>
#define canswap(p) if(p->v2<p->v1){int tmp=p->v2;p->v2=p->v1;p->v1=tmp;}
struct tttree
	{
	int type;
	int v1,v2;
	tttree *left,*right,*mid;
	tttree *extra;
	tttree *par;
	tttree(int num)
		{
		v1=num;
		v2=0;
		type=2;
		left=right=mid=extra=NULL;
		}
	tttree(){v1=v2=type=0;left=right=mid=extra=par=NULL;}
	};
tttree *root=NULL;
int max(int a,int b,int c){int t=a>b?a:b;return t>c?t:c;}
int min(int a,int b,int c){int t=a>b?b:a;return t>c?c:t;}
bool isleaf(tttree *cur){if(cur->left==NULL&&cur->right==NULL&&cur->mid==NULL)return true;return false;}
void sort(tttree *cur)
	{
	tttree *arr[4]={cur->left,cur->mid,cur->right,cur->extra};
	for(int i=0;i<=3;i++)
		for(int j=i;j<=3;j++)
			if(arr[i]->v1>arr[j]->v1)
				{tttree *tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;}
	cur->left=arr[0];
	cur->mid=arr[1];
	cur->right=arr[2];
	cur->extra=arr[3];
	}
void split(tttree *cur,int num)
	{
	tttree *n1=new tttree(min(cur->v1,num,cur->v2));
	tttree *n2=new tttree(max(cur->v1,num,cur->v2));
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
	else if((p->type==2&&x>p->v1)||(p->type==3&&x>p->v2))
		{
		p->right=n2;
		p->extra=n1;
		}
	else if(p->v1!=x)
		{
		p->mid=n2;
		p->extra=n1;
		}
	if(!isleaf(cur))
		{
		sort(cur);//left mid right extra
		n1->left=cur->left;
		n1->right=cur->mid;
		n2->left=cur->right;
		n2->right=cur->extra;
		cur->left->par=n1;
		cur->mid->par=n1;
		cur->right->par=n2;
		cur->extra->par=n2;
		}
	if(p->v1==x)
		{
		p->left=n1;
		p->right=n2;
		delete cur;
		return;
		}
	if(p->type==2)
		{
		p->mid=p->extra;
		p->v2=x;
		canswap(p);
		p->type=3;
		delete cur;
		}
	else
		{
		split(p,x);
		delete cur;
		}
	}
void insert(tttree *cur,int num)
	{
	if(cur==NULL){cur=new tttree(num);root=cur;return;}
	if(num==cur->v1)return;
	if(cur->type==3&&num==cur->v2)return;
	if(isleaf(cur))
		{
		if(cur->type==0) {cur->type=2;cur->v1=num;return;}
		if(cur->type==2) {cur->type=3;cur->v2=num;canswap(cur);return;}
		if(cur->type==3) {split(cur,num);}
		}
	else
		{
		
		if(cur->type==2)
			if(num<cur->v1)insert(cur->left,num);
			else insert(cur->right,num);
		else
			if(num<cur->v1)insert(cur->left,num);
			else if(num>cur->v2)insert(cur->right,num);
			else insert(cur->mid,num);
		}
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
bool exist(int x,tttree *cur)
	{
	if(x<cur->v1)return exist(x,cur->left);
	if(x==cur->v1)return true;
	if(cur->type==3)
		{
		if(x==cur->v2)return true;
		if(x>cur->v2)return exist(x,cur->right);
		else return exist(x,cur->mid);
		}
	else
		return exist(x,cur->right);
	}
int main()
	{
	for(int i=1;i<=500000;i++)
		{
		int x=rand();
		insert(root,x);
		}
	//nsert(root,2);
	//insert(root,2);
	inorder(root);
	//printf("\n%d\n",exist(1863293,root));
	return 0;
	}
	
