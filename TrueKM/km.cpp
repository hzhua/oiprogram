#include<cstring>
#include<stdio.h>
#define INF 21474836
int n,m;
int conn[200][200];
int w[200][200];
int pre[201];
int lx[201],ly[201];
bool sx[201],sy[201];
int slack[201];
bool hun(int pos)
	{
	sx[pos]=true;
	for(int i=1;i<=conn[pos][0];i++)
		{
		int t=conn[pos][i];
		if(sy[t])continue;
		if(lx[pos]+ly[t]-w[pos][t]==0)
			{
			sy[t]=true;
			if(pre[t]==0||hun(pre[t]))
				{
				pre[t]=pos;
				return true;
				}
			}
		else
			{
			if(lx[pos]+ly[t]-w[pos][t]<slack[t])
				slack[t]=lx[pos]+ly[t]-w[pos][t];
			}
		}
	return false;
	}
void adjust()
	{
	int min=INF;
	for(int i=1;i<=m;i++)
		if(slack[i]<min)
			min=slack[i];
	for(int i=1;i<=n;i++)
		if(sx[i])
			lx[i]-=min;
	for(int i=1;i<=m;i++)
		if(sy[i])
			ly[i]+=min;
	for(int i=1;i<=m;i++)
		slack[i]-=min;
	}
void km()
	{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=conn[i][0];j++)
			if(w[i][conn[i][j]]>lx[i])
				lx[i]=w[i][conn[i][j]];
	for(int i=1;i<=n;i++)
		while(1)
			{
			memset(sy,0,sizeof(sy));
			memset(sx,0,sizeof(sx));
			memset(slack,0x7f,sizeof(slack));
			if(hun(i))
				break;
			adjust();
			}
	}
int main()
	{
	freopen("testdata.in","r",stdin);
	int t;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=t;i++)
		{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		conn[a][++conn[a][0]]=b;
		w[a][b]=c;
		}
	km();
	for(int i=1;i<=m;i++)
		printf("%d-%d\n",pre[i],i);
	return 0;
	}
