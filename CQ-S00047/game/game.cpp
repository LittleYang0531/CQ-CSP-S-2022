#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int l1,r1,l2,r2;
int a[100005];
int b[100005];
int da[100005];
int db[100005];
int e[100005];
int ka[18][4][100005];
int kb[18][2][100005];
long long ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]),da[i]=da[i-1]+(a[i]<0),
		ka[0][0][i]=ka[0][1][i]=a[i];
		ka[0][2][i]=INT_MIN;
		ka[0][3][i]=INT_MAX;
		if(a[i]<=0)
		ka[0][2][i]=a[i];
		if(a[i]>=0)
		ka[0][3][i]=a[i];
	}
	for(int i=1;i<=m;i++)
	scanf("%d",&b[i]),db[i]=db[i-1]+(b[i]<0),
	kb[0][0][i]=kb[0][1][i]=b[i];
	for(int i=1,x=0,p=1;i<=n||i<=m;i++)
	{
		if(i>=p)
		x++,p*=2;
		e[i]=x-1;
	}
	for(int i=1;i<=16;i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			ka[i][0][j]=max(ka[i-1][0][j],ka[i-1][0][j+(1<<(i-1))]);
			ka[i][1][j]=min(ka[i-1][1][j],ka[i-1][1][j+(1<<(i-1))]);
			ka[i][2][j]=max(ka[i-1][2][j],ka[i-1][2][j+(1<<(i-1))]);
			ka[i][3][j]=min(ka[i-1][3][j],ka[i-1][3][j+(1<<(i-1))]);
		}
		for(int j=1;j+(1<<i)-1<=m;j++)
		{
			kb[i][0][j]=max(kb[i-1][0][j],kb[i-1][0][j+(1<<(i-1))]);
			kb[i][1][j]=min(kb[i-1][1][j],kb[i-1][1][j+(1<<(i-1))]);
		}
	}
	while(q--)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(db[r2]-db[l2-1]==r2-l2+1)
		ans=min(ka[e[r1-l1+1]][1][l1],ka[e[r1-l1+1]][1][r1-(1<<e[r1-l1+1])+1]);
		else
		{
			if(db[r2]-db[l2-1])
			{
				if(da[r1]-da[l1]==r1-l1+1)
				ans=max(ka[e[r1-l1+1]][2][l1],ka[e[r1-l1+1]][2][r1-(1<<e[r1-l1+1])+1]);
				else
				{
					if(da[r1]-da[l1])
					{
						printf("%lld\n",max
						(
							1ll*max(ka[e[r1-l1+1]][2][l1],ka[e[r1-l1+1]][2][r1-(1<<e[r1-l1+1])+1])
							*max(kb[e[r2-l2+1]][0][l2],kb[e[r2-l2+1]][0][r2-(1<<e[r2-l2+1])+1]),
							1ll*min(ka[e[r1-l1+1]][3][l1],ka[e[r1-l1+1]][3][r1-(1<<e[r1-l1+1])+1])
							*min(kb[e[r2-l2+1]][1][l2],kb[e[r2-l2+1]][1][r2-(1<<e[r2-l2+1])+1])
						));
						continue;
					}
					else
					ans=min(ka[e[r1-l1+1]][3][l1],ka[e[r1-l1+1]][3][r1-(1<<e[r1-l1+1])+1]);
				}
			}
			else
			ans=max(ka[e[r1-l1+1]][0][l1],ka[e[r1-l1+1]][0][r1-(1<<e[r1-l1+1])+1]);
		}
		if(ans>0)
		ans=ans*min(kb[e[r2-l2+1]][1][l2],kb[e[r2-l2+1]][1][r2-(1<<e[r2-l2+1])+1]);
		else
		ans=ans*max(kb[e[r2-l2+1]][0][l2],kb[e[r2-l2+1]][0][r2-(1<<e[r2-l2+1])+1]);
		printf("%lld\n",ans);
	}
	return 0;
}
