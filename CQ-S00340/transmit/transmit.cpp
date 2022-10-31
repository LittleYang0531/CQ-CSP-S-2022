#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T> inline void chkmax(T &x,T y) {x = max(x,y);}
template <typename T> inline void chkmin(T &x,T y) {x = min(x,y);}
inline int read() {
	int res = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		res = res * 10 + (ch - '0');
		ch = getchar();
	}
	return res * f;
}
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5 + 5;
struct Graph {
	int v,nxt;
} gra[MAXN << 1];
int head[MAXN],val[MAXN],a[MAXN],dp[MAXN];
bool son[MAXN];
int n,q,k,s,t,idx,cnt;
inline void add(int u,int v) {
	gra[++ idx] = (Graph){v,head[u]},head[u] = idx; 
}
inline void dfs(int now,int fath) {
	if (now == t) {
		son[fath] = true;
		return;
	}
	for (int i = head[now];i;i = gra[i].nxt) {
		int v = gra[i].v;
		if (v != fath) {
			dfs(v,now);
			son[now] |= son[v];
		}
	}
}
inline void dfs_find(int now,int fath) {
	a[++ cnt] = now;
	for (int i = head[now];i;i = gra[i].nxt) {
		int v = gra[i].v;
		if (v != fath) {
			if (son[v]) dfs_find(v,now);
		}
	}
}
#undef int
int main(void) {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
#define int long long
	n = read(),q = read(),k = read();
	for (int i = 1;i <= n; ++ i) val[i] = read();
	for (int i = 1;i < n; ++ i) {
		int u = read(),v = read();
		add(u,v),add(v,u);
	}
	while (q --) {
		cnt = 0;
		memset(son,false,sizeof(son)),memset(dp,0x3f,sizeof(dp)),memset(a,0,sizeof(a)); 
		s = read(),t = read();
		dfs(s,0),dfs_find(s,0);
		a[++ cnt] = t;
//		for (int i = 1;i <= cnt; ++ i) cout << a[i] << ' '; puts("");
		dp[1] = val[s];
		for (int i = 2;i <= cnt; ++ i) {
			for (int j = max(i - k + 1,1ll);j < i; ++ j) {
				chkmin(dp[i],dp[j] + val[a[i]]);
			}
		}
		int ans = dp[cnt];
//		for (int i = max(cnt - k + 1,1ll);i <= cnt; ++ i) chkmin(ans,dp[i]);
		printf("%lld\n",ans);
	}
	
	return 0;
}

