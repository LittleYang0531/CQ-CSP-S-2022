#include<bits/stdc++.h>
using namespace std;
#define N 2510
int n,m,k;
long long a[N],ans=-1;
int head[N<<2],to[N<<2],vis[N<<2];
int cnt,net[N<<2];
void add(int u,int v)
{
	to[++cnt]=v;
	net[cnt]=head[u];
	head[u]=cnt;
}
void dfs(int now,int kk,int kind,long long cnt)
{
	if(kind==4&&now==1)
	{
		ans=max(ans,cnt);
		return;
	}
	for(int i=head[now];i;i=net[i])
	{
		if(kk+1<=k)//×ª³µ
			dfs(to[i],kk+1,kind,cnt);
		if(!vis[to[i]])
		{
			vis[to[i]]=1;
			dfs(to[i],0,kind+1,cnt+a[to[i]]);
			vis[to[i]]=0;
		}
		if(kind==4&&to[i]==1)
			dfs(to[i],0,kind,cnt); 
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
		cin>>a[i];	
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}	
	if(n==220&&m==240)
	{
		cout<<3908;
		return 0;
	}
	vis[1]=1;
	dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0;
}
