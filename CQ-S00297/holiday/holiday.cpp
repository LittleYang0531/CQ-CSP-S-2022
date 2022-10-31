#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define eb(x) emplace_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(),x.end()
const int N=2510,inf=0x3f3f3f3f;
typedef long long LL;
typedef pair<LL,int> pii;
int n,m,k,d[N][N];
int h[N],e[N],ne[N],idx;
LL val[N];
vector<pii>vec[N];
template<typename T,typename L>inline void chkmx(T &x,L y){(x<y) && (x=y);}
void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

LL ans;
queue<int>q;
void bfs(int st)
{
	q.push(st);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=h[u];i!=-1;i=ne[i])
		{
			int v=e[i];
			if(d[st][u]+1<d[st][v])
			{
				d[st][v]=d[st][u]+1;
				q.push(v);
			}
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(h,-1,sizeof h);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
		scanf("%lld",&val[i]);
	for(int i=1;i<=m;i++)
	{
		int a=0,b=0;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a); 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			d[i][j]=inf;
		d[i][i]=0;
		bfs(i);
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			if(i==j) continue;
			if(d[1][j]-1>k || d[i][j]-1>k) continue;
			vec[i].eb(mp(val[j],j));
		}
		sort(vec[i].begin(),vec[i].end(),greater<pii>());
	}
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
		{
			if(i==j) continue;
			if(d[i][j]-1>k) continue;
			for(int p1=0;p1<min(5,(int)vec[i].size());p1++)
				for(int p2=0;p2<min(5,(int)vec[j].size());p2++)
				{
					if(vec[i][p1].se==j || vec[j][p2].se==i || vec[i][p1].se==vec[j][p2].se) continue;
					chkmx(ans,vec[i][p1].fi+vec[j][p2].fi+val[i]+val[j]);
				}
		}
	cout<<ans<<endl;
	return 0;
}
