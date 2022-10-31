#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,inf=0x3f3f3f3f;
int n,m,x,y,q,op,out[N],head[N],to[N],nxt[N],e,from[N];
bool die[N],die2[N];
void add_edge(int x,int y)
{
	from[++e]=x;
	to[e]=y;
	nxt[e]=head[x];
	head[x]=e;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int a=1;a<=m;a++)
	{
		scanf("%d%d",&x,&y);
		out[x]++;
		add_edge(y,x);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			scanf("%d",&y);
			out[x]--;
			for(int a=head[y];a>0;a=nxt[a])
			{
				if(to[a]==x)
				{
					die2[a]=1;
					break;
				}
			}
		}
		else if(op==2)
		{
			for(int a=head[x];a>0;a=nxt[a])
			{
				if(die2[a]==0) out[to[a]]--,die2[a]=1;
			}
		}
		else if(op==3)
		{
			scanf("%d",&y);
			out[x]++;
			die[y]=0;
			for(int a=head[y];a>0;a=nxt[a])
			{
				if(to[a]==x)
				{
					die2[a]=0;
					break;
				}
			}
		}
		else
		{
			for(int a=head[x];a>0;a=nxt[a])
			{
				if(die2[a]==1) out[to[a]]++,die2[a]=0;
			}
		}
		bool ans=1;
		for(int a=1;a<=n;a++)
		{
			if(out[a]!=1)
			{
				ans=0;
				break;
			}
		}
		if(ans==1) printf("YES\n");
		else printf("NO\n");
	}
}
