#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read() {
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
namespace tokidosaya {
#define fi first
#define sc second
	typedef pair<ll,int> pi;
	const int maxn=2505;
	struct edge {
		int next,to;
	} e[maxn*8];
	int n,m,k,h[maxn],cnt,d[maxn][maxn];
	ll a[maxn],ans=-1e18;
	vector<pi> f[maxn];
	bool vis[maxn];
	void addedge(int x,int y) {
		e[++cnt].next=h[x],e[cnt].to=y,h[x]=cnt;
	}
	void bfs(int s) {
		queue<int> q;
		memset(vis,0,sizeof(vis)),q.push(s),d[s][s]=-1,vis[s]=1;
		while(!q.empty()) {
			int u=q.front();
			q.pop();
			for(int i=h[u]; i; i=e[i].next) {
				int v=e[i].to;
				if(!vis[v])d[s][v]=d[s][u]+1,vis[v]=1,q.push(v);
			}
		}
	}
	int main() {
		freopen("holiday.in","r",stdin);
		freopen("holiday.out","w",stdout);
		int x,y;
		n=read(),m=read(),k=read();
		for(int i=2; i<=n; i++)a[i]=read();
		for(int i=1; i<=m; i++) {
			x=read(),y=read();
			addedge(x,y),addedge(y,x);
		}
		for(int i=1; i<=n; i++)bfs(i);
		for(int i=2; i<=n; i++) {
			if(d[1][i]>k)continue;
			for(int j=2; j<=n; j++) {
				if(i==j||d[i][j]>k)continue;
//				cout<<j<<' '<<a[i]+a[j]<<' '<<i<<"*\n";
				f[j].push_back(pi(a[i]+a[j],i));
			}
		}
		for(int i=2; i<=n; i++)sort(f[i].begin(),f[i].end()),reverse(f[i].begin(),f[i].end());
		for(int i=2; i<=n; i++)
			for(int j=i+1; j<=n; j++) {
				if(d[i][j]>k)continue;
				for(int i1=0; i1<f[i].size()&&i1<5; i1++)
					for(int j1=0; j1<f[j].size()&&j1<5; j1++)
						if(f[i][i1].sc!=j&&f[j][j1].sc!=i&&f[i][i1].sc!=f[j][j1].sc) {
							ans=max(ans,f[i][i1].fi+f[j][j1].fi);
							break;
						}
			}
		printf("%lld",ans);
		return 0;
	}
}
int main() {
	return tokidosaya::main();
}

