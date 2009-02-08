#include<stdio.h>
#include<string.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
int nx,ny;
bool apr[100];
int link[100];
bool conn[100][100];

bool dfs(int cur)
	{
	rep(i,1,ny)
		if(conn[cur][i]&&!apr[i])
			{
			apr[i]=true;
			if(!link[i]||dfs(link[i]))
				{
				link[i]=cur;
				return true;
				}
			}
	return false;
	}
	
bool mark_l[100],mark_r[100];
void cover_right(int from,int cur);
void cover_left(int from,int cur)
	{
	mark_l[cur]=true;
	rep(i,1,ny)
		if(i!=from&&link[i]==cur)
			{
			cover_right(cur,i);
			return;
			}
	}
void cover_right(int from,int cur)
	{
	mark_r[cur]=true;
	rep(i,1,nx)
		if(link[i]!=from&&conn[i][cur])
			{
			cover_left(cur,i);
			return;
			}
	}
int main()
	{
	scanf("%d%d",&nx,&ny);
	rep(i,1,nx)
		{
		int tn;
		scanf("%d",&tn);
		rep(j,1,tn)
			{
			int to;
			scanf("%d",&to);
			conn[i][to]=true;
			}
		}
	int ans=0;
	rep(i,1,nx)
		{
		memset(apr,0,sizeof(apr));
		if(dfs(i))ans++;
		}
	printf("%d\n",ans);
	rep(i,1,ny)
		if(link[i]==0)
			cover_right(-1,i);
	rep(i,1,nx)
		if(mark_l[i])
			printf("Left:%d\n",i);
	rep(i,1,ny)
		if(!mark_r[i])
			printf("Right:%d\n",i);
	return 0; 
	}