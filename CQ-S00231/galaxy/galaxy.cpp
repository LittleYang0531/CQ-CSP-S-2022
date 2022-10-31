#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void _fre(string txt);
template<typename T> inline void read(T& x);
template<typename... Args> inline void read(Args& ...args);
const int N=5e5+5,M=1e6+5;
struct edge{
	int to,nex;
	bool alive;
};
int n,m,q;
class LS{
private:
	int Head1[N],Head2[N],Ver[M],Next[M],tot;
	bool Alive[M];
	int Cnt[N];
public:
	LS(){tot=1;}
	void add(int u,int v){
		Ver[++tot]=v,Next[tot]=Head1[u],Head1[u]=tot,Alive[tot]=1;
		Ver[++tot]=u,Next[tot]=Head2[v],Head2[v]=tot,Alive[tot]=1;
		Cnt[u]++;
	}
	int& head_from(int u){return Head1[u];}
	int& head_to(int u){return Head2[u];}
	int& ver(int i){return Ver[i];}
	int& next(int i){return Next[i];}
	bool& alive(int i){return Alive[i];}
	int& cnt(int u){return Cnt[u];}
	void del(int i){Alive[i]=Alive[i^1]=0;}
	void rep(int i){Alive[i]=Alive[i^1]=1;}
};
LS G;
inline void del(int u,int v){
	for(int i=G.head_from(u);i;i=G.next(i)){
		int to=G.ver(i);
		if(to==v){
			if(G.alive(i)) G.cnt(u)--;
			G.del(i);
			break;
		}
	}
}
inline void del(int u){
	for(int i=G.head_to(u);i;i=G.next(i)){
		int from=G.ver(i);
		if(G.alive(i)) G.cnt(from)--;
		G.del(i);
	}
}
inline void rep(int u,int v){
	for(int i=G.head_from(u);i;i=G.next(i)){
		int to=G.ver(i);
		if(to==v){
			if(!G.alive(i)) G.cnt(u)++;
			G.rep(i);
			break;
		}
	}
}
inline void rep(int u){
	for(int i=G.head_to(u);i;i=G.next(i)){
		int from=G.ver(i);
		if(!G.alive(i)) G.cnt(from)++;
		G.rep(i);
	}
}
bool vis[N];
inline bool dfs(int u){
	for(int i=G.head_from(u);i;i=G.next(i)){
		if(G.alive(i)){
			int to=G.ver(i);
			if(vis[to]) return 1;
			vis[to]=1;
			if(dfs(to)) return 1;
		}
	}
	return 0;
}
inline bool Go(){
	for(int i=1;i<=n;i++) if(G.cnt(i)>1) return 0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		vis[i]=1;
		if(!dfs(i)) return 0;
	}
	return 1;
}
int main(){
	_fre("galaxy");
	read(n,m);
	for(int i=1,u,v;i<=m;i++){
		read(u,v);
		G.add(u,v);
	}
	read(q);
	for(int opt,u,v;q--;){
		read(opt);
		switch(opt){
			case 1:
				read(u,v);
				del(u,v);
				break;
			case 2:
				read(u);
				del(u);
				break;
			case 3:
				read(u,v);
				rep(u,v);
				break;
			case 4:
				read(u);
				rep(u);
				break;
		}
		printf("%s\n",Go()?"YES":"NO");
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
