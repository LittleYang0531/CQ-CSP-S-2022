#include <bits/stdc++.h>
using namespace std;
#define int long long

#define rep(i, a, b) for (int i = (a); i <= (b); i ++)
#define dep(i, a, b) for (int i = (a); i >= (b); i --)

bool cur1;
const int N =1e5+5,inf=2e9;
int n,m,q,a[N],b[N];

#define ls (k<<1)
#define rs (ls|1)
#define mid ((l+r)>>1)
struct Seg{
  int zmax[N*4],zmin[N*4],fmax[N*4],fmin[N*4],fl[N*4];
  void pushup(int k){
    zmax[k]=max(zmax[ls],zmax[rs]);
    zmin[k]=min(zmin[ls],zmin[rs]);
    fl[k]=fl[ls]|fl[rs];
    fmax[k]=max(fmax[ls],fmax[rs]);
    fmin[k]=min(fmin[ls],fmin[rs]);
  }
  void build(int k,int l, int r,int op){
    if (l==r){
      int v=op==1?a[l]:b[l];
      if(v>0) zmax[k]=zmin[k]=v,fmax[k]=-inf,fmin[k]=inf;
      else if(v<0) fmax[k]=fmin[k]=v,zmax[k]=-inf,zmin[k]=inf;
      else fl[k]=1,zmax[k]=-inf,zmin[k]=inf,fmax[k]=-inf,fmin[k]=inf;
      return;
    }
    build(ls,l,mid,op),build(rs,mid+1,r,op);
    pushup(k);
  }
  
  int ask(int x,int y,int v,int k,int l,int r) {
    if(x<=l&&r<=y) {
      if(v==1) return zmax[k];
      if(v==2) return zmin[k];
      if(v==3) return fl[k];
      if(v==4) return fmax[k];
      if(v==5) return fmin[k];
    }
    if(y<=mid)return ask(x,y,v,ls,l,mid);
    if(x>mid) return ask(x,y,v,rs,mid+1,r);
    int vl=ask(x,y,v,ls,l,mid),vr=ask(x,y,v,rs,mid+1,r);
    if(v==1)return max(vl,vr);
    if(v==2)return min(vl,vr);
    if(v==3)return vl|vr;
    if(v==4)return max(vl,vr);
    return min(vl,vr);
  }
} A,B;

int x[7],y[7];
bool cur2;

signed main(){
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n>>m>>q;
  rep(i,1,n)cin>>a[i];
  rep(i,1,m)cin>>b[i];
  A.build(1,1,n,1),B.build(1,1,m,2);
  while(q--){
    int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
    rep(i,1,5)x[i]=A.ask(l1,r1,i,1,1,n);
    rep(i,1,5)y[i]=B.ask(l2,r2,i,1,1,m);
    int ans=-1e18-1;
    rep(i,1,5){
      if (i==3&&x[i]) ans=max(ans,0ll);
      else if((i==1&&x[i]!=-inf)||(i==2&&x[i]!=inf)){
        int res;
        rep(j,1,5)
          if(((j==2||j==5)&&y[j]!=inf)||((j==1||j==4)&&y[j]!=-inf)) res=y[j];
          else if(j==3&&y[j]) res=0;
        ans=max(ans,x[i]*res);
      }
      else if((i==4&&x[i]!=-inf)||(i==5&&x[i]!=inf)){
        int res;
        dep(j,5,1)
          if(((j==2||j==5)&&y[j]!=inf)||((j==1||j==4)&&y[j]!=-inf)) res=y[j];
          else if(j==3&&y[j]) res=0;          
        ans=max(ans,x[i]*res);
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}
