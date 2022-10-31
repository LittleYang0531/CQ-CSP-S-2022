#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[10001],b[10001][21],b1[10001][21],n,m,q,l1,r1,l2,r2;
ll ksm(ll a,ll b){
	ll res=1;
	while(b>0){
		if(b&1)res=res*a;
		a=a*a;
		b=b>1;
	}
	return res;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q; 
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=m;j++){
		cin>>b[j][0];
		b1[j][0]=b[j][0];
	}
	for(int i=1;i<=21;i++){
		for(int j=1;j+ksm(2,i)-1<=m;j++){
			b[j][i]=max(b[j][i-1],b[j+ksm(2,i-1)][i-1]);
			b1[j][i]=min(b1[j][i-1],b1[j+ksm(2,i-1)][i-1]);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>l1>>r1>>l2>>r2;
		ll ans=-1e15,maxn=-1e15,minn=1e15;
		ll k=log2(r2-l1+1);
		maxn=max(b[l2][k],b[r2-ksm(2,k)+1][k]);
		minn=min(b1[l2][k],b1[r2-ksm(2,k)+1][k]);
		for(int j=l1;j<=r1;j++){
			if(a[j]>=0)ans=max(ans,minn*a[j]);
			else ans=max(ans,maxn*a[j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
