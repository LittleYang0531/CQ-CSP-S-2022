#include <bits/stdc++.h>
using namespace std;
int n,m,k,sco[1001],pd[1001],step,sum,ans,an;
int head[1001],tot,to[1001],nxt[1001];
void add(int a,int b)
{
	tot++;
	to[tot]=b;
	nxt[tot]=head[a];	
	head[a]=tot;
}
void bfs(int x,int y)
{
	int hed=1,tail=2;
	int way[1001][2]; 
	way[hed][0]=-1;
	way[hed][1]=0;
	while(hed<tail)
	{
		for(int i=head[x];i;i=nxt[i])
		{
			way[tail][0]=way[hed][0]+1;
			way[tail][1]=way[hed][1]+sco[to[i]];
			if(tail==y)
			{
				step=way[tail][0];
				sum=way[tail][1];
				return;
			}
			tail++;
		}
		hed++;
	}
}
int main() 
{
freopen("holiday.in","r",stdin);
freopen("holiday.out","w",stdout);
cin>>n>>m>>k;
for(int i=2;i<=n;i++)
	cin>>sco[i];
sco[1]=0;
for(int i=1;i<=m;i++)
{
	int x,y;
	cin>>x>>y;
	add(x,y);
	add(y,x);
}
for(int i=1;i<=n-3;i++)
{
	bfs(1,i);
	if(step>k)
		continue;
	ans+=sum;
	for(int j=i+1;j<=n-2;j++)
	{
		bfs(i,j);
		if(step>k)
			continue;
		ans+=sum;
		for(int kk=j+1;kk<=n-1;kk++)
		{
			bfs(j,kk);
			if(step>k)
				continue;
			ans+=sum;
			for(int l=kk+1;l<=n;l++)
			{
				bfs(kk,l);
				if(step>k)
					continue;
				ans+=sum;
				bfs(l,1);
				if(step>k)
					continue;
				ans+=sum;
				an=max(ans,an);
				ans=0;
			}
			ans-=sum;
		}
		ans-=sum;
	}
}
cout<<an;
	return 0;
}
