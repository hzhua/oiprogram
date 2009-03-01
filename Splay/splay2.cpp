#include<stdio.h>
#include<stdlib.h>
#include<cstring>
int tn,father[100000],left[100000],right[100000];
int size[100000];
int v[100000]; 
int root;
void update(int x)
	{size[x]=size[left[x]]+size[right[x]]+1;}
void rr(int pos)
	{
	int y=father[pos];
	left[y]=right[pos];
	if(!right[pos])
		father[right[pos]]=y;
	right[pos]=y;
	father[pos]=father[y];
	if(father[y])
		{
		if(left[father[y]]==y)
			left[father[y]]=pos;
		else right[father[y]]=pos;
		}
	father[y]=pos;
	update(y);
	update(pos);
	}
void lr(int pos)
	{
	int y=father[pos];
	right[y]=left[pos];
	if(!left[pos])
		father[left[pos]]=y;
	left[pos]=y;
	father[pos]=father[y];
	if(father[y]) //!!!!@!@#!@#!@#!
		{
		if(left[father[y]]==y)
			left[father[y]]=pos;
		else right[father[y]]=pos;
		}
	father[y]=pos;
	update(y);
	update(pos);
	}
void splay(int pos,int topos)
	{
	if(topos==0)root=pos;//!!!!#@$@#$@#$@#$@#$$
	while(father[pos]!=topos)
		{
		int y=father[pos];
		if(father[y]==topos)
			{
			if(left[y]==pos)
				rr(pos);
			else lr(pos);
			}
		else
			{
			if(left[father[y]]==y)
				{
				if(left[y]==pos)
					{rr(y);rr(pos);}
				else {lr(pos);rr(pos);}
				}
			else 
				{
				if(right[y]==pos)
					{lr(y);lr(pos);}
				else {rr(pos);lr(pos);}
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
