#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define int long long
#define MAXN 2505

template <typename T> inline void read (T &x){x = 0;char c = getchar ();int f = 1;while(!isdigit (c)) f*= (c == '-' ? -1 : 1),c = getchar ();while (isdigit (c)) x = x * 10 + c - '0',c = getchar ();x *= f;}
template <typename T,typename ... Args> inline void read (T &x,Args& ... args){read (x),read (args...);}
template <typename T> inline void write (T x){if (x < 0) putchar ('-'),x = -x;if (x > 9) write (x / 10);putchar (x % 10 + '0');}
template <typename T> inline void chkmax (T &a,T b){a = max (a,b);}
template <typename T> inline void chkmin (T &a,T b){a = min (a,b);}

vector <int> g[MAXN];bool vis[MAXN][MAXN];
int n,m,K,val[MAXN],dep[MAXN],pos[MAXN][4];//记录每个点可达中权值最大的3个 

signed main(){
	freopen ("holiday.in","r",stdin);
	freopen ("holiday.out","w",stdout);
	read (n,m,K);
	for (Int i = 2;i <= n;++ i) read (val[i]);
	for (Int i = 1,u,v;i <= m;++ i) read (u,v),g[u].push_back (v),g[v].push_back (u);
	for (Int u = 1;u <= n;++ u){
		queue <int> q;memset (dep,-1,sizeof (dep)),dep[u] = 0,vis[u][u] = 1,q.push (u);
		while (!q.empty()){
			int t = q.front();q.pop ();vis[u][t] = 1;
			if (dep[t] > K + 1) break;
			for (Int x : g[t]) if (dep[x] == -1)
				dep[x] = dep[t] + 1,q.push (x);
		}
	}
	for (Int u = 2;u <= n;++ u){
		for (Int v = 2;v <= n;++ v) if (u != v && vis[1][v] && vis[u][v]){
			if (!pos[u][1] || val[pos[u][1]] < val[v]) pos[u][3] = pos[u][2],pos[u][2] = pos[u][1],pos[u][1] = v;
			else if (!pos[u][2] || val[pos[u][2]] < val[v]) pos[u][3] = pos[u][2],pos[u][2] = v;
			else if (!pos[u][3] || val[pos[u][3]] < val[v]) pos[u][3] = v;
		}
	}
	int ans = 0;
	for (Int su = 2;su <= n;++ su)
		for (Int sv = 2;sv <= n;++ sv) if (su != sv && vis[su][sv])
			for (Int ps = 1;ps <= 3;++ ps) if (pos[su][ps] && pos[su][ps] != sv)
				for (Int pt = 1;pt <= 3;++ pt) if (pos[sv][pt] && pos[sv][pt] != su && pos[sv][pt] != pos[su][ps]) 
					chkmax (ans,val[su] + val[sv] + val[pos[su][ps]] + val[pos[sv][pt]]);
	write (ans),putchar ('\n');
	return 0;
}
/*
从我成年那天开始我就想要住进上海，因为我家客厅有张光盘
一部旅游记录片，关于黄浦江畔，关于东方明珠，群众演员表情怪诞 
*/
