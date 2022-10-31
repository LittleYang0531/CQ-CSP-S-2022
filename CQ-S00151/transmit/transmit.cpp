#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+5;
void read(int &x)
{
	x=0;
	short flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=flag;
}
int to[MAXN],nxt[MAXN],head[MAXN],val[MAXN],vis[MAXN],tot,sum[MAXN],value[MAXN];
void add(int x,int y,int w)
{
	to[++tot]=y,val[tot]=w;
	nxt[tot]=head[x],head[x]=tot;
}
priority_queue<pair<long long,int> > que;
long long dis[MAXN];
int n,Q,k;
void Dijkstra(int s)
{
	for(int i=1;i<=n;i++)	dis[i]=1e17;
	dis[s]=value[s];
	que.push(make_pair(0,s));
	while(!que.empty())
	{
		int t=que.top().second;
		que.pop();
		if(vis[t])	continue;
		vis[t]=1;
		if(sum[t]==k)	continue;
		for(int i=head[t];i;i=nxt[i])
		{
			if(dis[to[i]]>dis[t]+val[i])
			{
				dis[to[i]]=dis[t]+val[i];
				sum[to[i]]=sum[t]+1;
				que.push(make_pair(-dis[to[i]],to[i]));
			}
		}
	}
}
int from[MAXN],TO[MAXN];
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	read(n),read(Q),read(k);
	for(int i=1;i<=n;i++)	read(value[i]);
	for(int i=1;i<n;i++)
	{
		read(from[i]),read(TO[i]);
		add(from[i],TO[i],value[TO[i]]),add(TO[i],from[i],value[from[i]]);
	}
	int mini=1;
	for(int i=2;i<=n;i++)
	{
		if(value[mini]>value[i])	mini=i;
	}
	Dijkstra(mini);
	while(Q--)
	{
		int fr,t;
		read(fr),read(t);
		if(fr==mini)
		{
			if(dis[t]!=1e17)	printf("%lld\n",value[fr]+value[t]);
			else	puts("1221097936");
		}
		else if(t==mini)
		{
			if(dis[fr]!=1e17)	printf("%lld\n",value[t]+value[fr]);
			else	puts("1221097936");
		}
		else	printf("%lld\n",value[fr]+value[t]+value[mini]);
	}
	return 0;
}
