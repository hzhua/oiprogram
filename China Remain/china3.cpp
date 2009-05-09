#include<stdio.h>
int remainer[100],goal[100];
int n;
int china()//x=goal[i] (mod remainer[i])
	{
	int M=1;
	for(int i=1;i<=n;i++)
		M*=remainer[i];
	for(int i=1;i<=n;i++)
		{
		int tM=M/remainer[i];
		int x,y;
		int nouse=extend_gcd(tM,remainer[i],x,y);
		ans=(ans+tM*x*goal[i])%n;
		}
	return a<0?a+n:a;
	}
