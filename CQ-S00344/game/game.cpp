#include<bits/stdc++.h>
using namespace std;
const long long INF=1e86;
long long grd[1005][1005];
long long a[100005],b[100005];
inline int work(int lx,int rx,int ly,int ry)
{
	priority_queue<long long> q;
	if(lx==rx)//只能在一行里面选，选最小 
	{
		long long minn=INF;
		for(int i=ly;i<=ry;i++)
		{
			minn=min(minn,grd[lx][i]);
		}
		return minn;
	}
	if(ly==ry)//只能在一列里面选，选最大
	{
		long long maxn=-INF;
		for(int i=lx;i<=rx;i++)
		{
			maxn=max(maxn,grd[i][ly]);
		}
		return maxn;
	}
	for(int i=lx;i<=rx;i++)//无特殊情况 
	{
		long long minn=INF;
		for(int j=ly;j<=ry;j++)
		{
			minn=min(minn,grd[i][j]);
		}
		q.push(minn);
	}
	return q.top();
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) in>>b[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			grd[i][j]=a[i]*b[j];
		}
	}
	while(q--)
	{
		int lx,rx,ly,ry;
		cin>>lx>>rx>>ly>>ry;//可选择的范围：lx,ly  rx,ry 
		cout<<work(lx,rx,ly,ry)<<endl;
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
*/
