#include <iostream>
 #include <math.h>
 #define max(a,b) ((a>b)?a:b)
 #define min(a,b) (a<b?a:b)
 
using namespace std;
 
const int maxn=50001;
 int h[maxn];
 int mx[maxn][16],mn[maxn][16];
int n,q;
 
 void rmq_init()
 {
     int i,j;
     for(j=1;j<=n;j++) mx[j][0]=mn[j][0]=h[j];
     int m=floor(log((double)n)/log(2.0));
     for(i=1;i<=m;i++){
         for(j=n;j>0;j--){
             mx[j][i]=mx[j][i-1];
             if(j+(1<<(i-1))<=n) mx[j][i]=max(mx[j][i],mx[j+(1<<(i-1))][i-1]);
         }
    }
    for(i=1;i<=m;i++){
         for(j=n;j>0;j--){
            mn[j][i]=mn[j][i-1];
             if(j+(1<<(i-1))<=n) mn[j][i]=min(mn[j][i],mn[j+(1<<(i-1))][i-1]);
         }
     }
 }
 
 int rmq(int l,int r)
 {
     int m=floor(log((double)(r-l+1))/log(2.0));
    //int a=max(mx[l][m],mx[r-(1<<m)+1][m]);
     int b=min(mn[l][m],mn[r-(1<<m)+1][m]);
    return b;  
 }
 
 int main()
 {
 	freopen("st.in","r",stdin);
     int i,l,r;
     scanf("%d%d",&n,&q);
     for(i=1;i<=n;i++) scanf("%d",&h[i]);
     rmq_init();
     for(i=0;i<q;i++){
         scanf("%d%d",&l,&r);
         printf("%d\n",rmq(l,r));
     }

 }
