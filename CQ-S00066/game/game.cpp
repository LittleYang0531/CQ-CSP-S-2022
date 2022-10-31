#include<bits/stdc++.h>
namespace ifzw{
#define ll long long
#define dd double
#define LL __int128
#define ull unsigned ll
#define uLL __uint128_t 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=1e5+5;
int n,m,q;
int a[xx],b[xx];
int u[xx],is[xx];
struct seg//最大绝对值 
{
	int N,mx[xx<<2],mn[xx<<2];
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			if(!is[l])mx[k]=-2e9,mn[k]=2e9;
			else mx[k]=mn[k]=u[l];
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		mx[k]=max(mx[k<<1],mx[k<<1|1]);
		mn[k]=min(mn[k<<1],mn[k<<1|1]);
//		cerr<<k<<" "<<l<<" "<<r<<" "<<mx[k]<<"$\n";
	}
	int amn(int k,int l,int r,int x,int y)
	{
		if(x>y)return 2e9;
		if(x<=l&&r<=y)return mn[k];
		int mid=l+r>>1;
		if(y<=mid)return amn(k<<1,l,mid,x,y);
		if(mid<x)return amn(k<<1|1,mid+1,r,x,y);
		return min(amn(k<<1,l,mid,x,y),amn(k<<1|1,mid+1,r,x,y));
	}
	int amx(int k,int l,int r,int x,int y)
	{
		if(x>y)return -2e9;
		if(x<=l&&r<=y)return mx[k];
		int mid=l+r>>1;
		if(y<=mid)return amx(k<<1,l,mid,x,y);
		if(mid<x)return amx(k<<1|1,mid+1,r,x,y);
		return max(amx(k<<1,l,mid,x,y),amx(k<<1|1,mid+1,r,x,y));
	}
	int amn(int l,int r){return amn(1,1,N,l,r);}
	int amx(int l,int r){return amx(1,1,N,l,r);}
	void ini(int len)
	{
		build(1,1,len),N=len;
	}
}ap,an,bp,bn;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	
	// 0 一起考虑 
	
	for(int i=1;i<=n;i++)is[i]=0,u[i]=0;
	for(int i=1;i<=n;i++)
		if(a[i]>=0)u[i]=abs(a[i]),is[i]=1;
//	for(int i=1;i<=n;i++)cerr<<u[i]<<" "<<is[i]<<"$\n";
	ap.ini(n);
//	cerr<<ap.amx(2,3)<<"$\n";
//	exit(0);
	for(int i=1;i<=n;i++)is[i]=0,u[i]=0;
	for(int i=1;i<=n;i++)
		if(a[i]<=0)u[i]=abs(a[i]),is[i]=1;
	an.ini(n);
	
	
	for(int i=1;i<=m;i++)is[i]=0,u[i]=0;
	for(int i=1;i<=m;i++)
		if(b[i]>=0)u[i]=abs(b[i]),is[i]=1;
	bp.ini(m);
	
	for(int i=1;i<=m;i++)is[i]=0,u[i]=0;
	for(int i=1;i<=m;i++)
		if(b[i]<=0)u[i]=abs(b[i]),is[i]=1;
	bn.ini(m);
	
	while(q--)
	{
		int l1=read(),r1=read(),l2=read(),r2=read();
		int Ap=(ap.amx(l1,r1)>=0),An=(an.amx(l1,r1)>=0),Bp=(bp.amx(l2,r2)>=0),Bn=(bn.amx(l2,r2)>=0);
		ll ans=-2e18;
		if(Ap)
		{
			//注意绝对值 
			if(Bn)
			{
				ans=max(ans,-1ll*(ap.amn(l1,r1))*(bn.amx(l2,r2)));
			}
			else 
			{
//				cerr<<"!!\n";
				ans=max(ans,1ll*(ap.amx(l1,r1))*(bp.amn(l2,r2)));
			}
		}
		if(An)
		{
			if(Bp)
			{
				ans=max(ans,-1ll*(an.amn(l1,r1))*(bp.amx(l2,r2)));
			}
			else 
			{
				ans=max(ans,1ll*(an.amx(l1,r1))*(bn.amn(l2,r2)));
			}
		}
//		cerr<<Ap<<" "<<An<<" "<<Bp<<" "<<Bn<<" "<<(ap.amx(l1,r1))<<"$\n";
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}
