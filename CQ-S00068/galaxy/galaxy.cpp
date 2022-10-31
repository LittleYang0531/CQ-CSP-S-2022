#include<bits/stdc++.h>
using namespace std;
struct node
{
	int to,next;
}e[1000005];
struct Node
{
	int num,x,y;
}s[500005];
struct did
{
	int x,t;
};
int n,m,cnt,h[500005];
void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
vector<did>fqr[500005];
int v[500005];
int q,kong[500005],sz[500005],vis[500005];
int Top[500005],top,num,belong[500005],dfn[500005],low[500005],scc;
void tarjan(int root)
{
	dfn[root]=++num;
	low[root]=num;
	kong[root]=1;
	Top[++top]=root;
	for(int i=h[root];i;i=e[i].next)
	{
		int y=e[i].to;
		if(!dfn[y])
		{
			tarjan(y);
			low[root]=min(low[root],low[y]);
		}
		else if(vis[y])low[root]=min(low[root],dfn[y]);
	}
	if(low[root]==dfn[root])
	{
		int t=0;
		scc++;
		do
		{
			t=Top[top--];
			vis[t]=0;
			belong[t]=scc;
			++sz[scc];
		}while(t!=root);
	}
}
void work(int i)
{
	cin>>s[i].num;
	if(s[i].num==1)
	{
		cin>>s[i].x>>s[i].y;
		for(int dz=0;dz<fqr[s[i].y].size();dz++)
		{
			if(fqr[s[i].y][dz].x==s[i].x)
			{
				v[fqr[s[i].y][dz].t]=1;
				break;
			}
		}
	}
	else if(s[i].num==2)
	{
		cin>>s[i].y;
		for(int dz=0;dz<fqr[s[i].y].size();dz++)
		{
			v[fqr[s[i].y][dz].t]=1;
		}		
	}
	else if(s[i].num==3)
	{
		cin>>s[i].x>>s[i].y;
		for(int dz=0;dz<fqr[s[i].y].size();dz++)
		{
			if(fqr[s[i].y][dz].x==s[i].x)
			{
				v[fqr[s[i].y][dz].t]=0;
				break;
			}
		}		
	}
	else
	{
		cin>>s[i].y;
		for(int dz=0;dz<fqr[s[i].y].size();dz++)
		{
			v[fqr[s[i].y][dz].t]=0;
		}			
	}
	cout<<"NO\n";
}
int main()
{	
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		did rez;
		rez.t=cnt;
		rez.x=x;
		fqr[y].push_back(rez);
	}
	cin>>q;
	for(int i=1;i<=q;i++)work(i);
	return 0;
}
/*
*/
