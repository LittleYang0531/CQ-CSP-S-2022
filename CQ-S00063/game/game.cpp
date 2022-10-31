#include<iostream>
#include<vector>
using namespace std;
#define re register
#define r read()
#define NMAX 100005
#define INF 1e18
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*f;
}
int n,m,q,a[NMAX],b[NMAX];
int l1,l2,r1,r2;
long long mi[NMAX],mapp[4000][4000];
int main()
{
	ios::sync_with_stdio(false);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=r,m=r,q=r;
	for(re int i=1;i<=n;i++)
		a[i]=r;
	for(re int i=1;i<=m;i++)
		b[i]=r;
	for(re int i=1;i<=n;i++)
	{
		long long m1=INF;
		for(re int j=1;j<=m;j++)
		{
			mapp[i][j]=a[i]*b[j];
			if(mapp[i][j]<m1)
				m1=mapp[i][j];
		}
		mi[i]=m1;
	}
	for(re int i=1;i<=q;i++)
	{
		l1=r,r1=r,l2=r,r2=r;
		long long m1=-1,m1i,m2=INF;
		for(re int j=l1;j<=r1;j++)
			if(mi[j]>m1)
				m1=mi[j],m1i=j;
		//cout<<"find m1="<<m1<<" m1i="<<m1i<<endl;
		for(re int j=l2;j<=r2;j++)
			if(mapp[m1i][j]<m2)
				m2=a[i]*b[j];
		cout<<m2<<endl;
	}
	return 0;
}
