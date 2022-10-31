#include <bits/stdc++.h>
#define inf 1000000007
using namespace std;
int n, m, k, u, v, sum[2505], pd[2505][2505], vis[2505];
long long s[2505], ans;
struct bian{
	int to, w;
	bool operator <(const bian& A)const {
		return A.w < w;
	};
};
vector <bian> d[2505];
vector <int> p2[2505];
void dfs(int x, int now, long long ww) {
	vis[x]=1;
	for(int j = 0; j < d[x].size(); ++j) {
		if(now == 4 && d[x][j].to == 1)
			ans=max(ans, ww);
		if(!vis[d[x][j].to])
			dfs(d[x][j].to, now+1, ww+s[d[x][j].to]);
	}
	vis[x]=0;
}
inline void ri(int &x) {
	x=0; int f = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') f=-1; c=getchar(); }
	while(c <= '9'&& c >= '0') x=(x<<1)+(x<<3)+(c^48), c=getchar();
	x*=f;
}
inline void rl(long long &x) {
	x=0; long long f = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') f=-1; c=getchar(); }
	while(c <= '9' && c >= '0') x=x*10LL+1LL*(c-'0'), c=getchar();
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
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	ri(n), ri(m), ri(k); ++k;
	for(int i = 2; i <= n; ++i)
		rl(s[i]);
	for(int i = 1; i <= m; ++i)
		ri(u), ri(v), d[u].push_back((bian) {v, 1}), d[v].push_back((bian) {u, 1});
	if(k == 1) {
		dfs(1, 0, 0);
		print(ans);
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) sum[j]=inf;
		priority_queue <bian> q;
		sum[i]=0;
		q.push((bian) {i, 0});
		while(!q.empty()) {
			bian it = q.top(); q.pop();
			if(sum[it.to] < it.w) continue;
			for(int j = 0; j < d[it.to].size(); ++j) {
				bian o = d[it.to][j];
				if(sum[it.to]+it.w < sum[o.to])
					sum[o.to]=sum[it.to]+o.w, 
					q.push((bian) {o.to, sum[o.to]});
			}
		}
		for(int j = i+1; j <= n; ++j)
			if(sum[j] <= k)
				pd[i][j]=pd[j][i]=1;
	}
	for(int b = 2; b <= n; ++b) {
		if(!pd[1][b]) continue;
		for(int c = 2; c <= n; ++c) {
			if(c == b || !pd[b][c]) continue;
			for(int d = 2; d <= n; ++d) {
				if(c == d || b == d || !pd[c][d]) continue;
				for(int e = 2; e <= n; ++e) {
					if(e == d || e == b || e == c || !pd[e][1] || !pd[e][d]) continue;
					ans=max(ans, s[b]+s[c]+s[d]+s[e]);
				}
			}
		}
	}
	print(ans);
	return 0;
} 
