#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+2;
const long long inf32=1e9+1;
const long long inf64=1e18+1;
int n,m,Q;
long long ar[maxn],br[maxn],va[maxn];
int sum1[maxn],sum2[maxn];
struct SEGTREE{
    struct node{
        int ls,rs,l,r;
        long long mx,mi;
    }t[maxn*4];
    void pushup(int x){
        t[x].mx=max(t[t[x].ls].mx,t[t[x].rs].mx);
        t[x].mi=min(t[t[x].ls].mi,t[t[x].rs].mi);
        return ;
    }
    void build(int x,int l,int r){
        t[x].l=l,t[x].r=r;
        if(t[x].l==t[x].r){
            if(va[l]<inf32)t[x].mi=va[l],t[x].mx=va[l];
            else t[x].mi=inf32,t[x].mx=-inf32;
            t[x].ls=t[x].rs=0;
            return ;
        }
        int mid=(t[x].l+t[x].r)>>1;
        t[x].ls=(x<<1),t[x].rs=(x<<1|1);
        build(t[x].ls,l,mid);
        build(t[x].rs,mid+1,r);
        pushup(x);
        return ;
    }
    long long query(int x,int l,int r,bool ty){
        if(t[x].l==l&&t[x].r==r){
            if(!ty)return t[x].mi;
            else return t[x].mx;
        }
        int mid=(t[x].l+t[x].r)>>1;
        if(l>mid)return query(t[x].rs,l,r,ty);
        else if(r<=mid)return query(t[x].ls,l,r,ty);
        else {
            if(!ty)return min(query(t[x].ls,l,mid,ty),query(t[x].rs,mid+1,r,ty));
            else return max(query(t[x].ls,l,mid,ty),query(t[x].rs,mid+1,r,ty));
        }
    }
}s1,s2,s3,s4;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%d%d",&n,&m,&Q);
    sum1[0]=sum2[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&ar[i]);
        if(ar[i]>=0)sum1[i]++;
        sum1[i]+=sum1[i-1];
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&br[i]);
        if(br[i]>=0)sum2[i]++;
        sum2[i]+=sum2[i-1];
    }
    for(int i=1;i<=n;i++){
        if(ar[i]>=0)va[i]=ar[i];
        else va[i]=inf32;
    }
    s1.build(1,1,n);
    for(int i=1;i<=n;i++){
        if(ar[i]<0)va[i]=-ar[i];
        else va[i]=inf32;
    }
    s2.build(1,1,n);
    for(int i=1;i<=m;i++){
        if(br[i]>=0)va[i]=br[i];
        else va[i]=inf32;
    }
    s3.build(1,1,m);
    for(int i=1;i<=m;i++){
        if(br[i]<0)va[i]=-br[i];
        else va[i]=inf32;
    }
    s4.build(1,1,m);
    int l1,r1,l2,r2;
    long long v1,v2,ans;
    for(int i=1;i<=Q;i++){
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(sum2[r2]-sum2[l2-1]==0){//-
            if(sum1[r1]-sum1[l1-1]==r1-l1+1){//+-
                ans=-s1.query(1,l1,r1,0)*s4.query(1,l2,r2,1);
            }
            else {//--
                ans=s2.query(1,l1,r1,1)*s4.query(1,l2,r2,0);
            }
        }
        else if(sum2[r2]-sum2[l2-1]==r2-l2+1){//+
            if(sum1[r1]-sum1[l1-1]==0){//-+;
                ans=-s2.query(1,l1,r1,0)*s3.query(1,l2,r2,1);
            }
            else {//++
                ans=s1.query(1,l1,r1,1)*s3.query(1,l2,r2,0);
            }
        }
        else {//+-;
            ans=-inf64;
            if(sum1[r1]-sum1[l1-1]!=0){//+-
                ans=max(ans,-s1.query(1,l1,r1,0)*s4.query(1,l2,r2,1));
            }
            if(sum1[r1]-sum1[l1-1]!=r1-l1+1){//-+
                ans=max(ans,-s2.query(1,l1,r1,0)*s3.query(1,l2,r2,1));
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}