#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
set<int> G[1005];
int de[1005][1005];
int dn[1005];
int sum;
int s[1005];
int vis[1005];
int ok;

void dfs(int u,int k){
	vis[u]=k;
	for(int v:G[u]){
		if(dn[v]==0){
			if(vis[v]==k){ok=1;return;}
		dfs(v,k);
		}
	}
}

int main(){
	freopen("galaxy1.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		G[u].insert(v);
	}
	for(int i=1;i<=n;i++)if(G[i].size()==1)sum++;
	int q=read();
	while(q--){
		int t=read();
		if(t==1){
			int u=read(),v=read();
			G[u].erase(G[u].lower_bound(v));
		}else if(t==2){
			int u=read();
			dn[u]=1;
		}else if(t==3){
			int u=read(),v=read();
			G[u].insert(v);
		}else {
			int u=read();
			dn[u]=0;
		}
		ok=0;
		int ok1=1;
		for(int i=1;i<=n;i++)if(dn[i]==1)ok1=0;
		int ok2=1;
		for(int i=1;i<=n;i++)if(G[i].size()!=1)ok2=0;
		dfs(1,q);
		if(ok&&ok1&&ok2)printf("YES");
		else printf("NO");
	}
	return 0;
}