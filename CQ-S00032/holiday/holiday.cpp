#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18+5;
const int N=2505;
int n,m,k;
ll d[N];
vector<int> a[N];
struct EDGE{
	int v,nex;
}e[N<<1];
int head[N<<1],cnt;
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
int vis[N];
void get_a(int x,int father,int step,int K){
	if(step>k+1) return;
	if(x!=K&&!vis[x]) a[K].push_back(x),vis[x]=1;
	for(int i=head[x];i;i=e[i].nex){
		int v=e[i].v;
		if(v==father) continue;
		get_a(v,x,step+1,K);
	}
}
int flag[N];
ll maxn[N],maxnn[N],maxnnn[N];
int id1[N],id2[N],id3[N];
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%lld",&d[i]);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		get_a(i,0,0,i);
	}
	for(int i=0;i<(int)a[1].size();i++) flag[a[1][i]]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<(int)a[i].size();j++){
			int x=a[i][j];
			if(x==1) continue;
			if(flag[x]){
				if(d[x]>maxn[i]){
					maxnnn[i]=maxnn[i];
					maxnn[i]=maxn[i];
					maxn[i]=d[x];
					id3[i]=id2[i];
					id2[i]=id1[i];
					id1[i]=x;
				}
				else if(d[x]>maxnn[i]){
					maxnnn[i]=maxnn[i];
					maxnn[i]=d[x];
					id3[i]=id2[i];
					id2[i]=x;
				}
				else if(d[x]>maxnnn[i]){
					maxnnn[i]=d[x];
					id3[i]=x;
				}
			}
		}
	}
	ll ans=0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<(int)a[i].size();j++){
			int x=i,y=a[i][j];
			if(y==1) continue;
			ll sum=d[x]+d[y];
			int id=0;
			if(id1[x]==y) sum+=maxnn[x],id=id2[x];
			else sum+=maxn[x],id=id1[x];
			if(id1[y]==x||id1[y]==id){
				if(id2[y]==x||id2[y]==id) sum+=maxnnn[y];
				else sum+=maxnn[y];
			}
			else sum+=maxn[y];
			ans=max(ans,sum);
		}
	}
	printf("%lld",ans);
	return 0;
}
