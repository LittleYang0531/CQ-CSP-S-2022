#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=310;
const int INF=1e8+10;
int n,m,k;
ull c[N];
int mmp[N][N];

int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}

ull uread()
{
	ull x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}

signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(); m=read(); k=read();
	for(int i=2;i<=n;i++)
		c[i]=uread();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			mmp[i][j]=INF;
			if(i==j) mmp[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		mmp[x][y]=1; mmp[y][x]=1;
	}
	for(int ik=1;ik<=n;ik++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(mmp[i][j]>=mmp[i][ik]+mmp[ik][j])
					mmp[i][j]=mmp[i][ik]+mmp[ik][j];
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//			cout<<mmp[i][j]<<" ";
//		cout<<"\n";
//	}
	ull ans=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			if(i==j) continue;
			for(int x=2;x<=n;x++)
			{
				if(x==i || x==j) continue;
				for(int y=2;y<=n;y++)
				{
					if(y==i || y==j || y==x) continue;
					if(mmp[1][i]-1<=k && mmp[i][j]-1<=k &&
					   mmp[j][x]-1<=k && mmp[x][y]-1<=k && mmp[y][1]-1<=k)
					{
						if(ans<c[i]+c[j]+c[x]+c[y])
							ans=max(ans,c[i]+c[j]+c[x]+c[y]);
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
