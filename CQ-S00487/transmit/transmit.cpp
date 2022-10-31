#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(int i=(a); i>=(b); --i)
#define pb push_back
#define ll long long
#define modj(x) ((x)-=((x)>=MOD)?MOD:0)
using namespace std;
//
bool h1;
const ll N=2e5;
vector<ll> side[N+10];
ll fa[N+10],dth[N+10],a[N+10],la[N+10];
ll b1[N+10],b2[N+10],c1[N+10],c2[N+10];
ll b[N+10],c[N+10],f[N+10],g[N+10];
ll up[N+10][22],upz[N+10][22];
ll n,q,k;
bool H1;
//
void dfs(ll ypo,ll po){
	FOR(i,1,20){
		if(!up[po][i-1]) break;
		up[po][i]=up[up[po][i-1]][i-1];
		upz[po][i]=upz[po][i-1]+upz[up[po][i-1]][i-1]-a[up[po][i-1]];
	}
	dth[po]=dth[ypo]+1; fa[po]=ypo; la[po]=a[po];
	for(auto tox:side[po]){
		la[po]=min(la[po],a[tox]);
		if(tox==ypo) continue;
		up[tox][0]=po; upz[tox][0]=a[po]+a[tox];
		dfs(po,tox);
	}
}
ll lca_bl(ll x,ll y){
	ll to1=0,to2=0;
	while(dth[x]>dth[y]) ++to1,b1[to1]=a[x],c1[to1]=la[x],x=fa[x];
	while(dth[y]>dth[x]) ++to2,b2[to2]=a[y],c2[to2]=la[y],y=fa[y];
	while(x!=y){
		++to1,b1[to1]=a[x],c1[to1]=la[x],x=fa[x];
		++to2,b2[to2]=a[y],c2[to2]=la[y],y=fa[y];
	}
	++to1,b1[to1]=a[x],c1[to1]=la[x];
	FOR(i,1,to1) b[i]=b1[i],c[i]=c1[i];
	FOR(i,1,to2) b[to1+i]=b2[to2-i+1],c[to1+i]=c2[to2-i+1];
	return to1+to2;
}
ll lca(ll x,ll y){
	ll rt=0;
	if(dth[x]<dth[y]) swap(x,y);
	ROF(i,20,0) if(dth[up[x][i]]>=dth[y]) rt+=upz[x][i]-a[up[x][i]],x=up[x][i];
	if(x==y) return rt+a[x];
	ROF(i,20,0){
		if(up[x][i]!=up[y][i]){
			rt+=upz[x][i]-a[up[x][i]]+
			upz[y][i]-a[up[y][i]];
			x=up[x][i]; y=up[y][i];
		}
	}
	return rt+a[x]+a[y]+a[fa[x]];
	
}
ll solv(ll cnt){
	memset(f,0x3f,sizeof(ll)*(cnt+5));
	memset(g,0x3f,sizeof(ll)*(cnt+5));
	f[1]=b[1]; 
	FOR(i,1,cnt){
		FOR(j,1,k){
			f[i+j]=min(f[i+j],f[i]+b[i+j]);
		}
		if(k==3){
			g[i+1]=min(g[i+1],min(f[i],g[i])+c[i+1]);
			g[i+2]=min(g[i+2],f[i]+c[i+2]);
			f[i+2]=min(f[i+2],g[i]+b[i+2]);
		}
	}
	return f[cnt];
}
//
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline ll gt(){
	ll x=0,b=0; char c=getchar();
	while(!isdigit(c)) b|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return b?-x:x;
}
inline void wr(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}
int main(){
//	cout<<(&H1-&h1)/1024/1024<<endl;
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=gt(),q=gt(),k=gt();
	FOR(i,1,n) a[i]=gt();
	FOR(i,1,n-1){
		ll x=gt(),y=gt();
		side[x].pb(y);
		side[y].pb(x);
	}
	dfs(1,1);
	FOR(i,1,q){
		ll x=gt(),y=gt();
		if(k==1){
			wr(lca(x,y)); putchar('\n');
			continue;
		}
		ll cnt=lca_bl(x,y);
		wr(solv(cnt)); putchar('\n');
	}
	return 0;
}


