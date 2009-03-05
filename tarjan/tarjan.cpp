#include<stdio.h>
#include<stdlib.h>
#include<cstring>
int Q[1000][100];
int father[1000];
int root[1000];
int child[1000][100];
int ans[1000][100];
int dfs(int x)
	{
	root[x]=x;
	for(int i=1;i<=Q[x][0];i++)
		if(root[Q[x][i]])
			ans[x][Q[x][i]]=root[root[Q[x][i]]];
	for(int i=1;i<=child[x][0];i++)
		dfs(child[x][i]);
	root[x]=root[father[x]];
	}
int main()
	{
	freopen("tarjan.in","r",stdin);
	int n,qn;
	scanf("%d%d",&n,&qn);
	for(int i=1;i<=n;i++)
		{
		int cn;
		scanf("%d",&cn);
		child[i][0]=cn;
		for(int j=1;j<=cn;j++)
			{
			int tmp;
			scanf("%d",&tmp);
			child[i][j]=tmp;
			father[tmp]=i;
			}
		}
	int listx[1000]={0},listy[1000]={0};
	for(int i=1;i<=qn;i++)
		{
		int a,b;
		scanf("%d%d",&a,&b);
		Q[a][++Q[a][0]]=b;
		Q[b][++Q[b][0]]=a;
		listx[i]=a;
		listy[i]=b;
		}
	dfs(1);
	for(int i=1;i<=qn;i++)
		{
		int x=listx[i],y=listy[i];
		if(ans[x][y])
			printf("%d\n",ans[x][y]);
		else printf("%d\n",ans[y][x]);
		}
	return 0;
	}
