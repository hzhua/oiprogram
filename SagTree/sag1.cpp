#include<stdio.h>
#include<stdlib.h>
struct node
	{
	int x1,x2;
	int y1,y2;
	int  p; //1-FULL 0-NONE -1-PART
	};
/*
x2-x1>=y2-y1
	Left [x1,(x2+x1)/2][y1,y2]
	Right [(x2+x1)/2+1,x2][y1,y2]
x2-x1<y2-y1
	Left [x1,x2][y1,(y2+y1)/2]
	Right [x1,x2][(y2+y1)/2+1,y2]
*/
node arr[5000];
void insert(int a1,int a2,int b1,int b2,int pos)
	{
	int x1=arr[pos].x1,x2=arr[pos].x2;
	int y1=arr[pos].y1,y2=arr[pos].y2;
	if((arr[pos].x1+1==arr[pos].x2&&arr[pos].y1+1==arr[pos].y2))
		{
		arr[pos].p=1;
		return;
		}
	if(a1 <= arr[pos].x1 && a2 >= arr[pos].x2 &&
		b1 <= arr[pos].y1 && b2 >= arr[pos].y2)
			{
			arr[pos].p=1;
			insert(a1,a2,b1,b2,pos*2);
			insert(a1,a2,b1,b2,pos*2+1);
			return;
			}
	else
		{
		arr[pos].p=-1;
		if(x2-x1>=y2-y1)
			{
			int mid=arr[pos].x1+arr[pos].x2;
			mid/=2;
			if(x1<=mid)insert(a1,a2,b1,b2,pos*2);
			if(x2>=mid)insert(a1,a2,b1,b2,pos*2+1);
			}
		else
			{
			int mid=arr[pos].y1+arr[pos].y2;
			mid/=2;
			if(y1<=mid)insert(a1,a2,b1,b2,pos*2);
			if(y2>=mid)insert(a1,a2,b1,b2,pos*2+1);
			}
		}
	if(arr[pos*2].p==1&&arr[pos*2+1].p==1)
		arr[pos].p=1;
	else if(arr[pos*2].p==0&&arr[pos*2+1].p==0)
		arr[pos].p=0;
	}
int ans;
bool flag;
void del(int a1,int a2,int b1,int b2,int pos)
	{
	int x1=arr[pos].x1,x2=arr[pos].x2;
	int y1=arr[pos].y1,y2=arr[pos].y2;
	if(arr[pos].p==0)return;
	if(a1 <= arr[pos].x1 && a2 >= arr[pos].x2 &&
		b1 <= arr[pos].y1 && b2 >= arr[pos].y2)
			{
			if(arr[pos].p==1)
				{
				if(!flag)
					ans+=(arr[pos].x2-arr[pos].x1)*(arr[pos].y2-arr[pos].y1);
				flag=true;
				if(!(arr[pos].x1+1==arr[pos].x2&&arr[pos].y1+1==arr[pos].y2))
					{
					del(a1,a2,b1,b2,pos*2);
					del(a1,a2,b1,b2,pos*2+1);
					}
				arr[pos].p=0;
				}
			return;
			}
	else
		{
		if(x2-x1>=y2-y1)
			{
			int mid=arr[pos].x1+arr[pos].x2;
			mid/=2;
			if(x1<=mid)del(a1,a2,b1,b2,pos*2);
			if(x2>=mid)del(a1,a2,b1,b2,pos*2+1);
			}
		else
			{
			int mid=arr[pos].y1+arr[pos].y2;
			mid/=2;
			if(y1<=mid)del(a1,a2,b1,b2,pos*2);
			if(y2>=mid)del(a1,a2,b1,b2,pos*2+1);
			}
		}
	if(arr[pos*2].p==1&&arr[pos*2+1].p==1)
		arr[pos].p=1;
	else if(arr[pos*2].p==0&&arr[pos*2+1].p==0)
		arr[pos].p=0;
	}
void creat(int x1,int x2,int y1,int y2,int pos)
	{
	arr[pos].x1=x1;arr[pos].y1=y1;
	arr[pos].x2=x2;arr[pos].y2=y2;
	if(x1+1==x2&&y1+1==y2)
		return;
	else
		{
		if(x2-x1>=y2-y1)
			{
			int mid=x1+x2;
			mid/=2;
			creat(x1,mid,y1,y2,pos*2);
			creat(mid,x2,y1,y2,pos*2+1);
			}
		else
			{
			int mid=arr[pos].y1+arr[pos].y2;
			mid/=2;
			creat(x1,x2,y1,mid,pos*2);
			creat(x1,x2,mid,y2,pos*2+1);
			}
		}
	}
int main()
	{
	int mx,my;
	FILE *in=fopen("sagtree.in","r");
	FILE *out=fopen("sagtree.out","w");
	
	int on;
	fscanf(in,"%d%d%d\n",&mx,&my,&on);
	creat(1,mx,1,my,1);
	for(int i=1;i<=on;i++)
		{
		char t;
		int a,b,c,d;
		fscanf(in,"%c %d%d%d%d\n",&t,&a,&b,&c,&d);
		if(t=='I')
			insert(a,b,c,d,1);
		else if(t=='D')
			{
			ans=0;
			del(a,b,c,d,1);
			fprintf(out,"%d\n",ans);
			}
		}
	
	fclose(out);
	return 0;
	}
