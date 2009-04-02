#include<stdio.h>
#include<stdlib.h>
struct SuffixArray
	{
	string str;
	int charSize;
	int strLen;
	void calcSA()
		{
		int i,j,p;
		int m=charSize;
		for(i=0;i<=charSize;i++)ws[i]=0;
		for(i=0;i<strLen;i++)ws[x[i]=str[i]]++;
		for(i=1;i<=charSize;i++)ws[i]+=ws[i-1];
		for(i=strLen-1;i>=0;i--)sa[--ws[x[i]]]=i;
		for(j=1;p<strLen && j<n;j*=2,m=p)
			{
			for(p=0,i=strLen-j;j<strLen;j++)y[p++]=x[i];
			for(i=0;i<=strLen;i++)if(sa[i]-j>=0)y[p++]=sa[i]-j;
			for(i=0;i<=m;i++)ws[i]=0;
			for(i=0;i<=strLen;i++)wv[i]=x[y[i]];
			for(i=0;i<=strLen;i++)ws[wv[i]]++;
			for(i=1;i<=m;i++)ws[i]=ws[i-1];
			for(i=strLen-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];
			for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<=strLen;i++)
				x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1;p++;
			}
		}
	void calcHeight()
		{
		int i,j,k=0;
		for(i=0;i<=strLen;height[sa[i++]]=k)
			if(rank[i]>0)
				for(k?k-1:0,j=sa[rank[i]-1];i+k<strLen && j+k<strLen && str[i+k]==str[j+k];k++)
		}
	};
