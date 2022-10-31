#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,u,h[5005],t[5005],nxt[5005],vis[2501];
ll sco[2505],sum,ans=-1e9;
void add(int x,int y)
{
	u++,t[u]=y,nxt[u]=h[x],h[x]=u;
	u++,t[u]=x,nxt[u]=h[y],h[y]=u;
}
void dfs(int now,int c,int cnt)
{
	if(cnt==6) 
	{
		if(now!=1)	return;
		ans=max(ans,sum);
		return;
	}
	if(c==0)
	{
		if(vis[now]==1)	return ;
		for(int i=h[now];i;i=nxt[i])
			for(int j=k;j>=0;j--)
			{
				vis[now]=1;
				sum+=sco[now];
				dfs(t[i],j,cnt+1);
				vis[now]=0;
				sum-=sco[now];
			}
		return;
	}
	else if(c!=0 && cnt!=6)
		for(int i=h[now];i;i=nxt[i])
			dfs(t[i],c-1,cnt);
	return;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=2;i<=n;i++)	cin >> sco[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		add(x,y);
	}
	if(k==0)	dfs(1,0,1);
	else		dfs(1,k-1,1);
	cout<<ans;
	return 0;
}
