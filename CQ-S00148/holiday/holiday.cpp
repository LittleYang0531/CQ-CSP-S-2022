//fuck!
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>

template<typename T>
inline void read(T &a)
{
	char c;
	bool flag=0;
	while(!isdigit(c=getchar()))
		flag|=(c=='-');
	a=0;
	for(a=c-'0';isdigit(c=getchar());a=a*10+c-'0');
	flag&&(a=-a);
}
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=2.5e3+10;
int n,m,k;
ll w[N];
set<short> to[N],ori[N];
int dist[N];
bool vis2[N][N];

void dfs(short u,char cnt,short pa,short fa)
{
	if(u!=pa)	to[pa].emplace(u),vis2[pa][u]=1;
	if(cnt>0)
		for(auto v:ori[u])
			if(!vis2[pa][v])
				dfs(v,cnt-1,pa,u);
}

ll ans=0;
short stk[5],tt=0;
inline ll calc()
{
	ll res=0;
	for(int i=1;i<tt;i++)
		res+=w[stk[i]];
	return res;
}
inline bool chk(int u)
{
	for(int i=0;i<tt;i++)
		if(stk[i]==u)	return 1;
	return 0;
}
inline void debug()
{
	for(int i=0;i<tt;i++)
		cout<<stk[i]<<' ';
	cout<<endl;
}
int cnt=0;
map<ll,bool> mp;
inline bool Hash()
{
	if(tt<=1)	return 0;
	ll tmp2=0;
	vector<short> tmp;
	for(int i=1;i<tt-1;i++)	tmp.emplace_back(stk[i]);
	sort(tmp.begin(),tmp.end());
	tmp.emplace_back(stk[tt-1]);
	for(auto i:tmp)	tmp2=tmp2*2501+i;
	if(mp.count(tmp2))	return 1;
	mp[tmp2]=1;
	return 0;
}
void dfs2(short u)
{
	cnt++;
	if(tt==5)
	{
		if(u==1)
		{
			ll res=ans;
			ans=max(ans,calc());
//			if(ans!=res)	debug();
		}
		return;
	}
	if(tt&&u==1)	return;
	stk[tt++]=u;
//	if(Hash())	return;
	if(tt==5&&dist[u]==1)	dfs2(1);
	else if(tt<5)
	for(auto v:to[u])
		if(!chk(v))
		{
			if(dist[v]<=5-tt)
				dfs2(v);
		}
	tt--;
}

bool vis[N];
inline void dijkstra()
{
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,1});
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u])	continue;
		vis[u]=1;
		for(auto v:to[u])
			if(!vis[v])
			{
				if(dist[v]>dist[u]+1)
				{
					dist[v]=dist[u]+1;
					q.push({dist[v],v});
				}
			}
	}
}

int main()
{
//	freopen("C:\\Users\\HF01\\Desktop\\CSP-S\\CSP-S\\holiday\\holiday3.in","r",stdin);
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
//	read(n),read(m),read(k);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=2;i<=n;i++)	scanf("%lld",w+i);//read(w[i]);
	for(int i=1,a,b;i<=m;i++)
	{
//		read(a),read(b);
		scanf("%d %d",&a,&b);
		to[a].emplace(b),to[b].emplace(a);
		ori[a].emplace(b),ori[b].emplace(a);
	}
	for(int i=1;i<=n;i++)
		dfs(i,k+1,i,i);
	dijkstra();
	dfs2(1);
//	cout<<cnt<<endl;
	cout<<ans<<endl;
	return 0;
}

