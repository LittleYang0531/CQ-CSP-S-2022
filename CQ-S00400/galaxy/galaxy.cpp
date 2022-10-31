#include<bits/stdc++.h>
using namespace std;
struct edge{int next,to;bool vis=0;}q1[500001],q2[500001];
int n,m,h1[500001],h2[500001],cnt1,cnt2,sum;
inline void add1(int x,int y){q1[++cnt1].next=h1[x],q1[cnt1].to=y,h1[x]=cnt1;}
inline void add2(int x,int y){q2[++cnt2].next=h2[x],q2[cnt2].to=y,h2[x]=cnt2;}
inline void init()
{
	cin>>n>>m,sum=m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y,add1(x,y),add2(y,x);
	}
}
inline void solve()
{
	int q;
	cin>>q;
	while(q--)
	{
		int ty,u;
		cin>>ty>>u;
		if(ty==1)
		{
			int v;
			cin>>v;
			for(int i=h1[u];i;i=q1[i].next)if(q1[i].to==v)q1[i].vis=q2[i].vis=1,sum--;
		}
		if(ty==2)
		{
			for(int i=h2[u];i;i=q2[i].next)q1[i].vis=q2[i].vis=1,sum--;
		}
		if(ty==3)
		{
			int v;
			cin>>v;
			for(int i=h1[u];i;i=q1[i].next)if(q1[i].to==v)q1[i].vis=q2[i].vis=0,sum++;
		}
		if(ty==4)
		{
			for(int i=h2[u];i;i=q2[i].next)q1[i].vis=q2[i].vis=0,sum++;
		}
		bool bj=0;
		for(int i=1;i<=n;i++)
		{
			int summ=0;
			for(int j=h1[i];j;j=q1[j].next)
			{
				summ+=q1[j].vis;
				if(summ==2)
				{
					bj=1;break;
				}
			}
			if(bj)break;
		}
		if(bj)
		{
			cout<<"NO\n";
			continue;
		}
		if(sum<n-1)cout<<"NO\n";
		else cout<<"YES\n";
	}
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	init(),solve();
	return 0;
}
