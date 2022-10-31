#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,ans,tot;
int out[500005];
unordered_map<int,bool>f[500005],g[500005];
void read(int&x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9')
	x=x*10+c-'0',c=getchar();
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=m;i++)
	read(u),read(v),out[u]++,f[v][u]=1;
	for(int i=1;i<=n;i++)
	ans+=out[i]!=1;
	read(m);
	while(m--)
	{
		read(n);
		read(u);
		if(tot>10000000)
		{
			if(n&1)
			read(v);
			printf("NO\n");
			continue;
		}
		if(n==1)
		{
			read(v);
			ans-=out[u]!=1;
			out[u]--;
			f[v].erase(u);
			g[v][u]=1;
			ans+=out[u]!=1;
		}
		if(n==2)
		{
			for(auto i:f[u])
			{
				tot++;
				ans-=out[i.first]!=1;
				out[i.first]--;
				g[u][i.first]=1;
				ans+=out[i.first]!=1;
			}
			f[u].clear();
		}
		if(n==3)
		{
			read(v);
			ans-=out[u]!=1;
			out[u]++;
			g[v].erase(u);
			f[v][u]=1;
			ans+=out[u]!=1;
		}
		if(n==4)
		{
			for(auto i:g[u])
			{
				tot++;
				ans-=out[i.first]!=1;
				out[i.first]++;
				f[u][i.first]=1;
				ans+=out[i.first]!=1;
			}
			g[u].clear();
		}
		printf(ans?"NO\n":"YES\n");
	}
	return 0;
}
