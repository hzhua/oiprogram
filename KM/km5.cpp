#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int map[100][100];
bool conn[100][100];
int nx,ny;
bool apr[100];
int pre[100];
bool hun(int cur)
	{
	for(int i=1;i<=ny;i++)
		if(conn[cur][i]&&map[cur][i]==0&&!apr[i])
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
void visit_left(int x);
void visit_right(int x)
	{
	in_right[x]=false;
	for(int i=1;i<=nx;i++)
		if(conn[i][x]&&map[i][x]==0&&pre[i]!=x)
			{
			visit_left(i);
			return;
			}
	}
void visit_left(int x)
	{
	in_left[x]=true;
	for(int i=1;i<=ny;i++)
		if(conn[x][i]&&pre[i]==x)
			{
			visit_right(i);
			return;		
			}
	}
void konig()
	{
	while(1)
		{
		int tans=run_hun();
		if(tans==nx)return;
		memset(in_left,0,sizeof(in_left));
		memset(in_right,1,sizeof(in_right));
		for(int i=1;i<=ny;i++)
			if(pre[i]==0)
				visit_right(i);
		int delta=21474836;
		for(int i=1;i<=nx;i++)
			for(int j=1;j<=ny;j++)
				if(!in_left[i]&&!in_right[j]&&delta>map[i][j])
					delta=map[i][j];
		for(int i=1;i<=nx;i++)
			for(int j=1;j<=ny;j++)
				if(in_left[i]&&in_right[j])
					map[i][j]+=delta;
				else if(!in_left[i]&&!in_right[j])
					map[i][j]-=delta;
		}
	}
int main()
	{
	scanf("%d %d",&nx,&ny);
	int t_n;
	scanf("%d",&t_n);
	for(int i=1;i<=t_n;i++)
		{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		map[a][b]=c;
		conn[a][b]=true;
		}
	konig();
	for(int i=1;i<=ny;i++)
		if(pre[i])
			printf("%d---%d\n",pre[i],i);
	return 0;
	}
