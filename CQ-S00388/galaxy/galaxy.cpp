#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int N = 5e5 + 10;

int n, m, a, b, Q, t, cnt;
int chu[N];
map<pair<int, int>, bool> q;
vector<int> ru[N];

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d", &a, &b);
		q[make_pair(a, b)] = true;
		chu[a] ++;
		ru[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i ++)
		if (chu[i] == 1) cnt ++;
	
	scanf("%d", &Q);
	
	while (Q --) {
		scanf("%d", &t);
		
		if (t == 1) {
			scanf("%d%d", &a, &b);
			q[make_pair(a, b)] = false;
			chu[a] --;
			if (chu[a] == 0) cnt --;
			if (chu[a] == 1) cnt ++;
		}
		if (t == 2) {
			scanf("%d", &a);
			for (int i = 0; i < ru[a].size(); i ++) {
				if (q[make_pair(ru[a][i], a)]) {
					chu[ru[a][i]] --;
					if (chu[ru[a][i]] == 0) cnt --;
					if (chu[ru[a][i]] == 1) cnt ++;
				}
				q[make_pair(ru[a][i], a)] = false;
			}
		}
		if (t == 3) {
			scanf("%d%d", &a, &b);
			q[make_pair(a, b)] = true;
			chu[a] ++;
			if (chu[a] == 2) cnt --;
			if (chu[a] == 1) cnt ++;
		}
		if (t == 4) {
			scanf("%d", &a);
			for (int i = 0; i < ru[a].size(); i ++) {
				if (!q[make_pair(ru[a][i], a)]) {
					chu[ru[a][i]] ++;
					if (chu[ru[a][i]] == 2) cnt --;
					if (chu[ru[a][i]] == 1) cnt ++;
				}
				q[make_pair(ru[a][i], a)] = true;
			}
		}
		
		if (cnt == n) puts("YES");
		else puts("NO");
	} 
	
	return 0;
}
