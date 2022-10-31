#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cd[500005], rd[500005];
map<pair<int,int>, int> mp;
struct node {
	int to, next;
} e[500005];
int h[500005], cnt;
bool cz[500005];
void add(int x, int y) {
	if(!mp[ {x, y}]) {
		e[++cnt].to=y;
		e[cnt].next=h[x];
		cz[cnt]=1;
		h[x]=cnt;
		mp[ {x, y}]=cnt;
	}
}
int n, m, q;
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1, x, y; i<=m; ++i) {
		scanf("%d%d", &x, &y);
		cd[x]++;
		rd[y]++;
		add(y, x); //·´Ïò½¨±ß
	}
	int ok=0, bj=0;
	for(int i=1; i<=n; ++i) {
		if(cd[i]==1) ok++;
		if(!cd[i]) bj=1;
	}
	scanf("%d", &q);
	if(bj){
		while(q--){
			puts("NO");
		}
		return 0;
	}
	for(int tt=1; tt<=q; ++tt){
		int op, a, b;
		scanf("%d", &op);
		if(op==1) {
			scanf("%d%d", &a, &b);
//			if(!cz[mp[{b, a}]]) continue;
			cz[mp[ {b, a}]]=0;
			if(cd[a]==1) ok--;
			cd[a]--;
			if(cd[a]==1) ok++;
		} else if(op==2) {
			scanf("%d", &a);
			for(int i=h[a]; i; i=e[i].next) {
				if(!cz[i]) continue;
				cz[i]=0;
				int y=e[i].to;
				if(cd[y]==1) ok--;
				cd[y]--;
				if(cd[y]==1) ok++;
			}
		} else if(op==3) {
			scanf("%d%d", &a, &b);
//			if(cz[mp[{b, a}]]) continue;
			cz[mp[ {b, a}]]=1;
			if(cd[a]==1) ok--;
			cd[a]++;
			if(cd[a]==1) ok++;
		} else {
			scanf("%d", &a);
			for(int i=h[a]; i; i=e[i].next) {
				if(cz[i]) continue;
				cz[i]=1;
				int y=e[i].to;
				if(cd[y]==1) ok--;
				cd[y]++;
				if(cd[y]==1) ok++;
			}
		}
//		printf("==%d\n", tt);
//		printf("%d %d %d\n", op, a, b);
//		printf("%lld\n", ok);
//		for(int i=1; i<=n; ++i){
//			printf("%d ", cd[i]);
//		}
//		putchar('\n');
		if(ok==n) puts("YES");
		else puts("NO");
	}
	return 0;
}

