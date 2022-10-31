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
#define MAXN 200005
#define LL long long
#define DB double
#define ENDL putchar('\n')
#define lowbit(x) (-(x) & (x))
#define FI first
#define SE second
inline int xchar() {
	static const int maxn = 1000000;
	static char b[maxn];
	static int pos = 0,len = 0;
	if(pos == len) pos = 0,len = fread(b,1,maxn,stdin);
	if(pos == len) return -1;
	return b[pos ++];
}
// #define getchar() xchar()
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
inline LL Max(LL a,LL b) {return a>b ? a:b;}
inline LL Min(LL a,LL b) {return a<b ? a:b;}
struct mat{
	LL s[3][3];
	int n,m;
	mat(){n=m=0;s[0][1]=s[0][2]=s[0][0]=s[1][1]=s[1][2]=s[1][0]=s[2][1]=s[2][2]=s[2][0]=1e18;}
}t1[MAXN][20],t2[MAXN][20],nm1,nm0;
mat bui(int x) {
	mat a; a.n = a.m = k;
	for(int i = 0;i < k;i ++) a.s[i][0] = x;
	for(int i = 1;i < k;i ++) a.s[i-1][i] = 0;
	return a;
}
mat operator * (mat a,mat b) {
	mat c; c.n=a.n;c.m=b.m;
	for(int i = 0;i < a.n;i ++) {
		for(int k = 0;k < a.m;k ++) {
			for(int j = 0;j < b.m;j ++) {
				c.s[i][j] = Min(c.s[i][j],a.s[i][k]+b.s[k][j]);
			}
		}
	} return c;
}
vector<int> g[MAXN];
int a[MAXN];
int f[MAXN][20],d[MAXN];
void dfs0(int x,int ff) {
	d[x] = d[f[x][0] = ff] + 1;
	if(ff) t1[x][0] = bui(a[ff]);
	else t1[x][0] = nm0;
	t2[x][0] = bui(a[x]);
	for(int i = 1;i <= 18;i ++) {
		f[x][i] = f[f[x][i-1]][i-1];
		t1[x][i] = t1[x][i-1] * t1[f[x][i-1]][i-1];
		t2[x][i] = t2[f[x][i-1]][i-1] * t2[x][i-1];
	}
	for(int y:g[x]) {
		if(y != ff) dfs0(y,x);
	} return ;
}
mat lca(int a,int b) {
	mat l = nm1,r = nm1;
	if(d[a] > d[b]) {
		for(int i = 18;i >= 0;i --) {
			if(d[f[a][i]] >= d[b]) l = l*t1[a][i],a = f[a][i];
		}
	}
	if(d[b] > d[a]) {
		for(int i = 18;i >= 0;i --) {
			if(d[f[b][i]] >= d[a]) r = t2[b][i]*r,b = f[b][i];
		}
	}
	if(a == b) return l*r;
	for(int i = 18;i >= 0;i --) {
		if(f[a][i]^f[b][i]) {
			l = l*t1[a][i];a = f[a][i];
			r = t2[b][i]*r;b = f[b][i];
		}
	} return l*t1[a][0]*t2[b][0]*r;
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n = read();m = read();k = read();
	nm1 = mat();
	nm1.n = nm1.m = k;nm0 = nm1;
	for(int i = 0;i < k;i ++) nm1.s[i][i] = 0;
	for(int i = 1;i <= n;i ++) {
		a[i] = read();
	}
	for(int i = 1;i < n;i ++) {
		s = read();o = read();
		g[s].push_back(o);
		g[o].push_back(s);
	}
	dfs0(1,0);
	while(m --) {
		s = read();o = read();
		mat me; me.n = 1;me.m = k;
		me.s[0][0] = a[s];
		me = me * lca(s,o);
		AIput(me.s[0][0],'\n');
	}
	return 0;
}