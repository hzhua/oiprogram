#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define min(a,b) a>b?b:a
bool conn[100][100];
int dis[100][100];
int nx,ny;
bool apr[100];
int pre[100];
bool mark_left[100],mark_right[100];

bool hun(int cur)
	{
	rep(i,1,ny)
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
	memset(pre,0,sizeof(pre));
	int ans=0;
	rep(i,1,nx)
		{
		memset(apr,0,sizeof(apr));
		if(hun(i))ans++;
		}
	return ans;
	}
void visit_left(int cur);
void visit_right(int cur)
	{
	mark_right[cur]=false;
	for(int i=1;i<=nx;i++)
		if(conn[i][cur]&&pre[cur]!=i&&dis[i][cur]==0)//ZERO
			{
			visit_left(i);
			return;	
			}
	}
void visit_left(int cur)
	{
	mark_left[cur]=true;
	for(int i=1;i<=ny;i++)
		if(pre[i]==cur&&conn[cur][i]&&dis[cur][i]==0)//ZERO
			{
			visit_right(i);
			return;
			}
	}
void konig()
	{
	//initialization
	rep(i,1,nx)
		{
		int min_x=65535;
		rep(j,1,ny)
			if(conn[i][j])
				min_x=min(min_x,dis[i][j]);
		rep(j,1,ny)
			if(conn[i][j])
				dis[i][j]-=min_x;
		}
	rep(j,1,ny)
		{
		int min_x=65535;
		rep(i,1,nx)
			if(conn[i][j])
				min_x=min(min_x,dis[i][j]);
		rep(i,1,nx)
			if(conn[i][j])
				dis[i][j]-=min_x;
		}
	while(1)
		{
		int tans=run_hun();
		if(tans==nx)return;
		memset(mark_left,false,sizeof(mark_left));
		memset(mark_right,true,sizeof(mark_right));
		for(int i=1;i<=ny;i++)
			if(pre[i]==0)
				visit_right(i);
		int delta=2147483647;
		for(int i=1;i<=nx;i++)
			for(int j=1;j<=ny;j++)
				if(conn[i][j]&&!mark_left[i]&&!mark_right[j])
					delta=delta<dis[i][j]?delta:dis[i][j];
		for(int i=1;i<=nx;i++)
			for(int j=1;j<=ny;j++)
				if(mark_left[i]&&mark_right[j])
					dis[i][j]+=delta;
				else if(!(mark_left[i]||mark_right[j]))
					dis[i][j]-=delta;
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
