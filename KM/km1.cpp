#include<stdio.h>
#include<string.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
int nx,ny;
bool apr[100];
int link[100];
bool conn[100][100];
int dis[100][100];

int min(int a,int b){return a<b?a:b;}
bool dfs(int cur)
	{
	rep(i,1,ny)
		if(conn[cur][i]&&dis[cur][i]==0&&!apr[i])
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
		if(link[i]!=from&&conn[i][cur]&&dis[i][cur]==0)
			{
			cover_left(cur,i);
			return;
			}
	}

bool left_v[300],right_v[300];
bool put_V()
	{
	int ans=0;
	memset(link,0,sizeof(link));
	rep(i,1,nx)
		{
		memset(apr,0,sizeof(apr));
		if(dfs(i))ans++;
		}
	if(ans==nx)return true;
	rep(i,1,ny)
		if(link[i]==0)
			cover_right(-1,i);
	rep(i,1,nx)
		if(mark_l[i])
			left_v[i]=true;
	rep(i,1,ny)
		if(!mark_r[i])
			right_v[i]=true;
	return false;
	}
void km()
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
	rep(j,1,nx)
		{
		int min_x=65535;
		rep(i,1,ny)
			if(conn[i][j])
				min_x=min(min_x,dis[i][j]);
		rep(i,1,ny)
			if(conn[i][j])
				dis[i][j]-=min_x;
		}
	//Step1 Hungarian
	while(1)
		{
		if(put_V())
			return;
		else
			{
	//Step2 Adjust the value
			int delta=65535;
			rep(i,1,nx)
				rep(j,1,ny)
					if(!left_v[i]&&!right_v[j]) ///!!!Forgot conn[i][j]
						delta=min(delta,dis[i][j]);
			rep(i,1,nx)
				rep(j,1,ny)
					if(!left_v[i]&&!right_v[j]) ///!!!Forgot conn[i][j]
						dis[i][j]-=delta;
					else if(left_v[i]&&right_v[j]) ///!!!Forgot conn[i][j]
						dis[i][j]+=delta;
			}
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
	km();
	rep(i,1,ny)
		if(link[i])
			printf("%d---%d\n",link[i],i);
	return 0;
	}
