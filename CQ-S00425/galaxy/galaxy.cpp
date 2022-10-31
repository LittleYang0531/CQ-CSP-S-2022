#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;

int n,m,q,idx;
int head[N],deg[N];
bool flag,lstans;
bool mark[N],vis[N];
vector<int> vt[N];
struct edge
{
	int fr,to,ne;
}e[N];

void add(int x,int y)
{
	e[++idx].fr=x;
	e[idx].to=y;
	e[idx].ne=head[x];
	head[x]=idx;
	vt[y].push_back(idx);
	deg[x]++;
}

void dfs(int u)
{
	vis[u]=true;
	int cnt=0;
	for(int i=head[u];i;i=e[i].ne)
		if(!mark[i])
			cnt++;
	if(cnt!=1)
	{
		flag=true;
		return;
	}
	for(int i=head[u];i;i=e[i].ne)
		if(!mark[i])
		{
			int v=e[i].to;
			if(vis[v])return;
			else dfs(v);
		}
}

bool check()
{
	memset(vis,false,sizeof vis);
	flag=false;
	for(int i=n;i>=1;i--)
		if(!vis[i])
		{
			dfs(i);
			if(flag)return false;
		}
	return true;
}

int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	scanf("%d",&q);
	while(q--)
	{
		int op,x,y;
		scanf("%d%d",&op,&x);
		if(op==2)
		{
			for(int i=0;i<vt[x].size();i++)
			{
				if(!mark[vt[x][i]])deg[e[vt[x][i]].fr]--;
				mark[vt[x][i]]=true;
			}
			lstans=false;
			puts("NO");
			continue;
		}
		else if(op==4)
		{
			bool is_ok=false;
			for(int i=0;i<vt[x].size();i++)
			{
				if(mark[vt[x][i]])
				{
					deg[e[vt[x][i]].fr]++;
				}
				if(deg[e[vt[x][i]].fr]!=1)is_ok=true;
				mark[vt[x][i]]=false;
			}
			if(lstans||is_ok)
			{
				lstans=false;
				puts("NO");
				continue;
			}
		}
		else
		{
			scanf("%d",&y);
			if(op==1)
			{
				bool is_ok=false;
				for(int i=head[x];i;i=e[i].ne)
				{
					int v=e[i].to;
					if(v==y)
					{
						deg[x]--;
						if(deg[x]!=1)is_ok=true;
						mark[i]=true;
					}
				}
				if(lstans||is_ok)
				{
					lstans=false;
					puts("NO");
					continue;
				}
			}
			else
			{
				bool is_ok=false;
				for(int i=head[x];i;i=e[i].ne)
				{
					int v=e[i].to;
					if(v==y)
					{
						mark[i]=false;
						deg[x]++;
						if(deg[x]!=1)is_ok=true;
					}
				}
				if(lstans||is_ok)
				{
					lstans=false;
					puts("NO");
					continue;
				}
			}
		}
		if(lstans=check())puts("YES");
		else puts("NO");
	}
	return 0;
}


/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2
*/
