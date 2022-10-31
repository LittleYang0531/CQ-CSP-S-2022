#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,a[100005],b[100005],l1,r1,l2,r2,qzh1[100005],qzh2[100005];
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]),qzh1[i]=qzh1[i-1]+(a[i]<0);
	for(int i=1; i<=m; ++i) scanf("%lld",&b[i]),qzh2[i]=qzh2[i-1]+(b[i]<0);
	while(q--)
	{
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		if(r1-l1+1==qzh1[r1]-qzh1[l1-1])
		{
			int x=a[l1],y=b[l2];
			for(int i=l1; i<=r1; ++i) x=max(a[i],x);
			for(int i=l2; i<=r2; ++i) y=max(b[i],y);
			printf("%lld\n",x*y);
		}
		else if(qzh1[r1]-qzh1[l1-1]==0)
		{
			int x=a[l1],y=b[l2];
			for(int i=l1; i<=r1; ++i) x=max(a[i],x);
			for(int i=l2; i<=r2; ++i) y=min(b[i],y);
			printf("%lld\n",x*y);
		}
		else
		{
			if(qzh2[r2]-qzh2[l2-1]==0)
			{
				int x=a[l1],y=b[l2];
				for(int i=l1; i<=r1; ++i) x=max(a[i],x);
				for(int i=l2; i<=r2; ++i) y=min(b[i],y);
				printf("%lld\n",x*y);
			}
			else if(r2-l2+1==qzh2[r2]-qzh2[l2-1])
			{
				int x=a[l1],y=b[l2];
				for(int i=l1; i<=r1; ++i) x=min(a[i],x);
				for(int i=l2; i<=r2; ++i) y=max(b[i],y);
				printf("%lld\n",x*y);
			}
			else
			{
				int x=-1000000009,xx=1000000009,yy=1000000009,y=-1000000009;
				for(int i=l1; i<=r1; ++i)
				{
					x=max((a[i]<0?a[i]:x),x),xx=min((a[i]>0?a[i]:xx),xx);
					if(a[i]==0)
					{
						x=0,xx=0;
						break;
					}
				}
				for(int i=l2; i<=r2; ++i)
				{
					y=max((b[i]<0?b[i]:y),y),yy=min((b[i]>0?b[i]:yy),yy);
					if(b[i]==0)
					{
						y=0,yy=0;
						break;
					}
				}
				if(x==0 || y==0 || xx==0 || yy==0) printf("0\n");
				else printf("-114514\n");
			}
		}
	}
	return 0;
}
