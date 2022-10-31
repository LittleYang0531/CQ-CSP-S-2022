#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,Q,k;
ll v[N];
struct EDGE{
	int v,nex;
}e[N<<1];
int head[N<<1],cnt;
void add(int u,int v){e[++cnt].v=v;e[cnt].nex=head[u];head[u]=cnt;}
int f[N][25],dep[N];
void dfs(int x,int father){
	for(int i=1;i<=20;i++){
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=e[i].nex){
		int v=e[i].v;
		if(v==father) continue;
		f[v][0]=x;
		dep[v]=dep[x]+1;
		dfs(v,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;~i;i--){
		if(dep[f[x][i]]>=dep[y]){
			x=f[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20;~i;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int sta[N],top;
ll dp[N];
vector<int> a;
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&Q,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&v[i]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dep[1]=1;
	dfs(1,0);
	while(Q--){
		int s,t;
		scanf("%d%d",&s,&t);
		int c=lca(s,t);
		a.clear();
		while(s!=c){
			a.push_back(s);
			s=f[s][0];
		}
		a.push_back(c);
		top=0;
		while(t!=c){
			sta[++top]=t;
			t=f[t][0];
		}
		while(top) a.push_back(sta[top--]);
		int len=a.size();
		memset(dp,0x3f,sizeof(dp));
		dp[0]=v[a[0]];
		for(int i=1;i<len;i++){
			for(int j=1;j<=k;j++){
				if(i-j>=0) dp[i]=min(dp[i],dp[i-j]+v[a[i]]);
			}
		}
		printf("%lld\n",dp[len-1]);
	}
	return 0;
}
