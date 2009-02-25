#include<stdio.h>
#include<stdlib.h>
int tn,father[100000],left[100000],right[100000];
int size[100000];
int v[100000]; 
int root;
void update(int x)
	{size[x]=size[left[x]]+size[right[x]]+1;}
void leftrotate(int pos)
	{
	int y=father[pos];
	right[y]=left[pos];
	if(left[pos]!=0)
		father[left[pos]]=y;
	father[pos]=father[y];
	if(!father[y])
		if(y==left[father[y]])
			left[father[y]]=pos;
		else
			right[father[y]]=pos;
	left[pos]=y;
	father[y]=pos;
	update(pos);
	update(y);
	return;
	}
void rightrotate(int pos)
	{
	int y=father[pos];
	left[y]=right[pos];
	if(right[pos]!=0)
		father[right[pos]]=y;
	father[pos]=father[y];
	if(!father[y])
		if(y==left[father[y]])
			left[father[y]]=pos;
		else
			right[father[y]]=pos;
	right[pos]=y;
	father[y]=pos;
	update(pos);
	update(y);
	return;
	}
void splay(int pos,int topos)
	{
	int y=father[pos];
	if(y==0)return;
	if(topos==0)root=pos;
	while(father[pos]!=topos)
		{
		if(father[y]==topos)
			{
			if(pos==left[y])
				rightrotate(pos);
			else leftrotate(pos);
			break;
			}
		if(y==left[father[y]])
			{
			if(pos==left[y])
				{
				rightrotate(y);
				rightrotate(pos);
				}
			else 
				{
				leftrotate(pos);
				rightrotate(pos);
				}
			}
		else
			{
			if(pos==right[y])
				{
				leftrotate(y);
				leftrotate(pos);
				}
			else 
				{
				rightrotate(pos);
				leftrotate(pos);
				}
			}
		}
	}
void insert(int num)
	{
	if(root==0)
		{
		tn++;
		v[tn]=num;
		root=1;
		return;
		}
	int pos=root;
	int fat=0;
	while(pos)
		{
		if(v[pos]==num)return;
		size[pos]++;
		fat=pos;
		if(num<v[pos])
			pos=left[pos];
		else pos=right[pos];
		}
	tn++;
	v[tn]=num;
	father[tn]=fat;
	size[tn]=1;
	if(num<v[fat])
		left[fat]=tn;
	else right[fat]=tn;
	return;
	}
void output(int pos)
	{
	if(pos==0){printf("()");return;}
	printf("(%d",v[pos]);
	output(left[pos]);
	output(right[pos]);
	printf(")");
	}
int main()
	{
	//freopen("splay.in","r",stdin);
	int num[]={421,1241,511,11241,41421,14,512,6234,51};
	for(int i=0;i<=8;i++)insert(num[i]);
	output(root);
	printf("\n");
	splay(3,0);
	output(root);
	/*insert(2);
	insert(1);
	insert(3);
	output(root);
	printf("\n");
	splay(2,0);
	output(root);*/
	return 0;
	}
