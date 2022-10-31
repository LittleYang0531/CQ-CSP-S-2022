#include <iostream>
using namespace std;
int n,m,u,v,t,q;
int x[50000],y[50000],mapp[100][100];
bool flag;
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		x[u]++;
		y[u]++;
		mapp[u][v]=1;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		flag=0;
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d",&u,&v);
			if(mapp[u][v]==1)
			{	
				x[u]=max(--x[u],0);
			}
			mapp[u][v]=0;
		}
		else if(t==2)
		{
			scanf("%d",&u);
			for(int j=1;j<=n;j++)
			{
				mapp[u][j]=0;
			}
			x[u]=0;
		}
		else if(t==3)
		{
			scanf("%d%d",&u,&v);
			if(mapp[u][v]==0)
			{
				x[u]++;
			}
			mapp[u][v]=1;
		}
		else
		{
			scanf("%d",&u);
			for(int j=1;j<=n;j++)
			{
				mapp[u][j]=1;
			}
			x[u]=y[u];
		}
		for(int j=1;j<=n;j++)
		{
			if(x[j]!=1)
			{
				printf("NO\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("YES\n");
		}
	}
	
	return 0;
}
