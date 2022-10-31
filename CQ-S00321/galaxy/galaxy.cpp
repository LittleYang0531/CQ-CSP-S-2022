#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node
{
	int to,l;
};
int n,m,x,y,q,t,u_,v_,flag;
int l[N];
vector<node>v[N];
int dfs(int now)
{
	if(l[now]==1)
	{
		return 1;
	}
	l[now]=1;
	for(int i=0;i<v[now].size();i++)
	{
		if(v[now][i].l==1)
		{
			continue;
		}
		if(dfs(v[now][i].to)==1)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		node a;
		a.to=y;
		v[x].push_back(a);
	}
	scanf("%d",&q);
	for(int u=1;u<=q;u++)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d",&u_,&v_);
			for(int i=0;i<v[u_].size();i++)
			{
				if(v[u_][i].to==v_)
				{
					v[u_][i].l=1;
					break;
				}
			}
		}
		else if(t==2)
		{
			scanf("%d",&u_);
			for(int i=0;i<v[u_].size();i++)
			{
				v[u_][i].l=1;
			}
		}
		else if(t==3)
		{
			scanf("%d%d",&u_,&v_);
			for(int i=0;i<v[u_].size();i++)
			{
				if(v[u_][i].to==v_)
				{
					v[u_][i].l=0;
					break;
				}
			}
		}
		else if(t==4)
		{
			scanf("%d",&u_);
			for(int i=0;i<v[u_].size();i++)
			{
				v[u_][i].l=1;
			}
		}
		flag=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				l[i]=0;
			}
			if(dfs(i)==0)
			{
				flag=0;
			}
			int k=0;
			for(int j=0;j<v[i].size();j++)
			{
				k+=v[i][j].l;
			}
			if(k!=1)
			{
				flag=0;
			}
			if(flag==0)
			{
				break;
			}
		}
		if(flag==1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
