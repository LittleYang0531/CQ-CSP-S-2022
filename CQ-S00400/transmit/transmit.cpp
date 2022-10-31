#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{int next,to;}q[200001];
int n,qq,k,h[200001],cnt,a[200001],g[2001][2001],g1[2001][2001];
inline void add(int x,int y){q[++cnt].next=h[x],q[cnt].to=y,h[x]=cnt;}
inline void init()
{
	cin>>n>>qq>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)g[i][j]=0x7fffffffffffff,g1[i][j]=0x7fffffffffffff;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y,g[x][y]=g[y][x]=1;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(g[i][k]!=0x7fffffffffffff&&g[k][j]!=0x7fffffffffffff)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(g[i][j]<=k&&i!=j)g1[i][j]=a[j];
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(g1[i][k]!=0x7fffffffffffff&&g1[k][j]!=0x7fffffffffffff)g1[i][j]=min(g1[i][j],g1[i][k]+g1[k][j]);
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)cout<<g[i][j]<<" ";
//		cout<<'\n';
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)cout<<g1[i][j]<<" ";
//		cout<<'\n';
//	}
}
inline void solve()
{
	while(qq--)
	{
		int s,t;
		cin>>s>>t;
		cout<<g1[s][t]+a[s]<<'\n';
	}
}
signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	init(),solve();
	return 0;
}
/*
input1:
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2

output1:
12
12
3
*/
