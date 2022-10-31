#include<iostream>
#include<algorithm>
using namespace std;
const int M=1001;
int n,m,q;
int l1,l2,r1,r2;
long long ma=-0x7ffffff,mi=0x7ffffff;
long a[M],b[M];
long long c[M][M]={0};
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			c[i][j]=a[i]*b[j];
		}
	}
	while(q--)
	{
		mi=0x7ffffff;
		ma=-0x7ffffff;
		cin>>l1>>r1>>l2>>r2;
		for(int i=l1;i<=r1;i++)
		{
			mi=0x7ffffff;
			for(int j=l2;j<=r2;j++)
			{
				mi=min(c[i][j],mi);
			}
			ma=max(mi,ma);
		}
		cout<<ma<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
