#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
const int N=1e5+10;
int n,m,k;
int a[N],b[N];
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
	while(k--){
		int l1,r1,l2,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		int cnt1=0,cnt2=-1e18,cnt3=1e18+7;
		for(int i=l2;i<=r2;i++){
			if(b[i]==0) cnt1=1;
			else{
				cnt2=max(cnt2,b[i]);
				cnt3=min(cnt3,b[i]);
			} 
		}
		int res=-1e18;
		for(int i=l1;i<=r1;i++){
			if(a[i]==0) res=max(res,1ll-1);
			else if(a[i]>0) res=max(res,a[i]*cnt3);
			else res=max(res,a[i]*cnt2);
		}
		if(res>0&&cnt1) printf("0\n");
		else printf("%lld\n",res);
	}
	return 0;
}/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
