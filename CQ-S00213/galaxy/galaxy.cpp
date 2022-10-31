#include<bits/stdc++.h>
using namespace std;
const int MaxN=500000,MaxM=500000;
typedef unsigned long long ullong;
struct Edge{
	int next;
	int from;
	int to;
	bool useful;
	inline Edge(){}
	inline Edge(const int next,const int from,const int to)
		:next(next),from(from),to(to),useful(true){}
}edge[MaxM+10];
struct Hasher{
	inline ullong operator()(const pair<int,int>&pi)const{
		return pi.first*pi.second;
	}
};
unordered_map<pair<int,int>,int,Hasher>edgeInd;
vector<int>redge[MaxN+10];
int edgeCnt[MaxN+10];
int cnt=0,h[MaxN+10];
inline void AddEdge(const int from,const int to){
	edge[++cnt]=Edge(h[from],from,to);
	h[from]=cnt;
	edgeInd[make_pair(from,to)]=cnt;
	redge[to].push_back(cnt);
	edgeCnt[from]++;
}
int n,m;
void Read(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		AddEdge(x,y);
	}
}
int q;
int unOKcnt=0;
void Modify0(const int u,const int v){
	edge[edgeInd[make_pair(u,v)]].useful=false;
	edgeCnt[u]--;
	if(edgeCnt[u]==1)unOKcnt--;
	else unOKcnt++;
}
void Modify1(const int u){
	for(int i=0;i<(int)redge[u].size();i++){
		if(edge[redge[u][i]].useful){
			edge[redge[u][i]].useful=false;
			edgeCnt[edge[redge[u][i]].from]--;
			if(edgeCnt[edge[redge[u][i]].from]==1)unOKcnt--;
			else unOKcnt++;
		}
	}
}
void Modify2(const int u,const int v){
	edge[edgeInd[make_pair(u,v)]].useful=true;
	edgeCnt[u]++;
	if(edgeCnt[u]==1)unOKcnt--;
	else unOKcnt++;
}
void Modify3(const int u){
	for(int i=0;i<(int)redge[u].size();i++){
		if(!edge[redge[u][i]].useful){
			edge[redge[u][i]].useful=true;
			edgeCnt[edge[redge[u][i]].from]++;
			if(edgeCnt[edge[redge[u][i]].from]==1)unOKcnt--;
			else unOKcnt++;
		}
	}
}
inline void Solve(){
	for(int u=1;u<=n;u++)
		if(edgeCnt[u]!=1)
			unOKcnt++;
	cin>>q;
	for(int i=1;i<=q;i++){
		int t,u,v;
		cin>>t;
		if(t==1){
			cin>>u>>v;
			Modify0(u,v);
		}else if(t==2){
			cin>>u;
			Modify1(u);
		}else if(t==3){
			cin>>u>>v;
			Modify2(u,v);
		}else if(t==4){
			cin>>u;
			Modify3(u);
		}
		if(unOKcnt)cout<<"NO\n";
		else cout<<"YES\n";
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
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
