#include<cstdio>
#include<cstdlib>
#include<cstring>
ARR pre,slack,lx,ly;
bool sx[SIZE],sy[SIZE];
bool hun(int x)
	{
	sx[x]=true;
	for(Node *p=adj[x];p;p=p->next)
		if(!sy[p->y])
			{
			if(lx[x]+ly[p->y]-p->c==0)
				{
				sy[p->y]=true;
				if((!pre[p->y]) || hun(p->y))
					{
					pre[p->y]=x;
					return true;
					}
				}
			if(lx[x]+ly[p->y]- p->c <slack[x])
				slack[x]=lx[x]+ly[p->y]- p->c;
			}
	return false;
	}
void maintain()
	{
	int delta=INF;
	for(int i=1;i<=n;i++)
		for(Node *p=adj[i];p;p=p->next)
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
int km()
	{
	for(int i=1;i<=n;i++)
		{
		int delta=-1;
		for(Node *p=adj[i];p;p=p->next)
			if(delta<p->c)
				delta=p->c;
		lx[i]=delta;
		}
	for(int i=1;i<=n;i++)
		while(1)
			{
			memset(sx,0,sizeof(sx));
			memset(sy,0,sizeof(sy));
			memset(slack,0x7F,sizeof(slack));
			if(hun(i))
				break;
			maintain();
			}
	}
int main()
	{
	return 0;
	}
