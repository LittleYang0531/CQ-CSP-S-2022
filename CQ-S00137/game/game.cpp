#include<bits/stdc++.h>
using namespace std;
long long n,m,q,a[100005],b[100005],l1,l2,r1,r2,ans[5],sum[5];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=q;i++){
		cin>>l1>>r1>>l2>>r2;
		ans[1]=ans[4]=sum[1]=sum[4]=-0x3f;
		ans[2]=ans[3]=sum[2]=sum[3]=0x3f;
		for(int j=l1;j<=r1;j++){
			ans[1]=max(ans[1],a[j]);
			ans[2]=min(ans[2],a[j]);
			if(a[j]>=0) ans[3]=min(ans[3],a[j]);
			if(a[j]<=0) ans[4]=max(ans[4],a[j]);
		}
		for(int k=l2;k<=r2;k++){
			sum[1]=max(sum[1],b[k]);
			sum[2]=min(sum[2],b[k]);
			if(b[k]>=0) sum[3]=min(sum[3],b[k]);
			if(b[k]<=0) sum[4]=max(sum[4],b[k]);
		}
		if(ans[1]>=0&&sum[2]>=0) cout<<ans[1]*sum[2]<<endl;
		else if(ans[2]<=0&&sum[1]<=0) cout<<ans[2]*sum[1]<<endl;
		else if(ans[2]>=0&&sum[2]<=0) cout<<ans[2]*sum[2]<<endl;
		else if(ans[1]<=0&&sum[1]>=0) cout<<ans[1]*sum[1]<<endl;
		else cout<<max(ans[3]*sum[2],ans[4]*sum[1])<<endl;
	}
	return 0;
}
