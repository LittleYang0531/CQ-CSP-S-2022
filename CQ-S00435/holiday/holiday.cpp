#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
const int M = 20005, N = 2505;
int n, m, k, tot;
int fir[N], nxt[M], ver[M];
int vis[N][N];
int to[N][N],cnt[N];
ll si[N], ans; // ¾°µã·ÖÊý
queue<int> q[2];
inline void add(int x, int y) {
	ver[++tot] = y, nxt[tot] = fir[x], fir[x] = tot;
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);

	for (int i =2; i <= n; i++){
		scanf("%lld",&si[i]);
	}
	for(int x, y, i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		add(x,y), add(y, x);
	}
//	if (k == 0) {
//		
//	}
	for (int x = 1; x <= n; x++) {
		while (q[0].size()) q[0].pop();
		while (q[1].size()) q[1].pop();
		q[0].push(x), vis[x][x] = 1;
		
		for (int i = 0; i <= k; i++) {
			int id = i & 1;
			while (q[id].size()) {
				int y = q[id].front(); q[id].pop();
				for (int j = fir[y]; j; j = nxt[j]) {
					int z = ver[j];
					if (!vis[x][z]){
						
						vis[x][z] = 1;
						to[x][++cnt[x]] = z;
						if (i != k) {
							q[id^1].push(z);
						}
					} 
				}
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
////		printf("cnt %d = %d\n", i, cnt[i]);
//		for (int j =1; j <= n; j++) {
//			printf("%d ", vis[i][j]);
//		}
//		printf("\n");
//	}
	for (int i1 = 1; i1 <= cnt[1]; i1++) {
		int a = to[1][i1];
		for (int i2 = 1; i2 <= cnt[a]; i2++) {
			int b = to[a][i2];
			if (b == a || b == 1) continue;
			for (int i3 = 1; i3 <= cnt[b]; i3++) {
				int c=to[b][i3];
				if (c == a || c == b || c == 1) continue;
				for (int i4 = 1; i4 <= cnt[c]; i4++) {
					int d = to[c][i4];
					if (d == a || d == b || d == c || d == 1) 
						continue;
					if (!vis[d][1]) continue;
					ans = max(ans, si[a]+si[b]+si[c]+si[d]);
//					printf("%d");
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
