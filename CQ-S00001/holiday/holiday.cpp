#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2505;

int n,m,k;
int vis[maxn][maxn],dis[maxn];
vector<int> g[maxn];

ll mx1[maxn],mx2[maxn],mx3[maxn];
ll a[maxn],val[maxn][maxn],ans;

void bfs(int x){
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(x);dis[x]=0;
	while(q.size()) {
		int t=q.front();q.pop();
		for(int p:g[t]) if(dis[p]>dis[t]+1) dis[p]=dis[t]+1,q.push(p);
	}
	for(int i=1;i<=n;i++) if(i!=x&&dis[i]<=k+1) vis[x][i]=vis[i][x]=1;
	return ;
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++) cin>>a[i];
	for(int i=1,u,v;i<=m;i++) {
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) bfs(i);
	a[0]=-4e18;
	for(int i=2;i<=n;i++) {
		for(int j=2;j<=n;j++) {
			if(!vis[i][j]) continue;
			if(!vis[j][1]) continue;
			if(a[j]>a[mx1[i]]) mx3[i]=mx2[i],mx2[i]=mx1[i],mx1[i]=j;
			else if(a[j]>a[mx2[i]]) mx3[i]=mx2[i],mx2[i]=j;
			else if(a[j]>a[mx3[i]]) mx3[i]=j;
		}
	}
	for(int i=2;i<=n;i++) {
		for(int j=2;j<=n;j++) {
			if(!vis[i][j]) continue;
			for(int kk=2;kk<=n;kk++) {
				if(!vis[j][kk]||kk==i) continue;
				if(mx1[kk]!=i&&mx1[kk]!=j) val[i][j]=max(val[i][j],a[mx1[kk]]+a[kk]);
				else if(mx2[kk]!=i&&mx2[kk]!=j) val[i][j]=max(val[i][j],a[mx2[kk]]+a[kk]);
				else val[i][j]=max(val[i][j],a[mx3[kk]]+a[kk]);
			}
		}
	}
	for(int i=2;i<=n;i++) {
		for(int j=2;j<=n;j++) {
			if(vis[i][j]&&vis[i][1]) ans=max(ans,a[i]+a[j]+val[i][j]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
