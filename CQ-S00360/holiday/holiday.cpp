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
const int N=2510,M=2e4+10,inf=0x3f3f3f3f;
int n,m,k,now=1,dis[N][N];
int first[N],to[M],nxt[M],cnt;
bool vis[N];
long long ans,a[N];
queue<int>q;
inline void inc(int x,int y) {nxt[++cnt]=first[x],to[cnt]=y,first[x]=cnt;}
void bfs(int S)
{
	for(int i=1;i<=n;i++) dis[S][i]=inf;
	dis[S][S]=0,q.push(S);
	while(!q.empty())
	{
		int x=q.front(),t=dis[S][x]+1;q.pop();
		for(int i=first[x],v;i;i=nxt[i])
			if(dis[S][v=to[i]]>t) dis[S][v]=t,q.push(v);
	}
}
void check()
{
	int To=0;
	vis[now]=true;
	for(int i=1;i<=n;i++)
		if(dis[now][i]<=k+1&&a[i]>a[To]&&!vis[i]) To=i;
	ans+=a[To];now=To;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%lld",a+i);
	int u,v;
	while(m--)
	{
		scanf("%d%d",&u,&v);
		inc(u,v),inc(v,u);
	}
	for(int i=1;i<=n;i++) bfs(i);
	for(int i=2;i<=n;i++)
	{
		if(dis[1][i]>k+1) continue;
		for(int j=2;j<=n;j++)
		{
			if(i==j||dis[i][j]>k+1) continue;
			for(int K=2;K<=n;K++)
			{
				if(K==i||K==j||dis[j][K]>k+1) continue;
				for(int p=2;p<=n;p++)
				{
					if(p==i||p==j||p==K||dis[K][p]>k+1||dis[1][p]>k+1) continue;
					ans=max(ans,a[i]+a[j]+a[K]+a[p]);
				}
			}
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
