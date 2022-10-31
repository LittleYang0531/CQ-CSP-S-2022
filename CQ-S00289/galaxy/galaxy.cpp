#include <bits/stdc++.h>
using namespace std;
vector<int> G[10005];
int wuc;
int m;
int visp[100005][100005];
int visb[100005][100005];
bool check() {
	for (int i= 0;i < m;i++){
		int cnt= 0;
		for (int j = 0;j < G[i].size();j++){
			if (!visb[i][G[i][j]]){
				cnt++;
			}
			
		}
		if (cnt != 1) {
			return 0;
		}		
	}
	return 1 && wuc;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int n;
	cin >> n >> m;
	for (int i = 0;i <m;i++) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v);
		if (G[v][u]) {
			wuc++;
		}
	}
	int q;
	cin >> q;
	for (int i =0;i < q;i++ ){
		int op ;
		cin >> op;
		int u,v;
		if (op == 1){
			cin >>u >> v;
			visb[u][v] = 1;
			if (G[v][u]) {
				wuc--;
			}
		}else if(op == 2) {
			int u;
			cin >> u;
			
		}
		
	}
	return 0;
}
