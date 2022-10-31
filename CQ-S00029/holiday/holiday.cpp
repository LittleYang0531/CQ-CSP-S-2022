#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100005;
long long n,m,k,tot,sum = -1e6,ans;
long long val[maxn],head[maxn],to[maxn],nxt[maxn],vis[maxn];
void add(long long  a,long long  b)
{
	to[++tot] = b;
	nxt[tot] = head[a];
	head[a] = tot;
}
//void dfs(long long now,int cnt)
//{
//	
//	if(cnt == 5 && now == 1)
//	{
//		sum = max(sum,ans);
//		return ;
//	}
//	for(long long  i = head[now]; i; i = nxt[i])
//	{
//		ans += val[to[i]];
//		dfs(to[i],cnt + 1);
//	//	ans -= val[to[i]];
//	}
//	return ;
//}
void dfs(long long now,long long cnt)
{
	if(cnt == 5 && now == 1)
	{
		sum = max(sum,ans);
	//	cout << sum << endl;
		return ;
	}
	if(cnt >= 5 && now != 1) return ;
	for(long long i = head[now]; i; i = nxt[i])
	{
		if(!vis[to[i]])
		{
			vis[to[i]] = 1;
			ans += val[to[i]];
			dfs(to[i],cnt + 1);
			ans -= val[to[i]];
			vis[to[i]] = 0;
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i = 2; i <= n; i++) scanf("%lld",&val[i]);
	for(int i = 1; i<= m; i++)
	{
		long long x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y); add(y,x);
	}
	val[1] = 0;
	dfs(1,1);
	cout << sum;
	return 0;
}
