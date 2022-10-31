#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,sum,num,ans,c[1005][1005],a[100005],b[100005],l,r,ll,rr;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=m;++i)
		b[i]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			c[i][j]=a[i]*b[j];
	for(int i=1;i<=q;++i)
	{
		l=read(),r=read(),ll=read(),rr=read();
		num=-0x3f3f3f3f;
		for(int j=l;j<=r;++j)
		{
			sum=0x3f3f3f3f;
			for(int g=ll;g<=rr;++g)
				sum=min(sum,c[j][g]);
			num=max(num,sum);
		}
		printf("%lld\n",num);
	}
	return 0;
}
