#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int M=1e4+5;
int n,m,q,deg[N],dfn[N];
bool ans;
int id=1,h[N],e[2*M],ne[2*M];
bool vis[2*M],ring[N];
void add(int a,int b){
	id++;
	ne[id]=h[a];
	h[a]=id;
	e[id]=b;
}
void dfs(int x,int cnt){
	dfn[x]=cnt;
	for(int i=h[x];i;i=ne[i]){
		if(!vis[i]&&i%2==0){
			if(!dfn[e[i]]){
				dfs(e[i],cnt);
			}else if(dfn[e[i]]==dfn[x]){
				ring[x]=1;
			}
			ring[x]|=ring[e[i]];
		}
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
		deg[a]++;
	}
	scanf("%d",&q);
	while(q--){
		int t,a,b;
		scanf("%d",&t);
		switch(t){
			case 1:
				scanf("%d%d",&a,&b);
				deg[a]--;
				for(int i=h[a];i;i=ne[i]){
					if(e[i]==b&&i%2==0){
						vis[i]=vis[i^1]=1;
					}
				}
				break;
			case 2:
				scanf("%d",&a);
				for(int i=h[a];i;i=ne[i]){
					if(!vis[i]&&i%2==1){
						deg[e[i]]--;
						vis[i]=vis[i^1]=1;
					}
				}
				break;
			case 3:
				scanf("%d%d",&a,&b);
				deg[a]++;
				for(int i=h[a];i;i=ne[i]){
					if(e[i]==b&&i%2==0){
						vis[i]=vis[i^1]=0;
					}
				}
				break;
			case 4:
				scanf("%d",&a);
				for(int i=h[a];i;i=ne[i]){
					if(vis[i]&&i%2==1){
						deg[e[i]]++;
						vis[i]=vis[i^1]=0;
					}
				}
				break;
		}
		ans=1;
		for(int i=1;i<=n;i++){
			if(deg[i]!=1){
				ans=0;
			}
		}
		if(ans){
			int c=0;
			memset(dfn,0,sizeof(dfn));
			memset(ring,0,sizeof(ring));
			for(int i=1;i<=n;i++){
				if(!dfn[i]){
					c++;
					dfs(i,c);
				}
			}
			for(int i=1;i<=n;i++){
				if(!ring[i]){
					ans=0;
				}
			} 
		}
		if(ans){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
