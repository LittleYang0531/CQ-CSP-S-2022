#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;
using ull=unsigned long long;

const int N=2505;

struct Node{
	int d,id;
	Node(){}
	Node(int a,int b){id=a,d=b;}
	bool operator < (const Node&x) const{return d>x.d;}
};

struct Dian{
	int val,id;
	bool operator < (const Dian&x) const{return val>x.val;}
}a[N];

int n,m,k,dis[N][N],V[N];
vector<int> E[N],Jz;
ull ans;

void Dij(int S){
	memset(dis[S],0x3f,sizeof dis[S]);
	memset(V,0,sizeof V);
	dis[S][S]=0;
	priority_queue<Node> q;
	q.push(Node(S,0));
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if(V[u])continue;
		V[u]=1;
		for(auto v:E[u]){
			if(V[v])continue;
			if(dis[S][v]>dis[S][u]+1){
				dis[S][v]=dis[S][u]+1;
				q.push(Node(v,dis[S][v]));
			}
		}
	}
}

int Pd(int u){
	for(auto v:Jz){
		if(dis[u][v]<=k)return 0;
	}
	return 1;
}

void Dfs(int u,int sum,ull tmp){
	if(Pd(u))return;
	V[u]=1;
	if(sum==4){
		if(dis[u][1]<=k)ans=max(ans,tmp);
		return;
	}
	for(int i=1;i<n;++i){
		if(V[a[i].id])continue;
		if(dis[u][a[i].id]<=k)Dfs(a[i].id,sum+1,tmp+a[i].val);
	}
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	
	cin>>n>>m>>k;
	for(int i=2;i<=n;++i)cin>>a[i].val,a[i].id=i;
	for(int i=1;i<=m;++i){
		int a,b;
		cin>>a>>b;
		E[a].push_back(b);
		E[b].push_back(a);
	}
//	if(k==0){
//		Dfs()
//	}
	for(int i=1;i<=n;++i){
		Dij(i);
		for(int j=1;j<=n;++j)--dis[i][j];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)if(dis[i][1]<=k)Jz.push_back(i);
	memset(V,0,sizeof V);
	Dfs(1,0,0);
	cout<<ans;
	
	return 0;
}
