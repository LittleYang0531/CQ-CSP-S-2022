#include<bits/stdc++.h>
#define LL long long
#define mes(s, x) memset(s, x, sizeof(s))
#define MAXN 500005
using namespace std;
vector<int> G[MAXN];
int s[MAXN], sum;
bitset<1005> b[1005];
void add(int i, int v){
	if(s[i] == 1) sum--;
	s[i] += v;
	if(s[i] == 1) sum++;
}
int main(){
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	int n, m, q, t, x, y;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &x, &y);
		b[x][y] = 1;
		add(x, 1);
		G[y].push_back(x);
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; i++){
		scanf("%d %d", &t, &x);
		if(t == 1 || t == 3) scanf("%d", &y);
		if(t == 1){
			if(n <= 1000) b[x][y] = 0;
			add(x, -1);
		}else if(t == 2){
			for(int j = 0; j < G[x].size(); j++){
				y = G[x][j];
				if(b[y][x]){
					b[y][x] = 0;
					add(y, -1);
				}
			}
		}else if(t == 3){
			if(n <= 1000) b[x][y] = 1;
			add(x, 1);
		}else if(t == 4){
			for(int j = 0; j < G[x].size(); j++){
				y = G[x][j];
				if(!b[y][x]){
					b[y][x] = 1;
					add(y, 1);
				}
			}
		}
		printf("%s\n", sum == n ? "YES" : "NO");
	}
	return 0;
}
