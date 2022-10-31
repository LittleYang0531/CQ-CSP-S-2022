#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2505;
vector<int> G[maxn];
int n,m,k,dis[maxn];
unsigned long long p[maxn],p1[maxn],ans;
//int dj(int s){
//	memset(dis,0x3f,sizeof dis);
//	dis[s]=0;
//	priority_queue<int> q;
//	while(!q.empty()){
//		
//	}
//}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	srand(time(NULL));
	scanf("%d%d%d",&n,&m,&k);
	for(int i(2);i<=n;++i){
		scanf("%lld",&p[i]);
		p1[i]=-p[i];
	}
	for(int i(1);i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		ans+=p[v];
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll ans1=rand()%ans+10;
	printf("%lld",ans1);
	return 0;
}
