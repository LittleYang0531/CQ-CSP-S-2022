#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,u,v,q,t,vis[maxn];
map<int,int> to[maxn],com[maxn];
int read(){
	int s=0;
	char ch=getchar(),last=' ';
	while(ch<'0'||ch>'9')
		last=ch,ch=getchar();
	while(ch>='0'&&ch<='9')
		s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return last=='-'?-s:s;
}
int dfs(int u){
	int cnt=0;
	vis[u]=q+1;
	for(auto v:to[u])
		if(v.second==1)
			cnt++;
	if(cnt!=1)
		return 0;
	for(auto v:to[u])
		if(v.second==1){
			if(vis[v.first]==q+1)
				return 1;
			dfs(v.first);
		}
}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		u=read(),v=read();
		to[u][v]=1;
		com[v][u]=1;
	}
	q=read();
	while(q--){
		t=read(),u=read();
		if(t==1){
			v=read();
			to[u][v]=-1;
			com[v][u]=-1;
		}
		if(t==2)
			for(auto v:com[u])
				if(v.second==1)
					v.second=-1,to[v.first][u]=-1;
		if(t==3){
			v=read();
			to[u][v]=1;
			to[v][u]=1;
		}
		if(t==4)
			for(auto v:com[u])
				if(v.second==-1)
					v.second=1,to[v.first][u]=1;
		int bj=0;
		for(int i=1;i<=n;i++)
			if(!dfs(i)){
				bj=1;
				puts("NO");
				break;
			}
		if(bj==0)
			puts("YES");
	}
    return 0;
}

