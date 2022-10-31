#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n,m,k,score[2500],way[100][100]={-1},maxn=0;
	/*for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			way[i][j]=-1;
		}
	}*/
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
	{
		cin>>score[i];
	}
    for(int i=1;i<=m;i++)
    {
    	int num1,num2;
    	cin>>num1>>num2;
    	way[num1][num2]=way[num2][num1]=1;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int z=1;z<=m;z++)
			{
				for(int x=1;x<=m;x++)
				{
					if(way[1][i]==1&&way[i][j]==1&&way[j][z]==1&&way[z][x]==1&&way[x][1]==1)
					{
						if(score[i]+score[j]+score[z]+score[x]>maxn)
						{
							maxn=score[i]+score[j]+score[z]+score[x];
						}
					}
				}
			}
		}
	}
	cout<<maxn;
	return 0;
}
