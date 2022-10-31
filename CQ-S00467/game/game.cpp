#include<bits/stdc++.h> 
#define int long long

using namespace std;

int n,m,q;

int a[100000000],b[100000000];

signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	cin>>n>>m>>q;//输入 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	
	while(q--)
	{
		int l1,l2,r1,r2;
		cin>>l1>>r1>>l2>>r2;
		
		//分类讨论
		int amx=-1e11;//最大 
		int amy=1e11;//最小 
		for(int i=l1;i<=r1;i++)//小L最 
		{
			amx=max(amx,a[i]);
			amy=min(amy,a[i]);
		}
		
		int bmx=-1e11;//最大
		int bmy=1e11;//最小
		for(int i=l2;i<=r2;i++)//小Q最
		{
			bmx=max(bmx,b[i]);
			bmy=min(bmy,b[i]);	
		} 
		
		int maxx=-1e17;//最终最大
		int minn=1e17;//最终最小 
		
		for(int i=l1;i<=r1;i++)//小L的选择 
		{
			int ans=0;
			
			if(a[i]==0)
			{
				maxx=max(maxx,a[i]);
			}
			else
			{
				if(a[i]>0)
				{
					ans=a[i]*bmy;//乘最小的 
				}
				else
				{
					ans=a[i]*bmx;//乘最大的	
				}
				
				maxx=max(maxx,ans); 
			}
		}
		for(int i=l2;i<=r2;i++)//小Q的选择
		{
			int ans=0;
			
			if(b[i]==0)
			{
				minn=min(minn,b[i]);	
			}	
			else
			{
				if(b[i]<0)
				{
					ans=b[i]*amy;//乘最小的 
				}
				else
				{
					ans=b[i]*amx;//乘最大的 
				}
				
				minn=min(minn,ans);
			}
		}
		
		cout<<min(minn,maxx)<<endl; //根据判断,求最小 
	}
	
	return 0;
}
