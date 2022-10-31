#include<bits/stdc++.h>
using namespace std;
int n,Q,k;int u,v;
long long w[200009];int vis[200009];long long mi=LONG_MAX*(long long)(10);
vector<int>a[200009];
void dfs(int x,long long sum,int p)
{
	if(x==v)
	{
		mi=min(mi,sum+w[v]);
		return ;
	}
	if(sum>mi)return ;
	for(int i=0;i<a[x].size();i++)
	{
		if(!vis[a[x][i]])
		{	
			vis[a[x][i]]=1;
			dfs(a[x][i],sum+w[x],1);
			vis[a[x][i]]=0;
		}if(p<k&&x!=u)
			dfs(a[x][i],sum,p+1);
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>Q>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int l=1;l<=Q;l++)
	{
		mi=LONG_MAX*(long long)(10);
		scanf("%d%d",&u,&v);
		vis[u]=1;
		dfs(u,0,0);
		vis[u]=0;
		printf("%lld\n",mi);
	}
	return 0;
}

