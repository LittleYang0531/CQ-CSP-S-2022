#include<bits/stdc++.h>
#define inlint inline int
#define inloid inline void
#define inbool inline bool
#define MAXN 100005
#define JZP fclose(stdin),
#define AK fclose(stdout),
#define I 0
#define INF 1000000001
#define ll long long
#define int long long
using namespace std;

namespace _MAIN {
	inlint read() {
		register int nega = 1, num = 0, c = getchar();
		for(;~c && !isdigit(c); c = getchar()) if(c == '-') nega = -1;
		for(;~c &&  isdigit(c); c = getchar()) (num *= 10) += c - '0';
		return nega * num;
	}
	int n, m, q;
} using namespace _MAIN;

namespace _SOLV {
	struct _tup {
		int psx, ngx, psn, ngn, mxx, mnn;
		_tup (int a = -INF, int b = -INF, int c = INF, int d = INF, int e = -INF, int f = INF) {
			psx = a, ngx = b, psn = c, ngn = d, mxx = e, mnn = f;
		}
	};
	struct _segt {
		int nums[MAXN], psmx[MAXN << 2], ngmx[MAXN << 2], psmn[MAXN << 2], ngmn[MAXN << 2], mx[MAXN << 2], mn[MAXN << 2]; // all literal values
		inloid pushUp(int cu) {
			psmx[cu] = max(psmx[cu * 2], psmx[cu * 2 + 1]),
			ngmx[cu] = max(ngmx[cu * 2], ngmx[cu * 2 + 1]),
			psmn[cu] = min(psmn[cu * 2], psmn[cu * 2 + 1]),
			ngmn[cu] = min(ngmn[cu * 2], ngmn[cu * 2 + 1]),
			mx[cu] = max(mx[cu * 2], mx[cu * 2 + 1]),
			mn[cu] = min(mn[cu * 2], mn[cu * 2 + 1]);
		}
		inloid build(int cu, int L, int R) {
			psmx[cu] = -INF, ngmx[cu] = -INF, psmn[cu] = INF, ngmn[cu] = INF, mx[cu] = -INF, mn[cu] = -INF;
			if(L == R) {
				if(nums[L] >= 0) psmx[cu] = psmn[cu] = nums[L];
				if(nums[L] <= 0) ngmx[cu] = ngmn[cu] = nums[L];
				mx[cu] = mn[cu] = nums[L];
				return;
			}
			int mid = (L + R) >> 1;
			build(cu * 2, L, mid), build(cu * 2 + 1, mid + 1, R), pushUp(cu);
		}
		_tup ask(int cu, int cuL, int cuR, int L, int R) {
			if(cuL >= L && cuR <= R) return _tup(psmx[cu], ngmx[cu], psmn[cu], ngmn[cu], mx[cu], mn[cu]);
			int mid = (cuL + cuR) >> 1;
			_tup lt, rt;
			if(L <= mid) lt = ask(cu * 2, cuL, mid, L, R);
			if(mid < R) rt = ask(cu * 2 + 1, mid + 1, cuR, L, R);
			return _tup(
			max(lt.psx, rt.psx), max(lt.ngx, rt.ngx), min(lt.psn, rt.psn), min(lt.ngn, rt.ngn), max(lt.mxx, rt.mxx), min(lt.mnn, rt.mnn)
			);
		}
	} A, B;
	inline long long ask(_tup a, _tup b) {
		int rea, reb;
		if(a.mnn >= 0) {
			if(b.mnn >= 0) rea = a.psx, reb = b.psn;
			else if(b.mxx <= 0) rea = a.psn, reb = b.ngn;
			else rea = a.psn, reb = b.ngn;
		} else if(a.mxx <= 0) {
			if(b.mnn >= 0) rea = a.ngx, reb = b.psx;
			else if(b.mxx <= 0) rea = a.ngn, reb = b.ngx;
			else rea = a.ngx, reb = b.psx;
		} else {
			if(b.mnn >= 0) rea = a.psx, reb = b.psn;
			else if(b.mxx <= 0) rea = a.ngn, reb = b.ngx;
			else {
				if((ll)a.psn * (ll)b.ngn >= (ll)a.ngx * (ll)b.psx) rea = a.psn, reb = b.ngn;
				else rea = a.ngx, reb = b.psx; 
			}
		}
		return (long long)rea * reb;
	}
} using namespace _SOLV;

signed main(void) {
//	freopen(R"(E:\CSP-S\game\game4.in)", "r", stdin), freopen(R"(E:\CSP-S\game\game4.out)", "w", stdout);
	freopen("game.in", "r", stdin), freopen("game.out", "w", stdout);
	n = read(), m = read(), q = read();
	for(int i = 1; i <= n; i++) A.nums[i] = read();
	for(int i = 1; i <= m; i++) B.nums[i] = read();
	A.build(1, 1, n), B.build(1, 1, m);
	for(int i = 1; i <= q; i++) {
		int l1 = read(), r1 = read(), l2 = read(), r2 = read();
		cout << ask(A.ask(1, 1, n, l1, r1), B.ask(1, 1, m, l2, r2)) << "\n";
	}
	return JZP AK I;
}

