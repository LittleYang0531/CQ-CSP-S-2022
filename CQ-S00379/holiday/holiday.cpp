#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt;
long long d[2505][2505],val[2505],a[2505],Max[5][2505],ans;
vector<long long>g[2505];
void bfs(long long x){
	queue<long long>q;
	q.push(x);
	while(q.size()){
		long long p=q.front();q.pop();
		for(long long i=0;i<g[p].size();i++){
			if(!d[x][g[p][i]])d[x][g[p][i]]=d[x][p]+1,q.push(g[p][i]);
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);k++;
	for(long long i=2;i<=n;i++)scanf("%lld",&val[i]);val[0]=-1e18;
	for(long long i=1,u,v;i<=m;i++){
		scanf("%lld%lld",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(long long i=1;i<=n;i++)bfs(i);
	for(long long i=1;i<=n;i++){
		if(d[1][i]<=k)a[++cnt]=i;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=cnt;j++){
			if(i==a[j])continue;
			if(d[i][a[j]]<=k){
				long long kk=val[a[j]];
				if(val[a[j]]>val[Max[1][i]])Max[3][i]=Max[2][i],Max[2][i]=Max[1][i],Max[1][i]=a[j];
				else if(val[a[j]]>val[Max[2][i]])Max[3][i]=Max[2][i],Max[1][i]=a[j];
				else if(val[a[j]]>val[Max[3][i]])Max[3][i]=a[j];
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i==j||d[i][j]>k)continue;
			for(long long u=1;u<=3;u++){
				for(long long v=1;v<=3;v++){
					long long x=Max[u][i],y=Max[v][j];
					if(x!=y&&x!=i&&y!=j&&x!=j&&y!=i&&i!=j){
						ans=max(ans,val[i]+val[j]+val[x]+val[y]);
						break;
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

