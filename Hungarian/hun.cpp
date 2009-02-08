#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool conn[100][100];
bool apr[100];
int link[100];
int nx,ny;
bool mark_l[100],mark_r[100];

bool hun(int cur)
	{
	for(int i=1;i<=ny;i++)
		if(conn[cur][i]&&!apr[i])
			{
			apr[i]=true;
			if(!link[i]||hun(link[i]))
				{
				link[i]=cur;
				return true;
				}
			}
	return false;
	}
void min_cover_left(int from,int cur);
void min_cover_right(int from,int cur)
	{
	mark_r[cur]=true;
	for(int i=1;i<=nx;i++)
		if(i!=from&&conn[i][cur])
			min_cover_left(cur,i);
	}

void min_cover_left(int from,int cur)
	{
	mark_l[cur]=true;
	for(int i=1;i<=ny;i++)
		if(i!=from&&link[i]==cur)
			min_cover_right(cur,i);
	}

int ans=0;
int main()
	{
	scanf("%d %d",&nx,&ny);
	int c_n;
	for(int i=1;i<=nx;i++)
		{scanf("%d",&c_n);
		for(int j=1;j<=c_n;j++)
			{
			int tmp;
			scanf("%d",&tmp);
			conn[i][tmp]=true;
			}
		}
	for(int i=1;i<=nx;i++)
		{
		memset(apr,0,sizeof(apr));
		if(hun(i))ans++;
		}
	for(int i=1;i<=ny;i++)
		printf("%d : %d\n",i,link[i]);
	for(int i=1;i<=ny;i++)
		if(link[i]==0)
			min_cover_right(-1,i);
	printf("%d\n",ans);
	for(int i=1;i<=nx;i++)
		if(mark_l[i])
			printf("Left:%d\n",i);
	for(int i=1;i<=ny;i++)
		if(!mark_r[i])
			printf("Right:%d\n",i);
	return 0;
	}