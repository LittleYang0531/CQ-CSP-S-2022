#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,q;
bool vis[maxn];
vector<int> G[maxn];
map<int,bool> flg[maxn];
inline int read(){
	int res=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=(ch=='-');
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<1)+(res<<3)+(ch^'0');
		ch=getchar();
	} 
	return f?-res:res;
}
bool dfs(int u){
	if(vis[u])
		return 1;
	vis[u]=1;
	for(int i=0,len=G[u].size();i<len;++i)
		if(!flg[u][G[u][i]])
			return dfs(G[u][i]);
}
inline bool check(int x){
	int cnt=0;
	for(int i=0,len=G[x].size();i<len;++i)
		if(!flg[x][G[x][i]])
			++cnt;
	if(cnt!=1)
		return 0;
	memset(vis,0,sizeof(vis));
	return dfs(x);
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
	}
	q=read();
	while(q--){
		int t=read();
		if(t==1){
			int u=read(),v=read();
			flg[u][v]=1;
		} else if(t==2){
			int u=read();
			for(int i=1;i<=n;++i)
				flg[i][u]=1;
		} else if(t==3){
			int u=read(),v=read();
			flg[u][v]=0;
		} else{
			int u=read();
			for(int i=1;i<=n;++i)
				flg[i][u]=0;
		}
		bool p=1; 
		for(int i=1;i<=n;++i)
			if(!check(i)){
				puts("NO");
				p=0;
				break;
			}
		if(p)
			puts("YES");
	}
	return 0;
}
