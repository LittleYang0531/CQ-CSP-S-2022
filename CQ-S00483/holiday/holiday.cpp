#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,k,numbers[3005];
long long maps[3005][3005],ans=0;
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%lld",&numbers[i]);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		maps[x][y]=maps[y][x]=1;
	}
	sort(numbers+1,numbers+n+1);
	for(int i=n;i>=n-3;i--){
		ans+=numbers[i];
	}
	ans-=numbers[n/2];
	printf("%lld",ans);
	return 0;
}
