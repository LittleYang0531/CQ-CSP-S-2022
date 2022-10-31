#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f;
int n,m,q,A[N],B[N],l,r,l2,r2;
long long mn,mx,mn2,mx2,ok,Mn,Mx,Mn2,Mx2,Ok;
struct Tree
{
	int l,r,mn,mx,mn2,mx2,ok;
}t[4*N][2];
void update(int p,int i)
{
	t[p][i].mn=min(t[p*2][i].mn,t[p*2+1][i].mn);
	t[p][i].mx=max(t[p*2][i].mx,t[p*2+1][i].mx);
	t[p][i].mn2=min(t[p*2][i].mn2,t[p*2+1][i].mn2);
	t[p][i].mx2=max(t[p*2][i].mx2,t[p*2+1][i].mx2);
	t[p][i].ok=t[p*2][i].ok|t[p*2+1][i].ok;
}
void maketree(int p,int l,int r,int i)
{
	t[p][i].l=l;
	t[p][i].r=r;
	t[p][i].mn=t[p][i].mn2=inf;
	t[p][i].mx=t[p][i].mx2=-inf;
	if(t[p][i].l==t[p][i].r)
	{
		if(i==0)
		{
		
		if(A[l]<0)
		{
			t[p][i].mn=A[l];
			t[p][i].mx=A[l];
		}
		else if(A[l]>0)
		{
			t[p][i].mn2=A[l];
			t[p][i].mx2=A[l];
		}
		else t[p][i].ok=1;
		}
		else
		{
		if(B[l]<0)
		{
			t[p][i].mn=B[l];
			t[p][i].mx=B[l];
		}
		else if(B[l]>0)
		{
			t[p][i].mn2=B[l];
			t[p][i].mx2=B[l];
		}
		else t[p][i].ok=1;
		}
		return;	
		
	}
	int mid=(l+r)/2;
	maketree(p*2,l,mid,i);
	maketree(p*2+1,mid+1,r,i);
	update(p,i);
}
void get(int p,int l,int r,int i)
{
	if(t[p][i].l>=l&&t[p][i].r<=r)
	{
		if(i==0)
		{
			mn=min(mn,(ll)t[p][i].mn);
			mn2=min(mn2,(ll)t[p][i].mn2);
			mx=max(mx,(ll)t[p][i].mx);
			mx2=max(mx2,(ll)t[p][i].mx2);
			ok|=t[p][i].ok;
		}
		else
		{
			Mn=min(Mn,(ll)t[p][i].mn);
			Mn2=min(Mn2,(ll)t[p][i].mn2);
			Mx=max(Mx,(ll)t[p][i].mx);
			Mx2=max(Mx2,(ll)t[p][i].mx2);
			Ok|=t[p][i].ok;
		}
		return;
	}
	int mid=(t[p][i].l+t[p][i].r)/2;
	if(l<=mid) get(p*2,l,r,i);
	if(r>mid) get(p*2+1,l,r,i);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int a=1;a<=n;a++) scanf("%d",&A[a]);
	for(int a=1;a<=m;a++) scanf("%d",&B[a]);
	maketree(1,1,n,0);
	maketree(1,1,m,1);
	while(q--)
	{
		scanf("%d%d%d%d",&l,&r,&l2,&r2);
		mn=mn2=Mn=Mn2=inf;
		mx=mx2=Mx=Mx2=-inf;
		ok=Ok=0;
		get(1,l,r,0);
		get(1,l2,r2,1);
		ll ans=-1e18;
		if(ok==1) ans=0;
		if(mn!=inf&&mx2!=-inf)
		{
			if(Mn!=inf&&Mx2!=-inf) ans=max(ans,max(mn2*Mn,mx*Mx2));
			else if(Mn!=inf) ans=max(ans,mn*Mx);
			else if(Mx2!=-inf) ans=max(ans,mx2*Mn2);
			else ans=0;
		}
		else if(mn!=inf)
		{
			if(Mn!=inf&&Mx2!=-inf) ans=max(ans,mx*Mx2);
			else if(Mn!=inf) ans=max(ans,mn*Mx);
			else if(Mx2!=-inf) ans=max(ans,mx*Mx2);
			else ans=0;
		}
		else if(mx2!=-inf)
		{
			if(Mn!=inf&&Mx2!=-inf) ans=max(ans,mn2*Mn);
			else if(Mn!=inf) ans=max(ans,mn2*Mn);
			else if(Mx2!=-inf) ans=max(ans,mx2*Mn2);
			else ans=0;
		}
		else ans=0;
		if(Ok==1) ans=min(ans,0ll);
		printf("%lld\n",ans);
	}
}
