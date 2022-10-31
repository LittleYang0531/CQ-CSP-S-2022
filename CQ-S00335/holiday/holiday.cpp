#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
	int tar,nxt;
}arr[200005];
int fst[20005],cnt;
void adds(int x,int y)
{
	arr[++cnt].tar=y,arr[cnt].nxt=fst[x],fst[x]=cnt;
}
bool vis[2505][2505];
int dis[2505][2505];
long long s[2505];
queue<int> p;
void bfs()
{
	memset(dis,0x3f,sizeof(dis));
	for(int st=1;st<=n;++st)
	{
		vis[st][st]=1;
		dis[st][st]=0;
		p.push(st);
		while(!p.empty())
		{
			int x=p.front();
			p.pop();
			for(int i=fst[x];i;i=arr[i].nxt)
			{
				int j=arr[i].tar;
				if(vis[st][j]) continue;
				vis[st][j]=true;
				dis[st][j]=dis[st][x]+1;
				p.push(j);
			}
		}
	}
}
pair<long long,int> nothing;
vector<pair<long long,int> > qwq1[2505],qwq2[2505];
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;++i) scanf("%lld",&s[i]);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adds(x,y);
		adds(y,x);
	}
	nothing=make_pair(0,0);
	bfs();
	for(int i=2;i<=n;++i)
	{
		qwq1[i].push_back(nothing);
		qwq1[i].push_back(nothing);
		qwq1[i].push_back(nothing);
		for(int j=2;j<=n;++j)
		{
			if(i==j) continue;
			if(dis[i][j]-1>k) continue;
			if(dis[j][1]-1>k) continue;
			pair<long long,int> no1=nothing,no2=nothing,no3=nothing,now;
			if(qwq1[i].size()) no1=qwq1[i][0];
			if(qwq1[i].size()>1) no2=qwq1[i][1];
			if(qwq1[i].size()>2) no3=qwq1[i][2];
			now=make_pair(s[j],j);
			if(now>no1)
			{
				no3=no2;no2=no1;no1=now;
			}
			else if(now>no2)
			{
				no3=no2;no2=now;
			}
			else if(now>no3)
			no3=now;
			qwq1[i][0]=no1;
			qwq1[i][1]=no2;
			qwq1[i][2]=no3;
		}
	}
	long long ans=0;
	for(int i=2;i<=n;++i)
	{
		for(int j=2;j<=n;++j)
		{
			if(i==j) continue;
			if(dis[i][j]-1>k) continue;
			for(int l1=0;l1<=2;++l1)
			{
				for(int l2=0;l2<=2;++l2)
				{
					if(qwq1[i][l1]==nothing||qwq1[j][l2]==nothing) continue;
					if(qwq1[i][l1].second==j||qwq1[i][l1].second==qwq1[j][l2].second||qwq1[j][l2].second==i) continue;
//					cout<<qwq1[i][l1].second<<" "<<i<<" "<<j<<" "<<qwq1[j][l2].second<<endl;
					ans=max(s[i]+s[j]+qwq1[i][l1].first+qwq1[j][l2].first,ans);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
