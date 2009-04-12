#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000
const int GREY=2,WHITE=0,BLACK=1;
int min(int a,int b){return a<b?a:b;}
struct Node
	{
	int t;
	Node *next;
	};
Node mem[1000000];
Node *adj[SIZE];
int useN;
int dep[SIZE],fmin[SIZE];
int color[SIZE];
int Root;
bool cut[SIZE];

void dfs(int x,int fat,int depth)
	{
	dep[x]=depth;
	fmin[x]=depth;
	color[x]=GREY;
	int tot=0;
	for(Node *p=adj[x];p;p=p->next)
		{
		int y=p->t;
		if(y!=fat && color[y]==GREY)
			fmin[x] = min(fmin[x] , dep[y]);
		if(color[y] == WHITE)
			{
			dfs(y , x ,depth+1);
			tot++;
			fmin[x] = min(fmin[x] , fmin[y]);
			if((x == Root && tot>1) || (x !=Root && fmin[y] >= dep[x]))
				cut[x]=true;
			/*
			 if(fat[y]>dep[x])cutEdge[x][y]=true;
			*/
			}
		}
	color[x]=BLACK;
	}
void addEdge(int x,int y)
	{
	Node *p = & mem[++useN];
	p->t=y;
	p->next=adj[x];
	adj[x] = p;

	p= & mem[++useN];
	p->t=x;
	p->next=adj[y];
	adj[y] = p;
	}
int main()
	{
	freopen("dfs.in","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		{
		int x,y;
		scanf("%d%d",&x,&y);
		addEdge(x,y);
		}
	Root=1;
	dfs(1,0,1);
	for(int i=1;i<=n;i++)
		if(cut[i])
			printf("%d\n",i);
	return 0;
	}
