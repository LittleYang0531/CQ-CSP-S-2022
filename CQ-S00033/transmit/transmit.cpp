#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q,k;
ll a[200005];
int fa[200005][21];
ll c[200005][21];
int dep[200005];
struct G{
	int v;
	int nxt;
}g[1000001];
int tot;
int head[1000001];
void add(int u,int v){
	g[++tot].v = v;
	g[tot].nxt = head[u];
	head[u] = tot;
}
void dfs(int u){
	for(int i=head[u];i;i=g[i].nxt){
		int v=g[i].v;
		if(v==fa[u][0]) continue;
		dep[v] = dep[u]+1;
		fa[v][0] = u;
		c[v][0] = a[u];
		dfs(v);
	}
}
ll w(int s,int t){
	if(dep[s]>dep[t]) swap(s,t);
	ll res=a[s]+a[t],tmp=a[s];
	for(int i=20;i>=0;i--){
		if(dep[fa[t][i]]>=dep[s]) res+=c[t][i],t=fa[t][i];
	}
	if(s==t) return res-tmp;
	for(int i=20;i>=0;i--){
		if(fa[t][i]!=fa[s][i]) res+=c[t][i]+c[s][i],t=fa[t][i],s=fa[s][i];
	}
	return res+c[t][0];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin >> n >> q >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dep[0]= 0;
	dep[1]= 1;
	dfs(1);
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n;j++){
			fa[j][i] = fa[fa[j][i-1]][i-1];
			c[j][i] = c[j][i-1]+c[fa[j][i-1]][i-1];
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin >> s >> t;
		if(k==1){
			cout << w(s,t) << '\n';
		}else{
			cout << a[s]+a[t] << '\n';
		}
	}
	return 0;
}


