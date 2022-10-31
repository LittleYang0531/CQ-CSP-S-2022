//n^2±©Á¦ 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=100005;
int a[MAXN],b[MAXN];
int n,m,q;
int Max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int Min(int x,int y)
{
	if(x<y) return x;
	else return y;
}
void solve()
{
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<a[i]*b[j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--)
	{
		int l1,r1,l2,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		if(l1==r1)
		{
			int MIN=LONG_LONG_MAX;
			for(int i=l2;i<=r2;i++) MIN=Min(MIN,a[l1]*b[i]);
			printf("%lld\n",MIN);
		}
		else if(l2==r2)
		{
			int MAX=LONG_LONG_MIN;
			for(int i=l1;i<=r1;i++) MAX=Max(MAX,a[i]*b[l2]);
			printf("%lld\n",MAX);
		}
		else
		{
			int temp=LONG_LONG_MIN;
			for(int i=l1;i<=r1;i++)
			{
				int tmp=LONG_LONG_MAX;
				for(int j=l2;j<=r2;j++) tmp=min(tmp,a[i]*b[j]);
				temp=max(temp,tmp);
			}
			printf("%lld\n",temp);
		}
	}
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	solve();
	return 0;
}
