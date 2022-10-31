#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 10,INF = 1e9 + 10;
int n,m,q;
int arr[N],brr[N];
bool f1 = true,f2 = true;

struct node{
	int l;
	int r;
	int Max;
	int Min;
}tr1[N << 1],tr2[N << 1];

int read(){
	int r = 0,w = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		r = r * 10 + c - '0';
		c = getchar();
	}
	return r * w;
}

void pushup1(int u){
	tr1[u].Max = max(tr1[u << 1].Max,tr1[u << 1 | 1].Max);
	tr1[u].Min = min(tr1[u << 1].Min,tr1[u << 1 | 1].Min);
}

void pushup2(int u){
	tr2[u].Max = max(tr2[u << 1].Max,tr2[u << 1 | 1].Max);
	tr2[u].Min = min(tr2[u << 1].Min,tr2[u << 1 | 1].Min);
}

void build1(int u,int l,int r){
	tr1[u] = {l,r,-INF,INF};
	if (l == r){
		tr1[u].Max = tr1[u].Min = arr[l];
		return;
	}
	int mid = l + r >> 1;
	build1(u << 1,l,mid);
	build1(u << 1 | 1,mid + 1,r);
	pushup1(u);
}

void build2(int u,int l,int r){
	tr2[u] = {l,r,-INF,INF};
	if (l == r){
		tr2[u].Max = tr2[u].Min = brr[l];
		return;
	}
	int mid = l + r >> 1;
	build2(u << 1,l,mid);
	build2(u << 1 | 1,mid + 1,r);
	pushup2(u);
}

int query1(int u,int l,int r,bool falg){
	if (l <= tr1[u].l && tr1[u].r <= r){
		if (falg) return tr1[u].Max;
		return tr1[u].Min;
	}
	int mid = tr1[u].l + tr1[u].r >> 1;
	int res;
	if (falg){
		res = -INF;
		if (l <= mid) res = max(res,query1(u << 1,l,r,falg));
		if (r > mid) res = max(res,query1(u << 1 | 1,l,r,falg));
	}
	else{
		res = INF;
		if (l <= mid) res = min(res,query1(u << 1,l,r,falg));
		if (r > mid) res = min(res,query1(u << 1 | 1,l,r,falg));
	}
	return res;
}

int query2(int u,int l,int r,bool falg){
	if (l <= tr2[u].l && tr2[u].r <= r){
		if (falg) return tr2[u].Max;
		return tr2[u].Min;
	}
	int mid = tr2[u].l + tr2[u].r >> 1;
	int res;
	if (falg){
		res = -INF;
		if (l <= mid) res = max(res,query2(u << 1,l,r,falg));
		if (r > mid) res = max(res,query2(u << 1 | 1,l,r,falg));
	}
	else{
		res = INF;
		if (l <= mid) res = min(res,query2(u << 1,l,r,falg));
		if (r > mid) res = min(res,query2(u << 1 | 1,l,r,falg));
	}
	return res;
}

signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n = read();
	m = read();
	q = read();
	for (int i = 1;i <= n;i++){
		arr[i] = read();
		if (arr[i] < 0) f1 = false;
	}
	for (int i = 1;i <= m;i++){
		brr[i] = read();
		if (brr[i] < 0) f2 = false;
	}
	if (f1 && f2){
		build1(1,1,n);
		build2(1,1,m);
		while (q--){
			int l1,r1,l2,r2;
			l1 = read();
			r1 = read();
			l2 = read();
			r2 = read();
			if (f1 && f2){
				int Max = query1(1,l1,r1,true);
				int Min = query2(1,l2,r2,false);
				printf("%lld\n",Max * Min);
			}
		}
	}
	else{
		build1(1,1,n);
		build2(1,1,m);
		while (q--){
			int l1,r1,l2,r2;
			l1 = read();
			r1 = read();
			l2 = read();
			r2 = read();
			if (l1 == r1){
				int x = arr[l1];
				if (x){
					int Min = query2(1,l2,r2,false);
					printf("%lld\n",Min * x);
				}
				else printf("0\n");
			}
			else if (l2 == r2){
				int x = brr[l2];
				if (x < 0){
					int Min = query1(1,l1,r1,false);
					printf("%lld\n",Min * x);
				}
				else if (x > 0){
					int Max = query1(1,l1,r1,true);
					printf("%lld\n",Max * x);
				}
				else printf("0");
			}
			else printf("%lld\n",query1(1,l1,r1,true) * query2(1,l2,r2,false));
		}
	}
	return 0;
}

/*
5 4 3
1 2 3 4 5
5 4 2 3
1 3 2 3
1 4 2 2
1 5 3 4

3 3 3
1 2 -3 
-1 -2 1
1 1 2 3
1 2 2 2
1 3 1 1
*/
