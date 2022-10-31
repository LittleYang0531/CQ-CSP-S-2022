#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
int n,q,k;
ll v[maxn];
int Map[2005][2005];
int jl[2005][2005];
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	memset(Map,0x3f,sizeof(Map));
	memset(jl,0x3f,sizeof(jl));
	for (int i=1; i<=n; i++)
	{
		scanf("%lld",&v[i]);
		jl[i][i] = Map[i][i] = 0;
	}
	for (int i=1; i<n; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		Map[a][b] = v[a];
		Map[b][a] = v[b];
		jl[a][b] = jl[b][a] = 1;
	}
	for (int t=1; t<=n; t++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
			{
				Map[i][j] = min(Map[i][j],Map[i][t]+Map[t][j]);
				jl[i][j] = min(jl[i][j],jl[i][t]+jl[t][j]);
			}
//	for (int i=1; i<=n; i++)
//	{
//		for (int j=1; j<=n; j++)
//			cout<<Map[i][j]<<" ";
//		cout<<endl;
//	}
	for (int i=1; i<=q; i++)
	{
		int a,b;
		ll ans;
		scanf("%d%d",&a,&b);
		ans = Map[a][b]+v[b];
		printf("%lld\n",ans);
	}
	return 0;
}
