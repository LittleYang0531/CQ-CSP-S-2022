#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,ans[2505][2505],head[200005],vis[2505],ansm,p[2505];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector <int> v[2505],vp[2505];
void dfs(int x,int now,int sum)
{
	if(now==4)
	{
		//cout<<"in: "<<now<<" "<<ans[now][1]<<endl;
		if(ans[x][1]<=k)
		{
			//cout<<"ans: "<<x<<" "<<ansm<<" "<<sum<<endl;
			ansm=max(ansm,sum);
		}
		//cout<<"ansreturn"<<endl;
		return;
	}
	for(int i=0;i<vp[x].size();i++)
	{
		if(vis[vp[x][i]]==0)
		{
			//cout<<x<<" "<<vp[x][i]<<endl;
			//cout<<"DFS:"<<x<<" "<<now<<" "<<sum<<endl;
			vis[vp[x][i]]=1;
			dfs(vp[x][i],now+1,sum+p[vp[x][i]]);
			vis[vp[x][i]]=0;
		}
	}
	//cout<<"normal"<<endl;
}
void dij(int now,int sum)
{
	q.push(make_pair(now,sum));
	while(!q.empty())
	{
		int x=q.top().first,y=q.top().second;
		vis[x]++;
		q.pop();
		for(int i=0;i<v[x].size();i++)
		{
			if(vis[v[x][i]]==10) continue;
			if(ans[now][v[x][i]]>y+1)
			{
				ans[now][v[x][i]]=y+1;
				q.push(make_pair(v[x][i],y+1));
			}
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(ans,0x3f,sizeof(ans));
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int ii=1;ii<=n;ii++)
	{
		ans[ii][ii]=-1;
		memset(vis,0,sizeof(vis));
		dij(ii,-1);
		for(int i=1;i<=n;i++)
		{
			if(ans[ii][i]<=k)
			{
				vp[ii].push_back(i);
			}
			//cout<<ans[ii][i]<<" ";
		}
		//cout<<endl;
	}
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	dfs(1,0,0);
	cout<<ansm<<endl;
	return 0;
}
