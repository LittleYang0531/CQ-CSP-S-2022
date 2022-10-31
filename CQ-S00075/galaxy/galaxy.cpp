#include<bits/stdc++.h>
using namespace std;
inline int read() {
	register int s = 0, f = 1;
	register char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -f; ch = getchar(); }
	while (isdigit(ch)) { s = (s << 1) + (s << 3) + (ch ^ 48); ch = getchar(); }
	return s * f;
}
const int N=5e5+10;
vector <int> q[N];
int n,m,sz[N],a[1005][1005],ans;
signed main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) {
		int x=read(),y=read();
		if(n<=1000) a[x][y]=1; 
		q[y].push_back(x);
		sz[x]++;
	}
	for(int i=1;i<=n;i++) ans+=(sz[i]==1);
	int Q=read();
	while(Q--) {
		int id=read();
		if(id==1) {
			int u=read(),v=read();
		    if(n<=1000) a[u][v]=2;
			if(sz[u]==1) ans--;
			sz[u]--;
			if(sz[u]==1) ans++;
		}
		if(id==2) {
			int u=read();
			for(int i=0;i<q[u].size();i++) {
				if(a[q[u][i]][u]==1) {
					if(sz[q[u][i]]==1) ans--;
					sz[q[u][i]]--;
					if(sz[q[u][i]]==1) ans++;
				}
				a[q[u][i]][u]=2;
			}
		}
		if(id==3) {
			int u=read(),v=read();
			if(n<=1000) a[u][v]=1;
			if(sz[u]==1) ans--;
			sz[u]++;
			if(sz[u]==1) ans++;
		}
		if(id==4) {
			int u=read();
			for(int i=0;i<q[u].size();i++) {
				if(a[q[u][i]][u]==2) {
					if(sz[q[u][i]]==1) ans--;
					sz[q[u][i]]++;
					if(sz[q[u][i]]==1) ans++;
				}
				a[q[u][i]][u]=1;
			}
		}
		if(ans==n) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
