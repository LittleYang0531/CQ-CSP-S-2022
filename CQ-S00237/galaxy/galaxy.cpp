#include<bits/stdc++.h>
using namespace std;

const int N = 1e5*5+5;
int f, n, m, id, head[N], outdegree[N];
bool vd[N], vb[N];

struct Edge{
	int ne, to;
}eg[N];

void add(int u, int v)
{
	eg[++id].to = v;
	eg[id].ne = head[u];
	head[u] = id;
}

//void tarjan(int u, int last)

int main()
{
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	int op, u, v, q;
	scanf("%d%d", &n, &m);
	while(m --)
	{
		scanf("%d%d", &u, &v);
		add(u, v);
		outdegree[u] ++;
	}
	
	scanf("%d", &q);
	while(q --)
	{
		f = 0;
//		init();
		scanf("%d%d", &op, &u);
		if(op == 1)
		{
			scanf("%d", &v);
			for(int i=head[u]; i; i=eg[i].ne)
				if(eg[i].to == v)
					vb[i] = 1, outdegree[u] --;
		}
		else if(op == 2)
		{
			vd[u] = 1;
			for(int i=1; i<=n; i++)
			{
				if(i == u)
					continue;
				for(int j=head[i]; j; j=eg[j].ne)
					if(eg[j].to == v)
						vb[j] = 1, outdegree[i] --;
			}
		}
		else if(op == 3)
		{
			scanf("%d", &v);
			for(int i=head[u]; i; i=eg[i].ne)
				if(eg[i].to == v)
					vb[i] = 0, outdegree[u] ++;
		}
		else
		{
			vd[u] = 0;
			for(int i=1; i<=n; i++)
			{
				if(i == u)
					continue;
				for(int j=head[i]; j; j=eg[j].ne)
					if(eg[j].to == v)
						vb[j] = 0, outdegree[i] ++;
			}
		}
		
		for(int i=1; i<=n; i++)
			if(outdegree[i] != 1)
			{
				printf("NO\n");
				f = 0;
				break;
			}
		
		if(f == 0)
			continue;
		printf("YES\n");
		
//		for(int i=1; i<=n; i++)
//			if(vis[i] == 0)
//				tarjan();
	}
	
	return 0;
}

/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2

NO
NO
YES
NO
YES
NO
NO
NO
YES
NO
NO

*/
