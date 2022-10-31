#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005],b[100005],c[10005][10005],n,m,q;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for (int i = 1;i<=n;i++)cin>>a[i];
	for (int i = 1;i<=m;i++)cin>>b[i];
	for (int i = 1;i<=n;i++){
		for (int j = 1;j<=m;j++){
			c[i][j] = a[i]*b[j];
		}
	}
	ll l1,r1,l2,r2;
	while (q--){
		cin>>l1>>r1>>l2>>r2;
		if (l1 == r1){
			ll mmin = 1000000000000000001;
			for (int i = l2;i<=r2;i++){
				if (c[l1][i]<mmin)mmin = c[l1][i];
			}
			cout<<mmin<<endl;
		}
		else if (l2 == r2){
			ll mmax = -1000000000000000001;
			for (int i = l1;i<=r1;i++){
				if (c[i][l2]>mmax)mmax = c[i][l2];
			}
			cout<<mmax<<endl;
		}
		else if(l1 == r1 && l2 == r2){
			cout<<c[l1][l2]<<endl;
		}
		else cout<<c[n/2][m/2];
	}
	return 0;
}
