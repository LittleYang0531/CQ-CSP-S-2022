#include<bits/stdc++.h>

#define  Int  long long int
#define  Pub  public
#define  rand  Rand
using std::min;using std::max;
std::mt19937 rand(time(0));

int n,m,q;
Int a[300005],b[300005];
Int sta1[300005][18],stb1[300005][18];
Int sta2[300005][18],stb2[300005][18];
Int sta3[300005][18];
Int sta4[300005][18];
Int mina(int x,int y){
    int k=log2(y-x+1);
    return min(sta1[x][k],sta1[y-(1<<k)+1][k]);
}
Int minaa(int x,int y){
    int k=log2(y-x+1);
    return min(sta3[x][k],sta3[y-(1<<k)+1][k]);
}
Int minb(int x,int y){
    int k=log2(y-x+1);
    return min(stb1[x][k],stb1[y-(1<<k)+1][k]);
}
Int maxa(int x,int y){
    int k=log2(y-x+1);
    return max(sta2[x][k],sta2[y-(1<<k)+1][k]);
}
Int maxaa(int x,int y){
    int k=log2(y-x+1);
    return max(sta4[x][k],sta4[y-(1<<k)+1][k]);
}
Int maxb(int x,int y){
    int k=log2(y-x+1);
    return max(stb2[x][k],stb2[y-(1<<k)+1][k]);
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        sta1[i][0]=sta2[i][0]=a[i];
        if(a[i]>=0)sta3[i][0]=a[i];
        else sta3[i][0]=1e18;
        if(a[i]<=0)sta4[i][0]=a[i];
        else sta4[i][0]=-1e18;
    }
    
    for(int k=1;k<=17;++k)
        for(int i=1;i<=n;++i){
            sta1[i][k]=sta3[i][k]=1e18;
            sta2[i][k]=sta4[i][k]=-1e18;
            sta1[i][k]=min(sta1[i][k-1],sta1[i+(1<<k-1)][k-1]),
            sta3[i][k]=min(sta3[i][k-1],sta3[i+(1<<k-1)][k-1]),
            sta2[i][k]=max(sta2[i][k-1],sta2[i+(1<<k-1)][k-1]),
            sta4[i][k]=max(sta4[i][k-1],sta4[i+(1<<k-1)][k-1]);
        }
    for(int i=1;i<=m;++i){
        scanf("%lld",&b[i]);
        stb1[i][0]=stb2[i][0]=b[i];
    }
    for(int k=1;k<=17;++k)
        for(int i=1;i<=n;++i){
            stb1[i][k]=1e18;
            stb2[i][k]=-1e18;
            stb1[i][k]=min(stb1[i][k-1],stb1[i+(1<<k-1)][k-1]),
            stb2[i][k]=max(stb2[i][k-1],stb2[i+(1<<k-1)][k-1]);
        }
    
    while(~--q){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        Int a,b;
        Int a1=mina(l1,r1),a2=maxa(l1,r1),b1=minb(l2,r2),b2=maxb(l2,r2);
        Int a3=minaa(l1,r1),a4=maxaa(l1,r1);
             if(a1>=0&&b1>=0)a=a2,b=b1;
        else if(a2<=0&&b2<=0)a=a1,b=b2;
        else if(a1>=0&&b2<=0)a=a1,b=b1;
        else if(a2<=0&&b1>=0)a=a2,b=b2;
        else{
            if(b2<=0)a=a1,b=b2;
            else if(b1>=0)a=a2,b=b1;
            else if(a2<=0)a=a2,b=b2;
            else if(a1>=0)a=a1,b=b1;
            else{
                if(a3*b1>=a4*b2)a=a3,b=b1;
                else a=a4,b=b2;
            }
        }
        printf("%lld\n",a*b);
    }
    
    return 0;
}
