#include<bits/stdc++.h>
using namespace std;
int n,m,k,maxx=-1;
int pnt[2505],gt[2505][2505];
void dfs(int x,int pt,int step)
{
	if(step==5) return;
	maxx=max(maxx,pt);
	for(int i=1;i<=n;i++)
	{
		if(gt[i][x]==1)
		{
			dfs(i,pt+pnt[i],step+1);
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%d",&pnt[i]);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		gt[x][y]=1;
		gt[y][x]=1;
	}
	dfs(1,0,1);
	printf("%d",maxx);
	return 0;
}
/*

8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1


*/
