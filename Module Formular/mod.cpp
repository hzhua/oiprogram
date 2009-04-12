#include<stdio.h>
int extendGcd(int a,int b,int &x,int &y)
	{
	if(!b){x=1;y=0;return a;}
	int tx,ty,p;
	p=extendGcd(b,a%b,tx,ty);
	x=ty;y=tx-(a/b)*ty;
	return p;
	}
int calc(int a,int n,int b) //ax=b(mod n)
	{
	int x,y;
	int g=extendGcd(a,n,x,y);
	if(b%g==0)
		{
		int x0=(x*(b/g))%n;
		for(int i=0;i<=g-1;i++)
			printf("%d\n",x0+i*(n/g));
		}
	else return -1;
	}
int main()
	{
	int a,b,n;
	printf("a: b: n:");
	scanf("%d%d%d",&a,&b,&n);
	if(calc(a,n,b)==-1)printf("no answer\n");	
	return 0;
	}
