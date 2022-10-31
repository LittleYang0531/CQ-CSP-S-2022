#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=100005;
int n,m,q,lg[N];
void init()
{
	int k=1,j=-1;
	for(int i=1;i<N;lg[i]=j,i++) if(i==k) k<<=1,++j;
}
struct STofarr{
	int v[N],siz;
	int maxx[N][25],minn[N][25];
	void pre()
	{
		for(int i=1;i<=siz;i++) maxx[i][0]=minn[i][0]=v[i];
		for(int j=1;(1<<j)<=siz;j++)
		{
			for(int i=1;i<=siz;i++)
			{
				maxx[i][j]=max(maxx[i][j-1],maxx[i+(1<<j-1)][j-1]);
				minn[i][j]=min(minn[i][j-1],minn[i+(1<<j-1)][j-1]);
			}
		}
	}
	int ask(int L,int R,bool tp)
	{
		int k=lg[R-L+1];
		if(tp==0)
		{
			return min(minn[L][k],minn[R-(1<<k)+1][k]);
		}
		else 
		{
			return max(maxx[L][k],maxx[R-(1<<k)+1][k]);
		}
	}
}R,C;
struct o{int x1,x2,y1,y2;}Q[N];
namespace subsm{
	void solve()
	{
		for(int i=1;i<=n;i++)
		{
			int l1=Q[i].x1,r1=Q[i].x2,l2=Q[i].y1,r2=Q[i].y2;
			if(l1==r1)
			{
				int lv=R.v[l1];
				printf("%lld\n",1ll*lv*C.ask(l2,r2,(lv<0)));
			}
			else
			{
				int lv=C.v[l2];
				printf("%lld\n",1ll*lv*R.ask(l1,r1,(lv>=0)));
			}
		}
	}
}
namespace subbruce{
	void solve()
	{
		for(int i=1;i<=q;i++)
		{
			ll Ans=-LLONG_MAX;
			int l1=Q[i].x1,r1=Q[i].x2,l2=Q[i].y1,r2=Q[i].y2;
			for(int j=l1;j<=r1;++j)
				Ans=max(Ans,1ll*R.v[j]*C.ask(l2,r2,(R.v[j]<0)));
			printf("%lld\n",Ans);
		}
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	bool tsm=true;
	init();
	scanf("%d %d %d",&n,&m,&q);
	R.siz=n,C.siz=m;
	for(int i=1;i<=n;i++) scanf("%d",&R.v[i]);
	for(int i=1;i<=m;i++) scanf("%d",&C.v[i]);
	R.pre(); C.pre();
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d %d %d",&Q[i].x1,&Q[i].x2,&Q[i].y1,&Q[i].y2);
		if(Q[i].x1!=Q[i].x2 && Q[i].y1!=Q[i].y2) tsm=false;
	}
	if(n<=1000) subbruce::solve();
	else if(tsm) subsm::solve();
	else subbruce::solve();
	return 0;
}
