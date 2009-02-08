/*
ID:hzhua201
LANG:C++
PROB:fc
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>
struct point
	{
	double x,y;
	point(double a,double b){x=a;y=b;}
	point(){x=y=0.0;}
	};
point arr[10001];
int n;
double cross(point p1,point p2,point p3,point p4)
	{
	point l1=point(p1.x-p2.x,p1.y-p2.y);
	point l2=point(p3.x-p4.x,p3.y-p4.y);
	double ans=(double)((double)l1.x*l2.y)-((double)l2.x*l1.y);
	return ans;
	}
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
			point xorg=arr[i];arr[i]=arr[j];arr[j]=xorg;
			i++;j--;
			}
		}
	if(l<j)qsort(l,j);
	if(i<r)qsort(i,r);
	}
double leng(point a,point b)
	{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	}
double gamham()
	{
	int stack[20001]={0};
	int sn=3;
	stack[1]=1;
	stack[2]=2;
	stack[3]=3;
	for(int i=4;i<=n;i++)
		while(1)
			{
			double tmp=cross(arr[i],arr[stack[sn]],arr[stack[sn-1]],arr[stack[sn]]);
			if(tmp<0)
				sn--;
			else	
				{
				stack[++sn]=i;
				break;
				}
			}
	double ans=0.0;
	for(int i=2;i<=sn;i++)
		ans+=leng(arr[stack[i]],arr[stack[i-1]]);
	ans+=leng(arr[stack[sn]],arr[stack[1]]);
	return ans;
	}
int main()
	{
	FILE *in=fopen("fc.in","r");
	FILE *out=fopen("fc.out","w");
	
	fscanf(in,"%d",&n);
	int left=1;
	double leftx=1000000.0;
	for(int i=1;i<=n;i++)
		{
		double a,b;
		fscanf(in,"%lf %lf",&a,&b);
		arr[i].x=a;arr[i].y=b;
		if(a<leftx)
			{
			leftx=a;
			left=i;
			}
		}
	point tmp=arr[left];arr[left]=arr[1];arr[1]=tmp;
	qsort(2,n);
	fprintf(out,"%.2lf\n",gamham());
	
	fclose(out);
	return 0;
	}
