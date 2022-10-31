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

const int MAXN = 2505;
const LL inf = 4e18 + 1;

int dis[MAXN] , n , m , k;
LL val[MAXN];
bool f[MAXN][MAXN];
vector <int> G[MAXN];

inline void check(int s) {
	for (int i = 1; i <= n; ++i) dis[i] = 1e9;
	queue <int> q;
	q.push(s);dis[s] = 0;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto v:G[x]) {
			if(dis[v] > dis[x] + 1) {
				dis[v] = dis[x] + 1;
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; ++i) f[s][i] = (dis[i] <= k + 1);
}

set <pll> S[MAXN];

int main() {
	freopen("holiday.in" , "r" , stdin);
	freopen("holiday.out" , "w" , stdout);
	read(n),read(m),read(k);
	for (int i = 2; i <= n; ++i) read(val[i]);
	for (int i = 1; i <= m; ++i) {
		int u , v;
		read(u),read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for (int i = 1; i <= n; ++i) check(i);
		
	for (int i = 2; i <= n; ++i) if(f[1][i]) for (int j = 2; j <= n; ++j) if(i != j && f[i][j]) {
		S[j].insert((mp(val[i] + val[j] , i)));
		if(S[j].size() > 3u) S[j].erase(S[j].begin());
	}
	
	LL Ans = -inf;
	for (int i = 2; i <= n; ++i) {
		for (auto v1:S[i]) {
			for (int j = 2; j <= n; ++j) if(i != j && v1.sc != j && f[i][j]) {
				for (auto v2:S[j]) if(v2.sc != i && v2.sc != v1.sc) {
					Ans = max(Ans , v2.fs + v1.fs);
				}
			}
		}
	}
		
	write(Ans);
	
	return 0;
}
