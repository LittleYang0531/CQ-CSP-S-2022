#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
	int to, next;
} e[20005];
int h[3005], cnt;
int n, m, k;
void add(int x, int y) {
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
ll s[3005];
ll dis[3005];
int f1[3005], f2[3005], f3[3005];
//第一大贡献点 次大贡献点         
bool vis[3005];
bool can[3005][3005];
void bfs(int st, int bj) {
	queue<int> q;
	q.push(st);
	memset(dis, 0x3f, sizeof(dis));
	dis[st]=0;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		if(dis[x]>k) return;
		if(dis[x]<k) {
			for(int i=h[x]; i; i=e[i].next) {
				int y=e[i].to;
//				printf("%d %d %lld %lld\n", x, y, dis[x], dis[y]);
				if(dis[x]+1<dis[y]){
					dis[y]=dis[x]+1;
					can[st][y]=1;
					q.push(y);
					if(bj==0){ //染色 
						vis[y]=1;
					}else{ //计算贡献 
						if(vis[y]){
							if(s[y]>s[f1[st]]){
								f3[st]=f2[st];
								f2[st]=f1[st];
								f1[st]=y;
							}else if(s[y]>s[f2[st]]){
								f3[st]=f2[st];
								f2[st]=y;
							}else if(s[y]>s[f3[st]]){
								f3[st]=y;
							}
						}
					}
				}
//				printf("=%d %d %lld %lld\n", f1[st], f2[st], s[f1[st]], s[f2[st]]);
			}
		}
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	++k;
	for(int i=2; i<=n; ++i) {
		scanf("%lld", &s[i]);
	}
	for(int i=1, x, y; i<=m; ++i) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	bfs(1, 0);
	for(int i=2; i<=n; ++i){
//		printf("=====%d=====\n", i);
		bfs(i, 1);
	}
//	for(int i=1; i<=n; ++i){
//		if(vis[i]) printf("%d ", i);
//	}
//	putchar('\n');
//	for(int i=2; i<=n; ++i){
//		printf("%d %d %lld %lld\n", f1[i], f2[i], s[f1[i]], s[f2[i]]);
//	}
	ll ans=0;
	for(int i=2; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			if(can[i][j]){
				int i1, i2, j1, j2;
				if(f1[i]==j){
					i1=f2[i], i2=f3[i];
				}else if(f2[i]==j){
					i1=f1[i], i2=f3[i];
				}else{
					i1=f1[i], i2=f2[i];
				}
				if(f1[j]==i){
					j1=f2[j], j2=f3[j];
				}else if(f2[j]==i){
					j1=f1[j], j2=f3[j];
				}else{
					j1=f1[j], j2=f2[j];
				}
				if(!i1||!j1) continue;
				if(i1!=j1){
					ans=max(ans, s[i]+s[j]+s[i1]+s[j1]);
				}else{
					if(i2){
						ans=max(ans, s[i]+s[j]+s[i2]+s[j1]);
					}
					if(j2){
						ans=max(ans, s[i]+s[j]+s[i1]+s[j2]);
					}
					
				}	
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

