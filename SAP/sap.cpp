/*
ID:hzhua201
LANG:C++
PROB:ditch
*/
#include<stdio.h>
#include<stdlib.h>
int a[201][201];
int gap[201],vh[201];

int n,flow;
int minsize=2147483647;
bool flag=false;
int min(int a,int b){return a>b?b:a;}
void sap(int cur)
	{
	int mingap=n-1;//!@#$%^&*&^%$#@!#$%^&*&^%$#@注意！！n-1
	int tsize=minsize;
	if(cur==n)
		{
		flag=true;
		flow+=minsize;
		return;
		}
	int i;
	for(i=1;i<=n;i++)
		if(a[cur][i]>0)
			{
			if(gap[i]+1==gap[cur])
				{
				minsize=min(minsize,a[cur][i]);
				sap(i);
				if(gap[1]>=n)return;
				if(flag)break;
				minsize=tsize;
				}
			mingap=min(mingap,gap[i]);
			}
	if(flag)
		{
		a[cur][i]-=minsize;
		a[i][cur]+=minsize;
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
		a[x][b]+=c;
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
