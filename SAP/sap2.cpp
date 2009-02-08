#include<stdio.h>
#include<stdlib.h>
int map[300][300];
int gap[300];
int vh[300];
int n;
int flow=0;

int minsize=65535;
bool flag=false;
void sap(int cur)
	{
	int tsize=minsize;
	int mingap=n-1;
	
	if(cur==n)
		{
		flag=true;
		flow+=minsize;
		return;
		}
	int i;
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
				minsize=tsize;
				}
			if(gap[i]<mingap)mingap=gap[i];
			}
	if(flag)
		{
		map[cur][i]-=minsize;
		map[i][cur]+=minsize;
		}
	else
		{
		vh[gap[cur]]--;
		if(vh[gap[cur]]==0)gap[1]=n;
		gap[cur]=mingap+1;
		vh[gap[cur]]++;
		}
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
	vh[0]=n;
	while(gap[1]<n)
		{
		minsize=2147483647;
		flag=false;
		sap(1);
		}
	fprintf(out,"%d\n",flow);
	fclose(out);
	return 0;
	}
