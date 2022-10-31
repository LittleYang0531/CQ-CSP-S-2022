#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2505,Inf=1e9,INF=2e18;
int n,m,k;
vector<int>son[N];
int d[N];
bool v[N],vst[N][N];
ll mx[N][4],num[N][4],a[N];
inline void spfa(int s){
	fill(d+1,d+n+1,Inf),fill(v+1,v+n+1,false);
	queue<int>q;
	d[s]=0,v[s]=true,q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();v[x]=false;
		for(int y:son[x]){
			if(d[x]+1<d[y]){
				d[y]=d[x]+1;
				if(!v[y])q.push(y),v[y]=true;
			}
		}
	}
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	++k;
	for(int i=2;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		son[x].push_back(y),son[y].push_back(x);
	}
	for(int i=1;i<=n;++i){
		spfa(i);
		for(int j=1;j<=n;++j)vst[i][j]=(d[j]<=k&&j!=i);
	}
	for(int i=2;i<=n;++i){
		for(int j=0;j<4;++j)mx[i][j]=num[i][j]=0;
		for(int j=2;j<=n;++j){
			if(vst[i][j]&&i!=j&&vst[1][j]){
				int id=j,sd=a[j];
				for(int K=0;K<4;++K){
					if(mx[i][K]<sd){
						int smax=mx[i][K],now=num[i][K];
						mx[i][K]=sd,num[i][K]=id;
						sd=smax,id=now;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=2;i<=n;++i){
		for(int j=2;j<=n;++j){
			if(vst[i][j]&&i!=j){
				for(int id1=0;id1<4;++id1){
					for(int id2=0;id2<4;++id2){
						if(num[i][id1]!=num[j][id2]&&j!=num[i][id1]&&i!=num[j][id2]&&num[i][id1]&&num[j][id2])ans=max(ans,mx[i][id1]+mx[j][id2]+a[i]+a[j]);
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
