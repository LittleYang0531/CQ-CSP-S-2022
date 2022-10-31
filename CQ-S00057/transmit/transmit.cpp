#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
void fine() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
}
struct zjh {
	long long to,next;
}add[20005];
long long h[2505],cnt = 0,lzq[2505][2505],res[2505],n,m,kk,a,b,dis[2505],in[2505];
bool vis[2505];
struct ycy {
	long long a,step;
};
void addedge(long long a,long long b) {
	add[++cnt].to = b;
	add[cnt].next = h[a];
	h[a] = cnt;
}
void wsy(int u){
	for(int i = 1;i<=n;i++){
		if(lzq[u][i] <= kk&&in[u]+res[i] < in[i]){
			in[i] = in[u]+res[i];
//			cout<<' '<<u<<" "<<i<<" "<<in[i]<<"  "<<in[u]<<" "<<res[u]<<" "<<lzq[u][i]<<" "<<kk<<endl;
			wsy(i);
		}
	}
	return ;
}
void bfs(long long u) {
	queue <ycy> q;
	ycy b,v;
	b.a = u;
	b.step = 0;
	q.push(b);
	while(q.size()) {
		v = q.front();
		for(long long i = h[v.a]; i; i = add[i].next) {
			if(!vis[add[i].to]) {
				vis[add[i].to] = 1;
				lzq[u][add[i].to] = v.step;
				b.a = add[i].to;
				b.step = v.step+1;
				q.push(b);
			}
		}
		q.pop();
	}
}
/*
long long dij(int a,int b) {
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[a] = 0;
	int k;
	for(int i = 1;i<=n;i++){
		k = -1;
		for(int j = 1;j<=n;j++){
			if(vis[j] == 0&&(lzq[j])&&(k == -1||res[j] < res[k])) k = j;
		}
//		cout<<" "<<k<<" "<<b<<endl;
		vis[k] = 1;
		if(k == b) return dis[b];
		for(int j = 1;j<=n;j++){
			if(dis[k]+lzq[j][k] < dis[j]){
				dis[j] = dis[k]+lzq[j][k];
			}
		}
	}
	return -1;
}
long long ans;
bool dfs(long long u,long long step){
//	cout<<u<<" "<<step<<" "<<b<<endl;
	if(u == b){
		ans = min(ans,step);
//		cout<<ans<<endl;
		return 1;
	}
	for(long long i = 1;i<=n;i++){
		if(i == u||vis[i]||lzq[i][u] > kk) continue;
		vis[i] = 1;
		if(dfs(i,step+res[i]) == 1) return 1;
		vis[i] = 0;
	}
}
*/
int main() {
	fine();
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>kk;
	memset(lzq,0x3f,sizeof(lzq));
	for(long long i = 1; i<=n; i++) {
		cin>>a;
		res[i] = a;
	}
	for(long long i = 1; i<=n-1; i++) {
		cin>>a>>b;
		addedge(a,b);
		addedge(b,a);
	}
	for(long long i = 1; i<=n; i++) {
		vis[i] = 1;
		bfs(i);
		memset(vis,0,sizeof(vis));
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			cout<<lzq[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	for(int i = 1; i<=m; i++) {
		cin>>a>>b;
		memset(in,0x3f,sizeof(in));
		in[a] = res[a];
		wsy(a);
		cout<<in[b]<<'\n';
	}
	return 0;
}
/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2
*/
