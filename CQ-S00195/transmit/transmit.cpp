#include<bits/stdc++.h>
using namespace std;
const int N=200100;
vector<int> l[N];
int dep[N],f[N],point[N];
long long v[N],dp[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u]=fa;
	for(unsigned int i=0;i<l[u].size();i++){
		int v=l[u][i];
		if(v==fa){
			continue;
		}
		dfs(v,u);
	}
	return ;
}
void work(int u,int v,int &t){
	queue<int> qu;
	while(dep[u]>dep[v]){
		qu.push(u);
		u=f[u];
	}
	stack<int> sv;
	while(dep[v]>dep[u]){
		sv.push(v);
		v=f[v];
	}
	while(u!=v){
		qu.push(u);
		sv.push(v);
		u=f[u];
		v=f[v];
	}
	while(!qu.empty()){
		point[++t]=qu.front();
		qu.pop();
	}
	point[++t]=u;
	while(!sv.empty()){
		point[++t]=sv.top();
		sv.pop();
	}
	return ;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int n,q,k;
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&v[i]);
	}
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		l[a].push_back(b);
		l[b].push_back(a);
	}
	dfs(1,0);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		int t=0;
		work(a,b,t);
		point[1]=0;
		dp[1]=0;
		for(int i=2;i<=t;i++){
			dp[i]=LONG_LONG_MAX;
			for(int j=1;j<=k&&i-j>=1;j++){
				dp[i]=min(dp[i],dp[i-j]+v[point[i-j]]);
			}
		}
		printf("%lld\n",dp[t]+v[a]+v[b]);
	}
	return 0;
}

