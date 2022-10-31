/*
wonwon~ wonderhoy!
Wonderhoy!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while(!isdigit(c))	f=(c=='-'?-1:f),c=getchar();
	while(isdigit(c))	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
void write(LL x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
LL n,m,K;
LL a[2505];
vector<LL> G[2505];
LL dis[2505][2505];
bool vis[2505];
#define mp make_pair
typedef pair<LL,LL> P;
set<P> S[2505];
/*
 竟然要存前三大。
*/
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),K=read()+1;
	for(LL i=2;i<=n;++i)	a[i]=read();
	for(LL i=1;i<=m;++i)
	{
		LL u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	auto bfs=[&](LL s) -> void
	{
		queue<LL> Q;
		Q.push(s);
		memset(vis,false,sizeof vis);
		vis[s]=true;
		while(!Q.empty())
		{
			LL u=Q.front();
			Q.pop();
			for(auto v:G[u])
			{
				if(vis[v])	continue;
				Q.push(v);
				dis[s][v]=dis[s][u]+1;
				vis[v]=true;
			}
		}
	};
	for(LL i=1;i<=n;++i)	bfs(i);
	for(LL i=2;i<=n;++i)
	{
		if(dis[1][i]>K)	continue;
		for(LL j=2;j<=n;++j)
		{
			if(dis[i][j]>K || i==j)	continue;
			LL w=a[i]+a[j];
			S[j].insert(mp(w,i));
			if(LL(S[j].size())>3)	S[j].erase(S[j].begin());
		}
	}
	LL ans=0;
	for(LL i=2;i<=n;++i)
	{
		for(LL j=2;j<=n;++j)
		{
			if(dis[i][j]>K || i==j)	continue;
			for(P x:S[i])
			{
				if(x.second==j)	continue;
				for(P y:S[j])
				{
					if(x.second==y.second || i==y.second)	continue;
					ans=max(ans,x.first+y.first);
				}
			}
		}
	}
	write(ans);
	return 0;
}
