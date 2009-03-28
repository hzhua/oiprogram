#include<stdio.h>
#include<stdlib.h>
#include<cmath>
int min(int a,int b){return a<b?a:b;}
int wa[1000],wb[1000];
int wv[1000],ws[1000];
int ans[100]={0};
bool cmp(int *r,int a,int b,int l)
	{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int *r,int n,int *sa,int m)
	{
	int *x=wa,*y=wb,*t,p;
	int i,j;
	for(i=0;i<m;i++)ws[i]=0;
	for(i=0;i<n;i++)ws[x[i]=r[i]]++;
	for(i=1;i<m;i++)ws[i]+=ws[i-1];
	for(i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
	for(j=1,p=1;p<n && j<n;j*=2,m=p)
		{
		for(i=n-j,p=0;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)if(sa[i]-j>=0)y[p++]=sa[i]-j;
		for(i=0;i<n;i++)wv[i]=x[y[i]];
		for(i=0;i<m;i++)ws[i]=0;
		for(i=0;i<n;i++)ws[wv[i]]++;
		for(i=1;i<m;i++)ws[i]+=ws[i-1];
		for(i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];
		for(t=x,x=y,y=t,p=1,i=1,x[sa[0]]=0;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		}
	return;
	}
int rank[1000],height[1000];
void calcheight(int *r,int *sa,int n)
	{
	for(i=0;i<n;height[rank[i++]]=k)
		if(rank[i]>0)
			for(k?k--:0,j=sa[rank[i]-1];i+k<n && j+k<n && r[i+k]==r[j+k];k++);
	}
int rmq[10][1000];
void gen(int n)
	{
	for(int i=1;i<=n;i++)
		rmq[0][i]=height[i];
	int t = floor(log(double(n))/log(2.0));
	for(int i=1;i<=t;i++)
		for(int j=1;j<=n;j++)
			{
			rmq[i][j]=rmq[i-1][j];
			if(j+(1<<(i-1))<=n)
				rmq[i][j]=min(rmq[i][j],rmq[i-1][j+(1<<(i-1))]);
			}
	}
int query(int a,int b) //a<b
	{
	int t=floor(log(double(b-a+1))/log(2.0));
	int xa=rmq[t][a],xb=rmq[t][b-(1<<t)+1];
	return min(xa,xb);
	}
int  q2(int a,int b)
	{
	a=rank[a];b=rank[b];
	if(a>b){int t=a;a=b;b=t;}
	return query(a+1,b);
	}
int main()
	{
	int a[]={101,101,101,101,101,101,101,101,101};
	da(a,9,ans,3);
	calcheight(a,ans,9);
	gen(8);
	//for(int i=1;i<=7;i++)
		printf("%d\n",q2(0,4));
	return 0;
	}
