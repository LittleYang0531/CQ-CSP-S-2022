//n^4+Floyd暴力 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2505;
int dis[MAXN][MAXN];
int a[MAXN];
int MAX=LONG_LONG_MIN;
int n,m,K;
int Max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
inline bool check(int x,int y)
{
	if(0ll>dis[x][y]||dis[x][y]>K) return false;
	else return true;
}
void Floyd(int n)
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
void solve()
{
	scanf("%lld%lld%lld",&n,&m,&K);
	for(int i=2;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=0x3f;//哈儿不知道极大值是什么 
		}
	}
	while(m--)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		dis[x][y]=1;
		dis[y][x]=1;
	}
	Floyd(n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]--;
//			cout<<i<<" "<<j<<" : "<<dis[i][j]<<endl; 
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(!check(1,i)) continue;
		for(int j=2;j<=n;j++)
		{
			if(i==j||!check(i,j)) continue;
			for(int k=2;k<=n;k++)
			{
				if(i==k||j==k||!check(j,k)) continue;
				for(int l=2;l<=n;l++)
				{
					if(i==l||j==l||k==l||!check(k,l)||!check(l,1)) continue;
					MAX=Max(MAX,a[i]+a[j]+a[k]+a[l]);
				}
			}
		}
	}
	printf("%lld",MAX);
}
signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	solve();
	return 0;
}
