#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int n,m,T,q,w,qq,ww,ql,qr,a[maxn],b[maxn],ans,aMa,aMi,bMa,bMi,Mor,aMa0,aMi0,bMa0,bMi0;
int Ma[maxn<<2][2],Mi[maxn<<2][2],Ma0[maxn<<2][2],Mi0[maxn<<2][2];
bool h0[maxn<<2][2],ah,bh,Wh;
int max0(int x,int y)
{
	if(x==-1e12)return y;
	if(y==-1e12)return x;
	if(x<0&&y<0)return max(x,y);
	if(x<0&&y>=0)return x;
	if(y<0&&x>=0)return y;
	return min(x,y);
}
int min0(int x,int y)
{
	if(x==1e12)return y;
	if(y==1e12)return x;
	if(x>0&&y>0)return min(x,y);
	if(x>0&&y<=0)return x;
	if(y>0&&x<=0)return y;
	return max(x,y);
}
void build(int l,int r,int k,int t[])
{
	if(l==r)
	{
		if(!t[l])h0[k][Wh]=1;
//		printf("%lld %lld %lld\n",l,Wh,h0[k][Wh]);
		Ma[k][Wh]=Mi[k][Wh]=Ma0[k][Wh]=Mi0[k][Wh]=t[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,k*2,t);
	build(mid+1,r,k*2+1,t);
	h0[k][Wh]=h0[k*2][Wh]|h0[k*2+1][Wh];
	Ma[k][Wh]=max(Ma[k*2][Wh],Ma[k*2+1][Wh]);
	Mi[k][Wh]=min(Mi[k*2][Wh],Mi[k*2+1][Wh]);
	Ma0[k][Wh]=max0(Ma0[k*2][Wh],Ma0[k*2+1][Wh]);
	Mi0[k][Wh]=min0(Mi0[k*2][Wh],Mi0[k*2+1][Wh]);
}
int query(int l,int r,int k)
{
	if(ql>r||qr<l)
	{
		if(Mor==0||Mor==3)return -1e12;
		if(Mor==1||Mor==4)return 1e12;
		if(Mor==2)return 0;
	}
	if(ql<=l&&r<=qr)
	{
		if(Mor==0)return Ma[k][Wh];
		if(Mor==1)return Mi[k][Wh];
		if(Mor==2)return h0[k][Wh];
		if(Mor==3)return Ma0[k][Wh];
		return Mi0[k][Wh];
	}
	int mid=(l+r)/2;
	int q1=query(l,mid,k*2),q2=query(mid+1,r,k*2+1);
	if(Mor==0)return max(q1,q2);
	if(Mor==1)return min(q1,q2);
	if(Mor==3)return max0(q1,q2);
	if(Mor==4)return min0(q1,q2);
	return q1|q2;
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&T);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	Wh=0,build(1,n,1,a);
	Wh=1,build(1,m,1,b);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&q,&w,&qq,&ww);
		Mor=0;
		Wh=0,ql=q,qr=w,aMa=query(1,n,1);
		Wh=1,ql=qq,qr=ww,bMa=query(1,m,1);
		
		Mor=1;
		Wh=0,ql=q,qr=w,aMi=query(1,n,1);
		Wh=1,ql=qq,qr=ww,bMi=query(1,m,1);
		
		Mor=2;
		Wh=0,ql=q,qr=w,ah=query(1,n,1);
		Wh=1,ql=qq,qr=ww,bh=query(1,m,1);
		
		Mor=3;
		Wh=0,ql=q,qr=w,aMa0=query(1,n,1);
		Wh=1,ql=qq,qr=ww,bMa0=query(1,m,1);
		
		Mor=4;
		Wh=0,ql=q,qr=w,aMi0=query(1,n,1);
		Wh=1,ql=qq,qr=ww,bMi0=query(1,m,1);
		
		ans=max(max(min(min(aMa*bMa,aMa*bMi),min(aMa*bMa0,aMa*bMi0)),min(min(aMi*bMa,aMi*bMi),min(aMi*bMa0,aMi*bMi0))),max(min(min(aMa0*bMa,aMa0*bMi),min(aMa0*bMa0,aMa0*bMi0)),min(min(aMi0*bMa,aMi0*bMi),min(aMi0*bMa0,aMi0*bMi0))));
		if(ah&&ans<0)ans=0;
		if(bh&&ans>0)ans=0;
//		printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld ",aMa,aMi,bMa,bMi,ah,bh,aMa0,aMi0,bMa0,bMi0);
		printf("%lld\n",ans);
	}
	return 0;
}