#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, t, q, flag;
short graph[5005][5005];
int cnt[5005];
int main(){
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(register int i=1;i<=m;++i){
		scanf("%d%d", &u, &v);
		graph[u][v] = 1;
		++cnt[u];
	}
	scanf("%d", &q);
	for(register int T=1;T<=q;++T){
		scanf("%d", &t);
		if(t == 1){
			scanf("%d%d", &u, &v);
			graph[u][v] = -1;
			--cnt[u];
		}else if(t == 2){
			scanf("%d", &u);
			for(register int i=1;i<=n;++i){
				if(graph[i][u]){
					graph[i][u] = -1;
					--cnt[i];
				}
			}
		}else if(t == 3){
			scanf("%d%d", &u, &v);
			graph[u][v] = 1;
			++cnt[u];
		}else{
			scanf("%d", &u);
			for(register int i=1;i<=n;++i){
				if(graph[i][u]){
					graph[i][u] = 1;
					++cnt[i];
				}
			}
		}
		flag = 1;
		for(register int i=1;i<=n;++i){
			if(cnt[i] != 1){
				flag = 0;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


