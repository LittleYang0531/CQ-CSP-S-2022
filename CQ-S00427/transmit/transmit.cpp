//有很多明显的反例，比如去根节点上方休息会儿，但是在直接连接的路径上跑烽火传递的正确率还是不算低
//注意到，k的值简直离谱(可以尝试暴力枚举)
//经尝试，k = 1 or 2时一定在那条路径上，3时中间每一个节点的相邻节点都有可能被讨论(卒) 
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 2e5 + 10, M = 2 * N;
int n, m, k;
int a[N], mina[N];//mina相当于每一个节点的备用仓，只有k=3时会用到，它的作用是临时寄存 

int h[N], ne[M], e[M], idx;
void add(int a, int b)
{
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

int f[N][20];
int deep[N], S;
void dfs(int x, int fa)
{
	mina[x] = min(mina[x], fa);
	mina[fa] = min(mina[fa], x);
	deep[x] = deep[fa] + 1;
	S = max(S, deep[x]);
	f[x][0] = fa;
	
	for(int i = 1; deep[x] - (1 << i) >= 1; i++)
		f[x][i] = f[f[x][i - 1]][i - 1];
	
	for(int i = h[x]; i; i = ne[i])
		if(e[i] != fa)
			dfs(e[i], x);
}

int lca(int a, int b)
{
	if(deep[a] < deep[b]) swap(a, b);
	
	for(int i = S; i >= 0; i--)
		if(deep[a] - (1 << i) >= deep[b])
			a = f[a][i];
	if(a == b) return a;

	for(int i = S; i >= 0; i--)
		if(f[a][i] != f[b][i])
			a = f[a][i], b = f[b][i];
	return f[a][0];
}

int x[N];
LL f1[N];
LL work(int n)
{
	deque<int> q;
	f1[1] = a[x[1]];
	for(int i = 2; i <= min(k + 1, n); i++)
	{
		f1[i] = a[x[i]] + f1[1];
		while(!q.empty() && f1[q.back()] >= f1[i])
			q.pop_back();
		q.push_back(i);
		
		if(!q.empty() && q.front() < i + 1 - k)
			q.pop_front();
		if(!q.empty() && f1[i - 1] > f1[q.front()] + mina[x[i]])
		{
			f1[i - 1] = f1[q.front()] + mina[x[i]];
			while(!q.empty() && f1[q.back()] >= f1[i - 1])
				q.pop_back();
			q.push_back(i - 1);
		}
	}
	
	for(int i = k + 2; i <= n; i++)
	{
		if(!q.empty() && q.front() < i - k)
			q.pop_front();
		f1[i] = a[x[i]] + f1[q.front()];
		
		if(!q.empty() && q.front() < i + 1 - k)
			q.pop_front();
		if(!q.empty() && f1[i - 1] > f1[q.front()] + mina[x[i]])
		{
			f1[i - 1] = f1[q.front()] + mina[x[i]];
			while(!q.empty() && f1[q.back()] >= f1[i - 1])
				q.pop_back();
			q.push_back(i - 1);
		}
		while(!q.empty() && f1[q.back()] >= f1[i])
			q.pop_back();
		q.push_back(i);
	}
	
	return f1[n];
}

LL getans(int p, int a, int b, int fa)
{
	int len = 0;
	while(a != p) x[++len] = a, a = f[a][0];
	x[++len] = p;
	if(p != fa)
		x[++len] = fa, x[++len] = p;
	int t = len;
	while(b != p) x[++len] = b, b = f[b][0];
	reverse(x + t + 1, x + len + 1);
	
	return work(len);
}

int main()
{
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1, a, b; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	
	dfs(1, 0);
	S = log2(S);
	
	while(m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int p = lca(a, b);

		LL ans = getans(p, a, b, p);
		if(k == 3)
		{
			if(p != 1)
				ans = min(ans, getans(p, a, b, f[p][0]));
			for(int i = h[p]; i; i = ne[i])
				if(e[i] != a && e[i] != b)
					ans = min(ans, getans(p, a, b, e[i]));
		} 
		
		printf("%lld\n", ans);
	}
	return 0;
}

