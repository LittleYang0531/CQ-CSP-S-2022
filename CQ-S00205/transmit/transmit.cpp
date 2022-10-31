#include <bits/stdc++.h>
#define int long long
#define inf 4000000000000000000ll
using namespace std;
int n,Q,K,a[2020],st[2020],ed[2020],ans[2020][2020];
int dist[2020],vis[2020];
vector<int>v[2020],p[2020];
void getdist(int now,int step){
	dist[now]=step;
	vis[now]=1;
	p[step].push_back(now);
	for(int i=0,nx;i<v[now].size();i++){
		if(!vis[(nx=v[now][i])])getdist(nx,step+1);
	}
}
struct node{
	int id,dis,ti=inf;
	bool operator < (const node &oth)const{
		if(oth.dis!=dis) return dis<oth.dis;
		return id<oth.id;
	}
}tmpp;
priority_queue< node > pq;
void bfs(int stt){
	tmpp.dis=0,tmpp.id=stt,tmpp.ti=a[stt];
	pq.push(tmpp);
	int dd;
	while(!pq.empty()){
		node now=pq.top(),nxt;pq.pop();
		for(int delt=1;delt<=K;delt++){
			dd=now.dis+delt;nxt.dis=dd;
			for(int i=0;i<p[dd].size();i++){
				nxt.id=p[dd][i];nxt.ti=inf;
				nxt.ti=min(nxt.ti,now.ti+a[nxt.id]);
				ans[stt][nxt.id]=min(ans[stt][nxt.id],nxt.ti);
				pq.push(nxt);
			}
		}
	}
	return;
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>Q>>K;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&st[i],&ed[i]);
		v[st[i]].push_back(ed[i]);
		v[ed[i]].push_back(st[i]);
	}
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=0;j<=n+2;j++)p[j].clear();
		getdist(i,0);
		bfs(i);
	}
	for(int ll,rr;Q;Q--){
		scanf("%lld%lld",&ll,&rr);
		printf("%lld\n",ans[ll][rr]);
	}
	return 0;
}
