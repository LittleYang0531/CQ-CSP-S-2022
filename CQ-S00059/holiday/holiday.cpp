#include<bits/stdc++.h>
#define ll long long
#define inf 100005ll
#define maxn 2505
#define maxm 10005
using namespace std;
//2500 10000 100
ll n,m,k,a[maxn],ans;
ll f[maxn][maxn],an,v[maxn];
inline void dfs(ll x,ll now){
	if(x==4){
		//cout<<now<<" "<<f[1][now]<<" "<<an<<"\n";
		if(f[1][now]<=k)ans=max(ans,an);
		return ;
	}
	for(ll i=2;i<=n;++i){
		if(v[i]==1)continue;
		if(f[i][now]<=k){
			an+=a[i];
			v[i]=1;
			dfs(x+1,i);
			an-=a[i];
			v[i]=0;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);++k;
	for(ll i=1;i<=n;++i)for(ll j=1;j<=n;++j)if(i!=j)f[i][j]=inf;
	for(ll i=2;i<=n;++i)scanf("%lld",&a[i]);
	for(ll i=1;i<=m;++i){ll x,y;
		scanf("%lld%lld",&x,&y);
		f[x][y]=f[y][x]=1;
	}
	for(ll k=1;k<=n;++k)
		for(ll i=1;i<=n;++i){
			if(f[i][k]==inf)continue;
			for(ll j=1;j<=n;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
//	for(ll i=1;i<=n;++i){
//		for(ll j=1;j<=n;++j)cout<<f[i][j]<<" ";
//		cout<<"\n";
//	}
	dfs(0,1);
	printf("%lld",ans);
	return 0;
}
/*
7 9 0 
1 1 1 2 3 4 
1 2 
2 3 
3 4 
1 5 
1 6 
1 7 
5 4 
6 4 
7 4 
*/
