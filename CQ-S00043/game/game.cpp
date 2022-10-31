#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[100001],b[100001],l1,l2,r1,r2,q,c[10000][10000],d[10],e[10];
int main() {
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=m; i++) {
		cin>>b[i];
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[i][j]=a[i]*b[j];
		}
	}*/
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		cout<<	c[i][j];

		}
	}*/
	for(int i=1; i<=q; i++) {
		ans=-1e7-5;
		long long x=1e7+5,y=-1e7;
		cin>>l1>>r1>>l2>>r2;
		for(int i=l1; i<=r1; i++) {
         y=max(y,a[i]);
		}
		if(y>0){
			for(int j=l2; j<=r2; j++) {
	         x=min(x,b[j]);
		} 
		cout<<x*y;
		
		}
		else{
			x=-1e7;
			for(int i=l2;i<=r2;i++){
				x=max(x,b[i]);
			}
			cout<<x*y;
		}
		//cout<<ans;
	}
	return 0;
}

