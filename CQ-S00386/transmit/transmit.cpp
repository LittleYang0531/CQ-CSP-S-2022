#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5 + 5,N = 8e5 + 5;
int n,q,K;
struct node
{
	ll a[3][3];
	void init()
	{
		for(int i = 0;i < K; i++)
			for(int j = 0;j < K; j++)
				a[i][j] = 4e14;
	}
	void chu()
	{
		for(int i = 0;i < K; i++)
			for(int j = 0;j < K; j++)
				a[i][j] = 4e14;
		for(int i = 0;i < K; i++)
			a[i][i] = 0;
	}
};
node operator * (node a,node b)
{
	node z;z.init();
	for(int k = 0;k < K; k++) 
		for(int i = 0;i < K; i++)
			for(int j = 0;j < K; j++)
				z.a[i][j] = min(z.a[i][j],a.a[i][k] + b.a[k][j]);
	return z;
}
int Last[MAXN],End[MAXN],Next[MAXN],cnt,val[MAXN],fa[MAXN],dep[MAXN];
int Top[MAXN],dfn[MAXN],Size[MAXN],Time,son[MAXN];
void add(int x,int y)
{
	End[++cnt] = y;Next[cnt] = Last[x];Last[x] = cnt;
}
void dfs1(int x,int ff)
{
	dep[x] = dep[ff] + 1;
	fa[x] = ff;
	Size[x] = 1;
	for(int i = Last[x];i;i = Next[i])
	{
		int y = End[i];
		if(y ==ff)continue;
		dfs1(y,x);
		Size[x] += Size[y];
		if(Size[son[x]] < Size[y])son[x] = y;
	}
}
void dfs2(int x,int tp)
{
	Top[x] = tp;
	dfn[x] = ++Time;
	if(son[x])dfs2(son[x],tp);
	for(int i = Last[x];i;i = Next[i])
	{
		int y = End[i];
		if(y == fa[x] || y == son[x])continue;
		dfs2(y,y);
	}
}
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
node sum[N][3];
void pushup(int p)
{
	sum[p][0] = sum[ls][0] * sum[rs][0];
	sum[p][1] = sum[rs][1] * sum[ls][1];
}
void insert(int p,int l,int r,int x,node v)
{
	if(l == r)
	{
		sum[p][0] = sum[p][1] = v;
		return;
	}
	if(x <= mid)insert(ls,l,mid,x,v);
	else insert(rs,mid + 1,r,x,v);
	pushup(p);
}
node getans(int p,int l,int r,int x,int y,int k)
{
	if(k == 0)// left->right
	{
		if(x <= l && r <= y)return sum[p][0];
		node ans;
		ans.chu();
		if(x <= mid && y >= l)ans = ans * getans(ls,l,mid,x,y,k);
		if(y > mid && x <= r)ans = ans * getans(rs,mid + 1,r,x,y,k);
		return ans;
	}
	else
	{
		if(x <= l && r <= y)return sum[p][1];
		node ans;
		ans.chu();
		if(y > mid && x <= r)ans = ans * getans(rs,mid + 1,r,x,y,k);
		if(x <= mid && y >= l)ans = ans * getans(ls,l,mid,x,y,k);
		return ans;
	}
}
stack <node> S;
ll getans(int x,int y)
{
	if(x == y)return val[x];
	node ans;
	ans.chu();
	node p;
	p.init(); 
	p.a[K - 1][0] = 0;
	int fx = x,fy = y;
	while(Top[x] != Top[y])
	{
		if(dep[Top[x]] > dep[Top[y]])
		{
			S.push(getans(1,1,n,dfn[Top[x]],dfn[x],0));
			x = fa[Top[x]];
		}
		else
			y = fa[Top[y]];
	}
	if(dep[x] >= dep[y])
		S.push(getans(1,1,n,dfn[y],dfn[x],0));
	x = fx,y = fy;
	while(Top[x] != Top[y])
	{
		if(dep[Top[x]] > dep[Top[y]])
			x = fa[Top[x]];
		else
		{
			ans = ans * getans(1,1,n,dfn[Top[y]],dfn[y],1);
			y = fa[Top[y]];
		}
	}
	if(dep[x] < dep[y])
		ans = ans * getans(1,1,n,dfn[x],dfn[y],1);
	while(!S.empty())
	{
		node k = S.top();
		ans = (ans * k);
		S.pop();
	}
	ans = ans * p;
	return ans.a[0][0];
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d %d %d", &n, &q, &K);
	for(int i = 1;i <= n; i++)scanf("%d", &val[i]);
	for(int i = 1;i < n; i++)
	{
		int x,y;
		scanf("%d %d", &x, &y);
		add(x,y),add(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i = 1;i <= n; i++)
	{
		node ans;ans.init();
		for(int j = 1;j <= K - 1; j++)
			ans.a[j][j - 1] = 0;
		for(int k = 0;k < K; k++)
			ans.a[0][k] = val[i];		
		insert(1,1,n,dfn[i],ans);
	}
	for(int i = 1;i <= q; i++)
	{
		int x,y;
		scanf("%d %d", &x, &y);
		printf("%lld\n", getans(x,y));
	}
	return 0;
}

