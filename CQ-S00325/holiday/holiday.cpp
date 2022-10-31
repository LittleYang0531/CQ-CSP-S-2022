#include<iostream>
using namespace std;
const int M=2500;
int n,m,k,ma=0;
int a[M];
long long b[M+1][M+1]={-0x7ffffff};
long long f[5][M][M]={0};
int an=0;
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	a[0]=0;
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		b[x][y]=1;
		b[y][x]=1;
	}
	for(int i=0;i<n;i++)
	{
		if(b[1][i+1]&&i!=0)
		{
			an=max(an,a[i]);
			int bn=0;
			for(int j=0;j<n;j++)
			{
				if(b[i+1][j+1]&&j!=0&&j!=i)
				{
					bn=max(bn,a[j]);
					int cn=0;
					for(int l=0;l<n;l++)
					{
						if(b[j+1][l+1]&&l!=0&&l!=i&&l!=j)
						{
							cn=max(cn,a[l]);
							int dn=0;
							for(int h=0;h<n;h++)
							{
								if(b[l+1][h+1]&&h!=0&&h!=i&&h!=j&&h!=l)
								{
									dn=max(dn,a[h]);
								}
							}
							cn+=dn;
						}
					}
					bn+=cn;
				}
			}
			an+=bn;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			f[0][i][j]=b[i+1][j+1];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int l=1;l<=k;l++)
			{
				f[l][i][j]=f[l-1][i][j];
				if(b[1][i])
				{
					f[l][i][j]=max(f[l][i][j],f[l][1][j]+a[i]);
				}
			}
		}
	}
	cout<<an;
	return 0;	
	fclose(stdin);
	fclose(stdout);
}
