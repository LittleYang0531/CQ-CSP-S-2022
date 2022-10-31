#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
namespace ljx_9420yy {

	const int maxn = 1e5+5;
	int n, m, q, u, v, cnt[maxn], vis[maxn][maxn], duwn[maxn][maxn], op, top_duwn[maxn], t, up[maxn][maxn], top_up[maxn];

	bool dfs(int x){
		for(int i=1; i<=top_duwn[x]; i++){
			if( vis[up[x][i]][x] == 1 )	return 1;
			else if( dfs(i) == 1 )	return 1;
		}
		return 0;
	}

	int main() {
		cin>> n>> m;
		for(int i=1; i<=m; i++) {
			cin>> u>> v;
			cnt[u]++;
			duwn[v][++top_duwn[v]] = u;
			up[u][++top_up[u]] = v;
			vis[u][v] = 1;
		}
		cin>> q;
		while(q--) {
			cin>> t;
//			cout<< "t = "<< t<< endl;
			if(t == 1) {
				cin>> u>> v;
				vis[u][v] = 0;
				cnt[u]--;
			} else if(t == 2) {
				cin>> u;
				for(int i=1; i<=top_duwn[u]; i++)	vis[ duwn[u][i] ][u] = 0, cnt[ duwn[u][i] ]--;
			} else if(t == 3) {
				cin>> u>> v;
				vis[u][v] = 1;
				cnt[u]++;
			} else if(t == 4) {
				cin>> u;
				for(int i=1; i<=top_duwn[u]; i++)	vis[ duwn[u][i] ][u] = 1, cnt[ duwn[u][i] ]++;
			}
			op = 0;
//			cout<< op<< endl<<endl;
			for(int i=1; i<=n; i++) {
				if(cnt[i] != 1) {
					cout<<"NO\n";
					op = 1;
					break;
				} else if(dfs(i) == 0)	{
					cout<< "NO\n";
					op = 1;
					break;
				}
			}
			if(op == 0)	cout<< "YES\n";
		}
		return 0;
	}

}

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	ljx_9420yy::main();
	return 0;
}

