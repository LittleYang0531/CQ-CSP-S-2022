#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5,M=1e6+5;

int n,m,q;
int la[N],ne[M],en[M],la1[N],ne1[M],en1[M],st[M],idx;
int du[N];
set<int> s,r;
bool vis[N];

void add(int a,int b)
{
	idx++;
	ne[idx]=la[a];
	la[a]=idx;
	ne1[idx]=la1[b];
	la1[b]=idx;
	en[idx]=b;
	en1[idx]=a;
	st[idx]=1;
}

bool dfs(int u,int p)
{
	if(vis[u])return true;
	vis[u]=true;
	for(int i=la[u];i;i=ne[i])
		if(st[i]&&dfs(en[i],u))
			return true;
	return false;
}

int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		du[a]++;
		if(du[a]==2)s.insert(a);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		if(!dfs(i,0))
			r.insert(i);
	}
	scanf("%d",&q);
	while(q--)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			for(int i=la[x];i;i=ne[i])
				if(en[i]==y&&st[i])
				{
					st[i]=false;
					du[x]--;
					if(du[x]==1)s.erase(x);
					memset(vis,0,sizeof vis);
					if(!dfs(x,0))r.insert(x);
					memset(vis,0,sizeof vis);
				}
		}
		if(t==2)
		{
			int x;
			scanf("%d",&x);
			for(int i=la1[x];i;i=ne1[i])
				if(st[i])
				{
					int y=en1[i];
					st[i]=false;
					du[y]--;
					if(du[y]==1)s.erase(x);
				}
			for(int i=la1[x];i;i=ne1[i])
				if(!dfs(en1[i],0)&&r.count(en1[i]))
				{
					memset(vis,0,sizeof vis);
					r.insert(en1[i]);
				}
		}
		if(t==3)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			for(int i=la[x];i;i=ne[i])
				if(en[i]==y&&!st[i])
				{
					st[i]=true;
					du[x]++;
					if(du[x]==2)s.insert(x);
				}
			memset(vis,0,sizeof vis);
			if(r.count(x)&&dfs(x,0))r.erase(x);
		}
		if(t==4)
		{
			int x;
			scanf("%d",&x);
			for(int i=la1[x];i;i=ne1[i])
				if(!st[i])
				{
					int y=en1[i];
					st[i]=true;
					du[y]++;
					if(du[y]==2)s.insert(x);
				}
			for(int i=la1[x];i;i=ne1[i])
				if(dfs(en1[i],0)&&r.count(en1[i]))
				{
					memset(vis,0,sizeof vis);
					r.erase(en1[i]);
				}
		}
		bool flag=true;
		for(int i=1;i<=n;i++)
			if(!dfs(i,0))
			{
				flag=false;
				break;
			}
		if(s.empty()&&flag)puts("YES");
		else puts("NO");
	}
}
