#include<stdio.h>
#include<stdlib.h>
#include<cmath>
struct point 
	{
	double x,y;
	point(double a,double b){x=a,y=b;}
	point(){x=y=0;}
	};
point arr[20001];
int n;
double cross(point p1,point p2,point q1,point q2)
	{
	point a=point(p1.x-p2.x,p1.y-p2.y);
	point b=point(q1.x-q2.x,q1.y-q2.y);
	return a.x*b.y-a.y*b.x;
	}
double length(point a,point b)
	{return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
void qsort(int l,int r)
	{
	int i=l,j=r;
	point m=arr[(l+r)/2];
	while(i<j)
		{
		while(cross(m,arr[1],arr[i],arr[1])<0)i++;
		while(cross(m,arr[1],arr[j],arr[1])>0)j--;
		if(i<=j)
			{
			point tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
			i++;j--;
			}
		}
	if(l<j)qsort(l,j);
	if(i<r)qsort(i,r);
	}
double gramham()
	{
	int stack[21001];	
	int sn=3;
	stack[1]=1;
	stack[2]=2;
	stack[3]=3;
	for(int i=4;i<=n;i++)	
		while(1)
			{
			double tmp=cross(arr[i],arr[stack[sn]],arr[stack[sn-1]],arr[stack[sn]]); //!!!double
			if(tmp<0)
				sn--;
			else
				{
				stack[++sn]=i;
				break;
				}
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
	printf("%.2lf",gramham());
	
	return 0;
	}
