#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;
int n, m, q;
int a[N], b[N];//不难得到，2个人选的数都一定是正数/负数中的极值
int f[2][2][2][N][20];//a/b，大/小，正(非负)/负，st表

void get_st(int a[], int n, int v)
{
	memset(f[v][0], 0x3f, sizeof(f[v][0]));
	memset(f[v][1], -0x3f, sizeof(f[v][1]));
	
	for(int k = 0; k <= 1; k++)
		for(int t = 0; t <= 1; t++)
		{
			for(int i = 1; i <= n; i++)
			{
				if(t == 0 && a[i] < 0)
					f[v][k][t][i][0] = a[i];
				if(t == 1 && a[i] >= 0)
					f[v][k][t][i][0] = a[i];
			}
			for(int j = 1; j <= 17; j++)
				for(int i = 1; i + (1 << j) - 1 <= n; i++)
				{
					if(k == 0)
						f[v][k][t][i][j] = min(f[v][k][t][i][j - 1], f[v][k][t][i + (1 << j - 1)][j - 1]);
					if(k == 1)
						f[v][k][t][i][j] = max(f[v][k][t][i][j - 1], f[v][k][t][i + (1 << j - 1)][j - 1]);
				}
		}
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	
	get_st(a, n, 0);
	get_st(b, m, 1);
	
	while(q--)
	{
		LL ans = -1e18;
		
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		int len1 = log2(r1 - l1 + 1), len2 = log2(r2 - l2 + 1);
		
		int a, b;
		for(int i = 0; i <= 1; i++)
			for(int j = 0; j <= 1; j++)
			{
				if(i == 0)
					a = min(f[0][i][j][l1][len1], f[0][i][j][r1 - (1 << len1) + 1][len1]);
				else
					a = max(f[0][i][j][l1][len1], f[0][i][j][r1 - (1 << len1) + 1][len1]);
				if(!(-1e9 <= a && a <= 1e9))//是一个合法的值
					continue;
				
				LL res = 1e18;	
				for(int k = 0; k <= 1; k++)
					for(int t = 0; t <= 1; t++)
					{
						if(k == 0)
							b = min(f[1][k][t][l2][len2], f[1][k][t][r2 - (1 << len2) + 1][len2]);
						else
							b = max(f[1][k][t][l2][len2], f[1][k][t][r2 - (1 << len2) + 1][len2]);
						if(!(-1e9 <= b && b <= 1e9))//是一个合法的值
							continue;
						res = min(res, 1ll * a * b);
					}
				ans = max(ans, res);
			}
		
		printf("%lld\n", ans);		
	}
	return 0;
}

