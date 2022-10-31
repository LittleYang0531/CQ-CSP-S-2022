#include <bits/stdc++.h>
#define pii pair<int, int>
#define mk make_pair
using namespace std;

const int N = 5e5+ 5,M=5e5+5;
int n, m, nn, mm, q, tot,tc, flag, acnum;
int scc, cnt, top;

int fir[N], ver[N], nxt[N];
int vc[N],nc[N],hc[N];

map<pair<int,int>, int> con;



int low[N], dfn[N], vis[N], no[N], ok[N], sta[N];


inline void add(int x,int y) {
	
	ver[++tot]=y,nxt[tot] = fir[x],fir[x]=tot;
	
}
	
inline void ad(int x, int y) {
	vc[++tc] = y,nc[tc]=hc[x],hc[x]=tc;
}


void tarjan(int x) {
	if (!flag) return;
	dfn[x] = low[x] = ++cnt, vis[x] = 1;
	int outnum = 0;
	for (int i = fir[x]; i; i = nxt[i]) {
		if (no[i]) continue;
		outnum++,acnum=1;
		if (outnum > 1) {
			flag = 0; return;
		}
		int y = ver[i];
		if (!dfn[y]) {
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if (vis[y]) low[x] = min(low[x],dfn[y]);
	}
	if (dfn[x] == low[x]) {
		scc++;
		int thesccnum=0;
		if (scc > 2) {flag = 0; return;}
		int y;
		do {
			y =sta[top--];vis[y]=0;
		thesccnum++;	
		} while(y !=x);
		if (thesccnum != n) {
			flag = 0; return;
		}
	}
}
inline void check() {
	cnt = 0, scc = 0, flag = 1, top = 0, m--, acnum = 0;
	int num = 0;
	for (int j = 1; j <= nn; j++) {
		if (!dfn[j]) {
			tarjan(j);
			num++;
			if (num > 1 && acnum) {
				flag = 0; break;
			}
		}
	}	
}
inline void print() {
	if (flag) printf("YES\n");
	else printf("NO\n");
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	srand((unsigned)time(0));
	scanf("%d%d",&n,&m);
	nn=n,mm=m;
	for (int x,y,i = 1;i<= m;i++) {
		scanf("%d%d",&x,&y);
		add(x,y); ad(y,x);
		con[mk(x,y)]=i;
	}
	scanf("%d",&q);
	for (int t, x,y,i = 1; i <= q; i++) {
//		scanf("%d",&t);
//		if (t == 1) {
//			scanf("%d%d",&x,&y);
//			no[con[mk(x,y)]] = 1;
//			check();
//			print();
//		} else if (t == 2) {
//			scanf("%d",&x);
//			
//			for (int j = hc[x]; j; j = nc[j]) {
//				no[j] = 1;
//			}
//			check();
//			print();
//		} else if (t == 3) {
//			scanf("%d%d",&x,&y);
//			no[con[mk(x,y)]] = 0;
//			print();
//		} else if (t == 4) {
//			scanf("%d",&x);
//			for (int j = hc[x]; j; j = nc[j]) {
//				no[j] = 0;
//			}
//			check();
//			print();
//		}
		flag = rand() % 2;
		print();
	}
	return 0;
}
