#include <bits/stdc++.h>
#define inf 1000000007
using namespace std;
int n, m, q, l1, l2, r1, r2;
struct qwq {
	int fm, fx, zm, zx;
	void fst() {
		fm=inf, fx=-inf, zm=inf, zx=-inf;
	}
};
inline qwq upd(qwq X, qwq Y) {
	X.fm=min(X.fm, Y.fm);
	X.fx=max(X.fx, Y.fx);
	X.zm=min(X.zm, Y.zm);
	X.zx=max(X.zx, Y.zx);
	return X;
}
struct haha/*linetree*/ {
	int x[100005], pd[2][100005];
	qwq tree[2000006];
	void build(int l, int r, int k) {
		tree[k].fst();
		if(l == r) {
			if(x[l] < 0)
				tree[k].fm=tree[k].fx=x[l];
			else
				if(x[l] > 0)
					tree[k].zm=tree[k].zx=x[l];
				else
					tree[k].fm=tree[k].fx=tree[k].zm=tree[k].zx=x[l];
			return ;
		}
		int mid=(l+r)/2;
		build(l, mid, k*2);
		build(mid+1, r, k*2+1);
		tree[k]=upd(tree[k*2], tree[k*2+1]);
	}
	qwq find(int l, int r, int lq, int rq, int k) {
		if(lq <= l && r <= rq) 
			return tree[k];
		qwq ret;
		ret.fst();
		int mid = (l+r)/2;
		if(mid >= lq) ret=upd(ret, find(l, mid, lq, rq, k*2));
		if(mid+1 <= rq) ret=upd(ret, find(mid+1, r, lq, rq, k*2+1));
		return ret;
	}
}A, B;
inline void read(int &x) {
	x=0; int f = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') f=-1; c=getchar(); }
	while(c <= '9' && c >= '0') x=(x<<1)+(x<<3)+(c^48), c=getchar();
	x*=f;
}
char ot[45];
int len;
inline void print(long long x) {
	len=0; if(x < 0) x=-x, putchar('-');
	do{ ot[++len]=x%10, x/=10; } while(x);
	while(len) putchar(ot[len]+'0'), --len;
	putchar('\n');//!!!
} 
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n), read(m), read(q);
	for(int i = 1; i <= n; ++i) {
		read(A.x[i]);
		A.pd[0][i]=A.pd[0][i-1];
		A.pd[1][i]=A.pd[1][i-1];
		if(A.x[i] < 0) ++A.pd[0][i];
		else if(A.x[i] > 0) ++A.pd[1][i];
		else  ++A.pd[0][i], ++A.pd[1][i];
	}
	for(int i = 1; i <= m; ++i) {
		read(B.x[i]);
		B.pd[0][i]=B.pd[0][i-1];
		B.pd[1][i]=B.pd[1][i-1];
		if(B.x[i] < 0) ++B.pd[0][i];
		else if(B.x[i] > 0) ++B.pd[1][i];
		else ++B.pd[0][i], ++B.pd[1][i];
	}
	A.build(1, n, 1);
	B.build(1, m, 1);
	for(int i =1; i <= q; ++i) {
		read(l1), read(r1), read(l2), read(r2);
		int a=A.pd[0][r1]-A.pd[0][l1-1], 
		b=A.pd[1][r1]-A.pd[1][l1-1],
		c=B.pd[0][r2]-B.pd[0][l2-1],
		d=B.pd[1][r2]-B.pd[1][l2-1];
//		cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
		qwq e = A.find(1, n, l1, r1, 1);
//		cout<<e.fm<<" "<<e.fx<<" "<<e.zm<<" "<<e.zx<<"\n";
		qwq f = B.find(1, m, l2, r2, 1);
//		cout<<f.fm<<" "<<f.fx<<" "<<f.zm<<" "<<f.zx<<"!!!\n";
		if(a && b) {
			if(c && d)
				print(max(1LL*e.fx*f.zx, 1LL*e.zm*f.fm));
			else {
				if(c)
					print(max(1LL*e.fm*f.fx, 1LL*e.zm*f.fm));
				else
					print(max(1LL*e.fx*f.zx, 1LL*e.zx*f.zm));
			}
		}
		else {
			if(a){
				if(c && d)
					print(1LL*e.fx*f.zx);
				else {
					if(c)
						print(1LL*e.fm*f.fx);
					else
						print(1LL*e.fx*f.zx);
				}
			}
			else {
				if(c && d)
					print(1LL*e.zm*f.fm);
				else {
					if(c)
						print(1LL*e.zm*f.fm);
					else
						print(1LL*e.zx*f.zm);
				}
			}
		}
	}
	return 0;
} 
