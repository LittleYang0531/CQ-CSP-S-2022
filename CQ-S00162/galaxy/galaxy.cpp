#include <bits/stdc++.h>
using namespace std;
int n,m,q;
int a[1005][1005];
int c[1005],flag[1005];
void huan2(int x)
{
	flag[x]++;
	if(flag[x]>1) return ;
	for(int i=1;i<=n;i++)
	{
		if(a[x][i]==1)
		{
			huan2(x);
		}
	}
	return ;
}
bool huan(int x)
{
	memset(flag,0,sizeof(flag));
	huan2(x);
	for(int i=1;i<=n;i++)
	{
		if(flag[i]>1) return true;
	}
	return false;
}
int main ()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		c[x]++;
	}
	if(q>=100000)
	{
		for(int i=1;i<=q;i++)
		{
			printf("NO\n");
		}
		return 0;
	} 
	scanf("%d",&q);
	for(int j=1;j<=q;j++)
	{
		int pos,x,y,f=0;
		scanf("%d",&pos);
		if(pos==1)
		{
			scanf("%d%d",&x,&y);
			a[x][y]=-1;
			c[x]--;
		}
		if(pos==2)
		{
			scanf("%d",&x);
			for(int i=1;i<=n;i++)
			{
				if(a[i][x]==1)
				{
					a[i][x]=-1;
					c[i]--;
				}
			}
		}
		if(pos==3)
		{
			scanf("%d%d",&x,&y);
			a[x][y]=1;
			c[x]++;
		}
		if(pos==4)
		{
			scanf("%d",&x);
			for(int i=1;i<=n;i++)
			{
				if(a[i][x]==-1)
				{
					a[i][x]=1;
					c[i]++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i]!=1 || !huan(i)) 
			{
				f=1;
				break;
			}
		}
		if(f==1) 
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
	}
	return 0;
}
