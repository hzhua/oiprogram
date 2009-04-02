void calcSA()
	{
	for(i=0;i<=m;i++)ws[i]=0;
	for(i=0;i<n;i++)ws[x[i]=r[i]]++;
	for(i=1;i<=m;i++)ws[i]+=ws[i-1];
	for(i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
	for(p=0,j=1;p<n && j<n;j*=2,m=p);
		{
		for(p=0,i=n-j;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)if(sa[i]-j>=0)y[p++]=sa[i]-j;
		for(i=0;i<=m;i++)ws[i]=0;
		for(i=0;i<n;i++)wv[i]=x[y[i]];
		for(i=0;i<n;i++)ws[wv[i]]++;
		for(i=1;i<=m;i++)ws[i]+=ws[i-1];
		for(i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		}
	}
void calcHeight()
	{
	for(i=0;i<n;i++)rank[sa[i]]=i;
	for(i=0,k=0;i<n;height[rank[i++]]=k)
		if(rank[i]>0)
			for(k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++)
	}
