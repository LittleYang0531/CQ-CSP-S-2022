#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2505,N = 2e4 + 5;
int Last[MAXN],End[N],Next[N],n,m,K,cnt,dis[MAXN];
void add(int x,int y)
{
	End[++cnt] = y;Next[cnt] = Last[x];Last[x] = cnt;
}
bool book[MAXN][MAXN];
ll val[MAXN],id[4][MAXN];
queue <int> Q;
void bfs(int x)
{
	Q.push(x);
	for(int i = 1;i <= n; i++)dis[i] = 0x3f3f3f3f;
	dis[x] = 0;
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for(int i = Last[x];i;i = Next[i])
		{
			int y = End[i];
			if(dis[y] == 0x3f3f3f3f)
				Q.push(y),dis[y] = dis[x] + 1;
		}
	}
	for(int i = 1;i <= n; i++)
		if(dis[i] <= K)
			book[x][i] = true;
}	
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d %d %d", &n, &m, &K);
	K++;
	for(int i = 2;i <= n; i++)scanf("%lld", &val[i]);
	for(int i = 1;i <= m; i++)
	{
		int x,y;
		scanf("%d %d", &x, &y);
		add(x,y),add(y,x);
	}
	for(int i = 1;i <= n; i++)bfs(i);
	for(int i = 2;i <= n; i++)
	{
		for(int j = 2;j <= n; j++)
		{
			if(i == j || !book[i][j] || !book[1][j])continue;
			if(val[j] > val[id[0][i]])
			{
				id[2][i] = id[1][i];
				id[1][i] = id[0][i];
				id[0][i] = j;
			}
			else if(val[j] > val[id[1][i]])
			{
				id[2][i] = id[1][i];
				id[1][i] = j;
			}
			else if(val[j] > val[id[2][i]])
				id[2][i] = j;
		}
	}
	ll maxn = 0;
	for(int i = 2;i <= n; i++)
		for(int j = i + 1;j <= n; j++)
		{
			if(!book[i][j])continue;
			for(int p1 = 0;p1 <= 2; p1++)
				for(int p2 = 0;p2 <= 2; p2++)
				{
					if(id[p1][i] == 0 || id[p2][j] == 0)continue;
					if(id[p1][i] != id[p2][j] && id[p1][i] != j && id[p2][j] != i)
						maxn = max(maxn,val[id[p1][i]] + val[id[p2][j]] + val[i] + val[j]);
				}
		}
	printf("%lld\n", maxn);
	return 0;
}
