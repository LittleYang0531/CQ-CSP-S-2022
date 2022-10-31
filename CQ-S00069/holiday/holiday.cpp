#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,a[2503][2503],s[2503],flag[2503];
struct node
{
	int ans,num,t;
};
queue<node> q;
int bfs(int v)
{
	node y;
	int maxx=0;
	y.num=1;
	y.ans=0;
	y.t=0;
	flag[1]=1;
	q.push(y);
	while(!q.empty())
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i][q.front().num]==1&&flag[i]<4)
			{
				flag[i]++;
				node f;
				f.ans=q.front().ans+s[i];
				f.t=q.front().t+1;
				f.num=i;
				maxx=max(maxx,f.ans);
				q.push(f);
			}
		}
		q.pop();
	}
	return maxx;
}
signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=m;i++)
	{
		int q,b;
		cin>>q>>b;
		a[q][b]=a[b][q]=1;
	}
	cout<<bfs(1)<<endl;
 	return 0;
}

