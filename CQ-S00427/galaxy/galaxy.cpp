//可以反击 <--> 所有点的出度为1 
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

const int N = 5e5 + 10;
int n, m, q;
int du[N], res;//出度不为1的个数 

vector<PII> e[N];
int get(int x, int y)
{
	int l = 0, r = e[x].size() - 1;
	while(l < r) 
	{
		int mid = l + r >> 1;
		if(e[x][mid].first < y) l = mid + 1;
		else r = mid;
	}
	return l;
}

int main()
{
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	
	cin >> n >> m;
	while(m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		e[b].push_back({a, 1});//直接存反图
		du[a]++;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(du[i] != 1) res++;
		sort(e[i].begin(), e[i].end());
	}
	
	cin >> q;
	while(q--)
	{
		int op, a, b;
		scanf("%d%d", &op, &a);
		
		if(op == 1)
		{
			scanf("%d", &b);
			e[b][get(b, a)].second = 0;
			if(--du[a] == 1) res--;
			else if(du[a] == 0) res++;
		}
		if(op == 2)
		{
			for(int i = 0; i < e[a].size(); i++)
				if(e[a][i].second == 1)
				{
					e[a][i].second = 0;
					int t = e[a][i].first;	
					if(--du[t] == 1) res--;
					else if(du[t] == 0) res++;
				}
		}
		if(op == 3)
		{
			scanf("%d", &b);
			e[b][get(b, a)].second = 1;
			if(++du[a] == 1) res--;
			else if(du[a] == 2) res++;
		}
		if(op == 4)
		{
			for(int i = 0; i < e[a].size(); i++)
				if(e[a][i].second == 0)
				{
					e[a][i].second = 1;
					int t = e[a][i].first;	
					if(++du[t] == 1) res--;
					else if(du[t] == 2) res++;
				}
		}
		
		if(res) puts("NO");
		else puts("YES");
	}
	return 0;
}

