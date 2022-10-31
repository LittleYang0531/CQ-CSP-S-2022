#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long res=0;
	char tmp=getchar();
	while(tmp>'9'||tmp<'0') tmp=getchar();
	while(tmp<='9'&&tmp>='0')
	{
		res=res*10+tmp-'0';
		tmp=getchar();
	}
	return res;
}
inline int readi()
{
	int res=0;
	char tmp=getchar();
	while(tmp>'9'||tmp<'0') tmp=getchar();
	while(tmp<='9'&&tmp>='0')
	{
		res=res*10+tmp-'0';
		tmp=getchar();
	}
	return res;
}
int v[200005],start,ci;
long long dis[200005];
int n,Q;
struct Edge
{
	int to,next;
}edge[400005];
int head[200005],cedge;
inline void add(int x,int y)
{
	edge[++cedge].to=y;
	edge[cedge].next=head[x];
	head[x]=cedge;
}
struct Node
{
	int id,cnt,prt,fath;
};
queue<Node> q;
inline void work()
{
	while(!q.empty())
	{
		Node tmp=q.front();
		q.pop();
		for(int i=head[tmp.id];i;i=edge[i].next)
		{
			if(edge[i].to==tmp.prt) continue;
			int to=edge[i].to;
			Node newone;
			if(tmp.cnt<ci)//还可以从fath继续直达 
			{
				dis[to]=min(dis[to],dis[tmp.fath]+v[to]);
				newone.cnt=tmp.cnt+1;
				newone.fath=tmp.fath;
				newone.id=to;
				newone.prt=tmp.id;
				q.push(newone);
			}
			dis[to]=min(dis[to],dis[tmp.id]+v[to]);//把tmp.id转给to 
			newone.cnt=1;
			newone.fath=tmp.id;
			newone.id=to;
			newone.prt=tmp.id;
			q.push(newone);//从to开始找直达的边
		}
	}
}
inline void solve(int s,int e)
{
	memset(dis,0x3f,sizeof dis);
	dis[s]=v[s];
	Node now;
	now.cnt=1;
	now.fath=s;
	now.id=s;
	now.prt=s;
	q.push(now);
	work();//处理s到所有点的最短距离
//	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
	cout<<dis[e];
	cout<<endl;
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>Q>>ci; 
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=readi();b=readi();
		add(a,b);
		add(b,a);
	}
	while(Q--)
	{
		int s,t;
		s=readi();t=readi();
		solve(s,t);
	}
	return 0;
}
