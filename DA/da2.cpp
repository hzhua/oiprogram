#include<stdio.h>
#include<stdlib.h>
int wa[100],wb[100],ws[100],wv[100];
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
	for(p=1,j=1;p<n;j*=2,m=p)
		{
		for(p=0,i=n-j;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)if(sa[i]-j>=0)y[p++]=sa[i]-j;
		for(i=0;i<n;i++)wv[i]=x[y[i]];
		for(i=0;i<m;i++)ws[i]=0;
		for(i=0;i<n;i++)ws[wv[i]]++;
		for(i=1;i<m;i++)ws[i]+=ws[i-1];
		for(i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		}
	return;
	}
int rank[100],height[100];
void calcheight(int *r,int n,int *sa)
	{
	int i,j,k=0;
	for(i=1;i<=n;i++)rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
	return ;
	}
int main()
	{
	int a[]={1,1,2,1,1,1,1,2};
	int ans[100]={0};
	da(a,8,ans,3);
	calcheight(a,8,ans);
	for(int i=0;i<=7;i++)
		printf("%d\n",height[i]);
	return 0;
	}
