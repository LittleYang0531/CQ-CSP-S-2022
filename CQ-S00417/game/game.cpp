#include<bits/stdc++.h>
using namespace std;
int n,m,q,l1,r1,l2,r2;
long long a[1000000],b[1000000];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	while(q--)
	{
		cin>>l1>>r1>>l2>>r2;
		long long mina1,mina2,maxa1,maxa2,minb1,minb2,maxb1,maxb2;
		bool flag1=0,flag2=0,flag3=0,flag4=0;
		for(int i=l1;i<=r1;i++)
		{
			if(a[i]>=0)
			{
				if(flag1==0)mina1=a[i],maxa1=a[i];
				flag1=1;
				mina1=min(a[i],mina1);maxa1=max(a[i],maxa1);
			}
			if(a[i]<0)
			{
				if(flag2==0)mina2=a[i],maxa2=a[i];
				flag2=1;
				mina2=min(mina2,a[i]);maxa2=max(maxa2,a[i]);
			}
		}
		for(int i=l2;i<=r2;i++)
		{
			if(b[i]>=0)
			{
				if(flag3==0)minb1=b[i],maxb1=b[i];
				flag3=1;
				minb1=min(minb1,b[i]);maxb1=max(maxb1,b[i]);
			}
			if(b[i]<0)
			{
				if(flag4==0)minb2=b[i],maxb2=b[i];
				flag4=1;
				minb2=min(minb2,b[i]);maxb2=max(maxb2,b[i]);
			}
		}
		if(flag1)
		{
			if(flag2)
			{
				if(flag3)
				{
					if(flag4)
					{
						cout<<max(maxa2*maxb1,mina1*minb2)<<endl;
					}
					else
					{
						cout<<maxa1*minb1<<endl;
					}
				}
				else
				{
					cout<<mina2*maxb2<<endl;
				}
			}
			else
			{
				if(flag4)
				{
					cout<<mina1*minb2<<endl;
				}
				else
				{
					cout<<maxa1*minb1<<endl;
				}
			}
		}
		else
		{
			if(flag3)
			{
				cout<<maxa2*maxb1<<endl;
			}
			else
			{
				cout<<mina2*maxb2<<endl;
			}
		}
	}
	return 0;
}
/*


*/
