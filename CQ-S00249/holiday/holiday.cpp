#include<bits/stdc++.h>
#define maxn 10001
#define ll long long
#define pr pair<int,int>
using namespace std;
int n,m,k;
ll a[maxn],ans;
vector<int>mm[maxn];	
priority_queue<pr,vector<pr>,greater<pr> >q;
bool vis[maxn];
int nowdis[maxn];
vector<int>ma[maxn];
bool ism[2505][2505];
void dj(int x){
	memset(vis,0,sizeof(vis));
	memset(nowdis,0x7f,sizeof(nowdis));
	nowdis[x]=0;
	q.push({0,x});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(nowdis[u]>k) continue;
		for(auto v:mm[u]){
			if(nowdis[v]>nowdis[u]+1){
				nowdis[v]=nowdis[u]+1;
				q.push({nowdis[v],v});
			}
		}
	}
	//cout<<x<<" "<<nowdis[8]<<endl;
	for(int i=1;i<=n;i++){
		if(nowdis[i]!=0x7f7f7f7f&&i!=x){
			ma[x].push_back(i);
			ism[i][x]=1;
			ism[x][i]=1;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n-1;i++){
		scanf("%lld",&a[i+1]);
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		mm[u].push_back(v);
		mm[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		dj(i);
		//cout<<clock()<<endl;
	}
	for(auto a1:ma[1]){ 
		for(auto a2:ma[1]){
			if(a1==a2) continue;
			for(auto a3:ma[a1]){
				if(a3==a2||a3==a1) continue;
				for(auto a4:ma[a2]){
					if(a4==a2||a4==a1||a4==a3) continue;
					if(ism[a3][a4]&&ism[a4][a3]){
						ans=max(ans,a[a1]+a[a2]+a[a3]+a[a4]);
						//cout<<clock()<<endl;
					}
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

