#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<ctime>
#include<vector>
typedef long long ll;
const int maxn=100002,mod=998244353;
const int inf=(1<<30);
using namespace std;
int ask(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-f,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	return x*f;
}
int n,m,q;
int a[2][maxn];
int mn[2][maxn*4],mx[2][maxn*4];
int mn1[2][maxn*4],mx1[2][maxn*4];
void make(int k,int l,int r,int op)
{
	if(l==r)
	{
		if(op)
		{
			mn[op][k]=mx[op][k]=a[op][l];
			return;
		}
		if(a[op][l]>0)
		mn[op][k]=mx[op][k]=a[op][l];
		else
		{
			mn[op][k]=inf;
			mx[op][k]=-inf;
		}
		return;
	}
	int mid=(l+r)>>1;
	make(2*k,l,mid,op);
	make(2*k+1,mid+1,r,op);
	mn[op][k]=min(mn[op][2*k],mn[op][2*k+1]);
	mx[op][k]=max(mx[op][2*k],mx[op][2*k+1]);
}
int ask_mn(int k,int l,int r,int sl,int sr,int op)
{
	if(sl<=l&&sr>=r)return mn[op][k];
	if(sr<l||sl>r)return inf;
	int mid=(l+r)>>1;
	return min(ask_mn(2*k,l,mid,sl,sr,op),ask_mn(2*k+1,mid+1,r,sl,sr,op));
}
int ask_mx(int k,int l,int r,int sl,int sr,int op)
{
	if(sl<=l&&sr>=r)return mx[op][k];
	if(sr<l||sl>r)return -inf;
	int mid=(l+r)>>1;
	return max(ask_mx(2*k,l,mid,sl,sr,op),ask_mx(2*k+1,mid+1,r,sl,sr,op));
}
void make1(int k,int l,int r,int op)
{
	if(l==r)
	{
		if(a[op][l]<0)
		mn1[op][k]=mx1[op][k]=a[op][l];
		else
		{
			mn1[op][k]=inf;
			mx1[op][k]=-inf;
		}
		return;
	}
	int mid=(l+r)>>1;
	make1(2*k,l,mid,op);
	make1(2*k+1,mid+1,r,op);
	mn1[op][k]=min(mn1[op][2*k],mn1[op][2*k+1]);
	mx1[op][k]=max(mx1[op][2*k],mx1[op][2*k+1]);
}
int ask_mn1(int k,int l,int r,int sl,int sr,int op)
{
	if(sl<=l&&sr>=r)return mn1[op][k];
	if(sr<l||sl>r)return inf;
	int mid=(l+r)>>1;
	return min(ask_mn1(2*k,l,mid,sl,sr,op),ask_mn1(2*k+1,mid+1,r,sl,sr,op));
}
int ask_mx1(int k,int l,int r,int sl,int sr,int op)
{
	if(sl<=l&&sr>=r)return mx1[op][k];
	if(sr<l||sl>r)return -inf;
	int mid=(l+r)>>1;
	return max(ask_mx1(2*k,l,mid,sl,sr,op),ask_mx1(2*k+1,mid+1,r,sl,sr,op));
}
int v[maxn];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)a[0][i]=read();
	for(int i=1;i<=n;i++)if(a[0][i]==0)v[++v[0]]=i;
	v[++v[0]]=n+1;
	for(int i=1;i<=m;i++)a[1][i]=read();
	make(1,1,n,0);
	make(1,1,m,1);
	make1(1,1,n,0);
	while(q--)
	{
		int l1=read(),r1=read(),l2=read(),r2=read();
		int mn0=ask_mn(1,1,n,l1,r1,0),mx0=ask_mx(1,1,n,l1,r1,0),mn1=ask_mn(1,1,m,l2,r2,1),mx1=ask_mx(1,1,m,l2,r2,1);
		int mn10=ask_mn1(1,1,n,l1,r1,0),mx10=ask_mx1(1,1,n,l1,r1,0);
		int pos=lower_bound(v+1,v+v[0]+1,l1)-v;
		ll ans=-(1ll<<60);
		if(v[pos]<=r1)ans=0;
		if(mn10!=inf)ans=max(ans,1ll*mn10*mx1);
		if(mn0!=inf)ans=max(ans,1ll*mn0*mn1);
		if(mx10!=-inf)ans=max(ans,1ll*mx10*mx1);
		if(mx0!=-inf)ans=max(ans,1ll*mx0*mn1);
		printf("%lld\n",ans);
	}
	return 0;
}


