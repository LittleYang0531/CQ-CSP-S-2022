#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long a[100010],b[100010];
long long mna[100010];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q; 
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	while(q--){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		long long mxx=l1,ans=-1e18;
		for(int i=l1;i<=r1;i++){
			mna[i]=1e18;
			for(int j=l2;j<=r2;j++){
				mna[i]=min(mna[i],a[i]*b[j]);
			}
			ans=max(ans,mna[i]);
		} 
		cout<<ans<<endl;
	}
	return 0;
}
