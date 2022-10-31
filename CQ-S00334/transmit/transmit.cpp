#include<bits/stdc++.h>
using namespace std;
int n,k;
typedef long long ll;
const int maxn=2e5+5;
vector<int> G[maxn];
struct node{
	int to;
	ll w;
}t1,t2;
bool operator<(const node &P,const node &Q){
	return P.w>Q.w;
}
ll vis[maxn];
bool flag[maxn];
ll W[maxn];
void Dij(int s){
	priority_queue<node> q;
	t1.to=s,t1.w=W[s];
	q.push(t1);
	memset(vis,127,sizeof(vis));
	memset(flag,0,sizeof(flag));
	vis[s]=W[s];
	while(!q.empty()){
		t1=q.top();
		int u=t1.to;
//		printf("%d\n",u);
		q.pop();
		if(flag[u])	continue;
		flag[u]=1;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(vis[v]>t1.w+W[v]){
				vis[v]=t1.w+W[v];
				t2.to=v,t2.w=t1.w+W[v];
//				printf("%d %d %d\n",u,v,t2.w);
				q.push(t2);
			}
		}
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int Q;
	scanf("%d%d%d",&n,&Q,&k);
	for(int i=1;i<=n;i++)	scanf("%lld",&W[i]);
	for(int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	while(Q--){
		int u,v;
		scanf("%d%d",&u,&v);
		Dij(u);
		printf("%lld\n",vis[v]);
	}
	return 0;
}
