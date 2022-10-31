// Fight For the ASoul Kingdom.
#include <cstdio>

typedef long long LL;
LL Abs (LL x) { return x < 0 ? -x : x; }
LL Max (LL x, LL y) { return x > y ? x : y; }
LL Min (LL x, LL y) { return x < y ? x : y; }

int Read () {
	int x = 0, k = 1;
	char s = getchar ();
	while (s < '0' || s > '9') {
		if (s == '-')
			k = -1;
		s = getchar ();
	}
	while ('0' <= s && s <= '9')
		x = (x << 3) + (x << 1) + (s ^ 48), s = getchar ();
	return x * k;
}

void Write (LL x) {
	if (x < 0)
		putchar ('-'), x = -x;
	if (x > 9)
		Write (x / 10);
	putchar (x % 10 + '0');
}

void Print (LL x, char s) { Write (x), putchar (s); }

const int Inf = 1e9 + 1;
const int Maxn = 1e5 + 5;
const LL InfLL = 1e18 + 5;

int a[Maxn][4], Sum[Maxn][2];

struct Segment_Tree {
	struct Node {
#define Lson p << 1
#define Rson p << 1 | 1
		int Mi, Ma;
		Node () {}
		Node (int X, int Y) { Mi = X, Ma = Y; }
	} Tr[Maxn << 2]; 
	
	void Pull (int p) { Tr[p].Ma = Max (Tr[Lson].Ma, Tr[Rson].Ma), Tr[p].Mi = Min (Tr[Lson].Mi, Tr[Rson].Mi); }
	
	void Make_Tree (int p, int L, int R, int Opt) {
		if (L == R) {
			Tr[p].Mi = Tr[p].Ma = a[L][Opt];
			return ;
		}
		int Mid = (L + R) >> 1;
		Make_Tree (Lson, L, Mid, Opt), Make_Tree (Rson, Mid + 1, R, Opt);
		Pull (p);
	}
	
	int Query_Min (int p, int l, int r, int L, int R) {
		if (l <= L && R <= r)
			return Tr[p].Mi;
		int Mid = (L + R) >> 1, Res = Inf;
		if (l <= Mid)
			Res = Min (Res, Query_Min (Lson, l, r, L, Mid));
		if (r > Mid)
			Res = Min (Res, Query_Min (Rson, l, r, Mid + 1, R));
		return Res;
	}
	
	int Query_Max (int p, int l, int r, int L, int R) {
		if (l <= L && R <= r)
			return Tr[p].Ma;
		int Mid = (L + R) >> 1, Res = -Inf;
		if (l <= Mid)
			Res = Max (Res, Query_Max (Lson, l, r, L, Mid));
		if (r > Mid)
			Res = Max (Res, Query_Max (Rson, l, r, Mid + 1, R));
		return Res;
	}
} Tree[4];

int main () {
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);
	int n = Read (), m = Read (), q = Read ();
	for (int i = 1; i <= n; i++) {
		a[i][0] = Read (), Sum[i][0] = Sum[i - 1][0] + (a[i][0] > 0);
		if (a[i][0] > 0)
			a[i][1] = a[i][0], a[i][2] = -Inf;
		else
			a[i][1] = Inf, a[i][2] = a[i][0];
	}
	for (int i = 0; i <= 2; i++)
		Tree[i].Make_Tree (1, 1, n, i);
	for (int i = 1; i <= m; i++) 
		a[i][3] = Read (), Sum[i][1] = Sum[i - 1][1] + (a[i][3] > 0);
	Tree[3].Make_Tree (1, 1, m, 3);
	for (int i = 1, L1, R1, L2, R2; i <= q; i++) {
		L1 = Read (), R1 = Read (), L2 = Read (), R2 = Read ();
		if (Sum[R2][1] - Sum[L2 - 1][1] == R2 - L2 + 1) {
//			printf ("Cindy %d %d\n", (LL)Tree[0].Query_Max (1, L1, R1, 1, n), Tree[3].Query_Min (1, L2, R2, 1, m));
			if (Sum[R1][0] - Sum[L1 - 1][0] == 0)
				Print ((LL)Tree[0].Query_Max (1, L1, R1, 1, n) * Tree[3].Query_Max (1, L2, R2, 1, m), '\n');
			else
				Print ((LL)Tree[0].Query_Max (1, L1, R1, 1, n) * Tree[3].Query_Min (1, L2, R2, 1, m), '\n');
		}
		else if (Sum[R2][1] - Sum[L2 - 1][1] == 0) {	
			if (Sum[R1][0] - Sum[L1 - 1][0] == R1 - L1 + 1)
				Print ((LL)Tree[0].Query_Min (1, L1, R1, 1, n) * Tree[3].Query_Min (1, L2, R2, 1, m), '\n');
			else
				Print ((LL)Tree[0].Query_Min (1, L1, R1, 1, n) * Tree[3].Query_Max (1, L2, R2, 1, m), '\n');			
		}
		else {
			if (Sum[R1][0] - Sum[L1 - 1][0] == R1 - L1 + 1)
				Print ((LL)Tree[0].Query_Min (1, L1, R1, 1, n) * Tree[3].Query_Min (1, L2, R2, 1, m), '\n');
			else if (Sum[R1][0] - Sum[L1 - 1][0] == 0)
				Print ((LL)Tree[0].Query_Max (1, L1, R1, 1, n) * Tree[3].Query_Max (1, L2, R2, 1, m), '\n');
			else {
				LL Res = -InfLL;
				Res = Max (Res, (LL)Tree[1].Query_Min (1, L1, R1, 1, n) * Tree[3].Query_Min (1, L2, R2, 1, m));
				Res = Max (Res, (LL)Tree[2].Query_Max (1, L1, R1, 1, n) * Tree[3].Query_Max (1, L2, R2, 1, m));
				Print (Res, '\n');
			}
		}
	}
	return 0;
}
