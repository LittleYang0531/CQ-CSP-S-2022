#include<bits/stdc++.h>
#define ll long long
#define N 2505
#define M 10005
#define inf 1e7
using namespace std;
int tot,num,vis[N],n,m,k,A,B,C,D,f[N][N],dis[N],first[N],nex[N*N],v[N*N];
ll ans,w[N];
vector<int>vec[N];
inline void Add(int s,int e)
{
	nex[++num]=first[s];
	first[s]=num;
	v[num]=e;
}
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void bfs(int s)
{
	queue<int>q;
	for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
	q.push(s);dis[s]=0;vis[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto x:vec[u])
		{
			if(vis[x]) continue;
			vis[x]=1;dis[x]=dis[u]+1;
			if(dis[x]<=k+1) q.push(x);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i]<=k+1) f[s][i]=1,Add(s,i);
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=2;i<=n;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=m;i++)
	{
		A=read();B=read();
		vec[A].push_back(B);
		vec[B].push_back(A);
	}
	for(int i=1;i<=n;i++) bfs(i);
	for(int i=1;i<=n;i++)
	{
		if(!f[1][i]) continue;
		A=i;
		for(int j=i+1;j<=n;j++)
		{
			if(!f[1][j]) continue;
			D=j;
			for(int t1=first[i];t1;t1=nex[t1])
			{
				if(v[t1]==i||v[t1]==j) continue;
				B=v[t1];
				for(int t2=first[B];t2;t2=nex[t2])
				{
					if(v[t2]==A||v[t2]==B||v[t2]==D) continue;
					C=v[t2];
					if(f[C][D]) ans=max(ans,w[A]+w[B]+w[C]+w[D]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
