/*
45 pts
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=305,K=105;
int n,m,k,a[N],u,v;
vector<int> g[N];
int dp[N][7];
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	if(k==0){
		for(int i=2;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%lld %lld",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(dp,-0x3f,sizeof dp);
		int L=g[1].size();
		for(int i=0;i<L;i++){
			int y=g[1][i];
			dp[y][1]=a[y];
		}
		for(int i=2;i<=4;i++){
			for(int j=1;j<=n;j++){
				int l=g[j].size(),maxn=-0x3f3f3f3f;
				for(int o=0;o<l;o++){
					int y=g[j][o];
					if(y<=j){
						maxn=max(maxn,dp[y][i-1]);
					}
				}
				dp[j][i]=maxn+a[j];
			}
		}
		int ans=-0x3f3f3f3f;
		for(int i=0;i<L;i++){
			int y=g[1][i];
			ans=max(ans,dp[y][4]);
		}
		printf("%lld",ans);
	}
	else{		
	}
	return 0;
}
