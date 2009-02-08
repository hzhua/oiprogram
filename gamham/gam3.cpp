#include<stdio.h>
#include<stdlib.h>
#include<cmath>
struct point
	{
	double x,y;
	point(double a,double b){x=a;y=b;}
	point(){x=y=0.0;}
	};
point arr[100];
int n;
double cross(point a,point b,point c)
	{
	point l1(a.x-c.x,a.y-c.y);
	point l2(b.x-c.x,b.y-c.y);
	return l1.x*l2.y-l2.x*l1.y;
	}
double length(point a,point b)
	{return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
void qsort(int l,int r)
	{
	int i=l,j=r;
	point m=arr[(l+r)/2];
	while(i<j)
		{
		while(i<=j&&cross(m,arr[i],arr[1])<0)i++;  //<!!!
		while(i<=j&&cross(m,arr[j],arr[1])>0)j--;    // >!!!
		if(i<=j)
			{
			point t=arr[i];
			arr[i]=arr[j];
			arr[j]=t;
			i++;j--;
			}
		}
	if(l<j)qsort(l,j);
	if(i<r)qsort(i,r);
	}
double gam()
	{
	int stack[1001]={0};
	int sn=3;
	stack[1]=1;
	stack[2]=2;
	stack[3]=3;
	for(int i=4;i<=n;i++)
		while(1)
			{
			double tmp=cross(arr[i],arr[stack[sn-1]],arr[stack[sn]]);
			if(tmp>=0)
				{
				stack[++sn]=i;
				break;
				}
			else
				sn--;
			}
	double ans=0;
	for(int i=2;i<=sn;i++)
		ans+=length(arr[stack[i]],arr[stack[i-1]]);
	ans+=length(arr[stack[sn]],arr[stack[1]]);
	return ans;
	}
int main()
	{
	FILE *in=fopen("fc.in","r");
	fscanf(in,"%d",&n);
	int lefti=1;
	double leftx=100000.0;
	for(int i=1;i<=n;i++)
		{
		fscanf(in,"%lf %lf",&arr[i].x,&arr[i].y);
		if(arr[i].x<leftx)
			{
			lefti=i;
			leftx=arr[i].x;
			}
		}
	point tmp=arr[lefti];arr[lefti]=arr[1];arr[1]=tmp;
	qsort(2,n);
	printf("%.2lf",gam());
	return 0;
	}
