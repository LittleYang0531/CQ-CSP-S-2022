#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 1e3*2.5+5;
const int M = 1e4+5;
const int K = 1e2+5;
ll score[N], f[N][5], ans, vis[N][7];
bool flag;
int dian, r, dis[N][N], choose[N];

int main()
{
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	memset(dis, 127,sizeof dis);
	for(int i=2; i<=n; i++)
		scanf("%lld", &score[i]);
	score[0] = 0;
	int u, v;
	while(m --)
	{
		scanf("%d%d", &u, &v);
		dis[u][v] = dis[v][u] = 0;
	}
	
	//floyd跑两遍 O(2n^3)
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if(i == j)
				continue;
			for(int p=1; p<=n; p++)
				if(dis[i][p] <= 3500 && dis[p][j] <= 3500)
					dis[i][j] = min(dis[i][j], dis[i][p] + dis[p][j] + 1);
		}
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if(i == j)
				continue;
			for(int p=1; p<=n; p++)
				if(dis[i][p] <= 3500 && dis[p][j] <= 3500)
					dis[i][j] = min(dis[i][j], dis[i][p] + dis[p][j] + 1);
		}
	
	//暴力找点 O(n^2) + O(n^3)
//	for(int i=2; i<=n; i++)//i做第三景点 
//		for(int j=2; j<=n; j++)
//			if(dis[i][j] <= k && dis[j][1] <= k && score[j] > score[choose[i]])
//				choose[i] = j;
//	
//	for(int i=2; i<=n; i++)//第一景点 
//		for(int j=2; j<=n; j++)//第二景点 
//			for(int l=2; l<=n; l++)
//			{
//				if(i == j || i == l || i == choose[l] || j == l || j == choose[l])
//					continue;
//				if(dis[1][i] <= k && dis[i][j] <= k && dis[j][l] <= k && choose[l] && ans < score[i] + score[j] + score[l] + score[choose[l]])
//					ans = score[i] + score[j] + score[l] + score[choose[l]];
//			}
	
	//dp?找点 O(n) +  O(16n^2)
	for(int i=2; i<=n; i++)
		if(dis[i][1] <= k)
			f[i][4] = score[i], vis[i][4] = 1;
		else
			f[i][4] = -1;
	
	for(int p=3; p>0; p--)
	{
		for(int i=2; i<=n; i++)
		{
			f[i][p] = -1;
			for(int j=2; j<=n; j++)
			{
				flag = 0, dian = j, r = p+1;
				while(r <= 4)
				{
					if(vis[dian][r] == i) {
						flag = 1;
						break;
					}
					dian = vis[dian][r];
					r ++;
				}
				
				if(flag)
					continue;
				
				if(dis[i][j] <= k && f[j][p+1] > 0 && score[i] + f[j][p+1] > f[i][p])
					f[i][p] = score[i] + f[j][p+1], vis[i][p] = j;
			}
		}
	}
	
	for(int i=2; i<=n; i++)
		if(dis[1][i] <= k)
			ans = max(ans, f[i][1]);
	
//	for(int i=1; i<=n; i++)
//		for(int j=1; j<=4; j++)
//			printf("%d %d: %lld %d\n", i, j, f[i][j], vis[i][j]);
				
	printf("%lld\n", ans);
	
	return 0;
}
/*
2s
5 <= n <= 2500
1 <= m <= 10000
0 <= k <= 100
1 <= si <= 10^18 
*/
/*

8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4
*/
