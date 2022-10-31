//Linkwish's code
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2505;
int n,m,K,dis[N];
struct pnt{int pos,dis;};
vector<int> e[N];
ll val[N];

bool vis[N],can[N][N];
vector<int> p[N];

bool got[N];
int fir[N],sec[N];
vector<int> q;
struct T{
	int pos;
	bool operator < (const T y)const{
		if(val[pos]==val[y.pos])return pos<y.pos;
		return val[pos]>val[y.pos];
	}
};
inline set<T>::iterator nxt(set<T>::iterator it){return ++it;}
inline void bfs(int st){
	for(int i=1;i<=n;i++)vis[i]=0;
	queue<pnt> q;
	q.push({st,0});
	vis[st]=1;
	int now,nd;
	while(!q.empty()){
		now=q.front().pos,nd=q.front().dis;
		q.pop();
		p[st].push_back(now);
		can[st][now]=1;
		if(nd>K)continue;
		for(int to:e[now]){
			if(!vis[to]){
				vis[to]=1;
				q.push({to,nd+1});
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=2;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)bfs(i);
	for(int i:p[1]){
		if(i==1)continue;
		for(int j:p[i]){
			if(i==j)continue;
			got[j]=1;
			if(val[i]>val[fir[j]])sec[j]=fir[j],fir[j]=i;
			else if(val[i]>val[sec[j]])sec[j]=i;
		}
	}
	int a,b,c,d;
	ll ans=0;
	set<T> ls;
	for(int i=2;i<=n;i++){
		if(!got[i])continue;
		for(int j=2;j<=n;j++){
			if(!got[j]||i==j||!can[i][j])continue;
			ls.clear();
			a=fir[i],b=sec[i],c=fir[j],d=sec[j];
			ls.insert({a}),ls.insert({b}),ls.insert({c}),ls.insert({d});
			if(ls.count({i}))ls.erase({i});
			if(ls.count({j}))ls.erase({j});
			if(ls.size()>=2)ans=max(ans,val[i]+val[j]+val[(*ls.begin()).pos]+val[(*nxt(ls.begin())).pos]);
		}
	}
	cout<<ans;
	return 0;
}

