#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define rep1(i,l,r) for(int i=l;i<=r;i++)
#define rep2(i,l,r) for(int i=l;i>=r;i--)
const int N=4e5+10;
using namespace std;
int n,q,k,w[N],a,b,e[N],ne[N],h[N],idx=1,s,t,ans;
bool vis[N];
map<pii,bool> mp;
void add(int x,int y)
{
	e[idx]=y;
	ne[idx]=h[x];
	h[x]=idx++;
}
void bfs(int x)
{
	memset(vis,0,sizeof vis);
	vis[x]=1;
	queue<pii> q;
	q.push(make_pair(x,0));
	while(!q.empty())
	{
		int t=q.front().x;
		int ks=q.front().y;
		q.pop();
		for(int i=h[t];~i;i=ne[i])
		{
			int to=e[i];
			if(!vis[to]&&ks<k)
			{
				mp[make_pair(x,to)]=mp[make_pair(to,x)]=1;
				q.push(make_pair(to,ks+1));
				vis[to]=1;
			}
		}
	}
}
void find(int x,int y,int sum)
{
	vis[x]=1;
	if(x==y)
	{
		ans=min(ans,sum);
		return;
	}
	for(int i=h[x];~i;i=ne[i])
	{
		int to=e[i];
		if(!vis[to])
		{
			vis[to]=1;
			find(to,y,sum+w[to]);
			vis[to]=0;
		}
	}
}
signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	memset(h,-1,sizeof h);
	cin>>n>>q>>k;
	rep1(i,1,n) cin>>w[i];
	rep1(i,1,n-1)
	{
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	rep1(i,1,n) bfs(i);
	memset(h,-1,sizeof h);
	memset(e,0,sizeof e);
	memset(ne,0,sizeof ne);
	rep1(i,1,n) rep1(j,1,n) if(mp[make_pair(i,j)]) add(i,j);
	while(q--)
	{
		ans=LONG_LONG_MAX;
		cin>>s>>t;
		memset(vis,0,sizeof vis);
		find(s,t,w[s]);
		cout<<ans<<endl;
	}
	return 0;
}
/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2
*/

