#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>
int love[500][5000];
int mx,my;
int max(int a,int b)
	{return a>b?a:b;}
void update_y(int tag,int iHap,int iLove,int pos,int l,int r)
	{
	if(love[tag][pos]==0||love[tag][pos]<iLove)
		love[tag][pos]=iLove;
	if(l==r)return;
	int mid=(l+r)/2;
	if(iHap<=mid)
		update_y(tag,iHap,iLove,pos*2,l,mid);
	else
		update_y(tag,iHap,iLove,pos*2+1,mid+1,r);
	}
void update_x(int h,int iHap,int iLove,int pos,int l,int r)
	{
	update_y(pos,iHap,iLove,1,1,my);
	int mid=(l+r)/2;
	if(l==r)return;
	if(h<=mid)
		update_x(h,iHap,iLove,pos*2,l,mid);
	else if(h>mid)
		update_x(h,iHap,iLove,pos*2+1,mid+1,r);
	}
int get_y(int tag,int hapx,int hapy,int pos,int l,int r)
	{
	int ans=-1;
	if(hapx<=l&&hapy>=r)
		return love[tag][pos];
	int mid=(l+r)/2;
	if(hapx<=mid)
		ans=max(ans,get_y(tag,hapx,hapy,pos*2,l,mid));
	if(hapy>mid)
		ans=max(ans,get_y(tag,hapx,hapy,pos*2+1,mid+1,r));
	return ans;
	}
int get_x(int hx,int hy,int hapx,int hapy,int pos,int l,int r)
	{
	int ans=-1;
	if(hx<=l&&hy>=r)
		return get_y(pos,hapx,hapy,1,1,my);
	int mid=(l+r)/2;
	if(hx<=mid)
		ans=max(ans,get_x(hx,hy,hapx,hapy,pos*2,l,mid));
	if(hy>mid)
		ans=max(ans,get_x(hx,hy,hapx,hapy,pos*2+1,mid+1,r));
	return ans;
	}
int main()
	{
	mx=5;
	my=5;
	update_x(2,2,5,1,1,mx);
	printf("%d\n",get_x(2,3,2,3,1,1,mx));
	return 0;
	}
