#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=500005,MAXN=9223372036854775807;
ll n,m,f[M],r[M],s[M],h[M],cnt,ans,q,t1,t2;
bool vis[M],b[M];
struct node
{
	ll to,next;
	bool tp,w;
}e[5000005];
void add(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=h[u];
	h[u]=cnt;
}
void bkl(int x)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(!e[i].w)
		continue;
		else
		{
			int y=e[i].to;
			for(int j=h[y];j;j=e[j].next)
			{
				if(!e[j].w&&e[j].to==x)
				{
					if(e[j].tp)
					break;
					e[j].tp=1;
					s[y]--,r[x]--;
					break;
				}
			}
		}	
	}
	return;
}
void bkh(int u,int v)
{
	for(int i=h[u];i;i=e[i].next)
	{
		if(!e[i].w&&e[i].to==v)
		{
			if(e[i].tp)
			return;
			e[i].tp=1;
			s[u]--,r[v]--;
			return;
		}
	}
}
void rel(int x)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(!e[i].w)
		continue;
		else
		{
			int y=e[i].to;
			for(int j=h[y];j;j=e[j].next)
			{
				if(!e[j].w&&e[j].to==x)
				{
					if(!e[j].tp)
					break;
					e[j].tp=0;
					s[y]++,r[x]++;
					break;
				}
			}
		}	
	}
	return;
}
void reh(int u,int v)
{
	for(int i=h[u];i;i=e[i].next)
	{
		if(!e[i].w&&e[i].to==v)
		{
			if(!e[i].tp)
			return;
			e[i].tp=0;
			s[u]++,r[v]++;
			return;
		}
	}
}
void topo(int x,int t)
{
	vis[x]=1;
	if(t)
	return;
	if(!s[x]&&!t)
	{
		ans=1;
		return;
	}
	for(int i=h[x];i;i=e[i].next)
	{
		if(!e[i].tp&&!e[i].w)
		{
			int y=e[i].to;
			if(vis[y])
			{
				topo(y,1);
				return;
			}
			topo(y,0);
		}
	}
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		s[u]++,r[v]++;
		add(u,v,0);
		add(v,u,1);
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		memset(vis,0,sizeof(vis));
		ans=0;
		int op,xx,u,v,k=0;
		cin>>op;
		if(op==1)
		{
			cin>>u>>v;
			bkh(u,v);
		}
		if(op==2)
		{
			cin>>xx;
			bkl(xx);
		}
		if(op==3)
		{
			cin>>u>>v;
			reh(u,v);
		}
		if(op==4)
		{
			cin>>xx;
			rel(xx);
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]>1||(r[i]>0&&s[i]==0))
			{
				cout<<"NO\n";
				k=1;
				break;
			}
		}
		if(k)
		continue;
		for(int i=1;i<=n;i++)
		{
			if(!((s[i]==1&&r[i]==1)||(s[i]==0&&r[i]==0)))
			{
				k=1;
				break;
			}
		}
		if(!k)
		{
			cout<<"YES\n";
			continue;
		}
		else
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&s[i]>0&&r[i]==0)
			{
				topo(i,0);
				if(ans==1)
				{
					cout<<"NO\n";
					k=0;
					break;
				}
			}
		}
		if(k)
		cout<<"YES\n";
	}
	return 0;
}
