#include<cstring>
#include<stdio.h>
#define MAXINT 21474836
int lx[100],ly[100];
int slack[100];
bool sx[100],sy[100];
int n;
int conn[100][100];
int pre[100];
int w[100][100];
bool hun(int pos)
	{
	sx[pos]=true;
	for(int i=1;i<=n;i++)
		if(conn[pos][i]&&!sy[i])
			{
			if(lx[pos]+ly[i]-w[pos][i]==0)
				{
				sy[i]=true;
				if(pre[i]==0||hun(pre[i]))
					{
					pre[i]=pos;
					return true;
					}
				}
			else
				{
				if(lx[pos]+ly[i]-w[pos][i]<slack[i])
					slack[i]=lx[pos]+ly[i]-w[pos][i];
				}
			}
	return false;
	}
void maintain()
	{
	int delta=MAXINT;
	for(int i=1;i<=n;i++)
		if(slack[i]<delta)
			delta=slack[i];
	for(int i=1;i<=n;i++)
		{
		if(sx[i])lx[i]-=delta;
		if(sy[i])ly[i]+=delta;
		}
	for(int i=1;i<=n;i++)
		slack[i]-=delta;
	}
void km()
	{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(conn[i][j]&&lx[i]<w[i][j])
				lx[i]=w[i][j];
	for(int i=1;i<=n;i++)
		while(1)
			{
			memset(sx,0,sizeof(sx));
			memset(sy,0,sizeof(sy));
			memset(slack,0x7f,sizeof(slack));
			if(hun(i))
				break;
			maintain();
			}
	}
int main()
	{
	freopen("testdata.in","r",stdin);
	int t;
	int m;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=t;i++)
		{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		conn[a][b]=1;
		w[a][b]=c;
		}
	km();
	for(int i=1;i<=m;i++)
		printf("%d-%d\n",pre[i],i);
	return 0;
	}
