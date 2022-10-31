#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int to, next;
}e[400005];
int h[200005], cnt;
void add(int x, int y){
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
int a[200005];
int fa[200005], dep[200005], f[200005][25];
ll s[200005][25];
int n;
void ST() {
	memset(f, -1, sizeof(f));
	memset(s, 0, sizeof(s));
	for(int i=1; i<=n; ++i) {
		f[i][0]=fa[i];
		s[i][0]=a[i];
//		cout << f[i][0] << " ";
	}
//	cout << endl;
	for(int j=1; j<=20; ++j) {
		for(int i=1; i<=n; ++i) {
			if(f[i][j-1]!=-1) {
				f[i][j]=f[f[i][j-1]][j-1];
				s[i][j]=s[i][j-1]+s[f[i][j-1]][j-1];
			}
		}
	}
}
ll LCA(int x, int y) {
	if(dep[x]<dep[y]) swap(x, y);
//	printf("%d %d\n", x, y);
	ll ans=0;
	for(int j=20; j>=0; --j) {
		if(f[x][j]!=-1&&dep[f[x][j]]>=dep[y]) {
			ans+=s[x][j];
			x=f[x][j];
//			printf("%d %d\n", x, y);
		}
	}
//	printf("%d %d\n", x, y);
	if(x==y) return ans+a[x];
	for(int j=20; j>=0; --j) {
		if(f[x][j]!=-1&&f[x][j]!=f[y][j]) {
			ans+=s[x][j]+s[y][j];
			x=f[x][j], y=f[y][j];
		}
	}
//	printf("%d %d\n", x, y);
	ans+=s[x][0]+s[y][0];
	x=f[x][0], y=f[y][0];
//	printf("%d %d\n", x, y);
//	printf("%lld\n", ans);
	return ans+a[x];
}
void dfs(int x, int ff, int deep){
	dep[x]=deep;
	for(int i=h[x]; i; i=e[i].next){
		int y=e[i].to;
		if(y==ff) continue;
		fa[y]=x;
		dfs(y, x, deep+1);
	}
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	int Q, k;
	scanf("%d%d%d", &n, &Q, &k);
	for(int i=1; i<=n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i=1, x, y; i<n; ++i){
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
//	puts("OK");
	fa[0]=-1;
	dfs(1, 0, 1);
	ST();
	for(int tt=1, x, y; tt<=Q; ++tt){
		scanf("%d%d", &x, &y);
		printf("%lld\n", LCA(x, y));
	}
	return 0;
}

