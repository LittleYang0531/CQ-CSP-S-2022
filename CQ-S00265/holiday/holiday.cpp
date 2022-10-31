#include<bits/stdc++.h>
using namespace std;
unsigned long long www,a[2510];
int n,m,k,b[10010],x,y,ma;
bool v[2510];
vector<int>c[2510];
void dfs(int fx,int fy,int cs)
{
	if(cs > 4)
		return;
	if(cs == 4)
	{
		for(int i = 0;i < c[fx].size();i++)
		{
			if(c[fx][i] == 1)
			{
				ma = max(ma,fy);
				return;
			}
		}
		return;
	}
	v[fx] = 1;
	for(int i = 0;i < c[fx].size();i++)
	{
		if(!v[c[fx][i]])
			dfs(c[fx][i],fy + a[c[fx][i]],cs + 1);
		else if(c[fx][i] == 1)
			dfs(c[fx][i],fy + a[c[fx][i]],cs);
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	a[1] = 0;
	for(int i = 2;i <= n;i++)
	{
		scanf("%llu",&a[i]);
	}
	for(int i = 1;i <= m;i++)
	{
		scanf("%d%d",&x,&y);
		c[x].push_back(y);
		c[y].push_back(x);
	}
	for(int i = 0;i < c[1].size();i++)
	{
		dfs(c[1][i],a[c[1][i]],1);
		for(int j = 1;j <= n;j++)
			v[j] = 0;
	}
	cout << ma << endl;
	return 0;
}
/*
dp或dfs 
第一题应该很简单，所以应该是dfs 
*/

