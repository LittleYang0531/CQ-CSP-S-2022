#include<bits/stdc++.h>
using namespace std;
int n,m,q,h[500005],cnt,cd[500005],flagsum;
struct nn{
	int to,next;
}e[500005];
map<int,bool>p[500005];
void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
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
		add(y,x);
		cd[x]++;
		p[x][y]=1;
	}
	for(int i=1;i<=n;i++)if(cd[i]==1)flagsum++;
	scanf("%d",&q);
	while(q--)
	{
		int op,x,y;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			if(cd[x]==1)flagsum--;
			cd[x]--;
			if(cd[x]==1)flagsum++;
			p[x][y]=0;
		}
		if(op==2)
		{
			scanf("%d",&x);
			for(int i=h[x];i;i=e[i].next)
			{
				int y=e[i].to;
				if(p[y][x])
				{
					if(cd[y]==1)flagsum--;
					cd[y]--;
					if(cd[y]==1)flagsum++;
				}
				p[y][x]=0;
			}
		}
		if(op==3)
		{
			scanf("%d%d",&x,&y);
			if(cd[x]==1)flagsum--;
			cd[x]++;
			if(cd[x]==1)flagsum++;
			p[x][y]=1;
		}
		if(op==4)
		{
			scanf("%d",&x);
			for(int i=h[x];i;i=e[i].next)
			{
				int y=e[i].to;
				if(!p[y][x])
				{
					if(cd[y]==1)flagsum--;
					cd[y]++;
					if(cd[y]==1)flagsum++;
					p[y][x]=1;
				}
			}
		}
		if(flagsum==n)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
