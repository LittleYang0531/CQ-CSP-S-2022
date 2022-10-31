#include<bits/stdc++.h>
using namespace std;
const int N=500000+5;
int n,m,q;
int num[N];
bool f[N],f1[N],f2[N];
struct node{
	int y,flag;	
};
vector <node> v[N];
bool g1(int x)
{
	if(f[x]==1)
	{
		return true;
	}
	else
	{
		f[x]=1;
		for(int i=0;i<=v[x].size();i++)
		{
			if(v[x][i].flag==1)
			{
				return g1(v[x][i].y);
			}
		}
	}
	return false;
}
bool g2(int x)
{
	int tp=0;
	for(int i=0;i<=v[x].size()-1;i++)
	{
		if(tp==0&&v[x][i].flag==1)
		{
			tp=v[x][i].y;
		}
		if(v[x][v[x][i].y].flag==1&&tp!=v[x][i].y)
		{
			return true;
		}
	}
	return false;
}
bool g()
{
	for(int i=1;i<=m;i++)
	{
		if(v[i].size()>=1&&g2(i))
		{
			return false;
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof f);
		if(!f1[i]&&!g1(i))
		{
			return false;
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i])
				{
					f1[i]=1;
				}
			}
		}
	}
	return true;
}
int main()
{
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back((node){y,1});
		v[y].push_back((node){x,1});
	}	
	scanf("%d",&q);
	while(q--)
	{
		int t,x,y;
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d",&x,&y);
			v[x][y].flag=0;
		}
		if(t==2)
		{
			scanf("%d",&x);
			for(int i=0;i<=v[x].size()-1;i++)
			{
				v[v[x][i].y][x].flag=0;
			}
		}
		if(t==3)
		{
			scanf("%d%d",&x,&y);
			v[x][y].flag=1;
		}
		if(t==4)
		{
			scanf("%d",&x);
			for(int i=0;i<=v[x].size()-1;i++)
			{
				v[v[x][i].y][x].flag=1;
			}
		}
		if(g())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
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