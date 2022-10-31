#include <stdio.h>

#include <map>
#include <set>
#include <vector>

using namespace std;

int tot = 0;
set<int> edge[500007];
vector<int> vec[500007], rev[500007];

int main(){
	int n, m, q;
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u].insert(v);
		vec[u].push_back(v);
		rev[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		if (edge[i].size() == 1) tot++;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++){
		int t, u;
		scanf("%d %d", &t, &u);
		if (t % 2 == 1){
			int v;
			scanf("%d", &v);
			if (edge[u].size() == 1) tot--;
			if (t == 1){
				edge[u].erase(v);
			} else {
				edge[u].insert(v);
			}
			if (edge[u].size() == 1) tot++;
		} else if (t == 2){
			for (int j : rev[u]){
				if (edge[j].count(u)){
					if (edge[j].size() == 1) tot--;
					edge[j].erase(u);
					if (edge[j].size() == 1) tot++;
				}
			}
		} else {
			for (int j : rev[u]){
				if (!edge[j].count(u)){
					if (edge[j].size() == 1) tot--;
					edge[j].insert(u);
					if (edge[j].size() == 1) tot++;
				}
			}
		}
		if (tot == n){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
