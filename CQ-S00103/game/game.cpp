#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
const int inf=(1ll<<60);
int n,m,cnt,tot,q;
int a[100005],c[100005],Bj[100005][18],Bj2[100005][18];
int f[100005][18][4],g[100005][18][4],ans;//f1 -min f2 -max f3 +min f4 +max
inline int LOg2(int u)
{
	int s=0;
	while(u)
	{
		u>>=1;s++;
	}
	return s-1;
}
inline int read()
{
	int s=0,kw=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') 
	{
		if(ch=='-') kw=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*kw;
}
inline void putch(long long u)
{
	if(u<0) putchar('-'),u=-u;
	int s=0;
	char ch[25];
	while(u)
	{
		ch[++s]=(u%10)^48;
		u/=10;
	}
	if(!s) ch[++s]=48;
	for(int i=s;i;i--)
		putchar(ch[i]);
	putchar('\n');
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=m;i++)
		c[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0) f[i][0][0]=f[i][0][1]=a[i],f[i][0][2]=inf;
		if(a[i]==0) Bj[i][0]=1,f[i][0][2]=inf,f[i][0][1]=-inf;
		if(a[i]>0) f[i][0][2]=f[i][0][3]=a[i],f[i][0][1]=-inf;
	}
	for(int j=1;j<=LOg2(n);j++)
	for(int i=1;i<=n;i++)
		f[i][j][0]=min(f[i][j-1][0],f[i+(1<<(j-1))][j-1][0]),
		f[i][j][1]=max(f[i][j-1][1],f[i+(1<<(j-1))][j-1][1]),
		f[i][j][2]=min(f[i][j-1][2],f[i+(1<<(j-1))][j-1][2]),
		f[i][j][3]=max(f[i][j-1][3],f[i+(1<<(j-1))][j-1][3]),
		Bj[i][j]=(Bj[i][j-1]||Bj[i+(1<<(j-1))][j-1]);
	
	for(int i=1;i<=m;i++)
	{
		if(c[i]<0) g[i][0][0]=g[i][0][1]=c[i],g[i][0][2]=inf;
		if(c[i]==0) Bj2[i][0]=1,g[i][0][2]=inf,g[i][0][1]=-inf;
		if(c[i]>0) g[i][0][2]=g[i][0][3]=c[i],g[i][0][1]=-inf;
	}
	for(int j=1;j<=LOg2(m);j++)
	for(int i=1;i<=m;i++)
		g[i][j][0]=min(g[i][j-1][0],g[i+(1<<(j-1))][j-1][0]),
		g[i][j][1]=max(g[i][j-1][1],g[i+(1<<(j-1))][j-1][1]),
		g[i][j][2]=min(g[i][j-1][2],g[i+(1<<(j-1))][j-1][2]),
		g[i][j][3]=max(g[i][j-1][3],g[i+(1<<(j-1))][j-1][3]),
		Bj2[i][j]=(Bj2[i][j-1]||Bj2[i+(1<<(j-1))][j-1]);
	for(int i=1,l1,l2,r1,r2;i<=q;i++)
	{
		l1=read();r1=read();l2=read();r2=read();
		int k1=LOg2(r1-l1+1),k2=LOg2(r2-l2+1);
		long long s1=0,s2=0,s3=0,s4=0;
		long long w1,w2,w3,w4,w6,w7,w8,w9;
		bool bj1,bj2,bj3,bj4,bj5,bj6,bj7,bj8,bj9,bj10;
		w1=min(f[l1][k1][0],f[r1-(1<<k1)+1][k1][0]);
		bj1=(w1<0);
		w2=max(f[l1][k1][1],f[r1-(1<<k1)+1][k1][1]);
		bj2=(w2!=-inf);
		w3=min(f[l1][k1][2],f[r1-(1<<k1)+1][k1][2]);
		bj3=(w3!=inf);
		w4=max(f[l1][k1][3],f[r1-(1<<k1)+1][k1][3]);
		bj4=(w4>0);

		bj5=(Bj[l1][k1]||Bj[r1-(1<<k1)+1][k1]);
		
		w6=min(g[l2][k2][0],g[r2-(1<<k2)+1][k2][0]);
		bj6=(w6<0);
		w7=max(g[l2][k2][1],g[r2-(1<<k2)+1][k2][1]);
		bj7=(w7!=-inf);
		w8=min(g[l2][k2][2],g[r2-(1<<k2)+1][k2][2]);
		bj8=(w8!=inf);
		w9=max(g[l2][k2][3],g[r2-(1<<k2)+1][k2][3]);
		bj9=(w9>0);
		
		bj10=(Bj2[l2][k2]||Bj2[r2-(1<<k2)+1][k2]);
		
		ans=-inf;
		if(bj1) // a-min
		{
			if(bj9) s1=w1*w9;
			else if(bj10) s1=0;
			else if(bj7) s1=w1*w7;
			ans=max(ans,s1);
		}
		if(bj2) //a-max
		{
			if(bj9) s2=w2*w9;
			else if(bj10) s2=0;
			else if(bj7) s2=w2*w7;
			ans=max(ans,s2);
		}
		if(bj3) //a+min
		{
			if(bj6) s3=w3*w6;
			else if(bj10) s3=0;
			else if(bj8) s3=w3*w8;
			ans=max(ans,s3);
		}
		if(bj4) //a+max
		{
			if(bj6) s4=w4*w6;
			else if(bj10) s4=0;
			else if(bj8) s4=w4*w8;
			ans=max(ans,s4);
		}
//		printf("%lld %lld %lld %lld\n",s1,s2,s3,s4);
//		ans=max(s1,max(s2,max(s3,s4)));
		if(bj5) ans=max(ans,0ll);
		putch(ans);
	}
}
