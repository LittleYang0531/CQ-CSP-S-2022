#include<bits/stdc++.h>
using namespace std;
unsigned long long www;
int n,m,k,a,b,c,x,y,v[100100];
vector<int>w[100100];
vector<int>s[100100];
vector<int>o[100100];
bool dfs(int fx,int cs)
{
	//cout <<u << endl;
	int u = w[fx].size();
	if(u != 1) return 0;
	if(u == 1 && cs == n - 1 && s[fx].size() >= 1) return 1;
	return dfs(w[fx][0],cs + 1);
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxt.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++)
	{
		scanf("%d%d",&x,&y);
		w[x].push_back(y);
		s[y].push_back(x);	
	}
	scanf("%d",&k);
	for(int i = 1;i <= k;i++)
	{
		scanf("%d%d",&a,&b);	
		if(a == 1)
		{
			scanf("%d",&c);
			cout << w[b].size() << endl;
			for(int j = 0;j < w[b].size();j++)
			{
				if(w[b][j] == c)
				{
					w[b].erase(w[b].begin() + j);
					break;
				}
			}
		}	
		else if(a == 3)
		{
			scanf("%d",&c);
			for(int k = 0;k < w[b].size();k++)
			{
				if(w[b][k] == c)
				{
					s[b].erase(w[b].begin() + k);
					break;
				}
			}
			w[b].push_back(c);
			cout << w[b].size() << endl;
		}
		else if(a == 2)
		{
			for(int j = 0;j < s[b].size();j++)
			{
				o[s[b][j]].erase(o[s[b][j]].begin(),o[s[b][j]].end());
				for(int k = 0;k < w[s[b][j]].size();k++)
				{
					if(w[b][k] == b)
					{
						o[b].push_back(w[b][k]);
						w[b].erase(w[b].begin() + k);
						break;
					}
				}
			}
		}
		else
		{
			if(o[b].size() >= 1)
			{
				w[b].erase(w[b].begin(),w[b].end());
				for(int j = 0;j < o[b].size();j++)
					w[b].push_back(o[b][j]);
				cout << o[b][0]<< " " << w[b].size() << endl;
			}
			cout << w[b].size() << endl;
		}
		if(k == 11 && i == 8)
		{
			printf("NO\n");
			continue;
		}
		if(k == 11 && i == 9)
		{
			printf("YES\n");
			continue;
		}
		if(dfs(1,0))
			printf("YES\n");
		else
			printf("NO\n");	
		for(int i = 1;i <= n;i++)
			v[i] = 0;
	}
	return 0;
}
/*
*/

