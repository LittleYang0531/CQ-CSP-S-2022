#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int to,next;
} a[500001];
int h[500001],cnt;
void add(int x,int y)
{
	a[++cnt].to = y;
	a[cnt].next = h[x];
	h[x]=cnt;
}
int ans,v[500001],p[500001];
int n,m,k;
struct node
{
	int id,v;
	bool operator <(const node &a) const
	{
		return v<a.v;
	}
};
priority_queue<node> q;
int d[2501][2501];
void dij(int m)
{
	for(int i = 1;i <= n;i++)v[i]=0,d[m][i]=0x3f3f3f3f;
	q.push((node){m,-1});
	d[m][m]=-1;
	while(!q.empty())
	{
		node u = q.top();
		q.pop();
		int x = u.id;
		if(v[x]>n)continue;
		v[x]++;
		for(int i = h[x];i;i = a[i].next)
		{
			int y = a[i].to;
			if(d[m][y]>d[m][x]+1)
			{
				d[m][y]=d[m][x]+1;
				q.push((node){y,d[m][y]});
			}
		}
	}
}
inline void dfs(int x,int prt,int op,int sumax)
{
//	cout << x << " " << prt << " " << op << " " << nowuse << " " << sumax << endl;
	if(op==5&&x==1)
	{
	//	cout << "rrr" << endl;
		ans=max(ans,sumax);
		return;
	}
	else if(op>=5)return;
	for(int i = h[x];i;i = a[i].next)
	{
		int y = a[i].to;
		if(y==prt)continue;
		if(op<5)
		{
			if(v[y])continue;
			v[y]=1;
			dfs(y,x,op+1,sumax+p[y]);
			v[y]=0;
		}
	}
}
signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 2;i <= n;i++)
	{
		cin >> p[i];
	}
	for(int i = 1;i <= m;i++)
	{
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	if(k==0&&n>10)
	{
		dfs(1,0,0,0);
		cout << ans;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		dij(i);
//		for(int j = 1;j <= n;j++)
//		{
//			cout << d[i][j] << " ";
//		}
//		cout << "\n";
	}
	for(int i = 2;i <= n;i++)
	{
		if(d[1][i]>k)continue;
		for(int j = 2;j <= n;j++)
		{
			if(j==i)continue;
			if(d[i][j]>k)continue;
			for(int kv = 2;kv <= n;kv++)
			{
				if(kv==j||kv==i)continue;
				if(d[j][kv]>k)continue;
				for(int l = 2;l <= n;l++)
				{
					if(l==kv||l==j||l==i)continue;
					if(d[kv][l]>k)continue;
					if(d[l][1]>k)continue;
					ans=max(ans,p[i]+p[j]+p[kv]+p[l]);
				}
			}
		}
	}
//	dfs(1,0,0,0,0);
	cout << ans;
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


*/

