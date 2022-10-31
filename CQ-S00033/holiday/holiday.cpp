#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int lim=1e9;
ll n,m,k;
ll a[10001];
ll ans;
struct G{
	ll v;
	ll nxt;
}g[500001];
ll dis[2505][2505];
ll p[2505][2505];
ll p_2[2505][2505];
ll w[2505][2505],tw[2505][2505];
ll mx[2505][2505],cmx[2505][2505];
int tot,head[2505];
bool vis[2505];
void add(int u,int v){
	g[++tot].v = v;
	g[tot].nxt = head[u];
	head[u] = tot;
}
struct node{
	ll u;
	ll d;
	bool operator<(const node &x) const{
		return x.d<d;
	}
};
priority_queue<node> q;
void Dij(int x){
	while(q.size()) q.pop();
	for(int i=1;i<=n;i++) dis[x][i] = lim,vis[i] = 0;
	dis[x][x] = 0;
	q.push(node{x,0});
	while(q.size()){
		node tmp=q.top();
		q.pop();
		int u=tmp.u,d=tmp.d;
		vis[u] = 1;
		for(int i=head[u];i;i=g[i].nxt){
			int v=g[i].v;
			if(dis[x][v]>d+1){
				dis[x][v] = d+1;
				if(!vis[v]) q.push({v,d+1});
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i=2;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		Dij(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]<=k+1){
				p[i][j] = 1;
			}
		}
		p[i][i] = 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			for(int k=2;k<=n;k++){
				if(k==i || k==j) continue;
				if(p[i][k] && p[k][j]){
					p_2[i][j] = 1;
					if(a[i]+a[k]+a[j]>=w[i][j]){
						tw[i][j] = w[i][j];
						w[i][j] = a[i]+a[k]+a[j];
						cmx[i][j] = mx[i][j];
						mx[i][j] = k;
					}else{
						if(a[i]+a[k]+a[j]>tw[i][j]){
							tw[i][j] = a[i]+a[k]+a[j];
							cmx[i][j] = k;
						}
					}
				}
			}
		}
		p_2[i][i] = 0;
	}
	for(int i=2;i<=n;i++){
		if(!p[i][1]) continue;
		for(int j=2;j<=n;j++){
			if(p[i][j]){
				for(int k=2;k<=n;k++){
					if(k==i) continue;
					if(p_2[j][k] && p[k][1]){
						if(mx[j][k]!=i) ans = max(ans,w[j][k]+a[i]);
						else ans = max(ans,tw[j][k]+a[i]);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
