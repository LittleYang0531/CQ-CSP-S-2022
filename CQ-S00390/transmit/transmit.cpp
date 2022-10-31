#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

namespace Solve{
	const int N=200010,K=3;
	const ll INF=1e15;
	int n,k,q,a[N];
	int head[N],ver[N<<1],ne[N<<1],idx=2;
	void add(int x,int y){
		ver[idx]=y,ne[idx]=head[x],head[x]=idx++;
	}
	inline void Max(ll&x,ll y){
		x=(x>y?x:y);
	}
	inline void Min(ll&x,ll y){
		x=(x>y?y:x);
	}
	struct M1{
		ll a[K][K];
		void set(){
			for(int i=0;i<k;i++)
				for(int j=0;j<k;j++)
					a[i][j]=INF;
		}
		M1 operator*(const M1&m)const{
			M1 r;r.set();
			for(int i=0;i<k;i++)
				for(int j=0;j<k;j++)
					for(int z=0;z<k;z++)
						Min(r.a[i][j],a[i][z]+m.a[z][j]);
			return r;
		}
	};
	struct M2{
		ll f[K];
		void set(){
			for(int i=0;i<k;i++)f[i]=INF;
		}
		M2 operator*(const M1&m)const{
			M2 r;r.set();
			for(int i=0;i<k;i++)
				for(int j=0;j<k;j++)
					Min(r.f[j],f[i]+m.a[i][j]);
			return r;
		}
	};
	int son[N],siz[N],tpf[N],dfn[N],ind,ff[N],dep[N],bdfn[N];
	ll mins[N];
	void dfs1(int x,int fa){
		ff[x]=fa,dep[x]=dep[fa]+1,siz[x]=1;
		mins[x]=INF;
		if(fa)mins[x]=a[fa];
		for(int i=head[x];i;i=ne[i])
			if(ver[i]!=fa){
				dfs1(ver[i],x);
				siz[x]+=siz[ver[i]];
				Min(mins[x],a[ver[i]]);
				if(siz[ver[i]]>siz[son[x]])son[x]=ver[i];
			}
	}
	void dfs2(int x,int topf){
		tpf[x]=topf,dfn[x]=++ind;
		bdfn[ind]=x;
		if(son[x])dfs2(son[x],topf);
		for(int i=head[x];i;i=ne[i])
			if(!dfn[ver[i]])dfs2(ver[i],ver[i]);
	}
	struct SegmentTree{
		struct Node{
			int l,r;
			M1 m;
		}tr[N<<2];
		void pushup(int p){
			tr[p].m=tr[p<<1|1].m*tr[p<<1].m;
		}
		void build(int p,int l,int r){
			tr[p].l=l,tr[p].r=r;
			if(l==r){
				tr[p].m.set();
				for(int i=1;i<k;i++){
					tr[p].m.a[i][i-1]=0;
				}
				for(int i=0;i<k;i++){
					tr[p].m.a[i][k-1]=a[bdfn[l]];
				}
				if(k==3){
					tr[p].m.a[1][1]=mins[bdfn[l]];
				}
				return;
			}
			int mid=(l+r)>>1;
			build(p<<1,l,mid),build(p<<1|1,mid+1,r);
			pushup(p);
		}
		void query(int p,int l,int r,M2&f){
			if(l<=tr[p].l&&tr[p].r<=r){
				f=f*tr[p].m;
				return;
			}
			if(r>=tr[p<<1|1].l)query(p<<1|1,l,r,f);
			if(l<=tr[p<<1].r)query(p<<1,l,r,f);
		}
	}seg;
	ll Query(int x,int y){
		M2 fx,fy;fx.set(),fy.set();
		fx.f[k-1]=a[x],fy.f[k-1]=a[y];
		while(tpf[x]!=tpf[y]){
			if(dep[tpf[x]]<dep[tpf[y]]){
				if(tpf[y]!=y)seg.query(1,dfn[tpf[y]],dfn[ff[y]],fy);
				seg.query(1,dfn[ff[tpf[y]]],dfn[ff[tpf[y]]],fy);
				y=ff[tpf[y]];
			}
			else{
				if(tpf[x]!=x)seg.query(1,dfn[tpf[x]],dfn[ff[x]],fx);
//				cerr<<dfn[ff[tpf[x]]]<<' '<<dfn[ff[tpf[x]]]<<"QS\n";
				seg.query(1,dfn[ff[tpf[x]]],dfn[ff[tpf[x]]],fx);
//				cerr<<"QE\n";
				x=ff[tpf[x]];
			}
		}
		int z=(dep[x]<dep[y]?x:y);
//		cerr<<"Z "<<z<<'\n';
//		cerr<<"Z "<<x<<' '<<y<<'\n';
//		for(int i=0;i<k;i++)cerr<<fx.f[i]<<' ';cerr<<'\n';
//		for(int i=0;i<k;i++)cerr<<fy.f[i]<<' ';cerr<<'\n';
		if(dep[x]<dep[y]){
			seg.query(1,dfn[x],dfn[ff[y]],fy);
//			seg.query(1,dfn[ff[y]],dfn[ff[y]],fy);
//			seg.query(1,dfn[x],dfn[x],fy);
//			cerr<<"A\n";
		}
		else if(dep[x]>dep[y]){
			seg.query(1,dfn[y],dfn[ff[x]],fx);
		}
		ll res=fx.f[k-1]+fy.f[k-1]-a[z];
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				if(k-i-1+k-j-1<=k)
					Min(res,fx.f[i]+fy.f[j]);
		return res;
	}
	void main(){
		cin>>n>>q>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			add(x,y),add(y,x);
		}
		dfs1(1,0),dfs2(1,1);
		seg.build(1,1,n);
		
		while(q--){
			int x,y;cin>>x>>y;
			cout<<Query(x,y)<<'\n';
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	Solve::main();
}

