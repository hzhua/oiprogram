#include<stdio.h>
#include<stdlib.h>
int stack[1001];
bool map[101][101];
bool r1[101],r2[101];
int n,sn;
void dfs(int cur)
 {
 r1[cur]=true;
 for(int i=1;i<=n;i++)
  if(map[cur][i]&&!r1[i])
   dfs(i);
 stack[++sn]=cur;
 }
void dfs2(int cur)
 {
 r2[cur]=true;
 printf("%d ",cur);
 for(int i=1;i<=n;i++)
  if(map[i][cur]&&!r2[i])
   dfs2(i);
 }
void korasaju()
 {
 for(int i=1;i<=n;i++)
  if(!r1[i])
   dfs(i);
 for(int i=sn;i>=1;i--)
  if(!r2[stack[i]])
   {
   dfs2(stack[i]);
   printf("\n");
   }
 }
int main()
	{
	int m;
	FILE *in=fopen("test.txt","r");
	fscanf(in,"%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		{
		int a,b;
		fscanf(in,"%d%d",&a,&b);
		map[a][b]=true;
		}
	korasaju();
	return 0;
	}
