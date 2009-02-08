#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<string.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define min(a,b) a>b?b:a
bool apr[100];
int pre[100];
bool conn[100][100];
int dis[100][100];
int nx,ny;

bool hun(int cur)
	{
	for(int i=1;i<=ny;i++)
		if(conn[cur][i]&&!apr[i]&&dis[cur][i]==0)
			{
			apr[i]=true;
			if(pre[i]==0||hun(pre[i]))
				{
				pre[i]=cur;
				return true;
				}
			}
	return false;
	}
int run_hun()
	{
	int ans=0;
	memset(pre,0,sizeof(pre));
	for(int i=1;i<=nx;i++)
		{
		memset(apr,0,sizeof(apr));
		if(hun(i))ans++;
		}
	return ans;
	}
bool in_left[100],in_right[100];
void visit_right(int cur);
void visit_left(int cur)
	{
	in_left[cur]=true;
	for(int i=1;i<=ny;i++)
		if(pre[i]==cur)
			{
			visit_right(i);
			return;
			}
	}
void visit_right(int cur)
	{
	in_right[cur]=false;
	for(int i=1;i<=nx;i++)
		if(conn[i][cur]&&dis[i][cur]==0&&pre[cur]!=i)
			{
			visit_left(i);
			return;
			}
	}
void konig()
	{
	while(1)
		{
		int tans=run_hun();
		if(tans==nx)return;
		memset(in_left,false,sizeof(in_left));
		memset(in_right,true,sizeof(in_right));
		for(int i=1;i<=ny;i++)
			if(pre[i]==0)
				visit_right(i);
		int delta=2147483647;
		for(int i=1;i<=nx;i++)
			for(int j=1;j<=ny;j++)
				if(!in_left[i]&&!in_right[j])
					delta=min(delta,dis[i][j]);
		for(int i=1;i<=nx;i++)
			for(int j=1;j<=ny;j++)
				if(!in_left[i]&&!in_right[j])
					dis[i][j]-=delta;
				else if(in_left[i]&&in_right[j])
					dis[i][j]+=delta;
		}
	}
int main()
	{
	scanf("%d %d",&nx,&ny);
	int t_n;
	scanf("%d",&t_n);
	rep(i,1,t_n)
		{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		dis[a][b]=c;
		conn[a][b]=true;
		}
	konig();
	rep(i,1,ny)
		if(pre[i])
			printf("%d---%d\n",pre[i],i);
	return 0;
	}
