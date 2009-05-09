#include<stdio.h>
#include<cstring>
#include<stdlib.h>
void dfs(int x,int fat,int dep)
	{
	color[x]=GREY;
	d[x]=dep;
	for(int i=1;i<=n;i++)
		if(conn[x][i])	
			{
			if(color[i]==GREY &&i!=fat)
				fmin[x]=min(fmin[x],d[i]);
			else if(color[i]==WHITE)
				{
				dfs(i,x,dep+1);
				cnt++;
				fmin[x]=min(fmin[x],fmin[i]);
				if((x==ROOT && cnt>1) || (x!=ROOT && fmin[i]>=d[x]))
					cut[x]==true;

				}
			}
	color[x]=BLACK;
	}
int main()
	{
	return 0;
	}
