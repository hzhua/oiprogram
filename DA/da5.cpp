#include<stdio.h>
#include<stdlib.h>
int wa[100],wb[100],ws[1000];
int rank[100];
void calcSA(int *r,int n,int m)
	{
	int *x=wa,*y=wb,*t;
	int i,j;
	for(i=0;i<m;i++)ws[i]=0;
	for(i=0;i<n;i++)ws[x[i]=r[i]]++;
	for(i=1;i<m;i++)ws[i]+=ws[i-1];
	for(i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
	for(j=1;p<n;m=p,j*=2)
		{
		for(p=0,i=n-j;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)if(sa[i]-j>=0)y[p++]=sa[i]-j;
		for(i=0;i<m;i++)ws[i]=0;
		for(i=0;i<n;i++)wv[i]=x[y[i]];
		for(i=0;i<n;i++)ws[wv[i]]++;
		for(i=1;i<m;i++)ws[i]+=ws[i-1];
		for(i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];
		for(t=x,x=y,y=t,i=1,x[sa[0]]=0;i<n;i++)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
		}
	}
void calcHeight(int n)
	{
	for(i=0;i<n;i++)rank[sa[i]]=i;
	for(i=0,k=0;i<n;rank[i++]=k)
		if(rank[i]>0)
			for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
	}
int main()
	{
	return 0;
	}
