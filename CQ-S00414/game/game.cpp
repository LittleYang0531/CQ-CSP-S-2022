#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long n,m,q;
	cin>>n>>m>>q;
	long long a[n+1],b[m+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	//////////////上面全是输入的数据 
	
	long long ans=0;
	long long min=0;
	for(int i=0;i<q;i++)
	{
		int la,ra,lb,rb;
		cin>>la>>ra>>lb>>rb;
		
		for(int x=la;x<=ra;x++)
		{ 
			min=a[x]*b[lb];
			for(int y=lb;y<=rb;y++)
			{
				if(a[x]*b[y]<min)
				{
					min=a[x]*b[y];
				}
				
			}
			if(x==la) ans=min;
			if(ans<min)
			{
				ans=min;
			}
		} 
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
