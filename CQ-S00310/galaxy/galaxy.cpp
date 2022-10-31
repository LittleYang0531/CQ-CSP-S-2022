#include<bits/stdc++.h>
using namespace std;
int head[500001],c[500001];
int n,m,i,j,k,s,q,op,cnt;
struct eve
{
	int u,to,nxt,f;
} ed[1000001];
bool arr[500001],vis[500001],g;
map<pair<int,int>,int> mp;
void add(int x,int y)
{
	ed[++cnt].nxt=head[x];
	head[x]=cnt;
	ed[cnt].to=y;
	ed[cnt].u=x;
}
bool dfs(int nr)
{
	if(arr[nr])return 1;
	arr[nr]=1;
	for(int i=head[nr];i;i=ed[i].nxt)
	{
		if(ed[i].f)continue;
		if(vis[i])return 1;
		vis[i]=1;
		return dfs(ed[i].to);
	}
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&k,&s);
		add(k,s);mp[make_pair(k,s)]=cnt;
		c[k]++;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&op);g=0;
		if(op==1)
		{
			scanf("%d%d",&k,&s);c[k]--;
			ed[mp[make_pair(k,s)]].f=1;
		}
		if(op==2)
		{
			scanf("%d",&k);
			for(i=1;i<=cnt;i++)
				if(ed[i].to==k&&!ed[i].f)ed[i].f=1,c[ed[i].u]--;
		}
		if(op==3)
		{
			scanf("%d%d",&k,&s);c[k]++;
			ed[mp[make_pair(k,s)]].f=0;
		}
		if(op==4)
		{
			scanf("%d",&k);
			for(i=1;i<=cnt;i++)
				if(ed[i].to==k&&ed[i].f)ed[i].f=0,c[ed[i].u]++;
		}
		for(i=1;i<=n;i++)
		{
			memset(arr,0,sizeof(arr));
			memset(vis,0,sizeof(vis));
			if(c[i]>1||!dfs(i))g=1;
		}
		if(g)puts("NO");
		else puts("YES");
	}
	return 0;
}
