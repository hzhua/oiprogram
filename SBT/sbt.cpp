#include<stdio.h>
//#define LEFT 1
//#define RIGHT 0
#define LEFT 0
#define RIGHT 1
#define SIZE 10000
int arr[SIZE],an;
int left[SIZE],right[SIZE];
int size[SIZE];
int father[SIZE];
int root;
void update(int x){size[x]=size[left[x]]+size[right[x]]+1;}
int rr(int x)
	{
	int y=father[x];
	if(y==root)root=x;
	left[y]=right[x];
	if(right[x]!=0)
		father[right[x]]=y;
	father[x]=father[y];
	if(father[y]!=0)
		{
		if(left[father[y]]==y)
			left[father[y]]=x;
		else right[father[y]]=x;
		}
	right[x]=y;
	father[y]=x;
	update(y);
	update(x);
	}
int lr(int x)
	{
	int y=father[x];
	if(y==root)root=x;
	right[y]=left[x];
	if(left[x]!=0)
		father[left[x]]=y;
	father[x]=father[y];
	if(father[y]!=0)
		{
		if(left[father[y]]==y)
			left[father[y]]=x;
		else right[father[y]]=x;
		}
	left[x]=y;
	father[y]=x;
	update(y);
	update(x);
	}
void maintain(int pos,int dir)
	{
	//if(dir==LEFT && left[pos]==0)return;
	//if(dir==RIGHT && right[pos]==0)return;
	if(dir==RIGHT)
		{
		if(left[left[pos]] && size[right[pos]]<size[left[left[pos]]])
			rr(left[pos]);
		else if(right[left[pos]] && size[right[pos]]<size[right[left[pos]]])
			{lr(right[left[pos]]);rr(left[pos]);}
		else return;
		}
	else
		{
		if(right[right[pos]] && size[left[pos]]<size[right[right[pos]]])
			lr(right[pos]);
		else if(left[right[pos]] && size[left[pos]]<size[left[right[pos]]])
			{rr(left[right[pos]]);lr(right[pos]);}
		else return;
		}
	maintain(left[pos],LEFT);
	maintain(right[pos],RIGHT);
	maintain(pos,LEFT);
	maintain(pos,RIGHT);
	}
void insert(int num)
	{
	if(root==0)
		{arr[++an]=num;size[1]=1;root=1;return;}
	int pos=root;
	int fat=0;
	while(pos)
		{
		fat=pos;
		size[pos]++;
		if(num>arr[pos])
			pos=right[pos];
		else pos=left[pos];
		}
	++an;
	if(num>arr[fat])
		right[fat]=an;
	else left[fat]=an;
	arr[an]=num;
	father[an]=fat;
	size[an]=1;
	while(fat)
		{
		maintain(fat,num<arr[fat]);
		fat=father[fat];
		}
	}
void output(int pos)
	{
	if(pos==0){printf("()");return;}
	printf("(%d",arr[pos]);
	output(left[pos]);
	output(right[pos]);
	printf(")");
	}
int main()
	{
	freopen("sbt.in","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		{
		int tmp;
		scanf("%d",&tmp);
		insert(tmp);
		}
	output(root);
	printf("\n");
	return 0;
	}
