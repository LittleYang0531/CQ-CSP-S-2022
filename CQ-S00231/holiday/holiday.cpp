#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void _fre(string txt);
template<typename T> inline void read(T& x);
template<typename... Args> inline void read(Args& ...args);
const int N=2505;
int n,m,k;
ll w[N];
vector<int> G[N];
namespace solve0{
	ll max_[N],max__[N];
	ll dis[N];
	map<vector<int>,bool> vis;
	inline void MAIN(){
		queue<vector<int> > Q;
		Q.push(vector<int>(1,1));
		vis[vector<int>(1,1)]=1;
		while(!Q.empty()){
			vector<int> u=Q.front();
			Q.pop();
			int now=u.back();
			vis[u]=0;
			if(u.size()>3) continue;
			if(u.size()==3){
				if(dis[now]>max_[now]) max__[now]=max_[now],max_[now]=dis[now];
				else if(dis[now]>max__[now]) max__[now]=dis[now];
				continue;
			}
			for(int v:G[now]){
				bool flag=1;
				for(int i=0;i<(int)u.size()&&flag;i++) if(v==now) flag=0;
				if(!flag) continue;
				dis[v]=dis[now]+w[v];
				u.push_back(v);
				if(!vis[u]){
					vis[u]=1;
					Q.push(u);
				}
				u.pop_back();
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,max_[i]+max__[i]);
		printf("%lld",ans);
		return;
	}
};
int main(){
	_fre("holiday");
	read(n,m,k);
	for(int i=2;i<=n;i++) read(w[i]);
	for(int i=1,u,v;i<=m;i++){
		read(u,v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	if(k==0) return (solve0::MAIN(),0);
	return 0;
}

inline void _fre(string txt){
	string in_buf=txt+".in";
	string out_buf=txt+".out";
	freopen(in_buf.c_str(),"r",stdin);
	freopen(out_buf.c_str(),"w",stdout);
}
template<typename T> inline void read(T& x){
	x=0;bool flag=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag=1;
	if(flag) for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)-(ch&15);
	else for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch&15);
}
template<typename... Args> inline void read(Args& ...args){
	int arg[]{(read(args),0)...};
	if(0) *arg=*arg;
}
