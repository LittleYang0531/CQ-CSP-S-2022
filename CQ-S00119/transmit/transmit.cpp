#include <bits/stdc++.h>
#define mk make_pair
#define xx first
#define yy second
#define inf 1000000000000000007LL
using namespace std;
int n, q, k, s[200005], fa[200005], lca[200005], vis[200005], pd[200005],
jm[200005], a[200005], b[200005], u, v, tot, haha[200005];
long long now[200005], sum[200005];
inline void read(int &x) {
	x=0; int f = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') f=-1; c=getchar(); }
	while(c <= '9' && c >= '0') x=(x<<1)+(x<<3)+(c^48), c=getchar();
	x*=f;
}
char ot[45];
int len;
inline void print(long long x) {
	len=0; if(x < 0) x=-x, putchar('-');
	do{ ot[++len]=x%10, x/=10; } while(x);
	while(len) putchar(ot[len]+'0'), --len;
	putchar('\n');//!!!
} 
vector <int> to[200005];
vector < pair<int, int> > pro[200005];
void dfs(int x, int fat) {
	fa[x]=fat;
	if(k == 1)
		sum[x]=sum[fat]+s[x];
	for(int i = 0; i < to[x].size(); ++i)
		if(to[x][i] != fat)
			dfs(to[x][i], x);
}
int find(int x) { return (x == jm[x] ? x : jm[x] = find(jm[x])); }
void Tarjan(int x, int fat) {
	for(int i = 0; i < to[x].size(); ++i)
		if(to[x][i] != fat)
			Tarjan(to[x][i], x);
	for(int i = 0; i < pro[x].size(); ++i)
		if(!pd[pro[x][i].yy] && vis[pro[x][i].xx])
			lca[pro[x][i].yy]=find(pro[x][i].xx), pd[pro[x][i].yy]=1;
	vis[x]=1, jm[x]=fat;
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	read(n), read(q), read(k);
	for(int i = 1; i <= n; ++i)
		read(s[i]), jm[i]=i;
	for(int i = 1; i < n; ++i) 
		read(u), read(v), to[u].push_back(v), to[v].push_back(u);
	dfs(1, 1);
	for(int i = 1; i <= q; ++i)
		read(a[i]), read(b[i]), pro[a[i]].push_back(mk(b[i], i)), pro[b[i]].push_back(mk(a[i], i));
	Tarjan(1, 1);
	for(int i = 1; i <= q; ++i) {
		if(k == 1)
			print(sum[a[i]]+sum[b[i]]-sum[lca[i]]);
		else {
			tot=0;
			int qwq = a[i];
			while(qwq != lca[i])
				haha[++tot]=qwq, qwq=fa[qwq];
			haha[++tot]=lca[i];
			qwq = b[i];
			int o = tot;
			while(qwq != lca[i])
				haha[++tot]=qwq, qwq=fa[qwq];
			for(int i = 1; i*2 <= tot-o; ++i)
				swap(haha[i+o], haha[tot-i+1]);
			for(int i = 1; i <= tot; ++i)
				now[i]=inf;
			now[1]=s[a[i]];
			for(int i = 1; i <= tot; ++i) 
				for(int o = 1; i+o <= tot && o <= k; ++o)
					now[i+o]=min(now[i+o], now[i]+s[haha[i+o]]);
			print(now[tot]);
		}
	}
	return 0;
} 
