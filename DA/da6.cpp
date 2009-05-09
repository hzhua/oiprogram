#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#define SIZE 50002
int wx[SIZE],wy[SIZE];
int *x,*y;
int ws[SIZE],wv[SIZE];
int rank[SIZE],height[SIZE],sa[SIZE];
long long n,m;
int s[SIZE];
bool cmp(int *r,int a,int b,int l)
	{return a+l<n && b+l<n && r[a]==r[b]&&r[a+l]==r[b+l];}
void da()
	{
	int *x=wx,*y=wy,*t,p;
	int i,j;
	for(i=0;i<m;i++)ws[i]=0;
	for(i=0;i<n;i++)ws[x[i]=s[i]]++;
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
void calcHeight()
	{
	for(int i=0;i<n;i++) rank[sa[i]]=i;
	for(int i=0,j=0,k=0;i<n;height[rank[i++]]=k)
		if(rank[i]>0)
			for(k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
	}

int main()
	{
	freopen("SUBST1.in","r",stdin);
	int casen;
	scanf("%d\n",&casen);
	while(casen-->0)
		{
		n=0;
		m=255;
		char tmp;
		memset(rank,0,sizeof(rank));
		while(scanf("%c",&tmp)!=EOF)
			{if(tmp=='\n')break;s[n++]=tmp;}
		long long  ans=n*(1+n)/2;
		s[n]=-1;
		da();
		calcHeight();
		for(int i=1;i<n;i++)
			ans-=height[i];
		printf("%lld\n",ans);
		}
	return 0;
	}
