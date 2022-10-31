#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define pii pair <int , int>
#define pll pair <LL , LL>
#define mp make_pair
#define fs first
#define sc second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

template <typename T>
void read(T &x) {
	T f=1;x=0;char s=getchar();
	while(s<'0'||s>'9') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s^'0');s=getchar();}
	x *= f;
}

template <typename T>
void write(T x , char s='\n') {
	if(x<0) {putchar('-');x=-x;}
	if(!x) {putchar('0');putchar(s);return;}
	T tmp[25] = {} , t = 0;
	while(x) tmp[t ++] = x % 10 , x /= 10;
	while(t-->0) putchar('0' + tmp[t]);
	putchar(s);
}

const int MAXN = 2e5 + 5;
const LL inf = 1e18;

int n , Q , k;
LL v[MAXN];
vector <int> G[MAXN];

namespace Sub {
	struct Matrix {
		LL a[7][7] , n;
		inline Matrix operator * (Matrix B) {
			Matrix C;C.n = n;
			for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) C.a[i][j] = inf;
			for (int i = 1; i <= n; ++i) {
				for (int k = 1; k <= n; ++k) {
					for (int j = 1; j <= n; ++j) {
						C.a[i][j] = min(a[i][k] + B.a[k][j] , C.a[i][j]);
					}
				}
			}
			return C;
		}
	}I;
	
	int siz[MAXN] , hson[MAXN] , dfn[MAXN] , pre[MAXN] , num , top[MAXN] , dep[MAXN];
	
	void dfs1(int x , int fa) {
		siz[x] = 1;pre[x] = fa;
		dep[x] = dep[fa] + 1;
		for (auto v:G[x]) {
			if(v == fa) continue;
			dfs1(v , x);
			if(siz[v] > siz[hson[x]]) hson[x] = v;
			siz[x] += siz[v];
		}
	}
	
	Matrix cur , Lv[MAXN << 2] , Rv[MAXN << 2];
	void update(int l , int r , int now , int x) {
		if(l == r) {
			Lv[now] = Rv[now] = cur;
			return;
		}
		int mid = (l + r) >> 1;
		if(x <= mid) update(l , mid , now << 1 , x);
		else update(mid + 1 , r , now << 1 | 1 , x);
		Lv[now] = Lv[now << 1] * Lv[now << 1 | 1];
		Rv[now] = Rv[now << 1 | 1] * Rv[now << 1];
	}
	
	void find_L(int l , int r , int now , int x , int y) {
		if(l >= x && r <= y) {
			cur = cur * Lv[now];
			return;
		}
		int mid = (l + r) >> 1;
		if(x <= mid) find_L(l , mid , now << 1 , x , y);
		if(y > mid) find_L(mid + 1 , r , now << 1 | 1 , x , y);
	}
	
	void find_R(int l , int r , int now , int x , int y) {
		if(l >= x && r <= y) {
			cur = cur * Rv[now];
			return;
		}
		int mid = (l + r) >> 1;
		if(y > mid) find_R(mid + 1 , r , now << 1 | 1 , x , y);
		if(x <= mid) find_R(l , mid , now << 1 , x , y);
	}
	
	LL NowVal[MAXN];
	void dfs2(int x , int fa , int tp) {
		top[x] = tp;dfn[x] = ++num;
		if(k == 1) cur.n = 1 , cur.a[1][1] = v[x];
		else if(k == 2) cur.n = 2 , cur.a[1][1] = cur.a[1][2] = v[x] , cur.a[2][1] = 0 , cur.a[2][2] = inf;
		else {
			cur.n = 6;
			for (int i = 1; i <= 6; ++i) for (int j = 1; j <= 6; ++j) cur.a[i][j] = inf;
			NowVal[x] = v[x];
			for (auto y:G[x]) NowVal[x] = min(NowVal[x] , v[y]);
			cur.a[1][1] = cur.a[1][2] = cur.a[1][3] = cur.a[1][4] = cur.a[1][5] = v[x];
			cur.a[2][1] = cur.a[2][2] = cur.a[2][3] = NowVal[x];
			cur.a[3][1] = 0 , cur.a[4][2] = 0 , cur.a[5][3] = 0 , cur.a[6][4] = 0;			
		}
		update(1 , n , 1 , dfn[x]);
		if(hson[x]) dfs2(hson[x] , x , tp);
		for (auto v:G[x]) {
			if(v == fa || v == hson[x]) continue;
			dfs2(v , x , v);
		}
	}
	
	LL calc(int s , int t) {
//		LL VS = v[s];
		Matrix Lnow = I , Rnow = I;
		while(top[s] != top[t]) {
			cur = I;
			if(dep[top[s]] >= dep[top[t]]) {
				find_R(1 , n , 1 , dfn[top[s]] , dfn[s]);
				Lnow = Lnow * cur;
				s = pre[top[s]];
			}
			else {
				find_L(1 , n , 1 , dfn[top[t]] , dfn[t]);
				Rnow = cur * Rnow;
				t = pre[top[t]];
			}
		}
		cur = I;
		if(dep[s] >= dep[t]) {
			find_R(1 , n , 1 , dfn[t] , dfn[s]);
			Lnow = Lnow * cur;
		}
		else {
			find_L(1 , n , 1 , dfn[s] , dfn[t]);
			Rnow = cur * Rnow;
		}
		Lnow = Lnow * Rnow;
		if(k == 1) return Lnow.a[1][1];
		else if(k == 2) return Lnow.a[1][2];
		return Lnow.a[1][5];
	}
	
	void solve() {
		I.n = k;
		if(k == 3) I.n = 6;
		for (int i = 1; i <= I.n; ++i) for (int j = 1; j <= I.n; ++j) I.a[i][j] = (i!=j)*inf;
		dfs1(1 , 0);
		dfs2(1 , 0 , 1);
		while(Q -- > 0) {
			int s , t;
			read(s),read(t);
			write(calc(s , t));
		}
	}
}

int main() {
	freopen("transmit.in" , "r" , stdin);
	freopen("transmit.out" , "w" , stdout);
	read(n),read(Q),read(k);
	for (int i = 1; i <= n; ++i) read(v[i]);
	for (int i = 1; i < n; ++i) {
		int u , v;
		read(u),read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	Sub::solve();
	return 0;
}
