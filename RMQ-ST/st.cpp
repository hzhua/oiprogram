#include<stdio.h>
#include<cmath>
int num[1000];
int d[1000][30];
int n;
int min(int a,int b){return a>b?b:a;}
void gen()
	{
	for(int i=1;i<=n;i++)
		d[i][0]=num[i];
	int m=floor(log(double(n))/log(2.0));
	for(int i=1;i<=m;i++)
		{
		for(int j=1;j<=n;j++)
			{
			d[j][i]=d[j][i-1];
			if(j+(1<<(i-1))<=n)//位运算加括号！！！
				d[j][i]=min(d[j][i],d[j+(1<<(i-1))][i-1]);
			}
		}
	}
int query(int x,int y)
	{
	int k=floor(log((double)(y-x+1))/log(2.0));
	return min(d[x][k],d[y-(1<<k)+1][k]);
	}
int main()
	{
	freopen("st.in","r",stdin);
	int m;
	scanf("%d %d",&n,&m);
	//n--;
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	gen();
	for(int i=1;i<=m;i++)
		{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",query(a,b));
		}
	return 0;
	}
