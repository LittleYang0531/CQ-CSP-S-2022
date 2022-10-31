#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	register int s = 0, f = 1;
	register char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -f; ch = getchar(); }
	while (isdigit(ch)) { s = (s << 1) + (s << 3) + (ch ^ 48); ch = getchar(); }
	return s * f;
}
const int N=2e3+10;
int n,Q,k,v[N],a[N],f[N];
int s,t;
vector <int> q[N];
void solve(int len) {
	f[1]=a[1];
	for(int i=2;i<=len;i++) {
		f[i]=1e18;
		for(int j=max(i-k,1ll); j<=i-1; j++) {
			f[i]=min(f[j]+a[i],f[i]);
		}
	}
	cout<<f[len]<<"\n";
}
void dfs(int u,int fa,int dep) {
	a[dep]=v[u];
	if(u==t) {
	    solve(dep);
		return;
	}
	for(int i=0;i<q[u].size();i++) {
		int v=q[u][i];
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}
signed main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	n=read(),Q=read(),k=read();
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<n;i++) {
		int u=read(),v=read();
		q[u].push_back(v), q[v].push_back(u);
	}
	while(Q--) {
		s=read(), t=read();
		dfs(s,0,1);
	}
	return 0;
}
/*
10 1 3
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9
10 5

939363946
*/
