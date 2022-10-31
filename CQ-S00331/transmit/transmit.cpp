#include<bits/stdc++.h>
using namespace std;
int n,q,k,ww[200005];
int cnt=0,fir[200005],to[400005],nex[400005];
void add(int u,int v){
	to[++cnt]=v;
	nex[cnt]=fir[u];
	fir[u]=cnt;
}
int dep[200005],f[200005][20];
long long w[200005][20];
void dfs(int u,int fa){
	for(int i=fir[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		f[v][0]=u;
		w[v][0]=ww[u];
		dfs(v,u);
	}
}
long long findlca(int a,int b){
	if(a==b)return ww[a];
	long long ans=ww[a]+ww[b];
	if(dep[a]<dep[b])swap(a,b);
	for(int i=18;i>=0;i--){
		if(dep[f[a][i]]>=dep[b])ans+=w[a][i],a=f[a][i];
	}
	if(a==b)return ans-ww[b];
	for(int i=18;i>=0;i--){
		if(f[a][i]!=f[b][i])ans+=(w[a][i]+w[b][i]),a=f[a][i],b=f[b][i];
	}
	return ans+w[a][0];
}
int num[205],dp[205];
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%d",&ww[i]);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	for(int i=1;i<=18;i++){
		for(int j=1;j<=n;j++){
			f[j][i]=f[f[j][i-1]][i-1];
			w[j][i]=w[j][i-1]+w[f[j][i-1]][i-1];
		}
	}
	while(q--){
		int s,t;
		scanf("%d%d",&s,&t);
		if(k==1)printf("%lld\n",findlca(s,t));
		else{
			if(dep[s]<dep[t])swap(s,t);
			int len=0;
			while(f[s][0]!=t)num[++len]=ww[s],s=f[s][0];
			num[++len]=ww[s];num[++len]=ww[f[s][0]];
			memset(dp,0x3f,sizeof(dp));
			dp[0]=0;
			for(int i=1;i<=len;i++){
				for(int j=1;j<=k;j++){
					if(i-k>=0)dp[i]=min(dp[i],dp[i-k]+ww[i]);
				}
			}
			printf("%d\n",dp[len]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}