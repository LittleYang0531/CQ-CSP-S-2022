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
inline int Max(int a,int b) {return a>b ? a:b;}
inline int Min(int a,int b) {return a<b ? a:b;}
int a[MAXN];
int mx[MAXN<<2],mn[MAXN<<2];
int bmx[MAXN<<2],bmn[MAXN<<2];
int M;
void maketree(int n) {
	M=1;while(M<n+2) M<<=1;
	for(int i = 1;i <= n;i ++) {
		mx[M+i] = mn[M+i] = a[i];
		bmx[M+i] = (a[i] <= 0 ? a[i]:-0x3f3f3f3f);
		bmn[M+i] = (a[i] >= 0 ? a[i]:0x3f3f3f3f);
	}
	for(int i = M-1;i > 0;i --) {
		mx[i] = Max(mx[i<<1],mx[i<<1|1]);
		mn[i] = Min(mn[i<<1],mn[i<<1|1]);
		bmx[i] = Max(bmx[i<<1],bmx[i<<1|1]);
		bmn[i] = Min(bmn[i<<1],bmn[i<<1|1]);
	}
}
int findmax(int *tre,int l,int r) {
	int ans = -0x3f3f3f3f; if(l>r) return ans;
	for(int s=M+l-1,t=M+r+1;(s>>1)^(t>>1);s>>=1,t>>=1) {
		if(!(s&1)) ans = Max(ans,tre[s^1]);
		if(t & 1) ans = Max(ans,tre[t^1]);
	} return ans;
}
int findmin(int *tre,int l,int r) {
	int ans = 0x3f3f3f3f; if(l>r) return ans;
	for(int s=M+l-1,t=M+r+1;(s>>1)^(t>>1);s>>=1,t>>=1) {
		if(!(s&1)) ans = Min(ans,tre[s^1]);
		if(t & 1) ans = Min(ans,tre[t^1]);
	} return ans;
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n = read(); m = read(); int Q = read();
	for(int i = 1;i <= n+m;i ++) {
		a[i] = read();
	}
	maketree(n+m);
	for(int i = 1;i <= Q;i ++) {
		s = read();o = read();
		int ll = read()+n,rr = read()+n;
		int nl = findmin(mn,ll,rr),nr = findmax(mx,ll,rr);
		int nm[4] = {findmax(mx,s,o),findmax(bmx,s,o),findmin(mn,s,o),findmin(bmn,s,o)};
		LL ans = -2e18;
		for(int j = 0;j < 4;j ++) {
			if(nm[j] >= -1e9 && nm[j] <= 1e9) {
				ans = max(ans,min(nm[j]*1ll*nl,nm[j]*1ll*nr));
			}
		}
		AIput(ans,'\n');
	}
	return 0;
}