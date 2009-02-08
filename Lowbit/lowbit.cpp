#include<stdio.h>
#include<stdlib.h>
int lowbit(int p){return p&(-p);}
int a[100][100],t[100][100],n;
int plus(int num,int posx,int posy)
	{
	a[posx][posy]+=num;
	for(int i=posx;i<=n;i+=lowbit(i))
		for(int j=posy;j<=n;j+=lowbit(j))
			t[i][j]+=num;
	}
int get(int posx,int posy)
	{
	int sum=0;
	for(int i=posx;i>0;i-=lowbit(i)) //WRONG:i>=0
		for(int j=posy;j>0;j-=lowbit(j))
			sum+=t[i][j];
	return sum;
	}
int main()
	{
	FILE *in=fopen("data.in","r");
	
	fscanf(in,"%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			{
			int tmp;
			fscanf(in,"%d",&tmp);
			plus(tmp,i,j);
			}
	printf("%d\n",get(n,n));
	return 0;
	}
