#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define rep1(i,l,r) for(int i=l;i<=r;i++)
#define rep2(i,l,r) for(int i=l;i>=r;i--)
const int N=1e5+10;
using namespace std;
int n,m,k,a,b,w[N],e[N],ne[N],h[N],idx=1,ans;
pii f[N][10];
map<pii,bool> mp;
bool vis[N],st[N];
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
			if(!vis[to]&&ks<=k)
			{
				mp[make_pair(x,to)]=mp[make_pair(to,x)]=1;
				q.push(make_pair(to,ks+1));
				vis[to]=1;
			}
		}
	}
}
signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(h,-1,sizeof h);
	cin>>n>>m>>k;
	rep1(i,2,n) cin>>w[i];
	rep1(i,1,m)
	{
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	rep1(i,1,n) bfs(i);
	memset(h,-1,sizeof h);
	memset(e,0,sizeof e);
	memset(ne,0,sizeof ne);
	idx=1;
	rep1(i,1,n) rep1(j,1,n) if(mp[make_pair(i,j)]) add(i,j);
	for(int i=h[1];~i;i=ne[i]) st[e[i]]=1;
	for(int i1=h[1];~i1;i1=ne[i1])
	{
		int to1=e[i1];
		for(int i2=h[to1];~i2;i2=ne[i2])
		{
			int to2=e[i2];
			if(to2==to1) continue;
			for(int i3=h[to2];~i3;i3=ne[i3])
			{
				int to3=e[i3];
				if(to3==to2||to3==to1) continue;
				for(int i4=h[to3];~i4;i4=ne[i4])
				{
					int to4=e[i4];
					if(to1==to4||to2==to4||to3==to4) continue;
					if(st[to4]) ans=max(ans,w[to1]+w[to2]+w[to3]+w[to4]);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4

*/

