#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll A[10005],B[10006],C[2500][2500];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ll n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=m;i++) cin>>B[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			C[i][j]=A[i]*B[j];
		}
	}
	for(int i=1;i<=q;i++){
		ll l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		ll ansl=-1e8;
		ll ansss;
		for(int j=l1;j<=r1;j++){
			int minn=1e8;
			for(int k=l2;k<=r2;k++){
				if(C[j][k]<minn){
					minn=C[j][k];
				}
			}
			if(minn>ansl){
				ansl=minn;
				ansss=j;
			}
		}
		int ansr=1e9;
		for(int j=l2;j<=r2;j++){
			if(C[ansss][j]<ansr)
			ansr=C[ansss][j];
		}
		cout<<ansr<<endl;
	}
	return 0;
}
/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
