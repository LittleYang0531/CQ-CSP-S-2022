#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,Inf=1e18;
int n,q,k;
int v[N];
vector<int>son[N];
namespace bl1{
	int f[20][N],g[20][N],d[N];
	void dfs(int x,int prt){
		f[0][x]=prt,d[x]=d[prt]+1,g[0][x]=v[prt];
		for(int y:son[x])if(y!=prt)dfs(y,x);
	}
	inline void st(){
		dfs(1,0);
		int K=log2(n);
		for(int i=1;i<=K;++i){
			for(int j=1;j<=n;++j){
				f[i][j]=f[i-1][f[i-1][j]];
				g[i][j]=g[i-1][j]+g[i-1][f[i-1][j]];
			}
		}
	}
	inline int ask(int x,int y){
		if(d[x]<d[y])swap(x,y);
		int key=log2(d[x]),sum=v[x]+v[y];
		for(int i=key;i>=0;--i)if(d[x]-d[y]>=1<<i)sum+=g[i][x],x=f[i][x];
		if(x==y)return sum-v[x];
		for(int i=key;i>=0;--i)if(f[i][x]!=f[i][y])sum+=g[i][x]+g[i][y],x=f[i][x],y=f[i][y];
		return sum+v[f[0][x]];
	}
	inline void solve(){
		st();
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<ask(x,y)<<"\n";
		}
	}
}
namespace bl2{
	int f[2005][2005];
	struct data{
		int d,num;
		bool operator <(const data &t)const{return d>t.d;}
	};
	vector<data>e[N];
	int d[N],vst[N];
	inline void Dijkstra(int s){
		fill(d+1,d+n+1,Inf),fill(vst+1,vst+n+1,false);
		priority_queue<data>q;
		d[s]=v[s];
		q.push((data){d[s],s});
		while(!q.empty()){
			data u=q.top();q.pop();
			int x=u.num;
			if(vst[x])continue;
			vst[x]=true;
			for(data w:e[x]){
				int y=w.num;
				if(vst[y])continue;
				if(d[y]>d[x]+w.d)d[y]=d[x]+w.d,q.push((data){d[y],y});
			}
		}
	}
	void dfs(int x,int dep,int rt,int prt){
		if(dep>k)return;
		if(dep<=k&&dep)f[rt][x]=v[x];
		for(int y:son[x])if(y!=prt)dfs(y,dep+1,rt,x);
	}
	inline void solve(){
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)f[i][j]=Inf;
		for(int i=1;i<=n;++i)dfs(i,0,i,0);
		if(n<=200){
			for(int k=1;k<=n;++k){
				for(int i=1;i<=n;++i){
					for(int j=1;j<=n;++j)if(i!=j&&i!=k&&j!=k)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
			while(q--){
				int x,y;
				cin>>x>>y;
				cout<<v[x]+f[x][y]<<"\n";
			}
		}else{
			for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(f[i][j]!=Inf)e[i].push_back((data){f[i][j],j});
			while(q--){
				int x,y;
				cin>>x>>y;
				Dijkstra(x);
				cout<<d[y]<<"\n";
			}
		}
	}
}
signed main(){
	freopen("transmit3.in","r",stdin);
	freopen("transmit.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q>>k;
	for(int i=1;i<=n;++i)cin>>v[i];
	for(int i=2;i<=n;++i){
		int x,y;cin>>x>>y;
		son[x].push_back(y),son[y].push_back(x);
	}	
	if(k==1)bl1::solve(),exit(0);
	if(n<=2000)bl2::solve(),exit(0);
	return 0;
}
