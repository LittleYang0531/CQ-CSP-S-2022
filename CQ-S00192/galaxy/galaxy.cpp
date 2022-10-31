#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,q;
int cd[N];
int h[N],e[2*N],ne[2*N],idx;
bool vis[N];
int cnt;
void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		cd[a]++;
		if(cd[a]==1)cnt++;
		else if(cd[a]==2)cnt--;
		add(b,a);
	}
	scanf("%d",&q);
	int op,u,v;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&v,&u);
			for(int i=h[u];i!=-1;i=ne[i])
				if(e[i]==v)
				{
					vis[i]=1;
					cd[v]--;
					if(cd[v]==1)cnt++;
					else if(cd[v]==0)cnt--;
					break;
				}
		}
		else if(op==2)
		{
			scanf("%d",&u);
			for(int i=h[u];i!=-1;i=ne[i])
			{
				v=e[i];
				if(!vis[i])
				{
					cd[v]--;
					if(cd[v]==1)cnt++;
					else if(cd[v]==0)cnt--;
				}
				vis[i]=1;	
			}
		}
		else if(op==3)
		{
			scanf("%d%d",&v,&u);
			for(int i=h[u];i!=-1;i=ne[i])
				if(e[i]==v)
				{
					vis[i]=0;
					cd[v]++;
					if(cd[v]==1)cnt++;
					else if(cd[v]==2)cnt--;
					break;
				}
		}
		else if(op==4)
		{
			scanf("%d",&u);
			for(int i=h[u];i!=-1;i=ne[i])
			{
				v=e[i];
				if(vis[i])
				{
					cd[v]++;
					if(cd[v]==1)cnt++;
					else if(cd[v]==2)cnt--;
				}
				vis[i]=0;	
			}
		}
		if(cnt==n)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
