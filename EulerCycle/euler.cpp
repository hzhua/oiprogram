#include<stdio.h>
int num = 0;//标记输出队列
int match[100];//标志节点的度，无向图，不区分入度和出度
int Array[500][500];
int Record[500];
void sove(int x)
{
     if(match[x] == 0)

        Record[num++] = x;  
    else
    {
            for(int k =0;k<=100;k++)
            {
                if(Array[x][k] !=0 )
                {
                    Array[x][k]--;
                    Array[k][x]--;
                    match[x]--;
                    match[k]--;
                    sove(k); 
                }
 
            }   
            Record[num++] = x;         
    }   
} 
int main()
	{
	int n;
	freopen("euler.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		{
		int a,b;
		scanf("%d%d",&a,&b);
		Array[a][b]++;
		match[a]++;match[b]++;
		}
	sove(1);
	for(int i=num-1;i>=0;i--)printf("%d ",Record[i]);
	return 0;
	}
