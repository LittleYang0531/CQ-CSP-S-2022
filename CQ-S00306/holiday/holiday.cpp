#include<bits/stdc++.h>
#define N 5005
#define P pair<int,int>
#define mp make_pair
using namespace std;
int n,m,k;
long long ans,val[N];
int dis[N][N],vst[N];
bool go[N],a[N][N];
vector<int>s[N];
inline int re()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
void dij(int v0)
{
	priority_queue<P,vector<P>,greater<P> >q;
	for(int i=1;i<=n;i++) vst[i]=0,dis[v0][i]=1e9;
	dis[v0][v0]=0;
	q.push(mp(dis[v0][v0],v0));
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vst[x]) continue;
		vst[x]=1;
		for(int y:s[x])
			if(dis[v0][y]>dis[v0][x]+1)
				dis[v0][y]=dis[v0][x]+1,q.push(mp(dis[v0][y],y));
	}
	for(int i=1;i<=n;i++) if(i!=v0) dis[v0][i]--;
}
void dfs(int step,int x,long long s)
{
	if(step==5) return ans=max(ans,s),void();
	for(int i=1;i<=n;i++)
	{
		if(dis[x][i]>k||go[i]) continue;
		if(step==4&&dis[1][i]>k) continue;
		go[i]=1;
		dfs(step+1,i,s+val[i]);
		go[i]=0;
	}
}
void dfs2(int step,int x,long long s)
{
	if(step==5) return ans=max(ans,s),void();
	for(int i=1;i<=n;i++)
	{
		if(!a[x][i]) continue;
		if(go[i]) continue;
		if(step==4&&dis[1][i]>k) continue;
		go[i]=1;
		dfs(step+1,i,s+val[i]);
		go[i]=0;
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=re(),m=re(),k=re();
	for(int i=2;i<=n;i++) scanf("%lld",&val[i]);
	if(k==0)
	{
		for(int i=1,x,y;i<=m;i++) 
		{
			x=re(),y=re();
			a[x][y]=a[y][x]=1;
		}
		dfs2(1,1,0);
		printf("%lld",ans);
		return 0;
	}
	for(int i=1,x,y;i<=m;i++) 
	{
		x=re(),y=re();
		s[x].push_back(y);
		s[y].push_back(x);
	}
	for(int i=1;i<=n;i++) dij(i);
	go[1]=1;
	dfs(1,1,0);
	printf("%lld",ans);
	return 0;
}
/*
d**kwish       \
hhpq			\
push_and_knock   \
junkfood 		  \
multiset		   \				
horse               \                   Orz
chicken(unrated)    /
stasis             /
jason_sun         /
rxm              /
geng            /
captainWei     /
soup          /
It's a bad holiday :(
*/
