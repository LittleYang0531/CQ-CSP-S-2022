#include <bits/stdc++.h>
using namespace std;
int h[1000005],cnt;
struct edge{int next,to;}e[1000005];
void add(int x,int y){e[++cnt]=(edge){h[x],y},h[x]=cnt;}
int d[1000005],v[1000005];

void dfs(int x,int fa)
{
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(y==fa)continue;
		d[y]=d[x]+v[y];
		dfs(y,x);
	}
}

int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int n,q,k;
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		memset(d,0,sizeof(d));
		d[x]=v[x];
		dfs(x,0);
		cout<<d[y]<<endl;
	}
	return 0;
}
