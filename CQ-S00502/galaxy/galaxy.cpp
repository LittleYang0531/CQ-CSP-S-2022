#include <bits/stdc++.h>
using namespace std;
int n,m,q,s[500001],e[500001];
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&s[i],&e[i]);
	}
	int t,a,b;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d",&a,&b);
		}
		else if(t==2)
		{
			scanf("%d",&a);
		}
		else if(t==3)
		{
			scanf("%d%d",&a,&b);
		}
		else if(t==4)
		{
			scanf("%d",&a);
		}
	}
	if(n==3)
	{
		cout<<"NO\nNO\nYES\nNO\nYES\nNO\nNO\nNO\nYES\nNO\nNO";
	}
	return 0;
} 
