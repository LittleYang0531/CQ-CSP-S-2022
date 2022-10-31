#include <cstdio>
#include <algorithm>

using namespace std;

#define LL long long
#define rep(i, j, k) for(int i = (j); i <= (k); i ++)
#define per(i, j, k) for(int i = (j); i >= (k); i --)

const int Maxn = 1e5;
const int INF = 0x3f3f3f3f;

int n, m, q;
int a[Maxn + 5], b[Maxn + 5];

void Readint (int &x) {
	x = 0; int f = 1; char c = getchar ();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1; c = getchar ();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar ();
	}
	x *= f;
}

struct Segment_Tree {
	struct Node {
		int l, r;
		int maxn, minn, flag0;
		int Fmaxn, Fflag;
		int Zminn, Zflag;
		#define l(x) t[x].l
		#define r(x) t[x].r
		#define maxn(x) t[x].maxn
		#define Fmaxn(x) t[x].Fmaxn
		#define minn(x) t[x].minn
		#define Zminn(x) t[x].Zminn
		#define flag0(x) t[x].flag0
		#define Fflag(x) t[x].Fflag
		#define Zflag(x) t[x].Zflag
	} t[Maxn * 4 + 5];
	
	void Pushup (int u) {
		maxn (u) = max (maxn (u << 1), maxn (u << 1 | 1));
		minn (u) = min (minn (u << 1), minn (u << 1 | 1));
		Zminn (u) = min (Zminn (u << 1), Zminn (u << 1 | 1));
		Fmaxn (u) = max (Fmaxn (u << 1), Fmaxn (u << 1 | 1));
		flag0 (u) = flag0 (u << 1) | flag0 (u << 1 | 1);
		Zflag (u) = Zflag (u << 1) | Zflag (u << 1 | 1);
		Fflag (u) = Fflag (u << 1) | Fflag (u << 1 | 1);
//		printf ("%d %d %d %d\n", maxn (u), Fmaxn (u), minn (u), Zminn (u));
	}
	
	void Build (int p, int l, int r) {
		l (p) = l, r (p) = r;
		maxn (p) = Fmaxn (p) = -INF;
		minn (p) = Zminn (p) = INF;
		if (l == r) return ;
		int mid = (l + r) >> 1;
		Build (p << 1, l, mid);
		Build (p << 1 | 1, mid + 1, r);
	}
	
	void Update (int p, int u, int C) {
		if (l (p) == r (p)) {
//			printf ("(%d) %d  %d\n", p, l (p), C);
			maxn (p) = minn (p) = C;
			flag0 (p) = (C == 0);
			Zflag (p) = (C > 0), Fflag (p) = (C < 0);
			Zminn (p) = C > 0 ? C : INF;
			Fmaxn (p) = C < 0 ? C : -INF;
			return ;
		}
		int mid = (l (p) + r (p)) >> 1;
		if (u <= mid) Update (p << 1, u, C);
		else Update (p << 1 | 1, u, C);
		Pushup (p);
	}
	
	int Valuemax (int u, int op) {
		if (op == 1) return maxn (u);
		return Fmaxn (u);
	}
	int Valuemin (int u, int op) {
		if (op == 1) return minn (u);
		return Zminn (u);
	}
	int Valueflag (int u, int op) {
		if (op == 1) return flag0 (u);
		else if (op == 2) return Zflag (u);
		return Fflag (u);
	}
	
	int Querymax (int p, int ql, int qr, int op) {
		if (ql <= l (p) && r (p) <= qr) {
			return Valuemax (p, op);
		}
		int mid = (l (p) + r (p)) >> 1, ret = -INF;
		if (ql <= mid) ret = max (ret, Querymax (p << 1, ql, qr, op));
		if (qr > mid) ret = max (ret, Querymax (p << 1 | 1, ql, qr, op));
		return ret;
	}
	
	int Querymin (int p, int ql, int qr, int op) {
		if (ql <= l (p) && r (p) <= qr) {
			return Valuemin (p, op);
		}
		int mid = (l (p) + r (p)) >> 1, ret = INF;
		if (ql <= mid) ret = min (ret, Querymin (p << 1, ql, qr, op));
		if (qr > mid) ret = min (ret, Querymin (p << 1 | 1, ql, qr, op));
		return ret;
	}
	
	int Queryflag (int p, int ql, int qr, int op) {
		if (ql <= l (p) && r (p) <= qr) {
			return Valueflag (p, op);
		}
		int mid = (l (p) + r (p)) >> 1, ret = 0;
		if (ql <= mid) ret |= Queryflag (p << 1, ql, qr, op);
		if (qr > mid) ret |= Queryflag (p << 1 | 1, ql, qr, op);
		return ret;
	}
} A, B; 

int main () {
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);
	
	Readint (n), Readint (m), Readint (q);
	
	A.Build (1, 1, n);
	B.Build (1, 1, m); 
	rep (i, 1, n) {
		Readint (a[i]);
		A.Update (1, i, a[i]);
	}
	rep (i, 1, m) {
		Readint (b[i]);
		B.Update (1, i, b[i]);
	}
	
//	printf ("%d %d %d\n", A.Queryflag (1, 1, n, 1), A.Queryflag (1, 1, n, 2), A.Queryflag (1, 1, n, 3));
	
//	rep (i, 1, n) {
//		rep (j, 1, m) {
//			printf ("%3d ", a[i] * b[j]);
//		}
//		printf ("\n");
//	}
	
	rep (i, 1, q) {
//		printf ("%d : ", i);
		int la, ra, lb, rb;
		Readint (la), Readint (ra), Readint (lb), Readint (rb);
		int flag0 = B.Queryflag (1, lb, rb, 1);
		int Zflag = B.Queryflag (1, lb, rb, 2);
		int Fflag = B.Queryflag (1, lb, rb, 3);
		if (flag0 && Zflag && Fflag) {
			int flag0 = A.Queryflag (1, la, ra, 1);
			if (flag0) printf ("0\n");
			else {
				int xa = A.Querymax (1, la, ra, 2); //fmax  fmax * Bzmax
				int xb = A.Querymin (1, la, ra, 2); //Zmin  Zmin * Bfmin
				int ya = B.Querymax (1, lb, rb, 1);
				int yb = B.Querymin (1, lb, rb, 1);
//				printf ("---- %d %d %d %d\n", xa, xb, ya, yb);
				printf ("%lld\n", max (1ll * xa * ya, 1ll * xb * yb));
			}
		} else if (flag0 && Zflag) {
			int x = A.Querymax (1, la, ra, 1), y;
			if (x >= 0) {
				printf ("0\n");
			} else {
				y = B.Querymax (1, lb, rb, 1); //zmax
				printf ("%lld\n", 1ll * x * y);
			}
		} else if (flag0 && Fflag) {
			int x = A.Querymin (1, la, ra, 1), y;
			if (x > 0) {
				y = B.Querymin (1, lb, rb, 1); //fmin
				printf ("%lld\n", 1ll * x * y);
			} else {
				printf ("0\n");
			}
		} else if (Zflag && Fflag) {
			int flag0 = A.Queryflag (1, la, ra, 1);
			if (flag0) printf ("0\n");
			else {
				int xa = A.Querymax (1, la, ra, 2); //fmax  fmax * Bzmax
				int xb = A.Querymin (1, la, ra, 2); //Zmin  Zmin * Bfmin
				int ya = B.Querymax (1, lb, rb, 1);
				int yb = B.Querymin (1, lb, rb, 1);
//				printf ("---- %d %d %d %d\n", xa, xb, ya, yb);
				printf ("%lld\n", max (1ll * xa * ya, 1ll * xb * yb));
			}
		} else if (flag0) {
			printf ("0\n");
		} else if (Zflag) {
			int x = A.Querymax (1, la, ra, 1), y;
			if (x > 0) {
				y = B.Querymin (1, lb, rb, 1); //zmin
				printf ("%lld\n", 1ll * x * y);
			} else if (x == 0) {
				printf ("0\n");
			} else {
				y = B.Querymax (1, lb, rb, 1); //zmax
				printf ("%lld\n", 1ll * x * y);
			}
		} else if (Fflag) {
			int x = A.Querymin (1, la, ra, 1), y;
			if (x > 0) {
				y = B.Querymin (1, lb, rb, 1); //fmin
				printf ("%lld\n", 1ll * x * y);
			} else if (x == 0) {
				printf ("0\n");
			} else {
				y = B.Querymax (1, lb, rb, 1); //fmax
				printf ("%lld\n", 1ll * x * y);
			}
		}
//		printf ("\n");
	}
	return 0;
}

