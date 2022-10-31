#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define re register
#define r read()
#define NMAX 500005
struct edge
{
	bool use;
	int to;
};
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*f;
}
int n,m,q,u,v,s,cnt[NMAX];
vector <edge> g[NMAX];
bool pd1()
{
	memset(cnt,0,sizeof(cnt));
	for(re int i=1;i<=n;i++)
	{
		int len=g[i].size();
		for(re int j=0;j<len;j++)
			if(g[i][j].use)
				cnt[g[i][j].to]++;
	}
	for(re int i=1;i<=n;i++)
	{
		if(cnt[i]!=1)
			return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=r,m=r;
	for(re int i=1;i<=m;i++)
	{
		u=r,v=r;
		g[v].push_back(edge{1,u});
	}
	q=r;
	for(re int i=1;i<=q;i++)
	{
		s=r;
		if(s==1)
		{
			u=r,v=r;
			int len=g[v].size();
			for(re int j=0;j<len;j++)
				if(g[v][j].to==u)
				{g[v][j].use=0;break;}
		}
		else if(s==2)
		{
			u=r;
			int len=g[u].size();
			for(int j=0;j<len;j++)
				g[u][j].use=0;
		}
		else if(s==3)
		{
			u=r,v=r;
			int len=g[v].size();
			for(re int j=0;j<len;j++)
				if(g[v][j].to==u)
				{g[v][j].use=1;break;}
		}
		else
		{
			u=r;
			int len=g[u].size();
			for(int j=0;j<len;j++)
				g[u][j].use=1;
		}
		if(pd1())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
