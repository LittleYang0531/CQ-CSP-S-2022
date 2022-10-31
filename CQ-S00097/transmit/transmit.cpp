#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define N 200005
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int n,Q,k,p[N][55],d[N],l,x,y,prt;
LL a[N],s[N];
vector<int> e[N*2];
void dfs(int u,int fa,int dep)
{
	s[u]=s[fa]+a[u];
	p[u][0]=fa;
	d[u]=dep;
	for(auto v:e[u])
	{
		if(v==fa)
		{
			continue;
		}
		dfs(v,u,dep+1);
	}
}
void ST()
{
	l=log2(n);
	for(int j=1;j<=l;j++)
	{
		for(int i=1;i<=n;i++)
		{
			p[i][j]=p[p[i][j-1]][j-1];
		}
	}
}
int Ask(int a,int b)
{
	if(d[a]<d[b])
	{
		swap(a,b);
	}
	l=log2(d[a]-d[b]);
	for(int i=l;i>=0;i--)
	{
		if(d[p[a][i]]>=d[b])
		{
			a=p[a][i];
		}
	}
//	printf("a:%d\n",a);
	if(a==b)
	{
		return a;
	}
	l=log2(d[a]);
	for(int i=l;i>=0;i--)
	{
		if(p[a][i]!=p[b][i])
		{
			a=p[a][i];
			b=p[b][i];
		}
	}
	return p[a][0];
}
void solve1()
{
	ST();
	while(Q--)
	{
		scanf("%d%d",&x,&y);
		prt=Ask(x,y);
		printf("%lld\n",s[x]+s[y]-2*s[p[prt][0]]-a[prt]);
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&Q,&k);
	int u,v;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0,1);
	if(k==1)
	{
		solve1();
	}
	return 0;
}
/*
9 3 1
1 2 3 4 5 6 7 8 9
1 2
1 3
2 4
2 5
2 6
4 7
3 8
8 9
6 7
4 6
5 9

10 10 1
1 2 3 4 5 6 7 8 9 10
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9
1 7
1 5
2 1
1 9
10 5
3 10
2 9
10 2
1 4
4 7

*/

