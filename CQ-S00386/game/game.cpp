#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
ll a[MAXN],b[MAXN],Max[4][22][MAXN],Min[4][22][MAXN];
int n,m,Log[MAXN];
void init()
{
	for(int k = 0;k <= 2; k++)
		for(int j = 0;j <= 20; j++)
			for(int i = 1;i <= max(n,m); i++)
			{
				Max[k][j][i] = -2e9;
				Min[k][j][i] = 2e9;
			}
	for(int i = 1;i <= n; i++)if(a[i] >= 0)Max[0][0][i] = Min[0][0][i] = a[i];
	for(int i = 1;i <= n; i++)if(a[i] <= 0)Max[1][0][i] = Min[1][0][i] = a[i];
	for(int i = 1;i <= m; i++)Max[2][0][i] = Min[2][0][i] = b[i];
	for(int k = 0;k <= 2; k++)
	{
		for(int j = 1;j <= 20; j++)
			for(int i = 1;i <= max(n,m) - (1 << j) + 1; i++)
			{
				Max[k][j][i] = max(Max[k][j - 1][i],Max[k][j - 1][i + (1 << (j - 1))]);
				Min[k][j][i] = min(Min[k][j - 1][i],Min[k][j - 1][i + (1 << (j - 1))]);
			}
	}
}
ll getMax(int k,int x,int y)
{
	int len = Log[y - x + 1];
	return max(Max[k][len][x],Max[k][len][y - (1 << len) + 1]);
}
ll getMin(int k,int x,int y)
{
	int len = Log[y - x + 1];
	return min(Min[k][len][x],Min[k][len][y - (1 << len) + 1]);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int q;
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1;i <= n; i++)scanf("%lld", &a[i]);
	for(int i = 1;i <= m; i++)scanf("%lld", &b[i]);
	init();
	for(int i = 2;i <= max(n,m); i++)Log[i] = Log[i >> 1] + 1;
	while(q--)
	{
		int A,B,C,D;
		scanf("%d %d %d %d", &A, &B, &C, &D);
		ll maxn = -1e18;
		if(getMin(2,C,D) > 0 && getMax(0,A,B) != -2e9)maxn = max(maxn,getMin(2,C,D) * getMax(0,A,B));
		else if(getMin(0,A,B) != 2e9)maxn = max(maxn,getMin(2,C,D) * getMin(0,A,B));
		if(getMax(2,C,D) > 0 && getMax(1,A,B) != -2e9)maxn = max(maxn,getMax(2,C,D) * getMax(1,A,B));
		else if(getMin(1,A,B) != 2e9)maxn = max(maxn,getMax(2,C,D) * getMin(1,A,B));
		printf("%lld\n", maxn);
	}
	return 0;
}

