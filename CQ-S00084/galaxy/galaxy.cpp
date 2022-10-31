#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define il inline
#define ct const
#define dl double
#define pk push_back
#define N 500010
#define M 500010
using namespace std;
il int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
il void write(int x){
	int cnt=0;char f[40];
	if(!x) putchar('0');
	if(x<0){
		x=-x;putchar('-');
	}
	while(x){
		f[cnt++]=x%10+'0';x/=10;
	}
	while(cnt) putchar(f[--cnt]);
}
int head[N],nxt[M],to[M],t,du[N];
set<int> P[N],Q[N];
set<int>::iterator it;
il void add(int u,int v){
	P[u].insert(v);++du[v];
}
int n,m,cnt,q;
il void Add(int x,int k){
	if(du[x]==1) --cnt;
	du[x]+=k;
	if(du[x]==1) ++cnt;
}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read();m=read();
	while(m--) add(read(),read());
	for(int i=1;i<=n;++i) cnt+=du[i]==1;
	q=read();
	while(q--){
		int op=read(),u=read(),v;
		if(op==1){
			v=read();
			it=P[v].find(u);
			if(it!=P[v].end()){
				Add(*it,-1);Q[v].insert(*it);P[v].erase(it);
			}
		}
		else if(op==2){
			for(auto i:P[u]){
				Add(i,-1);Q[u].insert(i);
			}
			P[u].clear();
		}
		else if(op==3){
			v=read();
			it=Q[v].find(u);
			if(it!=Q[v].end()){
				Add(*it,1);P[v].insert(*it);Q[v].erase(it);
			}
		}
		else if(op==4){
			for(auto i:Q[u]){
				Add(i,1);P[u].insert(i);
			}
			Q[u].clear();
		}
		puts(cnt==n?"YES":"NO");
	}
	return 0;
}

