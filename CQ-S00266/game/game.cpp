#include<bits/stdc++.h>
using namespace std;
long long n,m,q,a[100005],b[100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
		cin>>b[j];
	}
	while(q--){
		long long l1,l2,r1,r2,minn=LONG_LONG_MAX,maxx=-LONG_LONG_MAX;
		cin>>l1>>r1>>l2>>r2;
		for(long long i=l1;i<=r1;i++){
			minn=LONG_LONG_MAX;
			for(long long j=l2;j<=r2;j++){
				minn=min(minn,a[i]*b[j]);
			}
			maxx=max(maxx,minn);
		}
		cout<<maxx<<endl;
	}
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
*/
