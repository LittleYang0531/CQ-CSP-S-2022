#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Inf=LLONG_MAX,MaxN=2500,MaxM=10000;
struct Edge{
	int next;
	int to;
	Edge(){}
	Edge(const int next,const int to):next(next),to(to){}
}edge[MaxM*2+10];
int cnt=0,h[MaxN+10];
inline void AddEdge(const int from,const int to){
	edge[++cnt]=Edge(h[from],to);
	h[from]=cnt;
}
int n,m,k;
int s[MaxN+10];
void Read(){
	cin>>n>>m>>k;
	s[1]=0;
	for(int i=2;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		AddEdge(x,y);
		AddEdge(y,x);
	}
}
int dis[MaxN+10];
bool vst[MaxN+10];
void Bfs(const int st){
	for(int i=1;i<=n;i++){
		dis[i]=Inf;
		vst[i]=false;
	}
	queue<int>q;
	q.push(st);
	dis[st]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		vst[u]=true;
		for(int i=h[u];i;i=edge[i].next){
			if((!vst[edge[i].to])&&(dis[u]+1<dis[edge[i].to])){
				dis[edge[i].to]=dis[u]+1;
				q.push(edge[i].to);
			}
		}
	}
}
int ans=0;
unordered_set<int>v[MaxN+10];
void Dfs(int u,int sum,int ctr){
	if(ctr>=4){
//		cout<<ctr;
		if(v[u].find(1)!=v[u].end())
			ans=max(ans,sum+s[u]);
		return;
	}
	vst[u]=true;
	for(
		unordered_set<int>::iterator it=v[u].begin();
		it!=v[u].end();
		it++
	){
		if(!vst[(*it)]){
			Dfs((*it),sum+s[u],ctr+1);
		}
	}
	vst[u]=false;
}
void Solve(){
	for(int u=1;u<=n;u++){
		Bfs(u);
//cout<<u<<':';
//for(int i=1;i<=n;i++)
//	cout<<dis[i]<<' ';
//cout<<endl;
		for(int j=1;j<=n;j++){
			if(u!=j&&dis[j]-1<=k){
				v[u].insert(j);
			}
		}
//cout<<u<<':';
//for(
//	unordered_set<int>::iterator it=v[u].begin();
//	it!=v[u].end();
//	it++
//){
//	cout<<(*it)<<' ';
//}
//cout<<endl;
	}
	for(int i=1;i<=n;i++)vst[i]=false;
	Dfs(1,0,0);
	cout<<ans;
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	int T;
//	cin>>T;
//	while(T--){
		Read();
		Solve();
//	}
	return 0;
}

