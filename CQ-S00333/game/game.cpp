#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18+10;
const int N=1e5+10;
const int M=3e3;
int n,m,q;
int a[N],b[N];
int c[M][M];

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

signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(); m=read(); q=read();
//	if(n>M || m>M) return 0;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			c[i][j]=a[i]*b[j];
	for(int qq=1;qq<=q;qq++)
	{
		int l1=read(),r1=read(),l2=read(),r2=read();
		int axz=-INF,aiz=INF,axf=-INF,aif=INF,fa=0;
		for(int i=l1;i<=r1;i++)
		{
			if(a[i]==0) fa=1;
			if(a[i]>0)
			{
				axz=max(axz,a[i]);
				aiz=min(aiz,a[i]);
			}
			if(a[i]<0)
			{
				axf=max(axf,a[i]);
				aif=min(aif,a[i]);
			}
		}
//		cout<<axz<<' '<<aiz<<' '<<axf<<' '<<aif<<"\n";
		int bxz=-INF,biz=INF,bxf=-INF,bif=INF,fb=0;
		for(int i=l2;i<=r2;i++)
		{
			if(b[i]==0) fb=1;
			if(b[i]>0)
			{
				bxz=max(bxz,b[i]);
				biz=min(biz,b[i]);
			}
			if(b[i]<0)
			{
				bxf=max(bxf,b[i]);
				bif=min(bif,b[i]);
			}
		}
//		cout<<bxz<<' '<<biz<<' '<<bxf<<' '<<bif<<"\n\n";
		if(bxz==-INF && bxf==-INF)
		{
			printf("0\n");
			continue;
		}
		if(axz==-INF && axf==-INF)
		{
			printf("0\n");
			continue;
		}
		if(bxz==-INF && bxf!=-INF)
		{
			if(axf!=-INF)
			{
				if(fb) printf("0\n");
				else printf("%lld\n",aif*bxf);
			}
			else if(axz!=-INF && axf==-INF && !fa) printf("%lld\n",aiz*bxf);
			else if(axz!=-INF && axf==-INF && fa) printf("0\n");
		}
		else if(bxz!=-INF && bxf==-INF)
		{
			if(axz!=-INF)
			{
				if(fb) printf("0\n");
				else printf("%lld\n",axz*biz);
			}
			else if(axz==-INF && axf!=-INF && !fa) printf("%lld\n",aif*bxz);
			else if(axz==-INF && axf!=-INF && fa) printf("0\n");
		}
		else if(bxz!=-INF && bxf!=-INF)
		{
			if(fa) printf("0\n");
			else printf("%lld\n",max(axf*bxz,aiz*bif));
		}
	}
	return 0;
}
