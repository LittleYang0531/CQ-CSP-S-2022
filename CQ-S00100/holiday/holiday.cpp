#include<bits/stdc++.h>
using namespace std;
int mapp[3005][3005]={0};
long long n,m,kk,a[6005],ans=0;
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				mapp[i][j]=min(mapp[i][j],mapp[i][k]+mapp[k][j]);
			}
		}
	}
}
bool equ(long long a1,long long a2,long long a3,long long a4)
{
	long long aa[10];
	aa[1]=a1;
	aa[2]=a2;
	aa[3]=a3;
	aa[4]=a4;
	sort(aa+1,aa+5);
	if(aa[1]==aa[2]||aa[2]==aa[3]||aa[3]==aa[4]||aa[4]==aa[1])return true;
	else return false;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>kk;
	for(int i=2;i<=n;i++)cin>>a[i];
	memset(mapp,0x3f,sizeof(mapp));
	for(int i=1;i<=n;i++)mapp[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		long long x,y;
		cin>>x>>y;
		mapp[x][y]=1;
		mapp[y][x]=1;
	}
	floyd();
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			for(int k=2;k<=n;k++)
			{
				for(int l=2;l<=n;l++)
				{
					if(equ(i,j,k,l))continue;
					else if(mapp[1][i]>kk+1||mapp[i][j]>kk+1||mapp[j][k]>kk+1||mapp[k][l]>kk+1||mapp[l][1]>kk+1)continue;
					else
					{
						long long nowans=a[i]+a[j]+a[k]+a[l];
						/*if(nowans>ans)
						{
							ans=max(ans,nowans);
							cout<<i<<j<<k<<l<<" "<<ans<<"\n";
						}*/
						ans=max(ans,nowans);
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

