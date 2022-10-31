#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
const int N=2e5+10;
int n;
int m,k;
int a[N];
int ans=0;
bool st[N];
int h[N],idx=0;
vector<int> to[N],kl;
map<int,map<int,int> > dis;
map<int,map<int,bool> > mp;
struct Node{
	int to,ne;
}tr[N*2];
void add(int u,int v){
	tr[idx].to=v,tr[idx].ne=h[u],h[u]=idx++;
}
bool dfs(int x,int y,int u,int p){
	if(u==y) return true;
	for(int i=h[u];i!=-1;i=tr[i].ne){
		int j=tr[i].to;
		if(st[j]) continue;
		if(p<k&&dfs(x,y,j,p+1)){
			st[j]=true;
			kl.push_back(j);
			return true;
		}
		else continue;
	}
	return false;
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		to[v].push_back(u);
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			memset(st,false,sizeof st);
			kl.clear();
			st[i]=true;
			dfs(i,j,i,-1);
			kl.push_back(i);
			for(int l=0;l<kl.size();l++) dis[i][j]+=a[kl[l]];
		}
	}
	while(m--){
		int u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		if(u==v) dis[u][v]=0;
		dis[u][v]=min(dis[u][v],a[u]+a[v]+a[1]);
		cout<<dis[u][v]<<endl;
	}
	return 0;
}/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2
*/
