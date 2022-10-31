/*
题意很清晰，显然就是求树上一条最短路径满足权值和最小且相邻距离不超 k。
k 还 <= 3，这啥意思，原问题是不是本来就可以做了。算了不清楚。
？？？
考虑这个 dp 其实比较虚假，我们直接大力线段树合并，保证任一时刻一个节点只属于树上连续的 3-th 级祖先。
但是是不是可以用矩阵啊 qwq。但是常数会很大。
那就线段树合并啊，有什么好说的。垫底了。 
来不及了，写部分分。 
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int Len = 2e5 + 5 , Inf = 1e9 + 1;
const ll inf = 1e15;
int n,q,k,v[Len],head[Len],cnt,fa[Len],st[25][Len],dep[Len];
ll dis[Len],dp[2005][2005];
struct node
{
	int next,to;
}edge[Len << 1];
inline void add(int from,int to)
{
	edge[++ cnt].to = to;
	edge[cnt].next = head[from];
	head[from] = cnt;
}
void dfs(int x,int f)
{
	dis[x] = dis[f] + v[x];
	dep[x] = dep[f] + 1;
	st[0][x] = f;
	for(int i = 1 ; (1 << i) <= dep[x] ; i ++) st[i][x] = st[i - 1][st[i - 1][x]];
	for(int e = head[x] ; e ; e = edge[e].next)
	{
		int to = edge[e].to;
		if(to == f) continue;
		dfs(to , x);
	}
}
inline int LCA(int x,int y)
{
	if(dep[x] < dep[y]) swap(x , y);
	for(int i = 20 ; i >= 0 ; i --) if(dep[st[i][x]] >= dep[y]) x = st[i][x];
	if(x == y) return x;
	for(int i = 20 ; i >= 0 ; i --) if(st[i][x] != st[i][y]) x = st[i][x] , y = st[i][y];
	return st[0][x];
}
inline ll Dis(int x,int y){return dis[x] + dis[y] - (dis[LCA(x,y)] << 1) + v[LCA(x,y)];}
inline int diss(int x,int y){return dep[x] + dep[y] - (dep[LCA(x,y)] << 1);}
void case1()
{
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++) dp[i][j] = inf;
	for(int i = 1 ; i <= n ; i ++) dp[i][i] = v[i];
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
		{
			if(i == j) continue;
			if(diss(i , j) <= k) dp[i][j] = min(dp[i][j] , 1ll * v[i] + v[j]);
		}
	for(int p = 1 ; p <= n ; p ++)
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= n ; j ++) dp[i][j] = min(dp[i][j] , dp[i][p] + dp[p][j] - v[p]);
	for(int i = 1 ; i <= q ; i ++)
	{
		int x,y;scanf("%d %d",&x,&y);
		printf("%lld\n",dp[x][y]);
	}
}
void case2()
{
	for(int i = 1 ; i <= q ; i ++)
	{
		int x,y;scanf("%d %d",&x,&y);
		printf("%lld\n",Dis(x , y));
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d %d %d",&n,&q,&k);
	for(int i = 1 ; i <= n ; i ++) scanf("%d",&v[i]);
	for(int i = 1 ; i < n ; i ++)
	{
		int x,y;scanf("%d %d",&x,&y);
		add(x , y) , add(y , x);
	}
	dfs(1 , 0);
	if(k <= 1) case2();
	else case1(); 
	return 0;
}
/*

题意很清晰，显然就是求树上一条最短路径满足权值和最小且相邻距离不超 k。
k 还 <= 3，这啥意思，原问题是不是本来就可以做了。算了不清楚。
？？？
考虑这个 dp 其实比较虚假，我们直接大力线段树合并，保证任一时刻一个节点只属于树上连续的 3-th 级祖先。
但是是不是可以用矩阵啊 qwq。但是常数会很大。
那就线段树合并啊，有什么好说的。垫底了。 

#include "bits/stdc++.h"
using namespace std;
const int Len = 2e5 + 5 , Inf = 1e9 + 1;
int n,m,dp[2005][2005],v[Len],vw[Len],head[Len],cnt,fa[Len],st[25][Len],dep[Len];
int W[Len][3];
struct node
{
	int next,to;
}edge[Len << 1];
inline void add(int from,int to)
{
	edge[++ cnt].to = to;
	edge[cnt].next = head[from];
	head[from] = cnt;
}
vector<int> vec[Len];
vector<int> w[Len][3];
inline void add(int from,int to){vec[from].push_back(to);}
void DFS(int x,int f)
{
	fa[x] = f;dep[x] = dep[f] + 1;st[0][x] = f;
	for(int i = 1 ; (1 << i) <= dep[x] ; i ++) st[i][x] = st[i - 1][st[i - 1][x]];
	for(int e = head[x] ; e ; e = edge[e].next)
	{
		int to = edge[e].to;
		if(to == f) continue;
		vec[x].push_back(to);
		w[x][0].push_back(0) , w[x][1].push_back(0) , w[x][2].push_back(0);
		DFS(to , x);
	}
	int mn = Inf , mnn = Inf;
	vw[x] = v[x];
	for(int i = 0 ; i < (int)vec[x].size() ; i ++)
	{
		int to = vec[x][i];
		vw[x] = max(vw[i] , v[to]);
		w[x][0][to] = v[to];
		w[x][1][to] = min(mn , v[x]);
		w[x][2][to] = min(mnn , v[x]);
		mn = min(mn , v[to]);mnn = min(mnn , vw[to]);
	}
	mn = mnn = Inf;
	for(int i = (int)vec[x].size() - 1 ; i >= 0 ; i --)
	{
		int to = vec[x][i];
		w[x][0][to] = v[to];
		w[x][1][to] = min(mn , v[x]);
		w[x][2][to] = min(mnn , v[x]);
		W[to][0] = w[x][0][to] , W[to][1] = w[x][1][to] , W[to][2] = w[x][2][to];
		mn = min(mn , v[to]);mnn = min(mnn , vw[to]);
	}
}
inline int LCA(int x,int y)
{
	if(dep[x] < dep[y]) swap(x , y);
	for(int i = 20 ; i >= 0 ; i --) if(dep[st[i][x]] >= dep[y]) x = st[i][x];
	if(x == y) return x;
	for(int i = 20 ; i >= 0 ; i --) if(st[i][x] != st[i][y]) x = st[i][x] , y = st[i][y];
	return st[0][x];
}
int nn[5],cs[5],len;
void gs(int x,int j,int w)
{
	int res = w;
	for(int i = 1 ; i <= len ; i ++) res += w[nn[i]][cs[i]];
	dp[x][j] = min(dp[x][j] , res);
}
void dfs(int now,int gg,int j,int w)
{
	if(nn[now] == gg)
	{
		gs(nn[now] , j , w);
		return;
	}
	if(nn[now + 1] == gg) 
	{
		cs[now + 1] = 0;
		dfs(now + 1 , gg , j , w);
	}
	else
	{
		for(int i = 0 ; i <= 2 ; i ++)
		{
			if(i + cs[now] <= k) 
			{
				cs[now + 1] = i;
				dfs(now + 1 , gg , j , w);
				cc[now + 1] = -1;	
			} 
		}
	}
}
inline void calc(int x,int y,int ds)
{
	for(int j = 1 ; j <= n ; j ++) 
	{
		int res = Inf;
		len = 0;
		cs[0] = -10;int w = x;
		while(ds --)
		{
			++ len;
			w = fa[w];
			nn[len] = w , cs[len] = -1;
		}
		dfs(0 , y , j , dp[x][j]);
	}
}
void DP(int x)
{
	for(int i = 0 ; i < (int)vec[x].size() ; i ++)
	{
		int to = vec[x][i];
		DP(to);
	}
	int w = x;
	if(k >= 1) 
	{
		w = fa[w];
		if(w) calc(x , w , 1);
	}
	if(k >= 2) 
	{
		w = fa[w];
		if(w) calc(x , w , 2);
	}
	if(k >= 3) 
	{
		w = fa[w];
		if(w) calc(x , w , 3);
	}
}
int main()
{
	//freopen("transmit.in","r",stdin);
	//freopen("transmit.out","w",stdout);
	
	return 0;
}
*/ 
