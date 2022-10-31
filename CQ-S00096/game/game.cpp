#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,Inf=1e9+7;
typedef long long ll;
const ll INF=LLONG_MAX;
int n,m,q;
int a[N][2];
struct sgt{
	struct tree{int l,r,mx[2],mn[2],tag;}t[N*4];
	#define lt p<<1
	#define rt p<<1|1
	inline void pushup(int p){
		t[p].tag=t[lt].tag|t[rt].tag;
		for(int i=0;i<=1;++i){
			t[p].mx[i]=max(t[lt].mx[i],t[rt].mx[i]);
			t[p].mn[i]=min(t[lt].mn[i],t[rt].mn[i]);
		}
	}
	void build(int p,int l,int r,int op){
		t[p]=(tree){l,r,-Inf,-Inf,Inf,Inf,0};
		if(l==r)return t[p].mn[abs(a[l][op])==a[l][op]]=t[p].mx[abs(a[l][op])==a[l][op]]=a[l][op],t[p].tag=(a[l][op]==0),void();
		int mid=(l+r)>>1;
		build(lt,l,mid,op),build(rt,mid+1,r,op);
		pushup(p);
	}
	int ask_mx(int p,int l,int r,int op){
		if(l<=t[p].l&&t[p].r<=r)return t[p].mx[op];
		int mid=(t[p].l+t[p].r)>>1,res=-Inf;
		if(l<=mid)res=max(res,ask_mx(lt,l,r,op));
		if(r>mid)res=max(res,ask_mx(rt,l,r,op));
		return res;
	}
	int ask_mn(int p,int l,int r,int op){
		if(l<=t[p].l&&t[p].r<=r)return t[p].mn[op];
		int mid=(t[p].l+t[p].r)>>1,res=Inf;
		if(l<=mid)res=min(res,ask_mn(lt,l,r,op));
		if(r>mid)res=min(res,ask_mn(rt,l,r,op));
		return res;
	}
	int ask_tag(int p,int l,int r){
		if(l<=t[p].l&&t[p].r<=r)return t[p].tag;
		int mid=(t[p].l+t[p].r)>>1,res=0;
		if(l<=mid)res=res|ask_tag(lt,l,r);
		if(r>mid)res=res|ask_tag(rt,l,r);
		return res;
	}
}A,B;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i)cin>>a[i][0];
	for(int i=1;i<=m;++i)cin>>a[i][1];
	A.build(1,1,n,0),B.build(1,1,m,1);
	while(q--){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		int Azmx=A.ask_mx(1,l1,r1,1),Afmx=A.ask_mx(1,l1,r1,0),Azmn=A.ask_mn(1,l1,r1,1),Afmn=A.ask_mn(1,l1,r1,0);
		int Bzmx=B.ask_mx(1,l2,r2,1),Bfmx=B.ask_mx(1,l2,r2,0),Bzmn=B.ask_mn(1,l2,r2,1),Bfmn=B.ask_mn(1,l2,r2,0);
		int tagb=B.ask_tag(1,l2,r2);
		ll ans;
		if(A.ask_tag(1,l1,r1))ans=0;
		else ans=-INF;
		if(Azmx!=-Inf){
			if(Bfmn!=Inf)ans=max(ans,1ll*Azmx*Bfmn);
			else if(tagb)ans=max(ans,0ll);
			else if(Bzmn!=Inf)ans=max(ans,1ll*Azmx*Bzmn);
		}
		if(Afmx!=-Inf){
			if(Bzmx!=-Inf)ans=max(ans,1ll*Afmx*Bzmx);
			else if(tagb)ans=max(ans,0ll);
			else if(Bfmx!=-Inf)ans=max(ans,1ll*Afmx*Bfmx);
		}
		if(Azmn!=Inf){
			if(Bfmn!=Inf)ans=max(ans,1ll*Azmn*Bfmn);
			else if(tagb)ans=max(ans,0ll);
			else if(Bzmn!=Inf)ans=max(ans,1ll*Azmn*Bzmn);
		}
		if(Afmn!=Inf){
			if(Bzmx!=-Inf)ans=max(ans,1ll*Afmn*Bzmx);
			else if(tagb)ans=max(ans,0ll);
			else if(Bfmx!=-Inf)ans=max(ans,1ll*Afmn*Bfmx);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
