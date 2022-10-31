#include<bits/stdc++.h>
using namespace std;
int n,k,prt[200001];
struct node{
	int next,to;
}e[400001];
int h[200001],cnt,vis[200001];
void Addedge(int x,int y){
	e[++cnt].next=h[x];
	e[cnt].to=y;
	h[x]=cnt;
}
long long dp[200001],v[200001];
int dep[200001],pos[200001],f[1000001][20],sign,top,a[200001];
void dfs(int u,int pt){
	prt[u]=pt;
	f[++sign][0]=u;
	if(!pos[u])pos[u]=sign;
	for(int i=h[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==pt)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		f[++sign][0]=u;
	}
}
void ST(){
	for(int j=1;j<=log2(sign);++j){
		for(int i=1;i+(1<<j)-1<=sign;++i){
			if(dep[f[i][j-1]]<dep[f[i+(1<<j-1)][j-1]]){
				f[i][j]=f[i][j-1];
			}
			else f[i][j]=f[i+(1<<j-1)][j-1];
		}
	}
}
int LCA(int x,int y){
	int l=min(pos[x],pos[y]);
	int r=max(pos[x],pos[y]);
	int m=log2(r-l+1);
	if(dep[f[l][m]]<dep[f[r-(1<<m)+1][m]])return f[l][m];
	else return f[r-(1<<m)+1][m];
}
int dis(int x,int y){
	int t=LCA(x,y);
	return dep[x]+dep[y]-dep[t]*2;
}
void solved(){
	int s,t,tmp;
	scanf("%d%d",&s,&t);
	tmp=s,top=0;
	int p=LCA(s,t);
	for(int i=dep[s];i>=max(1,dep[p]-k+1);--i){
		a[++top]=tmp;
		tmp=prt[tmp];
	}
	tmp=t;
	int tot=0;
	top+=dep[t]-dep[p]+1;
	for(int i=dep[t];i>=dep[p];--i){
		a[top-tot]=tmp;
		tmp=prt[tmp];
		++tot;
	}
	for(int i=1;i<=top;++i){
		dp[i]=0x7fffffffffff;
	}
	dp[1]=v[a[1]];
	for(int i=2;i<=top;++i){
		for(int j=i-1;j>=1;--j){
			if(dis(a[i],a[j])<=k){
				dp[i]=min(dp[i],dp[j]+v[a[i]]);
			}
		}
	}
	printf("%lld\n",dp[top]);
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int T;
	scanf("%d%d%d",&n,&T,&k);
	for(int i=1;i<=n;++i){
		scanf("%lld",v+i);
	}
	dep[0]=-1;
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		Addedge(u,v);
		Addedge(v,u);
	}
	dfs(1,0);
	ST();
	if(k==1){
		while(T--){
			int l,r;
			scanf("%d%d",&l,&r);
			int t=LCA(l,r);
			long long res=0;
			while(l!=t){
				res+=v[l];
				l=prt[l];
			}
			while(r!=t){
				res+=v[r];
				r=prt[r];
			}
			res+=v[t];
			printf("%lld",res);
		}
	}
	while(T--)solved();
	return 0;
}
/*
10 1 3
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9
10 5

939363946

1151305575
*/
