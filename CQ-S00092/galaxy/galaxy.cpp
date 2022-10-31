#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>

#define maxn 1005
#define rc() getchar()

using namespace std;

int n,m,a[maxn][maxn],t[maxn][maxn],rd[maxn],f[maxn],bj[maxn];

inline int read()
{
	int x=0,b=1;char c=rc();
	while(c<'0'||c>'9') (c=='-')&&(b=-1),c=rc();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=rc();
	return x*b;
}

inline int getf(int x) {return (x==f[x]?x:f[x]=getf(f[x]));}

inline bool solve()
{
	for(int i=1;i<=n;++i)
		if(rd[i]!=1) return false;
	for(int i=1;i<=n;++i) f[i]=i,bj[i]=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(t[i][j])
			{
				int fx=getf(j);
				if(fx==i) bj[i]=1;
				else f[i]=fx;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		f[i]=getf(i);
		if(bj[i]) bj[f[i]]=1;
	}
	for(int i=1;i<=n;++i)
		if(!bj[f[i]]) return false;
	return true;
}

inline void solve1(int x,int y)
{
	if(t[x][y]) t[x][y]=0,--rd[x];
}

inline void solve2(int x)
{
	for(int i=1;i<=n;++i)
		if(t[i][x]) t[i][x]=0,--rd[i];
}

inline void solve3(int x,int y)
{
	if(!t[x][y]) t[x][y]=1,++rd[x];
}

inline void solve4(int x)
{
	for(int i=1;i<=n;++i)
		if(t[i][x]==0&&a[i][x]==1) t[i][x]=1,++rd[i];
}

int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read();
		t[x][y]=a[x][y]=1;rd[x]++;
	}
	int q=read();
	for(int i=1;i<=q;++i)
	{
		int op=read(),x=read(),y;
		if(op==1) y=read(),solve1(x,y);
		if(op==2) solve2(x);
		if(op==3) y=read(),solve3(x,y);
		if(op==4) solve4(x);
		if(solve()) puts("YES");else puts("NO");
	}
	return 0;
}


