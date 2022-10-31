#include<bits/stdc++.h>
#define rd read()
using namespace std;
const int N=1e3+50;
int am[N][N],bm[N][N];
long long ab[N][N],a[N],b[N];
bool flag1=false,flag2=false;
long long read()
	{
		long long x=0,f=1;
		char c=getchar();
		while (c<'0' or c>'9')
			{
				if (c=='-')
					f=-1;
				c=getchar();
			}
		while (c>='0' and c<='9')
			{
				x=x*10+(c-'0');
				c=getchar();
			}
		return x*f;
	}
int main()
	{
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);
		int n=rd,m=rd,q=rd;
		for (int i=1;i<=n;i++)
			{
				a[i]=rd;
				am[i][i]=a[i];
				if (flag1 and a[i]<=0) flag1=false;
			}
		for (int i=1;i<=m;i++)
			{
				b[i]=rd;
				bm[i][i]=b[i];
				if (flag1 and b[i]<=0) flag1=false;
			}
		if (flag1)
			{
				for (int i=1;i<=n;i++)
					for (int j=i+1;j<=n;j++)
						am[i][j]=max((long long)am[i][j-1],a[j]);
				for (int i=1;i<=m;i++)
					for (int j=i+1;j<=m;j++)
						bm[i][j]=min((long long)bm[i][j-1],b[j]);
				for (int tmp=1;tmp<=q;tmp++)
					{
						int l1=rd,r1=rd,l2=rd,r2=rd;
						printf("%lld\n",am[l1][r1]*bm[l2][r2]);
					}
			}
		else
			{
				for (int i=1;i<=n;i++)
					for (int j=1;j<=m;j++)
						ab[i][j]=a[i]*b[j];
				for (int tmp=1;tmp<=q;tmp++)
					{
						int l1=rd,r1=rd,l2=rd,r2=rd;
						long long minn=1000000000000000000,maxx=-1000000000000000000;
						for (int i=l1;i<=r1;i++)
							{
								minn=2e18;
								for (int j=l2;j<=r2;j++)
									{
										minn=min(minn,ab[i][j]);
									}
								maxx=max(maxx,minn);
							}
						printf("%lld\n",maxx);	
					}
			}
	}

