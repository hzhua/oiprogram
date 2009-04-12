#include<stdio.h>
#include<stdlib.h>
struct Node
	{
	int limU,limD;
	int cap;
	int flow;
	Node *next;
	Node *rev;
	};
struct Network
	{
	void addEdge(int x,int y,int limU,int limD,int cap)
		{
		Node *p=new Node(y,limU,limD,cap,adj[x],NULL);
		Node *q=new Node(x,0,0,0,adj[y],NULL);
		p->rev=q;
		q->rev=p;
		}
	int gap[SIZE],vh[SIZE];
	int n;
	int s,t;
	private:
		Node *adj[SIZE];
	};
bool flag;
int flow,minCap;
void sap(Network &nt,int pos)
	{
	if(pos==nt.t)
		{
		flow+=minCap;
		flag=true;
		return ;
		}
	int tmpCap=minCap;
	int minGap=n-1;
	Node *p;
	for(p=nt.adj[pos];p;p+=p->next)
		if((p->cap - p->flow)>0)
			{
			if(p->cap - p->flow < minCap)
				minCap= p-> cap - p-> flow;
			sap(nt,p->y);
			if(flag)break;
			if(gap[1]>=n)return;
			minCap=tmpCap;
			if(gap[p->y]<minGap)
				minGap=gap[p->y];
			}
	if(flag)
		{
		p->flow+=minCap;
		p->rev->flow-=minCap;
		}
	else
		{
		vh[gap[pos]]--;
		if(!gap[pos])gap[1]=n;
		gap[pos]=minGap+1;
		vh[gap[pos]]++;
		}
	}
void runSAP(Network &nt)
	{
	memset(nt.gap,0,sizeof(nt.gap));
	memset(nt.vh,0,sizeof(nt.vh));
	nt.vh[0]=nt.n;
	while(nt.gap[0]<n)
		{
		flow=0;
		success=false;
		sap(nt,nt.s);
		}
	}
Network mainNet=Network;
int goIn[SIZE],goOut[SIZE];
void buildGraph()
	{
	mainNet.s=mainNet.n+1;
	mainNet.t=mainNet.n+2;
	for(int i=1;i<=mainNet.n;i++)
		for(Node *p=mainNet.adj[i];p;p=p->next)
			{
			goIn[p->y]+=p->limD;
			goOut[i]+=p->limD;
			}
	for(int i=1;i<=mainNet.n;i++)
		if(goIn[i]-goOut[i]>0)
			addEdge(mainNet.s,i,0,0,goIn[i]-goOut[i]);
		else addEdge(i,mainNet.t,0,0,goOut[i]-goIn[i]);
	mainNet.n+=2;
	}
int iG[SIZE][SIZE];
int dataX[SIZE],dataY[SIZE];
bool solve()
	{
	int m;
	scanf("%d%d",&mainNet.n,&m);
	for(int i=1;i<=n;i++)
		{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		addEdge(a,b,c,d,c-d);
		dataX[i]=a;dataY[i]=b;
		}
	buildGraph();
	runSAP(mainNet);
	for(Node *p=mainNet.adj[mainNet.s];p;p=p->next)
		if(p->cap!=p->flow)
			return false;
	for(int i=1;i<=mainNet.n-2;i++)
		for(Node *p=mainNet.adj[i];p;p=p->next)
			{
			if(p->y<=mainNet.n-2)
				iG[i][p->y]=p->limD+p->flow;
			}
	return true;
	}
int main()
	{
	bool success=solve();
	if(success)
		{
		printf("YES\n");
		for(int i=1;i<=n;i++)
			printf("%d\n",iG[dataX[i]][dataY[i]]);
		}
	else printf("NO\n");
	return 0;
	}
