//hj23308±£ÓÓÎÒ
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,t,K;
int x,y;
int v[MAXN];
int shen[MAXN];
int p[MAXN];
int ju[2005][2005];
long long f[2005][2005];
int sum,h[MAXN];
struct node{
	int next;
	int to;
}a[MAXN];
void hb(int aa,int bb)
{
	sum++;
	a[sum].next=h[aa];
	a[sum].to=bb;
	h[aa]=sum;
}
void dfs(int u,int father,int k)
{
	p[u]=father;
	shen[u]=k+1;
	for(int i=h[u];i;i=a[i].next)
	{
		int v=a[i].to;
		if(v==father)
		{
			continue;
		}
		dfs(v,u,k+1);
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>t>>K;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		int aa,bb;
		cin>>aa>>bb;
		hb(aa,bb);
		hb(bb,aa);
	}
	dfs(1,0,0);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		f[i][i]=v[i];
		for(int j=i+1;j<=n;j++)
		{
			int num=0;
			int hj1=i,hj2=j;
			if(shen[hj1]<shen[hj2])
			{
				swap(hj1,hj2);
			}
			int zeq1=shen[hj1],zeq2=shen[hj2];
			while(zeq1!=zeq2)
			{
				num++;
				zeq1--;
				hj1=p[hj1];
			}
			while(hj1!=hj2)
			{
				num+=2;
				hj1=p[hj1];
				hj2=p[hj2];
			}
			ju[i][j]=num;
			ju[j][i]=num;
			if(num<=K)
			{
				f[i][j]=v[i]+v[j];
				f[j][i]=v[i]+v[j];
//				if(i==1&&j==2)
//				{
//					cout<<f[1][2]<<'\n';
//				}
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]-v[k]);
			}
		}
	}
	while(t--)
	{
		int x,y;
		cin>>x>>y;
//		cout<<x<<' '<<y<<'\n';
		cout<<f[x][y]<<'\n';
//		cout<<f[1][2]<<'\n';
	}
	return 0;
}
/*
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
*/
