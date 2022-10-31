#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, q, k;

int v[maxn];
struct node{
	int a[3];
	int sum;
};
node t[maxn];
int x, y;
int r[maxn];
int l;
bool flag;
void dfs(int x, int y){
	if(x == y)return;
	if(flag)return;
	if(!t[x].sum)return;
	int u;
	for(int i = 1; i <= t[x].sum; i ++){
		u = t[x].a[i];
		if(u == y){
			flag = 1;
			r[++ l] = u;
			return;
		}
		else{
			dfs(u, y);
			if(flag){
				r[++ l] = u;
				break;
			}
		}
	}
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out ", "w", stdout);
	scanf("%d %d %d", &n, &q, &k);
	for(int i = 1; i <= n; i ++){
		scanf("%d", &v[i]);
	}
	for(int i = 1; i < n; i ++){
		scanf("%d %d", &x, &y);
		t[x].a[++ t[x].sum] = y;
		t[y].a[++ t[y].sum] = x;
	}
	for(int i = 1; i <= q; i ++){
		scanf("%d %d", &x, &y);
		l = 0;
		dfs(x, y);
		r[++ l] = x;
		for(int j = 1; j <= l; j ++){
			printf("%d ", r[j]);
		}
		printf("\n");
	}
	return 0;
} 
