#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	register int s = 0, f = 1;
	register char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -f; ch = getchar(); }
	while (isdigit(ch)) { s = (s << 1) + (s << 3) + (ch ^ 48); ch = getchar(); }
	return s * f;
}
const int N = 2510;
vector <int> q[N];
int n, m, k, a[N], vis[N], dis[N];
int d[N][N];
vector <int> f[N];
ll s[N], ans;
void bfs(int x) {
	memset(a, 0, sizeof(a));
	memset(vis, 0, sizeof(vis));
	int head=1, tail=1;
	a[1]=x, vis[x]=1, dis[x]=0;
	d[x][x]=0;
	while(head<=tail) {
		int u=a[head];
		if(dis[u]==k) break;
		for(int i=0;i<q[u].size();i++) {
			int v=q[u][i];
			if(vis[v]) continue;
			a[++tail]=v, vis[v]=1, dis[v]=dis[u]+1;
			d[x][v]=dis[v];
			if(v>1) f[x].push_back(v);
		}
		head++;
	}
}
struct node{
	ll x,id;
} c[N];
bool cmp(node A, node B) {
	return A.x > B.x;
}
void sub() {
	for(int i=2;i<=n;i++) {
		c[i].x=s[i],c[i].id=i;
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=100;i++) {
		for(int j=i+1;j<=100;j++) {
			int x=c[i].id,y=c[j].id;
			if(d[x][y]>k) continue;
			for(int I=j+1;I<=100;I++) {
				int u=c[I].id;
				if(d[x][u]>k || d[y][u]>k) continue;
				for(int J=k+1;J<=100;J++) {
					int v=c[J].id;
					if(d[x][v]>k || d[y][v]>k || d[u][v]>k) continue;
			        ans=max(ans,c[i].x+c[j].x+c[I].x+c[J].x);
				}
			}
		}
	}
	cout<<ans<<endl;
}
signed main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	n = read(), m = read(), k = read() + 1;
	for(int i=2;i<=n;i++) s[i]=read();
	for(int i=1;i<=m;i++) {
		int x=read(),y=read();
		q[x].push_back(y);
		q[y].push_back(x);
	}
	memset(d, 0x7f, sizeof(d));
	for(int i=1;i<=n;i++) bfs(i);
	
	if(n>200) {
		sub(); return 0;
	}
	
	for(int i=0;i<f[1].size();i++) {
		for(int j=i+1;j<f[1].size();j++) {
			int x=f[1][i], y=f[1][j];
			for(int I=0;I<f[x].size();I++) {
				int u=f[x][I];
				if(u==x || u==y) continue;
				for(int J=0;J<f[y].size();J++) {
					int v=f[y][J];
					if(v==x || v==y || v==u) continue;
					if(d[u][v] <= k) ans = max(ans, s[x]+s[y]+s[u]+s[v]);
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
*/
