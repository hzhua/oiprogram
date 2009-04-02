/*
ID:hzhua201
LANG:C++
PROB:ditch
*/
#include<stdio.h>
#include<string.h>
#define INF 21474936
struct MaxFlow
	{
	int flowSum;
	int minCap;
	int org,snk;
	int n;
	bool flag;
	int cap[305][305];
	int vh[1000];
	int gap[1000];
	MaxFlow()
		{
		flowSum =minCap =org =snk =0;
		flag=false;
		memset(cap,0,sizeof(cap));
		memset(vh,0,sizeof(vh));
		memset(gap,0,sizeof(gap));
		}
	void sap(int pos)
		{
		if(pos==snk)
			{
			flowSum+=minCap;
			flag=true;
			return;
			}
		int i;
		int minGap=n-1;
		int tmpCap=minCap;
		for(i=1;i<=n;i++)
			if(cap[pos][i])
				{
				if(gap[i]+1==gap[pos])
					{
					if(cap[pos][i]<minCap)
						minCap=cap[pos][i];
					sap(i);
					if(gap[1]>=n)return;
					if(flag)break;
					minCap=tmpCap;
					}
				if(gap[i]<minGap)
					minGap=gap[i];
				}
		if(flag)
			{
			cap[pos][i]-=minCap;
			cap[i][pos]+=minCap;
			}
		else
			{
			vh[gap[pos]]--;
			if(vh[gap[pos]]==0)gap[1]=n;
			gap[pos]=minGap+1;
			vh[gap[pos]]++;
			}
		}
	int maxFlow()
		{
		vh[0]=n;
		flowSum=0;
		while(gap[1]<n)
			{
			flag=false;
			minCap=INF;
			sap(org);
			}
		return flowSum;
		}
	void addEdge(int x,int y,int c)
		{cap[x][y]+=c;}
	};
int main()
	{
	FILE *in=fopen("ditch.in","r");
	FILE *out=fopen("ditch.out","w");
	int m,n;
	fscanf(in,"%d %d",&m,&n);
	MaxFlow nt= MaxFlow();
	nt.org=1;nt.snk=n;
	nt.n=n;
	for(int i=1;i<=m;i++)
		{int x,b,c;
		fscanf(in,"%d %d %d",&x,&b,&c);
		nt.addEdge(x,b,c);
		}
	fprintf(out,"%d\n",nt.maxFlow());
	fclose(out);
	return 0;
	}
