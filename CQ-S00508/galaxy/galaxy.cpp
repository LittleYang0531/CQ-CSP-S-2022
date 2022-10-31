#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, m, q, cd[N], rd[N];
int type;
int cnt, h[N];
bool bk[N];

int Bcnt, Bh[N];
int d[N], low[N], sign, st[N], top, scc, Belong[N], num[N];
bool inst[N], lian[N];

struct edge {
	int to, next, frm;
}a[N], Ba[N];
void Add(int x, int y) {
	cd[x]++;
	rd[y]++;
	cnt++;
	a[cnt].to = y;
	a[cnt].next = h[x];
	a[cnt].frm = x;
	h[x] = cnt;
}

void bre(int x, int y, int cntt) {
	bk[cntt] = 1;
	cd[x]--;
	rd[y]--;
}
void hui(int x, int y, int cntt) {
	bk[cntt] = 0;
	cd[x]++;
	rd[y]++;
}

void Badd(int x, int y) {
	Bcnt++;
	Ba[Bcnt].to = y;
	Ba[Bcnt].next = Bh[x];
	Bh[x] = Bcnt;
}
void Tarjan(int u) {
	int y(0);
	d[u] = low[u] = ++sign;
	st[++top] = u;
	inst[u] = 1;
	for(int i = h[u];i;i = a[i].next) {
		if(bk[i]) continue;
		y = a[i].to;
		if(!d[y]) {
			Tarjan(y);
			low[u] = min(low[u], low[y]);
		}
		else if(inst[y])
			low[u] = min(low[u], d[y]);
	}
	if(d[u] == low[u]) {
		scc++;
		do {
			y = st[top--];
			inst[y] = 0;
			Belong[y] = scc;
			num[scc]++;
		}while(y != u);
	}
}

bool check() {
	//2 : continue
//	for(int i = 1;i <= n; i++)
//		cout << cd[i] << " ";
//	cout << endl;
	
	for(int i = 1;i <= n; i++)
		if(cd[i] > 1)
			return 0;
//	cout << "***";
	//1 : INF
	sign = top = scc = 0;
	memset(d, 0, sizeof(d));
	memset(low, 0, sizeof(low));
	memset(st, 0, sizeof(st));
	memset(inst, 0, sizeof(inst));
	memset(Belong, 0, sizeof(Belong));
	memset(num, 0, sizeof(num));
	memset(lian, 0, sizeof(lian));
	for(int i = 1;i <= n; i++)
		if(!d[i])
			Tarjan(i);
	
//	for(int i = 1;i <= n; i++)
//		for(int j = h[i];j;j = a[j].next)
//			if(!bk[i])
//				cout << i << " " << a[j].to << endl;
//	cout << scc << endl;
//	for(int i = 1;i <= n; i++)
//		cout << Belong[i] << " ";
//	cout << endl;
//	for(int i = 1;i <= scc; i++)
//		cout << num[i] << " ";
//	cout << endl;
	
	int x(0), y(0);
	for(int i = 1;i <= n; i++)
		for(int j = h[i];j;j = a[j].next) {
			x = Belong[i];
			y = Belong[a[j].to];
			if(num[x] > 1 || num[y] > 1) {
				lian[x] = 1;
				lian[y] = 1;
			}
			if(x == y) continue;
			Badd(y, x);
			if(lian[y]) {
				lian[x] = 1;
				lian[y] = 1;
			}
		}
	for(int i = 1;i <= scc; i++)
		if(lian[i]) {
			for(int j = Bh[i];j;j = Ba[j].next) {
				y = Ba[j].to;
				lian[y] = 1;
			}
		}
	for(int i = 1;i <= scc; i++)
		if(!lian[i])
			return 0;
	return 1;
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	cin >> n >> m;
	int x(0), y(0);
	for(int i = 1;i <= m; i++) {
		scanf("%d%d", &x, &y);
		Add(x, y);
	}
	cin >> q;
	while(q--) {
		
//		cout << "-----------\n";
//		for(int i = 1;i <= n; i++)
//			for(int j = h[i];j;j = a[j].next)
//				if(!bk[j])
//					cout << i << " " << a[j].to << " " << j << endl;
//		cout << "-----------\n";
		
		scanf("%d", &type);
		if(type == 1 || type == 3) {
			scanf("%d%d", &x, &y);
			if(type == 1) {
				for(int i = h[x];i;i = a[i].next) {
					if(a[i].to == y) {
						bre(x, y, i);
						break;
					}
				}
			}
			else if(type == 3) {
				for(int i = h[x];i;i = a[i].next) {
					if(a[i].to == y) {
						hui(x, y, i);
						break;
					}
				}
			}
		}
		if(type == 2 || type == 4) {
			scanf("%d", &x);
			if(type == 2) {
				for(int i = 1;i <= cnt; i++) {
					if(a[i].to == x) {
						if(bk[i]) continue;
						bre(a[i].frm, a[i].to, i);
					}
				}
			}
			else if(type == 4) {
				for(int i = 1;i <= cnt; i++) {
					if(a[i].to == x) {
						if(!bk[i]) continue;
						hui(a[i].frm, a[i].to, i);
					}
				}
			}
		}
		if(check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

