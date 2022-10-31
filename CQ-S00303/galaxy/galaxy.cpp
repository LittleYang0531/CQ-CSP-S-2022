#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define ll long long
#define N 500005
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
int n,m,tot,Q;
set<int>eo[N],ei[N],Go[N],Gi[N];
void del(int x,int y) {
	tot -= eo[x].size()==1;
	eo[x].erase(y);ei[y].erase(x);
	Go[x].insert(y);Gi[y].insert(x);
	tot += eo[x].size()==1;
}
void add(int x,int y) {
	tot -= eo[x].size()==1;
	eo[x].insert(y);ei[y].insert(x);
	Go[x].erase(y);Gi[y].erase(x);
	tot += eo[x].size()==1;
}
char _ed;
int main() {
	cer("Memory:",(&_st-&_ed)>>20);
	file("galaxy");
	read(n);read(m);
	for(int i=1,x,y; i<=m; ++i)read(x),read(y),eo[x].insert(y),ei[y].insert(x);
	for(int i=1; i<=n; ++i)tot += eo[i].size()==1;
	read(Q);
	while(Q--) {
		int op,x,y;vector<int>tmp;tmp.clear();read(op);
		if(op == 1)read(x),read(y),del(x,y);
		if(op == 2) {
			read(x);for(int y:ei[x])tmp.push_back(y);
			for(int y:tmp)del(y,x);
		}
		if(op == 3)read(x),read(y),add(x,y);
		if(op == 4) {
			read(x);for(int y:Gi[x])tmp.push_back(y);
			for(int y:tmp)add(y,x);
		}
		puts(tot==n?"YES":"NO");
	}
	return 0;
}
}
int main(){return MAIN::main();}
