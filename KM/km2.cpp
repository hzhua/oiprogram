#include<stdio.h>
#include<stdlib.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
bool conn[100][100];
int dis[100][100];

/*Hungrian*/
int link[100];
bool hun(int cur)
	{
	rep(i,1,ny)
		if(conn[cur][i]&&!apr[i])
			{
			apr[i]=true;
			if(!link[i]||hun(link[i]))
				{
				link[i]=cur;
				return true;
				}
			}
	return false;
	}
int run_hun()
	{
	int ans=0;
	rep(i,1,nx)
		{
		memset(apr,0,sizeof(apr));
		if(hun(i))ans++;
		}
	return ans;
	}

/*Konig*/
bool v_left[100],v_right[100];
bool apr_left[100],apr_right[100];
void mark_left(int cur,bool color)
	{
	apr_left[cur]=true;
	rep(i,1,ny)
		if(conn[cur][i]&&((link[i]==cur)^color))
			{
			mark_right(i,!color);
			return;
			}
	}
void mark_right(int cur,bool color)
	{
	apr_right[cur]=true;
	rep(i,1,nx)
		if(conn[i][cur]&&((link[cur]==i)^color))
			{mark_left(i,!color);
			return;
			}
	}
void run_konig()
	{
	rep(i,1,ny)
		if(conn[i]==0)
			mark_right(i,true);
	rep(i,1,nx)
		if(apr_left[i])
			mark_left[i]=true;
	rep(i,1,ny)
		if(!apr_right[i])
			mark_right[i]=true;
	}

//Calc Maxinum Value
void calc()
	{
	//initialization
	rep(i,1,nx)
		{
		int minx=65535;
		rep(j,1,ny)
			if(conn[i][j])
				minx=min(minx,dis[i][j]);
		rep(j,1,ny)
			if(conn[i][j])
				dis[i][j]-=minx;
		}
	rep(i,1,ny)
		{
		int minx=65535;
		rep(j,1,nx)
			if(conn[i][j])
				minx=min(minx,dis[i][j]);
		rep(j,1,nx)
			if(conn[i][j])
				dis[i][j]-=minx;
		}
	while(1)
		{
		int tmp_ans=run_hun();
		if(tmp_ans==nx)return true;
		run_konig();
		int minx=65535;
		rep(i,1,nx)
			rep(j,1,ny)
				if(!mark_left[i]&&!mark_right[j])
					minx=min(minx,dis[i][j]);
		rep(i,1,nx)
			rep(j,1,ny)
				if(!mark_left[i]&&!mark_right[j])
					dis[i][j]-=minx;
				else if(mark_left[i]&&mark_right[j])
					dis[i][j]+=minx;
		}
	}
int main()
	{
	
	}
