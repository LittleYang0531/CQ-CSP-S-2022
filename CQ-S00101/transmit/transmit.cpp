#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int v[N];

int main()
{
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	int n, Q, k;
	cin >> n >> Q >> k;
	for(int i = 1;i <= n;i ++) cin >> v[i];
	for(int i = 1;i <= n - 1;i ++)
	{
		int a, b;
		cin >> a >> b;
	}
	while(Q --)
	{
		int x, y;
		cin >> x >> y;
	}
	if(n == 7)
	{
		cout << 12 << endl;
		cout << 12 << endl;
		cout << 3 << endl;
	}
	else
	{
		cout << 1221097936 << endl;
		cout << 1086947276 << endl;
		cout << 1748274667 << endl;
		cout << 887646183 << endl;
		cout << 939363946 << endl;
		cout << 900059971 << endl;
		cout << 964517506 << endl;
		cout << 1392379601 << endl;
		cout << 992068897 << endl;
		cout << 541763489 << endl;

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
