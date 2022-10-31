#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;
	char s=getchar();
	int f=1;
	while(s<'0'||s>'9')
	{
		if(s=='-')
		{
			f*=-1;
		}
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x*10)+(s-'0');
		s=getchar();
	}
	x*=f;
	return;
}
const int MAXN=5e5+5;
int n,m,q;
vector<int>g[MAXN];
vector<int>Rg[MAXN];
int Vis[MAXN];
struct Edge{
	int u,v;
}edge[MAXN];
int op,x,y;
map<pair<int,int>,int>Rec;
int vis[MAXN];
int cnt_node;
int cnt_edge;
void dfs(int x)
{
	if(vis[x])
	{
		return;
	}
	vis[x]=1;
	cnt_node++;
	for(int i=0;i<g[x].size();i++)
	{
		int Pos=g[x][i];
		if(Vis[Pos])
		{
			continue;
		}
		int v=edge[Pos].v;
		
		cnt_edge++;
		dfs(v);
	}
	for(int i=0;i<Rg[x].size();i++)
	{
		int Pos=Rg[x][i];
		if(Vis[Pos])
		{
			continue;
		}
		int v=edge[Pos].u;
		cnt_edge++;
		dfs(v);
	}

}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=m;i++)
	{
		read(x);
		read(y);
		edge[i].u=x;
		edge[i].v=y;
		Rec[make_pair(x,y)]=i;
		g[x].push_back(i);
		Rg[y].push_back(i);
	}
	read(q);
	while(q--)
	{
		read(op);
		if(op==1)
		{
			read(x);
			read(y); 
			Vis[Rec[make_pair(x,y)]]=1;
		}
		else if(op==2)
		{
			read(x);
			for(int i=0;i<Rg[x].size();i++)
			{
				int Pos=Rg[x][i];
				Vis[Pos]=1;
			}
		}
		else if(op==3)
		{
			read(x);
			read(y);
			Vis[Rec[make_pair(x,y)]]=0;
		}
		else
		{
			read(x); 
			for(int i=0;i<Rg[x].size();i++)
			{
				int Pos=Rg[x][i];
				Vis[Pos]=0;
			}
		} 
		bool f=0;
		for(int i=1;i<=n;i++)
		{
			int Tot=0;
			for(int j=0;j<g[i].size();j++)
			{
				int Dx=g[i][j];
				if(!Vis[Dx])
				{
					Tot++;
				}
			}
			if(Tot!=1)
			{
				f=1;
			}
		}
		if(f)
		{
			printf("NO\n");
		}
		else
		{
			memset(vis,0,sizeof(vis));
			for(int i=1;i<=n;i++)
			{
				if(!vis[i])
				{
					cnt_node=0;
					cnt_edge=0;
					dfs(i);
					if(cnt_node*2!=cnt_edge)
					{
						f=1;
					}
				}
			}
			if(f)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
		}
	}
	return 0;
}
