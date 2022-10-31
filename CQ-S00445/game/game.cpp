//hj23308±£ÓÓÎÒ
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m,t;
bool flag=1;
long long ans;
long long sum[MAXN];
long long a[MAXN],b[MAXN];
long long A_RMQ_f[MAXN][35],A_RMQ_z[MAXN][35],A_RMQ_d[MAXN][35],A_RMQ_x[MAXN][35],B_RMQ_d[MAXN][35],B_RMQ_x[MAXN][35];
void RMQ()
{
	for(int i=1;i<=n;i++)
	{
		A_RMQ_d[i][0]=a[i];
		A_RMQ_x[i][0]=a[i];
		if(a[i]==0)
		{
			A_RMQ_f[i][0]=a[i];
			A_RMQ_z[i][0]=a[i];
		}
		else if(a[i]<0)
		{
			A_RMQ_f[i][0]=a[i];
			A_RMQ_z[i][0]=0x7ffffffffffffff;
		}
		else
		{
			A_RMQ_z[i][0]=a[i];
			A_RMQ_f[i][0]=-0x7ffffffffffffff;
		}
	}
	for(int i=1;i<=m;i++)
	{
		B_RMQ_d[i][0]=b[i];
		B_RMQ_x[i][0]=b[i];
	}
	for(int j=1;j<=log2(n);j++)
	{
		for(int i=1;i<=n-(1<<j)+1;i++)
		{
			A_RMQ_d[i][j]=max(A_RMQ_d[i][j-1],A_RMQ_d[i+(1<<(j-1))][j-1]);
			A_RMQ_x[i][j]=min(A_RMQ_x[i][j-1],A_RMQ_x[i+(1<<(j-1))][j-1]);
			A_RMQ_f[i][j]=max(A_RMQ_f[i][j-1],A_RMQ_f[i+(1<<(j-1))][j-1]);
			A_RMQ_z[i][j]=min(A_RMQ_z[i][j-1],A_RMQ_z[i+(1<<(j-1))][j-1]);
		}
	}
	for(int j=1;j<=log2(m);j++)
	{
		for(int i=1;i<=m-(1<<j)+1;i++)
		{
			B_RMQ_d[i][j]=max(B_RMQ_d[i][j-1],B_RMQ_d[i+(1<<(j-1))][j-1]);
			B_RMQ_x[i][j]=min(B_RMQ_x[i][j-1],B_RMQ_x[i+(1<<(j-1))][j-1]);
		}
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<0)
		{
			flag=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		if(b[i]<0)
		{
			flag=0;
		}
	}
	RMQ();
	while(t--)
	{
		long long A_z,A_f,A_maxn,A_minn,B_maxn,B_minn;
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if(l1==r1)
		{
			int wei=log2(r2-l2+1);
			int u=r2-(1<<wei)+1;
			if(a[l1]<0)
			{
				ans=a[l1]*max(B_RMQ_d[l2][wei],B_RMQ_d[u][wei]);
			}
			else
			{
				ans=a[l1]*min(B_RMQ_x[l2][wei],B_RMQ_x[u][wei]);
			}
		}
		else if(l2==r2)
		{
			int wei=log2(r1-l1+1);
			int u=r1-(1<<wei)+1;
			if(b[l2]<0)
			{
				ans=b[l2]*min(A_RMQ_x[l1][wei],A_RMQ_x[u][wei]);
			}
			else
			{
				ans=b[l2]*max(A_RMQ_d[l1][wei],A_RMQ_d[u][wei]);
			}
		}
		else
		{
			int wei1=log2(r1-l1+1);
			int u1=r1-(1<<wei1)+1;
			int wei2=log2(r2-l2+1);
			int u2=r2-(1<<wei2)+1;
			A_maxn=max(A_RMQ_d[l1][wei1],A_RMQ_d[u1][wei1]);
			A_minn=min(A_RMQ_x[l1][wei1],A_RMQ_x[u1][wei1]);
			A_f=max(A_RMQ_f[l1][wei1],A_RMQ_f[u1][wei1]);
			A_z=min(A_RMQ_z[l1][wei1],A_RMQ_z[u1][wei1]);
			B_maxn=max(B_RMQ_d[l2][wei2],B_RMQ_d[u2][wei2]);
			B_minn=min(B_RMQ_x[l2][wei2],B_RMQ_x[u2][wei2]);
			if(B_maxn<=0)
			{
				if(A_minn<=0)
				{
					ans=A_minn*B_maxn;
				}
				else
				{
					ans=A_minn*B_minn;
				}
			}
			else
			{
				
				if(B_minn<0)
				{
					if(A_z>=0x7ffffffffffff)
					{
						ans=A_f*B_maxn;
					}
					else
					{
						if(A_f<=-0x7ffffffffffff)
						{
							ans=A_z*B_minn;
						}
						else
						{
							ans=max(A_z*B_minn,A_f*B_maxn);
						}
					}
				}
				else
				{
					if(A_maxn<=0)
					{
						ans=A_maxn*B_maxn;
					}
					else
					{
						ans=A_maxn*B_minn;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
155 949 453 481
*/
