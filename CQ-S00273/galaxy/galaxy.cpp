#include<bits/stdc++.h>
using namespace std;
int n,m,Q;
vector<int> g[500005],ung[500005];
int dist[500005];
bool SPFA(int root){
	memset(dist,0,sizeof(dist));
	queue<int> q;
	q.push(root);
	dist[root]++;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(dist[t]>=(n-1)*n/2)return 1;
		int lg=g[t].size();
		for(int i=0;i<lg;i++)if(g[t][i]!=0){
			q.push(g[t][i]);
			dist[g[t][i]]++;
		}
	}
	return 0;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		ung[v].push_back(u);
	}
	scanf("%d",&Q);
	while(Q--){
		bool hooch=0;
		int t,u,v;
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&u,&v);
			int lg=g[u].size();
			for(int i=0;i<lg;i++)if(g[u][i]==v){
				g[u][i]=0;
				break;
			}
		}else if(t==2){
			scanf("%d",&v);
			int lu=ung[v].size(),lg=0;
			for(int i=0;i<lu;i++){
				lg=g[ung[v][i]].size();
				for(int j=0;j<lg;j++)if(g[ung[v][i]][j]==v){
					g[ung[v][i]][j]=0;
					break;
				}
			}
		}else if(t==3){
			scanf("%d%d",&u,&v);
			int lg=g[u].size();
			for(int i=0;i<lg;i++)if(g[u][i]==0){
				g[u][i]=v;
				break;
			}
		}else if(t==4){
			scanf("%d",&v);
			int lu=ung[v].size(),lg;
			for(int i=0;i<lu;i++){
				lg=g[ung[v][i]].size();
				int ju=0;
				for(int j=0;j<lg;j++)if(g[ung[v][i]][j]==0){
					ju=j;
					break;
				}
				for(int j=0;j<=lg;j++)if(g[ung[v][i]][j]==v){
					ju=-1;
					break;
				}
				if(ju!=-1)g[ung[v][i]][ju]=v;
			}
		}
		bool flag=1;
		for(int i=1;i<=n;i++){
			int lg=g[i].size(),tlg=0;
			for(int j=0;j<lg;j++)if(g[i][j]!=0)tlg++;
			if(tlg!=1){
				flag=0;
//				printf("%d %d ",i,tlg);
				break;
			}
			if(SPFA(i)==0){
				flag=0;
//				printf("fucker:%d %d ",i,dist[i]);
				break;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
