#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define ll long long
#define N 100005
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
int n,m,q,a[N],b[N],a1[N],a2[N];
const int inf = 1e9+1;
struct Tree {
	int mx[N<<2],mn[N<<2];
	void pushup(int v){mx[v] = max(mx[v<<1],mx[v<<1|1]);mn[v] = min(mn[v<<1],mn[v<<1|1]);}
	void build(int v,int l,int r,int *arr) {
		if(l == r) {
			if(arr[l] != inf)return mn[v] = mx[v] = arr[l],void();
			return mn[v] = inf,mx[v] = -inf,void();
		}int mid = l+r>>1;build(v<<1,l,mid,arr);build(v<<1|1,mid+1,r,arr);
		pushup(v);
	}
	int askmin(int v,int l,int r,int L,int R) {
		if(R < l || r < L)return inf;
		if(L <= l && r <= R)return mn[v];
		int mid = l+r>>1;
		return min(askmin(v<<1,l,mid,L,R),askmin(v<<1|1,mid+1,r,L,R));
	}
	int askmax(int v,int l,int r,int L,int R) {
		if(R < l || r < L)return -inf;
		if(L <= l && r <= R)return mx[v];
		int mid = l+r>>1;
		return max(askmax(v<<1,l,mid,L,R),askmax(v<<1|1,mid+1,r,L,R));
	}
}Ta1,Ta2,Tb;
char _ed;
int main() {
	cer("Memory:",(&_st-&_ed)>>20);
	file("game");
	read(n);read(m);read(q);
	for(int i=1; i<=n; ++i)read(a[i]);
	for(int i=1; i<=n; ++i)if(a[i] >= 0)a1[i] = a[i];else a1[i] = inf;
	for(int i=1; i<=n; ++i)if(a[i] <= 0)a2[i] = a[i];else a2[i] = inf;
	for(int i=1; i<=m; ++i)read(b[i]);
	Ta1.build(1,1,n,a1);Ta2.build(1,1,n,a2);Tb.build(1,1,m,b);
	while(q--) {
		int l1,r1,l2,r2;ll ans = -1e18;
		read(l1);read(r1);read(l2);read(r2);
		ll A = Ta1.askmin(1,1,n,l1,r1),
		   B = Ta1.askmax(1,1,n,l1,r1),
		   C = Ta2.askmin(1,1,n,l1,r1),
		   D = Ta2.askmax(1,1,n,l1,r1),
		   E = Tb.askmin(1,1,m,l2,r2),
		   F = Tb.askmax(1,1,m,l2,r2);
		if(A != inf)ans = max(ans,max(A*E,B*E));
		if(C != inf)ans = max(ans,max(C*F,D*F));
		print(ans);
	}
	return 0;
}
}
int main(){return MAIN::main();}
