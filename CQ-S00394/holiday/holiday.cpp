#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define fi first
#define se second
using namespace std;
const int N=2.5e3+5;
const int M=1e4+5;
int n,m,k,dis[N];
ll s[N],ans;
vector<pli> ss[N];
priority_queue<pii,vector<pii>,greater<pii> > heap;
bool ed[N][N],in[N];
vector<int> v;
struct Graph{
	int id,h[N],e[2*M],ne[2*M];
	bool vis[N];
	void add(int a,int b){
		id++;
		ne[id]=h[a];
		h[a]=id;
		e[id]=b;
	}
	void dijkstra(int s){
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		while(heap.size()){
			heap.pop();
		}
		heap.push({dis[s]=0,s});
		while(heap.size()){
			int p=heap.top().se;
			heap.pop();
			if(dis[p]>=k){
				break;
			}
			if(!vis[p]){
				vis[p]=1;
				for(int i=h[p];i;i=ne[i]){
					if(dis[e[i]]>dis[p]+1){
						heap.push({dis[e[i]]=dis[p]+1,e[i]});
					}
				}
			}
		}
	}
}G;
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	k++;
	for(int i=2;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G.add(a,b);
		G.add(b,a);
	}
	for(int i=1;i<=n;i++){
		G.dijkstra(i);
		for(int j=1;j<=n;j++){
			if(j!=i&&dis[j]<=k){
				ed[i][j]=ed[j][i]=1;
				ss[i].push_back({s[j],j});
			}
		}
	}
	for(int i=1;i<=n;i++){
		sort(ss[i].begin(),ss[i].end(),greater<pli>());
	}
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int p=0;p<3;p++){
				for(int q=0;q<3;q++){
					if(ed[i][j]&&p<ss[i].size()&&q<ss[j].size()&&ed[1][ss[i][p].se]&&ed[1][ss[j][q].se]){
						if(i!=j&&i!=ss[j][q].se&&j!=ss[i][p].se&&ss[i][p].se!=ss[j][q].se){
							ans=max(ans,s[i]+s[j]+ss[i][p].fi+ss[j][q].fi);
						}
					}
				} 
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
