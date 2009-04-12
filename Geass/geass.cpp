#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
#define swap(a,b) {double adsf=a;a=b;b=adsf;}
double mt[SIZE][SIZE];
double ans[SIZE];
int n,m;
void calc()
	{
	int i=1,j=1;
	while(i<=n && j<=m)
		{
		int maxi=i;
		double maxv=mt[i][j];
		for(int p=i+1;p<=n;p++)
			if(mt[p][j] > maxv)
				{maxv=mt[p][j]; maxi=p;}
		for(int p=j;p<=m;p++)
			swap(mt[maxi][p] , mt[i][p])
		if(mt[i][j] !=0)
			{
			for(int p=j+1;p<=m;p++)
				mt[i][p] /= mt[i][j];
			mt[i][j]=1.0;
			
			for(int p=i+1;p<=n;p++)
				{
				double delta=mt[p][j];
				for(int u=j;u<=m;u++)
					mt[p][u]-=mt[i][u] * delta;
				}
			i++;
			}
		j++;
		}
	for(i=n;i>=1;i--)
		{
		double sum=0.0;
		for(j=i+1;j<=m-1;j++)
			sum +=mt[i][j] * ans[j];
		ans[i]=mt[i][m]-sum;
		}
	}
int main()
	{
	freopen("geass.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lf",&mt[i][j]);
	calc();
	for(int i=1;i<=n;i++)
		{
		for(int j=1;j<=m;j++)
			printf("%lf ",mt[i][j]);
		printf("\n");
		}
	for(int i=1;i<=n;i++)
		printf("%lf\n",ans[i]);
	return 0;
	}
