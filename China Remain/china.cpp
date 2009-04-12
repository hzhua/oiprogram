#include<stdio.h>
#include<stdlib.h>
//x=g (mod rem)
int g[100],rem[100];
int extendGcd(int a,int b,int &x,int &y)
	{
	if(!b){x=1;y=0;return a;}
	int tx,ty,p;
	p=extendGcd(b,a%b,tx,ty);
	x=ty;y=tx-(a/b)*ty;
	return p;
	}
int chinaRemain(int n)
	{
	int M=1,ans=0;
	for(int i=1;i<=n;i++)
		M*=rem[i];
	for(int i=1;i<=n;i++)
		{
		int m=M/rem[i];
		int x,y;
		int nouse=extendGcd(m,rem[i],x,y);
		ans= (ans+ m*x*g[i])%M;
		}
	if(ans<0)
		return ans+M;
	else return ans;
	}

int main()
	{
	freopen("china.in","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&g[i],&rem[i]);
	printf("%d\n",chinaRemain(n));
	return 0;
	}
