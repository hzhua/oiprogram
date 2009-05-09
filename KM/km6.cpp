#include<stdio.h>
#include<stdlib.h>
#include<cstring>
bool sx[SIZE],sy[SIZE];
int lx[SIZE],ly[SIZE];
int slack[SIZE];
int n;
bool hun(int x)
	{
	sx[x]=true;
	for(int i=1;i<=n;i++)
		if(conn[x][i])
			{
			if(lx[x]+ly[i]-w[x][i]==0)
				{
				sy[i]=true;
				if(pre[i]==0||hun(i))
					{
					pre[i]=x;
					return true;
					}
				}
			if(lx[x]+ly[i]-w[x][i]<slack[x])
				slack[x]=lx[x]+ly[i]-w[x][i];
			}
	return false;
	}
void maintain()
	{
	int delta=MAX_INT;
	for(int i=1;i<=n;i++)
		if(slack[i]<delta)
			delta=slack[i];
	for(int i=1;i<=n;i++)
		{
		if(sx[i])lx[i]-=slack[i];
		if(sy[i])ly[i]+=slack[i];
		}
	}
void km()
	{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(conn[i][j] && w[i][j]>lx[i])
				lx[i]=w[i][j];
	for(int i=1;i<=n;i++)
		while(1)
			{
			memset(sx,0,sizeof(sx));
			memset(sy,0,sizeof(sy));
			memset(slack,0x7F,sizeof(slack));
			if(hun(i))
				break;
			maintain();
			}
				
	}
int main()
	{
	return 0;
	}
