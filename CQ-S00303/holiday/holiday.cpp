#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define ll long long
#define N 2505
using namespace std;
template<class T>void read(T&x) {
	T f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
template<class T>void write(T x) {
	if(x<0)putchar('-'),x=-x;int s[20],top=0;
	while(s[++top]=x%10,x/=10);
	while(top)putchar(s[top--]+'0');
}
template<class T,class...Ts>void write(T arg,Ts...args){write(arg);putchar(' ');write(args...);}
template<class...Ts>void print(Ts...args){write(args...);putchar('\n');}
void cer(){cerr << '\n';}
template<class T,class...Ts>void cer(T arg,Ts...args){cerr << arg << ' ';cer(args...);}
namespace MAIN{
char _st;
int n,m,K,d[N][N],tag[N];
vector<int>e[N];
ll w[N];
void getdis(int s,int *d) {
	for(int i=1; i<=n; ++i)d[i] = 1e9;
	queue<int>q;q.push(s);d[s] = 0;
	while(!q.empty()) {
		int x = q.front();q.pop();
		for(int y:e[x])if(d[y] == 1e9)d[y] = d[x]+1,q.push(y);
	}
}
struct val{ll v;int p;};
struct node{val mx1,mx2,mx3;}f[N];
bool operator > (const val &x,const val&y){return x.v > y.v;}
void update(node &x,val y) {
	if(y > x.mx1)x.mx3 = x.mx2,x.mx2 = x.mx1,x.mx1 = y;
	else if(y > x.mx2)x.mx3 = x.mx2,x.mx2 = y;
	else if(y > x.mx3)x.mx3 = y;
}
void upd(ll &ans,val u,val v,int i,int j) {
	if(u.v == -1 || v.v == -1)return;
	if(u.p == v.p || u.p == i || u.p == j || v.p == i || v.p == j)return;
	ans = max(ans,u.v+v.v);
}
char _ed;
int main() {
	cer("Memory:",(&_st-&_ed)>>20);
	file("holiday");
	read(n);read(m);read(K);K++;
	for(int i=2; i<=n; ++i)read(w[i]);
	for(int i=1,x,y; i<=m; ++i)read(x),read(y),e[x].push_back(y),e[y].push_back(x);
	for(int i=1; i<=n; ++i)getdis(i,d[i]);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
	for(int i=1; i<=n; ++i)f[i].mx1.v = f[i].mx2.v = f[i].mx3.v = -1;
	for(int i=2; i<=n; ++i)if(d[1][i] <= K)
		for(int j=2; j<=n; ++j)if(i != j && d[i][j] <= K)
			update(f[j],{w[i]+w[j],i});
	ll ans = 0;
	for(int i=2; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)if(d[i][j] <= K) {
			upd(ans,f[i].mx1,f[j].mx1,i,j);
			upd(ans,f[i].mx1,f[j].mx2,i,j);
			upd(ans,f[i].mx1,f[j].mx3,i,j);
			upd(ans,f[i].mx2,f[j].mx1,i,j);
			upd(ans,f[i].mx2,f[j].mx2,i,j);
			upd(ans,f[i].mx2,f[j].mx3,i,j);
			upd(ans,f[i].mx3,f[j].mx1,i,j);
			upd(ans,f[i].mx3,f[j].mx2,i,j);
			upd(ans,f[i].mx3,f[j].mx3,i,j);
		}
	print(ans);
	return 0;
}
}
int main(){return MAIN::main();}
