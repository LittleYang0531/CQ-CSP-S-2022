#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e5 + 5;
const ll inf = 1e16;
int n,q, k ,tot,cnt,cnt2;
int fir[N], nxt[N<<1], ver[N<<1];
ll v[N],f[N];
int fa[N], dep[N],now[N],now2[N];
inline void add(int x, int y) {
	ver[++tot] = y,nxt[tot] = fir[x], fir[x] = tot;
}

void dfs(int x) {
	dep[x] = dep[fa[x]] + 1;
	for (int i = fir[x] ;i; i = nxt[i]){
		int y = ver[i];
		if (y == fa[x])  continue;
		fa[y] = x;
		dfs(y);
	}
}
inline void yzhfind(int x,int y) {
	cnt = 0,cnt2=0;
	
	if(dep[x]< dep[y]){
		swap(x, y);
	}
//	printf("dep[x]=%d,dep[y]=%d\n",dep[x],dep[y]);
	int depc=dep[x]-dep[y];
	for (int i = 1; i <= depc; i++) {
		now[++cnt] = x;
		x = fa[x];
	}
	while (x!=y) {
		now[++cnt]=x,now2[++cnt2]=y;
		x=fa[x],y=fa[y];
	}
//	printf("	cnt %d cnt2 %d\n",cnt,cnt2);
	now[++cnt]=x;
	for (int i = cnt2; i>=1;i--){
		now[++cnt]=now2[i];
	}
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d", &n, &q, &k);
	for (int i = 1; i<= n; i++) {
		scanf("%lld", &v[i]);
	}
	for (int x, y, i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(1);
	for (int x, y, cs = 1; cs <= q; cs++){
		scanf("%d%d", &x,&y);
		yzhfind(x, y);
//		printf("	%d ",now[1]);
		f[1]=v[now[1]];
		for(int i = 2; i <= cnt; i++){
			f[i]=inf;
//			printf("%d ",now[i]);
			for(int j = i - 1; j >=i - k && j >= 1;j--){
				f[i] = min(f[i],f[j]);
			}
			f[i]+=v[now[i]];
		}
//		printf("\n");
		printf("%lld\n",f[cnt]);
	}
	return 0;
}
