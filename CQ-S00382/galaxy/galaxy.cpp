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
#define MAXN 500005
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
#define getchar() xchar()
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

int tmp[MAXN];
int dom[MAXN];
int ind[MAXN],to[MAXN],el[MAXN],er[MAXN],dl[MAXN],dr[MAXN];
vector<int> ex[MAXN],ma[MAXN];
vector<int> g[MAXN],G[MAXN];
map<int,int> mp[MAXN];
vector<pair<int,int> > Inc[MAXN],Dec[MAXN];
bool op[MAXN];

int mx[MAXN<<3],mn[MAXN<<3],lz[MAXN<<3],M;
void upd(int s) {mx[s] = Max(mx[s<<1],mx[s<<1|1])+lz[s];mn[s] = Min(mn[s<<1],mn[s<<1|1])+lz[s];}
void maketree(int n) {M=1;while(M<n+2)M<<=1;}
void addp(int x,int y) {
	int s=M+x; lz[s] += y; mx[s] += y; mn[s] += y; s >>= 1;
	while(s) upd(s),s >>= 1;
}
void addtree(int l,int r,int y) {
	if(l > r) return ;
	for(int s=M+l-1,t=M+r+1;s||t;s>>=1,t>>=1) {
		if(s<M) upd(s),upd(t);
		if((s>>1) ^ (t>>1)) {
			if(!(s&1)) mx[s^1] += y,mn[s^1] += y,lz[s^1] += y;
			if(t & 1) mx[t^1] += y,mn[t^1] += y,lz[t^1] += y;
		}
	} return ;
}
int F(int x) {
	int s=M+x,as=mx[s]; s>>=1;
	while(s) as += lz[s],s >>= 1;
	return as;
}
bool OK(int l,int r) {
	int al=-0x3f3f3f3f,ar=-0x3f3f3f3f;
	int bl=0x3f3f3f3f,br=0x3f3f3f3f;
	for(int s=M+l-1,t=M+r+1;s||t;s>>=1,t>>=1) {
		al += lz[s];bl += lz[s];
		ar += lz[t];br += lz[t];
		if((s>>1) ^ (t>>1)) {
			if(!(s&1)) al = Max(al,mx[s^1]),bl = Min(bl,mn[s^1]);
			if(t & 1) ar = Max(ar,mx[t^1]),br = Min(br,mn[t^1]);
		}
	}
	al = Max(al,ar); bl = Min(bl,br);
	// cerr<<"l: "<<bl<<"  r: "<<al<<endl;
	return al == bl && al == 1;
}
void addcen(int x,int y) {
	addtree(el[x],er[x],y);
	// cerr<<"("<<el[x]<<" "<<er[x]<<")"<<endl;
	addtree(dl[x],dr[x],y);
	// cerr<<"add "<<dl[x]<<" "<<dr[x]<<" -- "<<y<<endl;
	for(int p:ex[x]) addp(to[p],y);//,cerr<<"addp "<<to[p]<<" "<<y<<endl;
	// OK(1,n);
	return ;
}
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n = read(); m = read();
	for(int i = 1;i <= m;i ++) {
		s = read();o = read();
		G[s].push_back(o);
		g[o].push_back(s); ind[o] ++;
	}
	ind[0] = -1;
	for(int i = 1;i <= n;i ++) {
		dom[i] = 0;
		for(int y:G[i]) if(ind[y] > ind[dom[i]]) dom[i] = y;
		if(dom[i])ma[dom[i]].push_back(i);
		for(int y:G[i]) if(y != dom[i]) ex[y].push_back(i);
	}
	int cnt = 0;
	for(int i = 1;i <= n;i ++) {
		dl[i] = cnt + 1;
		for(int y:ma[i]) to[y] = ++ cnt;
		dr[i] = cnt;
	}
	cnt = n;
	for(int i = 1;i <= n;i ++) {
		el[i] = cnt + 1;
		for(int y:g[i]) mp[i][y] = ++ cnt;
		er[i] = cnt;
	}
	maketree(n+m);
	for(int i = 1;i <= n;i ++) {
		addcen(i,1); op[i] = 1;
	}
	// OK(1,n);
	int Q = read();
	while(Q --) {
		k = read();
		if(k == 1) {
			s = read();o = read();
			int ei = mp[o][s];
			addp(ei,-1); addp(to[s],-1);
			Inc[o].push_back({ei,to[s]});
		}
		else if(k == 3) {
			s = read();o = read();
			int ei = mp[o][s];
			addp(ei,1); addp(to[s],1);
			Dec[o].push_back({ei,to[s]});
		}
		else if(k == 2) {
			s = read();
			for(auto &x:Inc[s]) addp(x.FI,1),addp(x.SE,1);
			for(auto &x:Dec[s]) addp(x.FI,-1),addp(x.SE,-1);
			Inc[s].clear(); Dec[s].clear();
			if(op[s]) addcen(s,-1),op[s] = 0;
		}
		else {
			s = read();
			for(auto &x:Inc[s]) addp(x.FI,1),addp(x.SE,1);
			for(auto &x:Dec[s]) addp(x.FI,-1),addp(x.SE,-1);
			Inc[s].clear(); Dec[s].clear();
			if(!op[s]) addcen(s,1),op[s] = 1;
		}
		printf(OK(1,n) ? "YES\n":"NO\n");
	}
	return 0;
}