#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define MAXN 500005

template <typename T> inline void read (T &x){x = 0;char c = getchar ();int f = 1;while(!isdigit (c)) f*= (c == '-' ? -1 : 1),c = getchar ();while (isdigit (c)) x = x * 10 + c - '0',c = getchar ();x *= f;}
template <typename T,typename ... Args> inline void read (T &x,Args& ... args){read (x),read (args...);}
template <typename T> inline void write (T x){if (x < 0) putchar ('-'),x = -x;if (x > 9) write (x / 10);putchar (x % 10 + '0');}
template <typename T> inline void chkmax (T &a,T b){a = max (a,b);}
template <typename T> inline void chkmin (T &a,T b){a = min (a,b);}

int n,m,q,deg[MAXN];

struct edge{
	int v,ind,nxt;
}e[MAXN << 1];
int toop = 1,head[MAXN];
void add_edge (int u,int v,int t){
	e[++ toop] = edge{v,t,head[u]},
	head[u] = toop;
}

bool vis[MAXN];
#define pii pair<int,int>
#define se second
#define fi first
map <pii,int> mp;
int sht[MAXN],all[MAXN];

signed main(){
	freopen ("galaxy.in","r",stdin);
	freopen ("galaxy.out","w",stdout);
	read (n,m);int cnt = 0;
	for (Int i = 1,u,v;i <= m;++ i)
		read (u,v),add_edge (v,u,i),deg[u] ++,mp[{u,v}] = i,vis[i] = 1,all[v] ++;
	bool flg = 0;
	for (Int u = 1;u <= n;++ u) flg |= (deg[u] == 0); 
	for (Int i = 1;i <= n;++ i) cnt += (deg[i] == 1);
	read (q);
	if (flg){
		for (Int i = 1;i <= q;++ i) puts ("NO");
		return 0;
	}
	while (q --> 0){
		int opt,u,v;read (opt);
		if (opt == 1) read (u,v),vis[mp[{u,v}]] = 0,sht[v] ++,cnt -= (deg[u] == 1),deg[u] --,cnt += (deg[u] == 1);
		else if (opt == 2){
			read (u);
			if (sht[u] == all[u]) ;
			else{
				for (Int i = head[u];i;i = e[i].nxt){
					if (vis[e[i].ind]){
						int v = e[i].v;vis[e[i].ind] = 0;
						cnt -= (deg[v] == 1),deg[v] --,cnt += (deg[v] == 1),sht[u] ++;
					}
				}
			}
		}
		else if (opt == 3) read (u,v),vis[mp[{u,v}]] = 1,sht[v] --,cnt -= (deg[u] == 1),deg[u] ++,cnt += (deg[u] == 1);
		else if (opt == 4){
			read (u);
			if (!sht[u]) ;
			else{
				for (Int i = head[u];i;i = e[i].nxt) if (!vis[e[i].ind]){
					int v = e[i].v;vis[e[i].ind] = 1;
					cnt -= (deg[v] == 1),deg[v] ++,cnt += (deg[v] == 1),sht[u] --;
				}
			}
		}
		puts (cnt == n ? "YES" : "NO");
	}
	return 0;
}
/*
可以发现其实只需要每个点出度都为1即等价于两个条件 
*/
