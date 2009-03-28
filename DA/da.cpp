#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#define maxn 1000001
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) ws[i]=0;
     for(i=0;i<n;i++) ws[x[i]=r[i]]++;
     for(i=1;i<m;i++) ws[i]+=ws[i-1];
     for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
     for(j=1,p=1;p<n;j*=2,m=p)
     {
       for(p=0,i=n-j;i<n;i++) y[p++]=i;
       for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
       for(i=0;i<n;i++) wv[i]=x[y[i]];
       for(i=0;i<m;i++) ws[i]=0;
       for(i=0;i<n;i++) ws[wv[i]]++;
       for(i=1;i<m;i++) ws[i]+=ws[i-1];
       for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
       for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
       x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
     }
     return;
}
int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n)
{
     int i,j,k=0;
     for(i=0;i<n;i++) rank[sa[i]]=i;
     for(i=0;i<n;height[rank[i++]]=k)
     	if(rank[i]!=0)
	       for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
     return;
}
int d[1000][30];
int min(int a,int b){return a>b?b:a;}
void gen(int n)
	{
	for(int i=1;i<=n;i++)
		d[i][0]=height[i];
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
int q2(int a,int b)
	{
	a=rank[a],b=rank[b];
	if(a>b){int t=a;a=b;b=t;}
	return query(a+1,b);
	}
int main()
	{
	int a[]={1,1,2,1,1,1,2,2};
	int ans[100]={0};
	da(a,ans,8,3);
	calheight(a,ans,8);
	gen(7);	
	printf("%d\n",q2(0,4));
	return 0;
	}
