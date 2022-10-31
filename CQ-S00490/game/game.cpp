#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,m,q;
ll a[N],b[N],C[1005][1005];

int lg[N];
ll st[1005][1005][12];
void init()
{
	lg[0]=-1;
	for(int i=1;i<=max(n,m);i++)
		lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=m;j++)
		{
			C[i][j]=a[i]*b[j];
			st[i][j][0]=C[i][j];
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=lg[m];j++)
		{
			for(int k=1;k<=m;k++)
			{
				st[i][k][j]=1e18;
				if(k+(1<<j-1)>m) continue;
				st[i][k][j]=min(st[i][k][j-1],st[i][k+(1<<j-1)][j-1]);
			}
		}
	}
}
ll query(int x,int l,int r)
{
	if(l==r) return C[x][l];
	int k=lg[r-l];
	return min(st[x][l][k],st[x][r-(1<<k)+1][k]);
}
void solve1()
{
	init();
	while(q--)
	{
		int l1,r1,l2,r2;
		ll maxn=-1e18;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		for(int i=l1;i<=r1;i++)
		{
			maxn=max(maxn,query(i,l2,r2));
		}
		printf("%lld\n",maxn);
	}
	
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%lld",&b[i]);
	if(n<=1000)
	{
		solve1();
	}
	else
	{
		printf("0\n");
	}
	return 0;
}
