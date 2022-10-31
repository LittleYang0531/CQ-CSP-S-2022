//hj23308±£ÓÓÎÒ
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2505;
long long ans;
long long pf;
int n,m,K;
bool bj[MAXN];
long long a[MAXN];
int f[305][305];
void dfs(int u,int k,long long he)
{
	if(k==4)
	{
		if(f[1][u]-1<=K)
		{
			ans=max(ans,he);
		}
		return;
	}
	bj[u]=1;
	for(int i=2;i<=n;i++)
	{
		if(bj[i]==1)
		{
			continue;
		}
		if(f[u][i]-1<=K)
		{
			dfs(i,k+1,he+a[i]);
		}
	}
	bj[u]=0;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>K;
	if(n<=300)
	{
		a[1]=0;
		for(int i=2;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				f[i][j]=0x7ffffff;
			}
		}
		for(int i=1;i<=m;i++)
		{
			int aa,bb;
			cin>>aa>>bb;
			f[aa][bb]=1;
			f[bb][aa]=1;
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		dfs(1,0,0);
		cout<<ans<<'\n';
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=n-3;i--)
	{
		pf+=a[i];
	}
	cout<<pf<<'\n';
	return 0;
}
