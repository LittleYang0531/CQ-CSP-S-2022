#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans = 0;
struct op
{
	int head,tail,zhi;
}b[10000];
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 2;i<=n;i++)
	{
		cin>>b[i].zhi;
	}
	for(int i = 1;i<=m;i++)
		cin>>b[i].head>>b[i].tail;
	int p = 0;
	for(int i = 2;i<=m;i++)
	{
		int turn = k;
		for(int j = 1;j<=m;j++)
		{
			if(b[i].tail == j)
			{
				if(b[i].zhi>b[j].zhi&&turn!=0&&i!=j)
				{
					ans+=b[i].zhi;
					turn--;
					i = j;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
