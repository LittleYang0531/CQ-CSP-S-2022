#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,q,k,ans,s,t,w[maxn];
vector<int> G[maxn];
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
void dfs(int u,int fa,int cnt,int res){
	if(res>=ans)
		return;
	if(u==t){
		ans=res;
		return;
	}
	for(int i=0,len=G[u].size();i<len;++i){
		int v=G[u][i];
		if(v==fa)
			continue;
		if(cnt+1<=k)
			dfs(v,u,cnt+1,res);
		dfs(v,u,1,res+w[u]);
	}
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),q=read(),k=read();
	for(int i=1;i<=n;++i)
		w[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	while(q--){
		ans=2e9;
	 	s=read(),t=read();
		dfs(s,0,0,w[s]+w[t]);
		printf("%lld\n",ans);
	} 
	return 0;
}
