#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,c;
const int maxn=200005;
ll head[maxn],enext[maxn],w[maxn],ey[maxn],ans;
bool visit[maxn];
bool DFS2(ll u,ll cnt){
	if(u==1) return 1;
	if(cnt>k+1) return 0;
	for(int i=head[u];i;i=enext[i]){
		if(ey[i]==1) return 1;
		DFS2(ey[i],cnt+1);
	}
}
void DFS(ll u,ll sum,ll num,ll cnt){
	if(num==4){
		bool f=DFS2(u,0);
		if(f==1) {
			ans=max(ans,sum);	
		}
		return;
	}
	for(ll i=head[u];i;i=enext[i]){
		if(cnt>k) return;
		if(!visit[ey[i]]){
			visit[ey[i]]=1;
			DFS(ey[i],sum+w[ey[i]],num+1,0);
			visit[ey[i]]=0;
		}
		if(cnt<=k){
			DFS(ey[i],sum,num,cnt+1);	
		}		
	}
	return;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<n;i++){
		scanf("%lld",&w[i+1]);
	}
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		c++;
		enext[c]=head[x],head[x]=c,ey[c]=y;
		c++;
		enext[c]=head[y],head[y]=c,ey[c]=x;
	}
	bool f=DFS2(1,0);
	DFS(1,0,0,0);
	cout<<ans<<endl;
	return 0;
}
