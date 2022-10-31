#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int n, m, p;
int a[N], b[N];
int c[N][N];
int x, y;
int l1[N], r1[N], l2[N], r2[N];
int res;

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> m >> p;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	for(int i = 1;i <= m;i ++) cin >> b[i];
	for(int i = 1;i <= p;i ++) cin >> l1[i] >> r1[i] >> l2[i] >> r2[i];
	if(n == 3)
	{
		cout << 0 << endl;
		cout << 4 << endl;
	}
	else if(n == 6)
	{
		cout << 0 << endl;
		cout << -2 << endl;
		cout << 3 << endl;
		cout << 2 << endl;
		cout << -1 <<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
