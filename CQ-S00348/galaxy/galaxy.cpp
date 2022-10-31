#include<bits/stdc++.h>
using namespace std;
#define int long long

const int Maxn=2010;
int N,M,Q,in[Maxn],out[Maxn];
bool G[Maxn][Maxn],Mark[Maxn],Vis[Maxn];
vector<int> E[Maxn];

inline int read(){
	int ret=0,f=0; char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=(ret<<1)+(ret<<3)+(ch^48),ch=getchar();
	return f?-ret:ret;
}

bool DFS(int x){
	Mark[x]=true;
	for(int i=1;i<=N;++i)if(i^x){
		if(G[x][i]){
			if(Mark[i]||Vis[i]) Vis[x]=1;
			else Vis[x]=DFS(i);
		}
	}
	return Vis[x];
}

bool check(){
	for(int i=1;i<=N;++i) Vis[i]=0;
	for(int i=1;i<=N;++i) if(out[i]!=1) return 0;
	for(int i=1;i<=N;++i) if(!Vis[i]){
		for(int j=1;j<=N;++j) Mark[j]=0;
		DFS(i);
	}
	for(int i=1;i<=N;++i) if(!Vis[i]) return 0;
	return 1;
}

signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	N=read(),M=read();
	for(int u,v,i=1;i<=M;++i){
		u=read(),v=read();
		E[v].push_back(u),G[u][v]=true;
		++out[u],++in[v];
	}
	Q=read();
	while(Q--){
		int t=read(),u=read(),v;
		if(t==1) v=read(),G[u][v]=0,--out[u],--in[v];
		if(t==2) for(int i=0;i<(int)E[u].size();++i) 
					if(G[E[u][i]][u]) G[E[u][i]][u]=0,--out[E[u][i]],--in[u];
		if(t==3) v=read(),G[u][v]=1,++out[u],++in[v];
		if(t==4) for(int i=0;i<(int)E[u].size();++i) 
					if(!G[E[u][i]][u]) G[E[u][i]][u]=1,++out[E[u][i]],++in[u];
		if(check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
