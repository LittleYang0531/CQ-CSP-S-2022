#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
long long s[3000];
int head[3000],nxt[3000],to[3000],cnt;
int w[3000][3000];
void add(int u,int v){
	nxt[++cnt]=head[u];to[cnt]=v;head[u]=cnt;
	nxt[++cnt]=head[v];to[cnt]=u;head[v]=cnt;
}
void dfs(int f,int x,int q,int step){
	if(step<1)return;
	if(f!=x)w[f][x]=q+s[x];
	for(int i=head[x];i;i=nxt[i])
		dfs(f,to[i],w[f][x],step-1);
}
void solve(){
	for(int i=1;i<=n;i++)dfs(i,i,0,k);
	for(int i=head[1];i;i=nxt[i])
		for(int j=head[1];j;j=nxt[j])
			for(int p=head[to[i]];p;p=nxt[p])
				for(int q=head[to[j]];q;q=nxt[q])
					if(i!=j&&i!=p&&i!=q&&
					   j!=p&&j!=q&&
						 p!=q)
						ans=max(ans,w[1][to[i]]+w[to[i]][to[j]]
												+w[to[j]][to[p]]+w[to[p]][to[q]]
												+w[to[q]][1]);
	printf("%d",ans);	
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("hoilday.out","w",stdout);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			w[i][j]=INT_MAX;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&s[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	solve();
	return 0;
}
