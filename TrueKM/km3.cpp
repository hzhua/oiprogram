#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#define INF 21474836
#define SIZE 200

		int n;
		int w[SIZE][SIZE];
		int lx[SIZE],ly[SIZE];
		bool sx[SIZE],sy[SIZE];
		int slack[SIZE];
		int pre[SIZE];
struct BiPartGraph
	{
	BiPartGraph(){memset(w,0,sizeof(w));
				  memset(lx,0,sizeof(lx));
				  memset(ly,0,sizeof(ly));
				  memset(sx,0,sizeof(sx));
				  memset(sy,0,sizeof(sy));
				  memset(slack,0,sizeof(slack));
				  n=0;
				  }
	void minMaxMatch()
		{
		km();
		}
	void addEdge(int x,int y,int c)
		{w[x][y]+=c;}
	
	bool hun(int pos)
		{
		sx[pos]=true;
		for(int i=1;i<=n;i++)
			if(w[pos][i] && !sy[i])
				{
				if(lx[pos]+ly[i]-w[pos][i]==0)
					{
					sy[i]=true;
					if(!pre[i] || hun(pre[i]))
						{pre[i]=pos;
						return true;}
					}
				else if(lx[pos]+ly[i]-w[pos][i]<slack[pos])
					slack[pos]=lx[pos]+ly[i]-w[pos][i];
				}
		return false;
		}
	void maintain()
		{
		int delta=INF;
		for(int i=1;i<=n;i++)
			if(delta>slack[i])
				delta=slack[i];
		for(int i=1;i<=n;i++)
			{
			if(sx[i])lx[i]-=delta;
			if(sy[i])ly[i]+=delta;
			}
		for(int i=1;i<=n;i++)
			slack[i]-=delta;
		}
	int km()
		{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(w[i][j]>lx[i])
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
	};
int main()
	{
	BiPartGraph nt=BiPartGraph();
	freopen("testdata.in","r",stdin);
	int t;
	int m;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=t;i++)
		{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		nt.addEdge(a,b,c);
		}
	nt.minMaxMatch();
	for(int i=1;i<=m;i++)
		printf("%d-%d\n",pre[i],i);
	return 0;
	}
