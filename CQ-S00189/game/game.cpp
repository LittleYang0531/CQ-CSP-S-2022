#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long A[100009],B[100009],mi=LONG_MAX*(long long)(10),mai=-LONG_MAX*(long long)(10);
int wrst[100009];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&A[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&B[i]);
	}
	for(int k=1;k<=q;k++)
	{
		int l1,l2,r1,r2,ans;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		mai=-LONG_MAX*(long long)(10);
		for(int i=l1;i<=r1;i++)
		{
			mi=LONG_MAX*(long long)(10);
			for(int j=l2;j<=r2;j++)
			{
				if(mi>A[i]*B[j])
				{
					mi=A[i]*B[j];
					wrst[i]=j;
				}
			}
			if(mai<mi)
			{
				mai=mi;
				ans=i;
			}
		}
		cout<<A[ans]*B[wrst[ans]]<<endl;
	}
	return 0;
}

