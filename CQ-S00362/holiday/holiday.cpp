#include<bits/stdc++.h>
bool ja[150]={0};//判断走了几个点 ,0表示未走 
int n,m,k,top=1;
int q=0;
int tot=0;//tot总值 
int a[150],tu[100][100];//每个点的权值 
int DA[10][4];
using namespace std;
int dfs(int step);
int main()
{
	//freopen("holiday.in","r",stdin);
	//freopen("holiday.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=m;j++)
	{
		int head,tale;
		cin>>head>>tale;
		tu[head][tale]=1;
		tu[tale][head]=1;
	}
	int pe[150];
	for(int i=2;i<=n;i++) pe[i]=1;
	
	for(int i=1;i<=4;i++)
	{
		int ma=0,t=1;
		for(int j=2;j<=n;j++)
		{
			if(ma<a[j]&&pe[j]) 
			{
				ma=a[j],t=j;
			}
		} 
		DA[i][1]=ma,pe[t]=0;
		DA[i][2]=t;
	}//找最大4个数 
	for(int i=1;i<=4;i++)
	{
		tot+=DA[i][1];
	}
	cout<<tot;
	return 0;
}
	
/**8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1**/
