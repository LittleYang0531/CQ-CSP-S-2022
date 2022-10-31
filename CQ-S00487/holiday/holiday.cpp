#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(int i=(a); i>=(b); --i)
#define pb push_back
#define ll long long
#define mid ((l+r)>>1)
#define modj(x) ((x)-=((x)>=MOD)?MOD:0)
using namespace std;
//
const ll N=3e2;
vector<ll> side[N+10];
ll lth[N+10][N+10],dp[N+10][N+10];
ll stac[N+10],a[N+10];
bool vis[N+10];
struct SGT{
	ll T[N*4+10];
	void init(ll po,ll l,ll r){
		T[po]=-1e18;
		if(l==r) return;
		init(po<<1,l,mid); init((po<<1)|1,mid+1,r);
	}
	void add(ll po,ll l,ll r,ll qpo,ll z){
		if(l==r){
			T[po]=max(T[po],z); return;
		} 
		if(qpo<=mid) add(po<<1,l,mid,qpo,z);
		else add((po<<1)|1,mid+1,r,qpo,z);
		T[po]=max(T[po<<1],T[(po<<1)|1]);
	}
	ll que(ll po,ll l,ll r,ll ql,ll qr){
		if(ql>qr) return -1e18;
		if(ql<=l&&r<=qr) return T[po];
		ll rt=-1e18;
		if(ql<=mid) rt=max(rt,que(po<<1,l,mid,ql,qr));
		if(qr>mid) rt=max(rt,que((po<<1)|1,mid+1,r,ql,qr));
		return rt;
	}
}T[N+10];
void bfs(ll yx){
	memset(vis,0,sizeof(vis));
	ll l=1,r=0; stac[++r]=yx;
	vis[yx]=1; lth[yx][yx]=0;
	while(l<=r){
		ll x=stac[l]; ++l;
		for(auto tox:side[x]){
			if(vis[tox]) continue;
			stac[++r]=tox; vis[tox]=1;
			lth[yx][tox]=lth[yx][x]+1;
		}
	}
}
//
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline ll gt(){
	ll x=0,b=0; char c=gc();
	while(!isdigit(c)) b|=(c=='-'),c=gc();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=gc();
	return b?-x:x;
}
inline void wr(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ll n=gt(),m=gt(),k=gt()+1;
	FOR(i,2,n) a[i]=gt();
	FOR(i,1,m){
		ll x=gt(),y=gt();
		side[x].pb(y);
		side[y].pb(x);
	}
	FOR(i,1,n) bfs(i);
	memset(dp,-0x3f,sizeof(dp));
	FOR(i,2,n){
		FOR(j,2,n){
			if(i==j) continue;
			if(lth[1][i]<=k&&lth[i][j]<=k) dp[i][j]=a[i]+a[j];
		}
	}
	FOR(i,2,n) T[i].init(1,1,n);
	FOR(i,2,n){
		FOR(j,2,n){
			if(i==j) continue;
			T[j].add(1,1,n,i,dp[i][j]);
		}
	}
	ll ans=-1e18;
	FOR(j,2,n){
		FOR(i,2,n){
			if(i==j||dp[i][j]<=0) continue;
			FOR(l,2,n){
				if(l==i||l==j||lth[j][l]>k) continue;
				ll t1=min(i,j),t2=max(i,j);
				ll t=max(T[l].que(1,1,n,1,t1-1),T[l].que(1,1,n,t1+1,t2-1));
				t=max(t,T[l].que(1,1,n,t2+1,n));
//				printf("[%lld,%lld]-%lld L:%lld %lld\n",i,j,dp[i][j],l,t);
				ans=max(ans,t+dp[i][j]);
			}
		}
	}
	cout<<ans;
	return 0;
}


