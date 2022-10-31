#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(xx) xx.begin(), xx.end()

using ll = long long;

ifstream __fin("holiday.in");
ofstream __fout("holiday.out");
#define cin __fin
#define cout __fout

vector<int> elist[2505];
ll va[2505];
int dis[2505][2505];
int b1[2505], b2[2505], b3[2505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for(int i=2;i<=n;i++) cin >> va[i];
	for(int i=0;i<m;i++){
		int a,b; cin >> a >> b;
		elist[a].pb(b);
		elist[b].pb(a);
	}
	k++;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=0x3f3f3f3f;
		dis[i][i]=0;
		queue<int> dq;
		dq.push(i);
		while(dq.size()){
			int u=dq.front(); dq.pop();
			for(int v:elist[u]) if(dis[i][v]>dis[i][u]+1) {
				dis[i][v] = dis[i][u]+1;
				dq.push(v);
			}
		}
		if(i != 1) {
			b1[i] = b2[i] = b3[i] = -1;
			for(int j=2;j<=n;j++) {
				if(j==i || dis[i][j]>k || dis[1][j]>k) continue;
				if(b1[i]==-1 || va[j]>=va[b1[i]]) b3[i]=b2[i], b2[i]=b1[i], b1[i]=j;
				else if(b2[i]==-1 || va[j]>=va[b2[i]]) b3[i]=b2[i], b2[i]=j;
				else if(b3[i]==-1 || va[j]>=va[b3[i]]) b3[i]=j;
			}
		}
	}
	ll ans=0;
	for(int b=2;b<=n;b++)for(int c=2;c<=n;c++){
		if(b==c||dis[b][c]>k) continue;
		int a=b1[b];
		if(a==c) a=b2[b];
		int d=b1[c];
		if(d==b||d==a) d=b2[c];
		if(d==b||d==a) d=b3[c];
		if(a!=-1&&d!=-1) {
			ans=max(ans,va[a]+va[b]+va[c]+va[d]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
