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

const int MAXN = 2505,MAXM = 1e4 + 5;
struct Graph {
	int v,nxt;
} gra[MAXM << 1];
int head[MAXM],val[MAXN];
bool vis[MAXN];
int n,m,k,idx,ans,runtims;
bool fl;
inline void add(int u,int v) {
	gra[++ idx] = (Graph){v,head[u]},head[u] = idx;
}
inline void dfs(int now,int sum,int numb,int step) {
	runtims ++;
	if (runtims > 5e8) {
		printf("%lld\n",ans);
		exit(0);
	}
	if (numb > 4) return;
	if (now == 1 && !fl) {
//		if (sum == 27 && numb == 4) {
//			for (int i = 1;i <= n; ++ i) {
//				if (vis[i]) printf("%d ",i);
//			}
//			puts("");
//		}
		if (numb == 4) chkmax(ans,sum);
		return;
	}
	fl = false;
//	printf("HERE: %d\n",now);
	for (int i = head[now];i;i = gra[i].nxt) {
		int v = gra[i].v;
		if (!vis[v]) {
			if (v != 1 || (v == 1 && numb == 4)) {
				if (v != 1) vis[v] = true;
				int nxt_numb = numb;
				if (v != 1) nxt_numb ++; 
				dfs(v,sum + val[v],nxt_numb,k);//选这个点
				vis[v] = false;
			}
		}
		if (step > 0) dfs(v,sum,numb,step - 1);//跳过这个点 
	}
}
#undef int
int main(void) {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
#define int long long
	n = read(),m = read(),k = read();
	for (int i = 2;i <= n; ++ i) val[i] = read();
	for (int i = 1;i <= m; ++ i) {
		int u = read(),v = read();
		add(u,v),add(v,u);
	}
	fl = true;
	dfs(1,0,0,k);
	printf("%lld\n",ans);
	
	return 0;
}
