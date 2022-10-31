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

const int MAXN = 5e5 + 5;

set <int> S[MAXN] , D[MAXN];
int n , m , q , cur[MAXN];

int main() {
	freopen("galaxy.in" , "r" , stdin);
	freopen("galaxy.out" , "w" , stdout);
	read(n),read(m);
	for (int i = 1; i <= m; ++i) {
		int u , v;
		read(u),read(v);
		S[v].insert(u);
		cur[u] ++;
	}
	read(q);
	int now = 0;
	for (int i = 1; i <= n; ++i) now += (cur[i] == 1);
	for (int i = 1; i <= q; ++i) {
		int t;read(t);
		if(t == 1) {
			int u , v;
			read(u),read(v);
			now -= (cur[u] == 1);
			S[v].erase(u) , D[v].insert(u);
			cur[u] --;
			now += (cur[u] == 1);
		}
		else if(t == 2) {
			int u;read(u);
			for (auto v:S[u]) {
				D[u].insert(v);
				now -= (cur[v] == 1);
				cur[v] --;
				now += (cur[v] == 1);
			}
			S[u].clear();
		}
		else if(t == 3) {
			int u , v;
			read(u),read(v);
			now -= (cur[u] == 1);
			D[v].erase(u) , S[v].insert(u);
			cur[u] ++;
			now += (cur[u] == 1);
		}
		else if(t == 4) {
			int u;read(u);
			for (auto v:D[u]) {
				S[u].insert(v);
				now -= (cur[v] == 1);
				cur[v] ++;
				now += (cur[v] == 1);
			}
			D[u].clear();
		}
		if(now == n) puts("YES");
		else puts("NO");
	}
	return 0;
}
