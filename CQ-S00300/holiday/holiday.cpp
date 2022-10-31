#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
namespace TYGAKIOI{
	struct edge{
		int nxt,to;
	}e[10010];
	int a[3000];
	int head[3000],cnt;
	int f[3000][3000];
	int n,m,k;
	void add(int u,int v){
		e[++cnt]={head[u],v};
		head[u]=cnt;
	}
	void bfs(int u,int tu){
		deque<int>q;
		q.push_back(u);
		while(!q.empty()){
			int u=q.front();
			q.pop_front();
			for(int i=head[u];i;i=e[i].nxt){
				int v=e[i].to;
				if(f[tu][v]!=-1)
					continue;
				f[tu][v]=f[tu][u]+1;
				q.push_back(v);
			}
		}
	}
	int vis[3000],answer;
	void dfs(int now1,int now2,int ans,int num){
		if(num==1){
			for(int i=2;i<=n;i++){
				if(vis[i]||f[now1][i]>k||f[now1][i]==-1)
					continue;
				vis[i]=1;
				for(int j=2;j<=n;j++){
					if(vis[j]||f[now2][j]>k||f[now2][j]==-1||f[i][j]>3*k+2||f[i][j]==-1)
						continue;
					vis[j]=1;
					dfs(i,j,ans+a[i]+a[j],num+1);
					vis[j]=0;
				}
				vis[i]=0;
			}
		}
		if(num==2){
			for(int i=2;i<=n;i++){
				if(vis[i]||f[now1][i]>k||f[now1][i]==-1)
					continue;
				vis[i]=1;
				for(int j=2;j<=n;j++){
					if(vis[j]||f[now2][j]>k||f[now2][j]==-1||f[i][j]>k||f[i][j]==-1)
						continue;
					vis[j]=1;
					dfs(i,j,ans+a[i]+a[j],num+1);
					vis[j]=0;
				}
				vis[i]=0;
			}
		}
		if(num==3){
			if(f[now1][now2]<=k)
				answer=max(answer,ans);
			return;
		}
	}
	int main(){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=2;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		memset(f,255,sizeof(f));
		for(int i=1;i<=n;i++){
			bfs(i,i);
			f[i][i]=-1;
		}
		dfs(1,1,0,1);
		printf("%d",answer);
		return 0;
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	TYGAKIOI::main();
	return 0;
}
