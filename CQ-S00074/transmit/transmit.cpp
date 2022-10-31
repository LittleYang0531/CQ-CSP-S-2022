#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const ll inf=2e16;
const int N=2e5;
ll s[N+5][21];
int Head[N+5],Nxt[2*N+5],V[2*N+5],tot=-1;
void add(int u,int v){
	Nxt[++tot]=Head[u];Head[u]=tot;
	V[tot]=v;return;
}
int fa[N+5][21];
int dep[N+5];
void dfs(int u,int x){
	for(int i=Head[u];i!=-1;i=Nxt[i]){
		if(i==x)continue;
		fa[V[i]][0]=u;dep[V[i]]=dep[u]+1;
		dfs(V[i],i^1);
	}
}
ll dp[N+5],dp2[N+5];
ll ans;
int lca;
void getlca(int a,int b)
{
	ans=0;
	for(int kk=20;kk>=0;kk--)
	{
		int na=fa[a][kk];
		if(dep[na]>=dep[b])
		{
			ans+=s[a][kk];
			a=na;
		}
	}
	if(a==b)
	{
		ans+=s[a][0];lca=b;
		return;
	}
	for(int kk=20;kk>=0;kk--)
	{
		int na=fa[a][kk],nb=fa[b][kk];
		if(na!=nb)
		{
			ans+=s[a][kk]+s[b][kk];
			a=na;b=nb;
		}
	}
	ans+=s[a][1]+s[b][0];
	lca=fa[a][0];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int n,q,k;scanf("%d %d %d",&n,&q,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i][0]);
		Head[i]=-1;
	}
	for(int i=1;i<n;i++){
		int u,v;scanf("%d %d",&u,&v);
		add(u,v);add(v,u);
	}
	dep[1]=1;dfs(1,-1);
	for(int kk=1;kk<=20;kk++)
		for(int u=1;u<=n;u++)
		{
			int v=fa[u][kk-1];
			fa[u][kk]=fa[v][kk-1];
			s[u][kk]=s[u][kk-1]+s[v][kk-1];
		}	
	if(k==1)
	{
		while(q--)
		{
			int a,b;scanf("%d %d",&a,&b);
			if(dep[a]<dep[b])swap(a,b);
			getlca(a,b);
			printf("%lld\n",ans);
		}
	}
	else
	{
		while(q--)
		{
			int a,b;scanf("%d %d",&a,&b);
			if(dep[a]<dep[b])swap(a,b);
			getlca(a,b);
			int l=0,r=n+1;
			while(1) 
			{
				dp[++l]=s[a][0];dp2[l]=inf;
				if(a==lca)break;
				a=fa[a][0];
			}
			while(b!=lca)
			{
				dp[--r]=s[b][0];dp2[r]=inf;
				b=fa[b][0];
			}
			dp2[1]=dp[1];
			for(int i=1;i<=l;i++)
				for(int kk=1;kk<=k;kk++)
					if(i-kk<=0)break;
					else dp2[i]=min(dp2[i],dp2[i-kk]+dp[i]);
			for(int i=r;i<=n;i++)
				for(int kk=1;kk<=k;kk++){
					int lst=i-kk;
					if(lst<r)lst+=l-r+1;
					if(lst<=0)break;
					else dp2[i]=min(dp2[i],dp2[lst]+dp[i]);
				}
			if(r<=n)printf("%lld\n",dp2[n]);
			else printf("%lld\n",dp2[l]);
		}
	}
	return 0;
}
