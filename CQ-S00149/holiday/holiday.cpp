#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int pts[2501];
struct node{
	int next,to;
}e[2000001];
int h[2501],cnt,vis[2501];
void Addedge(int x,int y){
	e[++cnt].next=h[x];
	e[cnt].to=y;
	h[x]=cnt;
}
int f[2501][2501],maxx;
void dfs1(int u,int K,int sum){
//	printf("%d %d %d\n",u,K,sum);
	if(K==5){
		if(f[u][1]-1<=k){
			maxx=max(maxx,sum);
		}
		return;
	}
	for(int i=h[u];i;i=e[i].next){
		int v=e[i].to;
		if(vis[v]||v==1)continue;
		vis[v]=1;
		dfs1(v,K+1,sum+pts[v]);
		vis[v]=0;
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;++i)scanf("%d",pts+i);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)f[i][j]=i==j?0:0x3f3f3f3f;
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		f[u][v]=f[v][u]=1;
	}
	if(n<=20){
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				if(f[i][k]==0x3f3f3f3f)continue;
				for(int j=1;j<=n;++j){
					if(f[k][j]==0x3f3f3f3f)continue;
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		int maxx=0;
		for(int a=2;a<=n;++a){
			for(int b=2;b<=n;++b){
				for(int c=2;c<=n;++c){
					for(int d=2;d<=n;++d){
						if(f[1][a]-1<=k&&f[a][b]-1<=k&&f[b][c]-1<=k&&f[c][d]-1<=k&&f[d][1]-1<=k&&a-b&&a-c&&a-d&&b-c&&b-d&&c-d){
							maxx=max(maxx,pts[a]+pts[b]+pts[c]+pts[d]);
						}
					}
				}
			}
		}
		printf("%d",maxx);
		return 0;
	}
	if(!k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(f[i][j]==1){
					Addedge(i,j);
				}
			}
		}
		dfs1(1,1,0);
		printf("%d",maxx);
		return 0;
	}
	if(n<=300){
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				if(f[i][k]==0x3f3f3f3f)continue;
				for(int j=1;j<=n;++j){
					if(f[k][j]==0x3f3f3f3f)continue;
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(f[i][j]-1<=k){
					Addedge(i,j);
					Addedge(j,i);
				}
			}
		}
//		cout<<"!!!!!!!!!!";
		dfs1(1,1,0);
		printf("%d",maxx);
		return 0;
	}
	return 0;
}

