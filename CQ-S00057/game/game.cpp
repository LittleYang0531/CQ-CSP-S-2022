#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
void fine(){
	 freopen("game.in","r",stdin);
	 freopen("game.out","w",stdout);
}
long long a[100005],b[100005];
int main(){
	fine();
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m,q,l1,l2,r1,r2;
	bool bj = 1;
	cin>>n>>m>>q;
	for(long long i = 1;i<=n;i++) {
		cin>>a[i];
		if(a[i] <= 0) bj = 0;
	}
	for(long long i = 1;i<=m;i++){
		cin>>b[i];
		if(b[i] <= 0) bj = 0;
	}
	for(long long k = 1;k<=q;k++){
		cin>>l1>>r1>>l2>>r2;
		if(l1 == r1||l2 == r2||bj == 1){
			long long ans1 = -0x7fffffffffffffff,ans2 = 0x7fffffffffffffff;
			for(long long j = l1;j<=r1;j++) {
				ans1 = max(ans1,a[j]);
			}
			for(long long j = l2;j<=r2;j++) {
				ans2 = min(ans2,b[j]);
			}
			cout<<ans1*ans2<<'\n';
			continue;
		}
		long long ans = -0x7fffffffffffffff;
		long long a1 = b[l2],a2 = b[l2],a3 = b[l2],a4 = b[l2],a5 = 5;
		for(long long j = l2;j<=r2;j++){
			a1 = min(a1,b[j]);
			a4 = max(a4,b[j]);
			if(b[j] < 0) a2 = max(a2,b[j]);
			if(b[j] == 0) a5 = 0; 
			if(b[j] > 0) a3 = min(a3,b[j]);
		}
		for(long long i = l1;i<=r1;i++){
			long long lzq = 0x7fffffffffffffff;
			lzq = min(a[i]*a1,min(a[i]*a2,min(a[i]*a3,a[i]*a4)));
			if(a5 == 0) lzq = min(lzq,a5);
			ans = max(ans,lzq);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
*/

