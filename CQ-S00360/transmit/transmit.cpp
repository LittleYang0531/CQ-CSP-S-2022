//sto Lisdery orz
//sto Mu_tr orz
//sto ryhuang orz
//sto piggydan orz
//sto MrXBJ orz
//sto PPYYHH orz
//sto LittleYang orz
//sto hualian orz
//sto moyujiang orz
//sto zjy orz
//sto unreachable orz
//sto shuaizui orz
//sto lmgoat orz
//sto my_grandson orz
//sto gyh20 orz
//sto feecle6418 orz
//sto mazihang2022 orz
//sto Prean orz
//sto Leasier orz
//sto OhtoAi orz
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ok{
	int x;
	ll y;
	bool operator <(const ok &A) const{return y>A.y;}
};
const int N=2010,P=2e5+10,M=P<<1,maxj=18,inf=0x3f3f3f3f;
int n,q,k,a[P],dep[P],f[19][P],dis[N][N];
int first[P],to[M],nxt[M],cnt;
ll dp[P],W[19][P];
queue<int>Q;
priority_queue<ok>dijkstra;
inline void inc(int x,int y) {nxt[++cnt]=first[x],to[cnt]=y,first[x]=cnt;}
void bfs(int S)
{
	for(int i=1;i<=n;i++) dis[S][i]=inf;
	dis[S][S]=0,Q.push(S);
	while(!Q.empty())
	{
		int x=Q.front(),t=dis[S][x]+1;Q.pop();
		for(int i=first[x],v;i;i=nxt[i])
			if(dis[S][v=to[i]]>t) dis[S][v]=t,Q.push(v);
	}
}
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[0][x]=fa;W[0][x]=a[fa];
	for(int i=1;i<=maxj;i++)
		f[i][x]=f[i-1][f[i-1][x]],W[i][x]=W[i-1][x]+W[i-1][f[i-1][x]];
	for(int i=first[x];i;i=nxt[i])
		if(to[i]!=fa) dfs(to[i],x);
}
ll query(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	ll res=a[x];
	for(int i=maxj;~i;i--)
		if(dep[f[i][x]]>=dep[y]) res+=W[i][x],x=f[i][x];
	if(x==y) return res;
	res+=a[y];
	for(int i=maxj;~i;i--)
		if(f[i][x]!=f[i][y])
			res+=(W[i][x]+W[i][y]),
			x=f[i][x],y=f[i][y];
	return res+W[0][x];
}
void Dijkstra(int S)
{
	for(int i=1;i<=n;i++) dp[i]=1e18;
	dp[S]=a[S],dijkstra.push((ok){S,a[S]});
	while(!dijkstra.empty())
	{
		int x=dijkstra.top().x;
		ll l=dijkstra.top().y;
		dijkstra.pop();
		if(dp[x]!=l) continue;
		for(int i=1;i<=n;i++)
			if(dis[x][i]<=k&&dp[i]>l+a[i]) dp[i]=l+a[i],dijkstra.push((ok){i,dp[i]});
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		inc(u,v),inc(v,u);
	}
	int s,t;
	if(n<=2e3&&q<=2e3)
	{
		for(int i=1;i<=n;i++) bfs(i);
		while(q--)
		{
			scanf("%d%d",&s,&t);
			Dijkstra(s);
			cout<<dp[t]<<'\n';
		}
		return 0;
	}
	dfs(1,0);
	while(q--)
	{
		scanf("%d%d",&s,&t);
		cout<<query(s,t)<<'\n';
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
