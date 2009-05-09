#include<stdio.h>
#include<stdlib.h>
#include<cstring>
int extend_gcd(int a,int b,int &x,int &y)
	{
	if(b==0){x=1;y=0;return a;}
	int tx,ty;
	int ret=extend_gcd(b,a%b,tx,ty);
	x=ty;y=tx-(a/b)*ty;
	return ret;
	}
void mod_f(int a,int b,int n)//ax=b(mod n)
	{
	int x,y;
	int g=extend_gcd(a,n,x,y);
	if(g%b==0)
		{
		int x0=((g/b)*x)%n;
		for(int i=0;i<=g-1;i++)
			printf("%d\n",x0+i*(g/b));
		}
	else printf("No Answer\n");
	}
int main()
	{
	return 0;
	}
