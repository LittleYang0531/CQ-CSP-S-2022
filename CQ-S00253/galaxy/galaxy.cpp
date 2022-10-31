#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define LL long long
#define uint unsigned int
#define uLL unsigned long long
#define mr make_pair
#define pr pair <int, int>
using namespace std;
const int MAXN = 5e5 + 5;
int n, m, q, rd[MAXN], cd[MAXN], totr, totc, d[MAXN];
bool vis[MAXN];
vector <pr > v[MAXN];
map <pr, int> mp;
/*
1/3. 删去/恢复某条边
2/4. 删去/恢复以某个点为结尾的边

问：是否 forall cd[i]=1，（不算自环）

1~3 暴力 4~8 暴力 9~12 暴力

暴力咋给 60 pts 啊 
*/
void read(int &x) {
	x = 0; bool f = 1; char c = getchar();
	for(; c < '0' || c > '9'; c = getchar()) if(c == '-') f = 0;
	for(; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x = (f ? x : -x);
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	int f, x, y;
	read(n); read(m);
	for(int i = 1; i <= m; i ++) {
		read(x); read(y); v[y].push_back(mr(x, i)); mp[mr(x, y)] = i;
		cd[x] ++; rd[y] ++; vis[i] = 1;
	}
	for(int i = 1; i <= n; i ++) {
		if(cd[i] != 1) totc ++;
		if(rd[i] != 1) totr ++;
	}
	read(q);
	for(int i = 1; i <= q; i ++) {
		read(f);
		if(f == 1) {
			read(x); read(y); cd[x] --; rd[y] --;
			if(cd[x] == 0) totc ++;
			if(cd[x] == 1) totc --;
			if(rd[y] == 0) totr ++;
			if(rd[y] == 1) totr --;
			vis[mp[mr(x, y)]] = 0;
		}
		if(f == 2) {
			read(x); 
			for(auto y : v[x]) {
				if(!vis[y.second]) continue;
				rd[x] --; cd[y.first] --; vis[y.second] = 0;
				if(rd[x] == 0) totr ++;
				if(rd[x] == 1) totr --;
				if(cd[y.first] == 0) totc ++;
				if(cd[y.first] == 1) totc --;
			}
		}
		if(f == 3) {
			read(x); read(y); cd[x] ++; rd[y] ++;
			if(cd[x] == 2) totc ++;
			if(cd[x] == 1) totc --;
			if(rd[y] == 2) totr ++;
			if(rd[y] == 1) totr --;
			vis[mp[mr(x, y)]] = 1;
		}
		if(f == 4) {
			read(x); 
			for(auto y : v[x]) {
				if(vis[y.second]) continue;
				rd[x] ++; cd[y.first] ++; vis[y.second] = 1;
				if(cd[y.first] == 2) totc ++;
				if(cd[y.first] == 1) totc --;
				if(rd[x] == 2) totr ++;
				if(rd[x] == 1) totr --;
			}
		}
		if(totc == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

