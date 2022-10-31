#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int to,next;
} a[8000001];
int h[8000001],cnt;
inline void add(int x,int y)
{
	a[++cnt].to = y;
	a[cnt].next = h[x];
	h[x]=cnt;
}
int d[500001],prt[500001];
inline void dfs(int x,int prtx)
{
	for(int i = h[x];i;i = a[i].next)
	{
		int y = a[i].to;
		if(y==prtx)continue;
		d[y]=d[x]+1;
		prt[y]=x;
		dfs(y,x);
	}
}
int n,f[500001][30];
inline void make()
{
	for(int i = 1;i <= n;i++)f[i][0]=prt[i];
	for(int j = 1;j <= log2(n);j++)
	{
		for(int i = 1;i <= n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
}
inline int lca(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	int k = log2(d[x]);
	for(int i = k;i >= 0;i--)
	{
		if(d[f[x][i]]>=d[y])x=f[x][i];
	}
	if(x==y)return x;
	k = log2(d[x]);
	for(int i = k;i >= 0;i--)
	{
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
struct node
{
	int id;
	long long v;
	bool operator <(const node &a) const
	{
		return v<a.v;
	}
};
priority_queue<node> q;
long long pu[500001];
int vu[500001],vp[500001];
inline void dij(int m)
{
	for(int i = 1;i <= n;i++)vu[i]=0,pu[i]=0x7fffffffffffffff;
	q.push((node){m,vp[m]});
	pu[m]=vp[m];
	while(!q.empty())
	{
		node u = q.top();
		q.pop();
		int x = u.id;
		if(vu[x]>sqrt(n))continue;
		vu[x]++;
		for(int i = h[x];i;i = a[i].next)
		{
			int y = a[i].to;
			if(pu[y]>pu[x]+vp[y])
			{
				pu[y]=pu[x]+vp[y];
				q.push((node){y,pu[y]});
			}
		}
	}
}
int x[500001],y[500001];
//set<int> vc[500001];
//int v[500001],num1[500001];
long long ans[500001];
//f[i][j]:
signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q,k;
	cin >> n >> q >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> vp[i];
	}
	for(int i = 1;i < n;i++)
	{
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	d[1]=1;
	dfs(1,0);
	make();
	memset(h,0,sizeof(h));
//	memset(a,0,sizeof(a));
	cnt=0;
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			int mid = lca(i,j);
			int len = d[i]+d[j]-2*d[mid];
	//		cout << mid << " " << len << " " << i << " " << j << endl;
			if(len<=k)
			{
				add(i,j);
				add(j,i);
			}
		}
	}
	int cnt1 = 0;
	for(int i = 1;i <= q;i++)
	{
		cin >> x[i] >> y[i];
		dij(x[i]);
		ans[i]=pu[y[i]];
//		vc[x[i]].insert(i);
//		vc[y[i]].insert(i);
//		if(!v[x[i]])
//		{
//			v[x[i]]=++cnt1;
//			num1[cnt1]=x[i];
//		}
//		if(!v[y[i]])
//		{
//			v[y[i]]=++cnt1;
//			num1[cnt1]=y[i];
//		}
//	}
//	for(int i = 1;i <= cnt1;i++)
//	{
//		int xp = num1[i];
//		dij(xp);
//		for(auto j:vc[xp])
//		{
//			if(xp==x[j])
//			{
//				ans[j]=pu[y[j]];
//				vc[y[j]].erase(j);
//			}
//			else
//			{
//				ans[j]=pu[x[j]];
//				vc[x[j]].erase(j);
//			}
//		}
	}
	for(int i = 1;i <= q;i++)
	{
		cout << ans[i] << "\n";
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

