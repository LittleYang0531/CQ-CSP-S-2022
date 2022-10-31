#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
const int M = 19;

int n, m, q, l, r, s, t;
int a[N], b[N], Log_[N];
int Larmax[N][M][2], Larmin[N][M][2], Lesmax[N][M][2], Lesmin[N][M][2];
vector<long long> U, D;

void init() {
	for (int i = 1; i <= n; i ++) {
		if (a[i] > 0) {
			Larmax[i][0][0] = Larmin[i][0][0] = a[i];
			Lesmax[i][0][0] = -2e9, Lesmin[i][0][0] = 2e9;
		}
		else {
			Lesmax[i][0][0] = Lesmin[i][0][0] = a[i];
			Larmax[i][0][0] = -2e9, Larmin[i][0][0] = 2e9;
		}
	}
	
	for (int i = 1; i <= m; i ++) {
		if (b[i] > 0) {
			Larmax[i][0][1] = Larmin[i][0][1] = b[i];
			Lesmax[i][0][1] = -2e9, Lesmin[i][0][1] = 2e9;
		}
		else {
			Lesmax[i][0][1] = Lesmin[i][0][1] = b[i];
			Larmax[i][0][1] = -2e9, Larmin[i][0][1] = 2e9;
		}
	}
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	for (int i = 2; i < N; i ++) Log_[i] = Log_[i / 2] + 1;
	
	scanf("%d%d%d", &n, &m, &q);
	
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i ++) scanf("%d", &b[i]);
	
	init();
	
	for (int i = 1; (1 << i) <= n; i ++)
		for (int j = 1; j + (1 << i) - 1 <= n; j ++)
			Larmax[j][i][0] = max(Larmax[j][i - 1][0], Larmax[j + (1 << (i - 1))][i - 1][0]);
	for (int i = 1; (1 << i) <= n; i ++)
		for (int j = 1; j + (1 << i) - 1 <= n; j ++)
			Lesmax[j][i][0] = max(Lesmax[j][i - 1][0], Lesmax[j + (1 << (i - 1))][i - 1][0]);
	for (int i = 1; (1 << i) <= n; i ++)
		for (int j = 1; j + (1 << i) - 1 <= n; j ++)
			Larmin[j][i][0] = min(Larmin[j][i - 1][0], Larmin[j + (1 << (i - 1))][i - 1][0]);
	for (int i = 1; (1 << i) <= n; i ++)
		for (int j = 1; j + (1 << i) - 1 <= n; j ++)
			Lesmin[j][i][0] = min(Lesmin[j][i - 1][0], Lesmin[j + (1 << (i - 1))][i - 1][0]);
	
	for (int i = 1; (1 << i) <= m; i ++)
		for (int j = 1; j + (1 << i) - 1 <= m; j ++)
			Larmax[j][i][1] = max(Larmax[j][i - 1][1], Larmax[j + (1 << (i - 1))][i - 1][1]);
	for (int i = 1; (1 << i) <= m; i ++)
		for (int j = 1; j + (1 << i) - 1 <= m; j ++)
			Lesmax[j][i][1] = max(Lesmax[j][i - 1][1], Lesmax[j + (1 << (i - 1))][i - 1][1]);
	for (int i = 1; (1 << i) <= m; i ++)
		for (int j = 1; j + (1 << i) - 1 <= m; j ++)
			Larmin[j][i][1] = min(Larmin[j][i - 1][1], Larmin[j + (1 << (i - 1))][i - 1][1]);
	for (int i = 1; (1 << i) <= m; i ++)
		for (int j = 1; j + (1 << i) - 1 <= m; j ++)
			Lesmin[j][i][1] = min(Lesmin[j][i - 1][1], Lesmin[j + (1 << (i - 1))][i - 1][1]);
	
	while (q --) {
		U.clear(), D.clear();
		scanf("%d%d%d%d", &l, &r, &s, &t);
		int LarMa = max(Larmax[l][Log_[r - l + 1]][0], Larmax[r - (1 << Log_[r - l + 1]) + 1][Log_[r - l + 1]][0]);
		if (LarMa != -2e9) U.push_back(LarMa);
		int LesMa = max(Lesmax[l][Log_[r - l + 1]][0], Lesmax[r - (1 << Log_[r - l + 1]) + 1][Log_[r - l + 1]][0]);
		if (LesMa != -2e9) U.push_back(LesMa);
		int LarMi = min(Larmin[l][Log_[r - l + 1]][0], Larmin[r - (1 << Log_[r - l + 1]) + 1][Log_[r - l + 1]][0]);
		if (LarMi != 2e9) U.push_back(LarMi);
		int LesMi = min(Lesmin[l][Log_[r - l + 1]][0], Lesmin[r - (1 << Log_[r - l + 1]) + 1][Log_[r - l + 1]][0]);
		if (LesMi != 2e9) U.push_back(LesMi);
		LarMa = max(Larmax[s][Log_[t - s + 1]][1], Larmax[t - (1 << Log_[t - s + 1]) + 1][Log_[t - s + 1]][1]);
		if (LarMa != -2e9) D.push_back(LarMa);
		LesMa = max(Lesmax[s][Log_[t - s + 1]][1], Lesmax[t - (1 << Log_[t - s + 1]) + 1][Log_[t - s + 1]][1]);
		if (LesMa != -2e9) D.push_back(LesMa);
		LarMi = min(Larmin[s][Log_[t - s + 1]][1], Larmin[t - (1 << Log_[t - s + 1]) + 1][Log_[t - s + 1]][1]);
		if (LarMi != 2e9) D.push_back(LarMi);
		LesMi = min(Lesmin[s][Log_[t - s + 1]][1], Lesmin[t - (1 << Log_[t - s + 1]) + 1][Log_[t - s + 1]][1]);
		if (LesMi != 2e9) D.push_back(LesMi);
		
		long long ans = -4e18;
		for (int i = 0; i < U.size(); i ++) {
			long long h;
			if (U[i] <= 0) {
				h = -2e9;
				for (int j = 0; j < D.size(); j ++) h = max(h, D[j]);
			}
			else {
				h = 2e9;
				for (int j = 0; j < D.size(); j ++) h = min(h, D[j]);
			}
			ans = max(ans, U[i] * h);
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
