#include<stdio.h>
#include<string.h>
int vh[300],gap[300];
int map[300][300];
int minsize;
bool flag;
int n,flow;
void sap(int cur)
	{
	int tsize=minsize;
	int mingap=n-1;
	int i;
	if(cur==n)
		{
		flag=true;
		flow+=minsize;
		return;
		}
	for(i=1;i<=n;i++)
		if(map[cur][i]>0)	
			{
			if(gap[i]+1==gap[cur])
				{
				if(map[cur][i]<minsize)
					minsize=map[cur][i];
				sap(i);
				if(gap[1]>=n)return;
				if(flag)break;
				minsize=tsize;//WRONG:tsize=minsize;
				}
			if(gap[i]<mingap)
				mingap=gap[i];
			}
	if(flag)
		{
		map[cur][i]-=minsize;
		map[i][cur]+=minsize;
		return;
		}
	else
		{
		vh[gap[cur]]--;
		if(vh[gap[cur]]==0)gap[1]=n;
		gap[cur]=mingap+1;
		vh[gap[cur]]++;
		}
	}
int run_sap()
	{
	memset(vh,0,sizeof(vh));
	vh[0]=n;
	flow=0;
	memset(gap,0,sizeof(gap));
	while(gap[1]<n)
		{
		flag=false;//FORGET!!
		minsize=21474836;//FORGET!!
		sap(1);
		}
	return flow;
	}
int main()
	{
	int m;
	FILE *in=fopen("ditch.in","r");
	FILE *out=fopen("ditch.out","w");
	fscanf(in,"%d %d",&m,&n);
	for(int i=1;i<=m;i++)
		{int x,b,c;
		fscanf(in,"%d %d %d",&x,&b,&c);
		map[x][b]+=c;
		}
	fprintf(out,"%d\n",run_sap());
	fclose(out);
	return 0;
	}
