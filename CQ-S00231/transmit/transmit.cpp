#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void _fre(string txt);
template<typename T> inline void read(T& x);
template<typename... Args> inline void read(Args& ...args);
const int N=2e5;
int n,q,k;
int w[N];
vector<int> G[N];
vector<pair<int,int> > H[N];
inline vector<int> solve(int u,int c){
	if(c==0) return vector<int>(0);
	vector<int> ret;
	for(int v:G[u]){
		ret.push_back(v);
		vector<int> now=solve(v,c-1);
		for(int g:now) ret.push_back(g);
	}
	return ret;
}
bool vis[N];
int dis[N];
inline int bfs(int s,int t){
	priority_queue<pair<int,int> > Q;
	Q.push(make_pair(0,s));
	memset(dis,0x3f,sizeof dis);
	vis[s]=1;
	dis[s]=0;
	while(!Q.empty()){
		int u=Q.top().first;
		Q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(dis[t]!=0x3f3f3f3f) break;
		for(int i=0;i<(int)H[u].size();i++){
			int v=H[u][i].first,val=H[u][i].second;
			if(dis[v]<dis[u]+val){
				dis[v]=dis[u]+val;
				Q.push(make_pair(dis[v],v));
			}
		}
	}
	return dis[t];
}
int main(){
	_fre("transmit");
	read(n,q,k);
	for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1,u,v;i<n;i++){
		read(u,v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		vector<int> to=solve(i,k);
		for(int v:to) H[i].push_back(make_pair(v,w[v]));
	}
	for(int i=1,s,t;i<=q;i++){
		read(s,t);
		printf("%d\n",bfs(s,t));
	}
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
