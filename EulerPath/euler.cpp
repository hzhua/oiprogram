#include<stdio.h>
#include<stdlib.h>
int match[100];
int conn[100][100];
int ans[100],ansn;
int n;
void solve(int pos)
	{
	if(!match[pos])
		ans[++ansn]=pos;
	else
		{
		for(int i=1;i<=n;i++)
			if(conn[pos][i])
				{
				conn[pos][i]--;
				conn[i][pos]--;
				match[pos]--;
				match[i]--;
				solve(i);
				}
		ans[++ansn]=pos;
		}
	}
int main()
	{
	freopen("euler.in","r",stdin);
	int t;
	scanf("%d%d",&n,&t);
	
	for(int i=1;i<=t;i++)
		{
		int a,b;
		scanf("%d%d",&a,&b);
		conn[a][b]=conn[b][a]=1;
		match[a]++;
		match[b]++;
		}
	solve(1);
	for(int i=ansn;i>=1;i--)
		printf("%d ",ans[i]);
	return 0;
	}
