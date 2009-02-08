#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
bool conn[100][100];
int v[100][100];
bool apr[100];
int pre[100];
int n;

int min(int a,int b){return a<b?a:b;}

bool hun(int x)
	{
	for(int i=1;i<=n;i++)
		if(conn[x][i]&&v[x][i]==0&&!apr[i])
			{
			apr[i]=true;
			if(pre[i]==0||hun(pre[i]))
				{
				pre[i]=x;
				return true;
				}
			}
	return false;
	}
int run_hun()
	{
	int ans=0;
	for(int i=1;i<=n;i++)
		{
		memset(apr,0,sizeof(apr));
		if(hun(i))ans++;
		}
	return ans;
	}

	
bool in_left[100];
bool in_right[100];
void visit_right(int cur);
void visit_left(int cur)
	{
	in_left[cur]=true;
	for(int i=1;i<=n;i++)
		if(conn[cur][i]&&pre[i]==cur&&v[cur][i]==0)
			{
			visit_right(i);
			return;
			}
	}
void visit_right(int cur)
	{
	in_right[cur]=false;
	for(int i=1;i<=n;i++)
		if(conn[i][cur]&&pre[cur]!=i&&v[i][cur]==0)  //Don't forget v[i][cur]
			{
			visit_left(i);
			return;
			}
	}
void konig()
	{
	//initialization
	rep(i,1,n)
		{
		int min_x=65535;
		rep(j,1,n)
			if(conn[i][j])
				min_x=min(min_x,v[i][j]);
		rep(j,1,n)
			if(conn[i][j])
				v[i][j]-=min_x;
		}
	rep(j,1,n)
		{
		int min_x=65535;
		rep(i,1,n)
			if(conn[i][j])
				min_x=min(min_x,v[i][j]);
		rep(i,1,n)
			if(conn[i][j])
				v[i][j]-=min_x;
		}
	while(1)
		{
		memset(pre,0,sizeof(pre));  //!!!  IMPOTANT or will cause while forever
		int ans=run_hun();
		if(ans==n)return;
		memset(in_left,false,sizeof(in_left));
		memset(in_right,true,sizeof(in_right));
		for(int i=1;i<=n;i++)
			if(pre[i]==0)
				visit_right(i);
		int delta=65535;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(conn[i][j]&&!in_left[i]&&!in_right[j])   //Dont forget this line!!!
					delta=delta<v[i][j]?delta:v[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(conn[i][j])
					if(in_left[i]&&in_right[j])
						v[i][j]+=delta;
					else if(!in_left[i]&&!in_right[j])
						v[i][j]-=delta;
		}
	}
int main()
	{
	scanf("%d",&n);
	int t_n;
	scanf("%d",&t_n);
	for(int i=1;i<=t_n;i++)
		{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		v[a][b]=c;
		conn[a][b]=true;
		}
	konig();
	for(int i=1;i<=n;i++)
		if(pre[i])
			printf("%d---%d\n",pre[i],i);
	return 0;
	}
