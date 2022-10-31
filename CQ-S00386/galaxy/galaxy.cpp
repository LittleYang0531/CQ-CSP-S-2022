#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;
map <pair<int,int>,bool> M;
int f[MAXN],d1[MAXN],d2[MAXN];
bool book[MAXN];
vector <int> V[MAXN],E[MAXN];
int find(int x)
{
	if(x == f[x])return x;
	return f[x] = find(f[x]);
}
void merge(int x,int y)
{
	x = find(x),y = find(y);
	if(x != y)f[x] = y,book[y] = book[x] || book[y];
	else book[x] = true;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= m; i++)
	{
		int x,y;
		scanf("%d %d", &x, &y);
		V[x].push_back(y);
		E[y].push_back(x);
		d1[x]++,d2[y]++;
		M[make_pair(x,y)] = true;
	}
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int t,u,v;
		scanf("%d", &t);
		if(t == 1)
		{
			scanf("%d %d", &u, &v);
			d1[u]--,d2[v]++;
			M[make_pair(u,v)] = false;
		}
		else if(t == 2)
		{
			int x;
			scanf("%d", &x);
			for(int y : E[x])
			{
				if(M[make_pair(y,x)])
				{
					M[make_pair(y,x)] = false;
					d1[y]--,d2[x]++;
				}
			}
		}
		else if(t == 3)
		{
			scanf("%d %d", &u, &v);
			d1[u]++,d2[v]--;
			M[make_pair(u,v)] = true;
		}
		else
		{
			int x;
			scanf("%d", &x);
			for(int y : E[x])
			{
				if(!M[make_pair(y,x)])
				{
					M[make_pair(y,x)] = true;
					d1[y]++,d2[x]--;
				}
			}
		}
		for(int i = 1;i <= n; i++)f[i] = i,book[i] = false;
		for(int i = 1;i <= n; i++)
		{
			if(d1[i] == 1 && d2[i] == 1)
			for(int x : V[i])
				if(d1[x] == 1 && d2[x] == 1 && M[make_pair(i,x)])
					merge(i,x);
		}
		for(int i = 1;i <= n; i++)
			if(d1[i] == 1)
			{
				for(int x : V[i])
					if(M[make_pair(i,x)])
						merge(x,i);
			}	
		int tot = 0;
		for(int i = 1;i <= n; i++)
			tot += (i == find(i));
		if(tot == 1 && book[find(1)] == true)puts("YES");
		else puts("NO");
	}
	return 0;
}

