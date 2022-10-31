#include<iostream> 
#include<cstdio>
#include<map>
#include<vector> 
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
int val[30005],head[10005],n,m,k,tot=0,nxt[30005],f[2600][2600],ver[30005],dis[30005],p[5],ans;
void add(int u,int v){
	nxt[++tot]=head[u],ver[head[u]=tot]=v;
	return ;
}
void dfs_k_0(int now,int dep){
	if(dep>5||(now==1&&dep<4))return ;
	if(now==1&&dep==4){
		ans=max(ans,val[p[1]]+val[p[2]]+val[p[3]]+val[p[4]]);
		return ;
	}
	for(int i=1;i<=dep;i++)if(p[i]==now)return ;
	p[dep+1]=now;
	for(int i=head[now];i;i=nxt[i]){
		int v=ver[i];
		dfs_k_0(v,dep+1);
	}
	p[dep+1]=0;
	return ;
}
int bfs(int s){
	queue<int>q;
	q.push(s);
	f[s][s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=ver[i];
			if(f[s][v]>f[s][u]+1){
				f[s][v]=f[s][u]+1;
				q.push(v);
			}
		}
	}
	return ;
}
bool check(int a,int b,int c,int d){
	if(f[a][b]-1>k||f[b][c]-1>k||f[c][d]-1>k||f[1][a]-1>k||f[1][d]-1>k)return false;
	return true;
}
void dfs_n(){ 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int h=1;h<=n;h++){
					if(i==j||i==k||i==h||j==k||j==h||k==h)continue;
					if(check(i,j,k,h)){
						ans=max(ans,val[i]+val[j]+val[h]+val[k]);
					}
				}
			}
		}
	}
	return ;
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	if(k==0){
		for(int i=head[1];i;i=nxt[i])dfs_k_0(ver[i],0);
	}
	else {
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=0x3f3f3f3f;
		for(int i=1;i<=n;i++)bfs(i);
		dfs_n();
	}
	printf("%lld\n",ans);
	return 0;
}
