#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 2505
#define LL long long
#define DB double
#define ENDL putchar('\n')
#define lowbit(x) (-(x) & (x))
#define FI first
#define SE second
LL read() {
	LL f=1,x=0;int s = getchar();
	while(s < '0' || s > '9') {if(s<0)return -1;if(s=='-')f=-f;s=getchar();}
	while(s >= '0' && s <= '9') {x=(x<<1)+(x<<3)+(s^48);s = getchar();}
	return f*x;
}
void putpos(LL x) {if(!x) return ;putpos(x/10);putchar((x%10)^48);}
void putnum(LL x) {
	if(!x) {putchar('0');return ;}
	if(x<0) {putchar('-');x=-x;}
	return putpos(x);
}
void AIput(LL x,int c) {putnum(x);putchar(c);}

int n,m,s,o,k;
LL a[MAXN];
int hd[MAXN],nx[20005],v[20005],cne;
void ins(int x,int y) {
	nx[++ cne] = hd[x]; v[cne] = y; hd[x] = cne;
}
int g[MAXN][MAXN];
bool f[MAXN];
void bfs(int S,int *dp) {
	for(int i = 1;i <= n;i ++) f[i] = 0,dp[i] = 0x3f3f3f3f;
	dp[S] = 0; f[S] = 1; queue<int> b; b.push(S);
	while(!b.empty()) {
		int t = b.front(); b.pop();
		if(dp[t] >= k) continue;
		for(int i = hd[t];i;i = nx[i]) {
			if(!f[v[i]]) {
				f[v[i]] = 1; dp[v[i]] = dp[t] + 1;
				b.push(v[i]);
			}
		}
	} return ;
}
int h1[MAXN],h2[MAXN],h3[MAXN];
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n = read(); m = read(); k = read() + 1;
	a[0] = -1e18;
	for(int i = 2;i <= n;i ++) a[i] = read();
	for(int i = 1;i <= m;i ++) {
		s = read();o = read(); ins(s,o); ins(o,s);
	}
	for(int i = 1;i <= n;i ++) bfs(i,g[i]);
	for(int i = 2;i <= n;i ++) {
		for(int j = 2;j <= n;j ++) {
			if(j == i || g[j][1] > k || g[i][j] > k) continue;
			if(a[j] > a[h3[i]]) h3[i] = j;
			if(a[h3[i]] > a[h2[i]]) swap(h3[i],h2[i]);
			if(a[h2[i]] > a[h1[i]]) swap(h2[i],h1[i]);
		}
	}
	LL ans = 0;
	for(int i = 2;i <= n;i ++) {
		for(int j = i+1;j <= n;j ++) {
			if(g[i][j] > k) continue;
			int a1 = (h1[i] == j ? h2[i]:h1[i]),a2 = (h1[i]==j || h2[i]==j ? h3[i]:h2[i]);
			int b1 = (h1[j] == i ? h2[j]:h1[j]),b2 = (h1[j]==i || h2[j]==i ? h3[j]:h2[j]);
			if(a1 != b1) {if(a1&&b1) ans = max(ans,a[i] + a[j] + a[a1] + a[b1]);}
			else {
				if(a1 && b2) ans = max(ans,a[i] + a[j] + a[a1] + a[b2]);
				if(a2 && b1) ans = max(ans,a[i] + a[j] + a[a2] + a[b1]);
			}
		}
	}
	AIput(ans,'\n');
	return 0;
}