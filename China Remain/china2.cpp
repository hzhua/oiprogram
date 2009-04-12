#include<stdio.h>
int remainer[4],goal[4];
int extendGcd(int a,int b,int &x,int &y)
    {
    if(b==0)
        {x=1;y=0;return a;}
    int tx,ty;
    int p=extendGcd(b,a%b,tx,ty);
    x=ty;y=tx-(a/b)*ty;
    return p;
    }
int chinaRemain(int n)
    {
    int M=1;
    for(int i=1;i<=n;i++)
        M*=remainer[i];
    int ans=0;
    for(int i=1;i<=n;i++)
        {
        int t=M/remainer[i];
        int ix,iy;
        int nouse=extendGcd(t,remainer[i],ix,iy);
        ans+=(ix*t*goal[i])%M;
        }
    return ans<0?ans+M:ans;
    }
int main()
	{
	freopen("china.in","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&goal[i],&remainer[i]);
	printf("%d\n",chinaRemain(n));
	return 0;
	}
