#include <cstdio>

#define LL long long
#define uLL unsigned LL

LL rint() {
	LL x = 0, Fx = 1; char c = getchar();
	while (c < '0' || c > '9') { Fx ^= (c == '-'); c = getchar(); }
	while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	return Fx ? x : -x;
}

LL Abs(LL x) { return (x > 0) ? x : -x; }
LL Max(LL u, LL v) { return (u > v) ? u : v; }
LL Min(LL u, LL v) { return (u < v) ? u : v; }

const int inf = 0x3f3f3f3f;

const int MAX_n = 1e5;
const int MAX_m = 1e5;
const int MAX_q = 1e5;
const int mx = 1e5;

int n, m, q;
int A[MAX_n + 5];
int B[MAX_m + 5];

int vs[mx + 5];

int mxA1[MAX_n + 5][20];
int mnA1[MAX_n + 5][20];
int mxA2[MAX_n + 5][20];
int mnA2[MAX_n + 5][20];
int mxB[MAX_n + 5][20];
int mnB[MAX_n + 5][20];

int MxA1(int L, int R) {
	int k = vs[R - L + 1];
	return Max(mxA1[L][k], mxA1[R - (1 << k) + 1][k]);
}

int MnA1(int L, int R) {
	int k = vs[R - L + 1];
	return Min(mnA1[L][k], mnA1[R - (1 << k) + 1][k]);
}

int MxA2(int L, int R) {
	int k = vs[R - L + 1];
	return Max(mxA2[L][k], mxA2[R - (1 << k) + 1][k]);
}

int MnA2(int L, int R) {
	int k = vs[R - L + 1];
	return Min(mnA2[L][k], mnA2[R - (1 << k) + 1][k]);
}

int MxB(int L, int R) {
	int k = vs[R - L + 1];
	return Max(mxB[L][k], mxB[R - (1 << k) + 1][k]);
}

int MnB(int L, int R) {
	int k = vs[R - L + 1];
	return Min(mnB[L][k], mnB[R - (1 << k) + 1][k]);
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	vs[1] = 0;
	for (int i = 2; i <= mx; i++)
		vs[i] = vs[i >> 1] + 1;
	n = rint(), m = rint(), q = rint();
	for (int i = 1; i <= n; i++) A[i] = rint();
	for (int i = 1; i <= m; i++) B[i] = rint();
	for (int i = 1; i <= n; i++) {
		if (A[i] > 0) mxA1[i][0] = mnA1[i][0] = A[i], mxA2[i][0] = -inf;
		if (A[i] < 0) mxA2[i][0] = mnA2[i][0] = A[i], mnA1[i][0] = inf;
		A[i] = A[i - 1] + (A[i] == 0);
	}
	for (int j = 1; j <= 16; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			mxA1[i][j] = Max(mxA1[i][j - 1], mxA1[i + (1 << (j - 1))][j - 1]);
			mnA1[i][j] = Min(mnA1[i][j - 1], mnA1[i + (1 << (j - 1))][j - 1]);
			mxA2[i][j] = Max(mxA2[i][j - 1], mxA2[i + (1 << (j - 1))][j - 1]);
			mnA2[i][j] = Min(mnA2[i][j - 1], mnA2[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 1; i <= m; i++)
		mxB[i][0] = mnB[i][0] = B[i];
	for (int j = 1; j <= 16; j++) {
		for (int i = 1; i + (1 << j) - 1 <= m; i++) {
			mxB[i][j] = Max(mxB[i][j - 1], mxB[i + (1 << (j - 1))][j - 1]);
			mnB[i][j] = Min(mnB[i][j - 1], mnB[i + (1 << (j - 1))][j - 1]);
		}
	}
	LL res, Temp = (LL)inf * inf;
	int L1, R1, L2, R2;
	while (q--) {
		L1 = rint(), R1 = rint();
		L2 = rint(), R2 = rint();
		res = -Temp;
		if (A[R1] - A[L1 - 1]) res = Max(res, 0);
		if (MxA1(L1, R1)) res = Max(res, Max((LL)MxA1(L1, R1) * MnB(L2, R2), (LL)MnA1(L1, R1) * MnB(L2, R2)));
		if (MnA2(L1, R1)) res = Max(res, Max((LL)MxA2(L1, R1) * MxB(L2, R2), (LL)MnA2(L1, R1) * MxB(L2, R2)));
		printf("%lld\n", res);
	}
	return 0;
}

