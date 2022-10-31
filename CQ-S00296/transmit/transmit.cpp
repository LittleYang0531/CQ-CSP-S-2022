#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define int long long
#define MAXN 200005

template <typename T> inline void read (T &x){x = 0;char c = getchar ();int f = 1;while(!isdigit (c)) f*= (c == '-' ? -1 : 1),c = getchar ();while (isdigit (c)) x = x * 10 + c - '0',c = getchar ();x *= f;}
template <typename T,typename ... Args> inline void read (T &x,Args& ... args){read (x),read (args...);}
template <typename T> inline void write (T x){if (x < 0) putchar ('-'),x = -x;if (x > 9) write (x / 10);putchar (x % 10 + '0');}
template <typename T> inline void chkmax (T &a,T b){a = max (a,b);}
template <typename T> inline void chkmin (T &a,T b){a = min (a,b);}

int n,Q,K,val[MAXN];
vector <int> g[MAXN];

struct Matrix{
	int mat[3][3];
	Matrix(){memset (mat,0x3f,sizeof (mat));}
	int * operator [] (const int &key){return mat[key];}
	Matrix operator * (const Matrix &p)const{
		Matrix New;
		for (Int i = 0;i < K;++ i)
			for (Int j = 0;j < K;++ j)
				for (Int k = 0;k < K;++ k) chkmin (New[i][k],mat[i][j] + p.mat[j][k]);
		return New;
	}
};

Matrix st1[MAXN][21],st2[MAXN][21];

int dep[MAXN],par[MAXN][21];
void dfs (int u,int fa){
	par[u][0] = fa,dep[u] = dep[fa] + 1;
	for (Int t = 0;t < K;++ t) st1[u][0][t][0] = st2[u][0][t][0] = val[u];
	for (Int t = 0;t + 1 < K;++ t) st1[u][0][t][t + 1] = st2[u][0][t][t + 1] = 0;
	for (Int i = 1;i <= 20;++ i) 
		par[u][i] = par[par[u][i - 1]][i - 1],
		st1[u][i] = st1[u][i - 1] * st1[par[u][i - 1]][i - 1],
		st2[u][i] = st2[par[u][i - 1]][i - 1] * st2[u][i - 1];
	for (Int v : g[u]) if (v ^ fa) dfs (v,u);
}

int getlca (int u,int v){
	if (dep[u] < dep[v]) swap (u,v);
	for (Int i = 20,dis = dep[u] - dep[v];~i;-- i) if (dis >> i & 1) u = par[u][i];
	if (u == v) return u;
	else{
		for (Int i = 20;~i;-- i) if (par[u][i] ^ par[v][i]) u = par[u][i],v = par[v][i];
		return par[u][0];
	}
}

Matrix getit1 (int s,int d){
	Matrix res;for (Int t = 0;t < K;++ t) res[t][t] = 0;
	for (Int i = 20;~i;-- i) if (d >> i & 1) res = res * st1[s][i],s = par[s][i];
	return res;
}
Matrix getit2 (int s,int d){
	Matrix res;for (Int t = 0;t < K;++ t) res[t][t] = 0;
	for (Int i = 20;~i;-- i) if (d >> i & 1) res = st2[s][i] * res,s = par[s][i];
	return res;
}

int queryit (int s,int t){
	if (s == t) return val[s];
	int lca = getlca (s,t);Matrix tmp;
	if (s == lca) tmp = getit2 (t,dep[t] - dep[s]);
	else tmp = getit1 (par[s][0],dep[s] - dep[lca]) * getit2 (t,dep[t] - dep[lca]);
	return tmp[0][0] + val[s];
}

int miv[MAXN];
namespace Subtask1{
	int fa[MAXN],dp[MAXN][2];
	void dfs1 (int u,int lst){
		fa[u] = lst,dep[u] = dep[fa[u]] + 1;
		for (Int v : g[u]) if (v ^ lst) dfs1 (v,u); 
	}
	void Work (){
		dfs1 (1,0);
		while (Q --> 0){
			int u,v;read (u,v);
			vector <int> s1,s2;
			while (dep[u] > dep[v]) s1.push_back (u),u = fa[u];
			while (dep[u] < dep[v]) s2.push_back (v),v = fa[v];
			while (u != v) s1.push_back (u),s2.push_back (v),u = fa[u],v = fa[v];
			s1.push_back (u),reverse (s2.begin(),s2.end());
			for (Int x : s2) s1.push_back (x);
			dp[0][0] = val[s1[0]],dp[0][1] = val[s1[0]] + miv[s1[0]];
			for (Int i = 1;i < s1.size();++ i){
				dp[i][0] = dp[i][1] = 1e18;
				for (Int t = 0;t < 2;++ t)
					for (Int d = 1;d <= 3 && d <= i && t + d <= 3;++ d)
						for (Int k = 0;t + d + k <= 3 && k < 2;++ k)
							chkmin (dp[i][t],dp[i - d][k] + (t == 0 ? val[s1[i]] : miv[s1[i]]));
			}
			write (dp[s1.size() - 1][0]),putchar ('\n');
		}
	}
}

signed main(){
	freopen ("transmit.in","r",stdin);
	freopen ("transmit.out","w",stdout);
	read (n,Q,K);
	for (Int i = 1;i <= n;++ i) read (val[i]);
	for (Int u = 1;u <= n;++ u) miv[u] = 1e18;
	for (Int i = 2,u,v;i <= n;++ i) read (u,v),g[u].push_back (v),g[v].push_back (u),chkmin (miv[u],val[v]),chkmin (miv[v],val[u]);
	if (K == 3){
		Subtask1::Work ();
		return 0;
	}
	dfs (1,0);
	while (Q --> 0){
		int s,t;read (s,t);
		write (queryit (s,t)),putchar ('\n');
	}
	return 0;
}
/*
K<=2的时候似乎可以直接矩阵乘法？因为这样一定都是在链上
K=3的时候它一定是走到一个节点相邻最小值，然后接着往后面的节点走，而且一定是每次跳满
这样也可以矩阵优化，不过似乎会很慢啊，而且特判很多啊 干脆写个暴力得了 
*/

