#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2505;
int n,m,k;
ll w[maxn];
vector<int> G[maxn],GG[maxn];
struct node{
	int to,w;
}t1,t2;
bool operator<(const node &P,const node &Q){
	return P.w>Q.w;
}
int vis[maxn];
bool flag[maxn];
void Dij(int s){
	priority_queue<node> q;
	t1.to=s,t1.w=0;
	q.push(t1);
	memset(vis,127,sizeof(vis));
	memset(flag,0,sizeof(flag));
	vis[s]=0;
	while(!q.empty()){
		t1=q.top();
		int u=t1.to;
//		printf("%d\n",u);
		q.pop();
		if(flag[u])	continue;
		flag[u]=1;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(vis[v]>t1.w+1){
				vis[v]=t1.w+1;
				t2.to=v,t2.w=t1.w+1;
//				printf("%d %d %d\n",u,v,t2.w);
				q.push(t2);
			}
		}
	}
}
bool F[maxn];
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)	scanf("%lld",&w[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		Dij(i);
		for(int j=i+1;j<=n;j++){
//			printf("%d %d : %d\n",i,j,vis[j]);
			if(vis[j]-1<=k)	GG[i].push_back(j),GG[j].push_back(i);
			if(i==1&&vis[j]-1<=k)	F[j]=1;
		}
	}
	ll ans=0;
	for(int i:GG[1]){
		for(int j:GG[i]){
			if(i==j||1==j)	continue;
			for(int o:GG[j]){
				if(i==o||j==o||1==o)	continue;
				for(int l:GG[o]){
					if(i==l||j==l||o==l||1==l)	continue;
					if(!F[l])	continue;
					ans=max(ans,w[i]+w[j]+w[o]+w[l]);
//					if(w[i]+w[j]+w[o]+w[l]==30)	printf("%d %d %d %d\n",i,j,o,l);
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
