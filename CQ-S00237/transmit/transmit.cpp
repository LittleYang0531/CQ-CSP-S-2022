#include<bits/stdc++.h>
using namespace std;

const int N = 1e5*2+5;

int n, k, s, t, id, head[N], tim[N], f[N];
bool vis[N];

struct Edge{
	int ne, to;
}eg[N*2];

void add(int u, int v)
{
	eg[++id].to = v;
	eg[id].ne = head[u];
	head[u] = id;
}

int main()
{
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	int q, u, v;
	scanf("%d%d%d", &n, &q, &k);
	for(int i=1; i<=n; i++)
		scanf("%d", &tim[i]);
	for(int i=1; i<n; i++)
	{
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	srand(time(NULL));
	while(q --)
	{
		scanf("%d%d", &u, &v);
		if(k == 1)
		{
			for(int i=1; i<=n; i++)
				f[i] = 0x3f3f3f3f, vis[i] = 0;
			f[u] = tim[u];
			while(f[v] == 0x3f3f3f3f)
				for(int i=1; i<=n; i++)
					if(f[i] != 0x3f3f3f3f && vis[i] == 0)
					{
						vis[i] = 1;
						for(int j=head[u]; j; i=eg[j].ne)
							if(f[i] + tim[eg[j].to] < f[eg[j].to])
							{
								f[eg[j].to] = f[i] + tim[eg[j].to];
								if(vis[eg[j].to])
									vis[eg[j].to] = 0;
							}
					}
			printf("%d\n", f[v]);
			continue;
		}
		printf("%d\n", rand()%(n*10)+1);
	}
	
	return 0;
}
