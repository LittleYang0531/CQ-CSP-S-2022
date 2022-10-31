#include<bits/stdc++.h>
using namespace std;
int n,m,fd;
bool ls=false;
int mp[1005][1005],jl[1005][1005];
int dfs(int nw,int step)
{
	if(step>n) return 0;
	if(nw==fd) return 1;
	for(int f=1;f<=n;f++)
		if(mp[nw][f]) return dfs(f,step+1);
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		mp[u][v]=1;
		jl[u][v]=1;
	}
	int t,q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d",&u,&v);
			mp[u][v]=0;
		}
		if(t==2)
		{
			scanf("%d",&u);
			for(int i=1;i<=n;i++) mp[i][u]=0;
		}
		if(t==3)
		{
			scanf("%d%d",&u,&v);
			mp[u][v]=1;
		}
		if(t==4)
		{
			scanf("%d",&u);
			for(int i=1;i<=n;i++)
				if(jl[i][u])
					mp[i][u]=1;
		}
		bool yn=true;
		for(int i=1;i<=n;i++) 
		{
			fd=i;
			ls=false;
			for(int k=1;k!=i&&k<=n;k++)
			{
				if(dfs(k,1))
				{
					int ls=0;
					for(int j=1;j<=n;j++)
						if(mp[i][j])
							ls++;
					if(ls!=1)
					{
						if(yn==true)
						{
							printf("NO\n");
							yn=false;
							break;
						}
					}
				}
				else
				{
					if(yn==true)
					{
						printf("NO\n");
						yn=false;
						break;
					}
				}
			}
		}
		if(yn==true) printf("YES\n");
	}
	return 0;
}
/*

3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2

*/
