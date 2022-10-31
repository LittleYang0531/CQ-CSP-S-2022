#include<bits/stdc++.h>
using namespace std;
const int maxx=5e5+5;
int n,m,q;
int dis[maxx];
bool vis[1005][1005];
int dent[1005][1005];
int cnt[maxx];
void add(int x,int y){
	dis[x]++;
	vis[x][y]=1;
	dent[y][++cnt[y]]=x;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
	}
	if(n<=1000){
		scanf("%d",&q);
		for(int kk=1;kk<=q;++kk){
			int t;
			scanf("%d",&t);
			if(t==1){
				int u,v;
				scanf("%d%d",&u,&v);
				dis[u]--;
				vis[u][v]=0;
			}
			else if(t==2){
				int u;
				scanf("%d",&u);
				for(int i=1;i<=cnt[u];++i){
					int cos=dent[u][i];
					if(vis[cos][u]){
						dis[cos]--;
						vis[cos][u]=0;
					}
				}
			}
			else if(t==3){
				int u,v;
				scanf("%d%d",&u,&v);
				dis[u]++;
				vis[u][v]=1;
			}
			else{
				int u;
				scanf("%d",&u);
				for(int i=1;i<=cnt[u];++i){
					int cos=dent[u][i];
					if(!vis[cos][u]){
						dis[cos]++;
						vis[cos][u]=1;
					}
				}
			} 
			bool flag=1;
			for(int i=1;i<=n;++i)if(dis[i]!=1)flag=0;
			if(flag)puts("YES");
			else puts("NO");
		}
	}
	else{
		scanf("%d",&q);
		for(int kk=1;kk<=q;++kk){
			int t;
			scanf("%d",&t);
			if(t==1){
				int u,v;
				scanf("%d%d",&u,&v);
				dis[u]--;
			}
			else if(t==2){
				int u;
				scanf("%d",&u);
			}
			else if(t==3){
				int u,v;
				scanf("%d%d",&u,&v);
				dis[u]++;
			}
			else{
				int u;
				scanf("%d",&u);
			} 
			bool flag=1;
			for(int i=1;i<=n;++i)if(dis[i]!=1)flag=0;
			if(flag)puts("YES");
			else puts("NO");
		}	
	}
}
