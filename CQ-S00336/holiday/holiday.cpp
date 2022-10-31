#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
typedef pair<int,int> pii;
const int nx=3030,mx=10010,inf=0x3f3f3f3f;
inline int read()
{
	int x=0;
	bool f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=1;
		ch=getchar();
	}
	while('0'<=ch&&'9'>=ch)
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return f?-x:x;
}
int v[nx],head[mx],nxt[mx],to[mx],cnt=1,k,n,m;
void add(int f,int t)
{
	nxt[cnt]=head[f],to[cnt]=t;
	head[f]=cnt++;
}
bool cmp(pii g,pii h)
{
	return g.first ==h.first?g.second>h.second:g.F>h.first;
}
bool far[nx][nx];
pii q[nx];
void bfs(int x)
{
	vector<int>p;
	for(int i=0; i<nx; ++i)
	{
		q[i].first=inf;
		p[i]=inf;
	}
	int sz=0;
	for(int i=head[x]; i; i=nxt[i])
		q[sz++]=pii(0,to[i]);
	sort(q,q+sz,cmp);
	while(q[0].first>=k&&sz)
	{
		int y=q[0].second ;
		p[y]=q[0].F;
		far[x][y]=1;
		q[0].first =inf;
		for(int j=head[j]; j; j=nxt[j])
			if(p[j]==inf)q[sz++]=pii(p[y]+1,to[j]);
		sort(q,q+sz,cmp);
	}
}
pair<pii,pii> bty[nx];
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=2; i<=n; ++i)v[i]=read();
	for(int i=0; i<m; i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	for(int i=0; i<n; i++)bfs(i);
	queue<int>p;
	for(int i=0; i<=n; i++)if(far[1][i])p.push(i);
	while(!p.empty())
	{
		int a=p.front() ;
		p.pop() ;
		for(int i=head[a]; i; i=nxt[i])
		{
			if(v[a]>bty[to[i]].first.F)
			{
				bty[to[i]].second =bty[to[i]].first;
				bty[to[i]].first=pii(v[a],a);
			}
			else if(v[a]>bty[to[i]].second.F)
				bty[to[i]].second =pii(v[a],a);
		}
	}
	int ans=0;
	for(int i=2; i<=n; ++i)
	{
		if(!bty[i].first.F)continue;
		for(int j=i+1; j<=n; ++j)
		{
			if(!bty[j].first.F)continue;
			if(far[i][j])
			{
				if(bty[i].first.S==j)
				{
					if(!bty[i].second.F)continue;
					if(bty[i].second.S==bty[j].first.S)
						if(bty[j].second.S==i)continue;
						else
						{
							ans=min(ans,v[i]+v[j]+bty[i].second.F+bty[j].second.F);
							continue;
						}
					if(i==bty[j].first.S)
						if(bty[i].second.S==bty[j].second.S)continue;
						else
						{
							ans=min(ans,v[i]+v[j]+bty[i].second.F+bty[j].second.F);
							continue;
						}
					ans=min(ans,v[i]+v[j]+bty[i].second.F+bty[j].first.F);
				}
				else if(bty[j].first.S==i)
				{
					if(!bty[j].second.F)continue;
					if(bty[j].second.S==bty[i].first.S)
						if(bty[i].second.S==j)continue;
						else
						{
							ans=min(ans,v[i]+v[j]+bty[j].second.F+bty[i].second.F);
							continue;
						}
					if(j==bty[i].first.S)
						if(bty[j].second.S==bty[i].second.S)continue;
						else
						{
							ans=min(ans,v[i]+v[j]+bty[j].second.F+bty[i].second.F);
							continue;
						}
					ans=min(ans,v[i]+v[j]+bty[j].second.F+bty[i].first.F);
				}
				else ans=min(ans,v[i]+v[j]+bty[i].first.F+bty[j].first.F);
			}
		}
	}
	return 0;
}
