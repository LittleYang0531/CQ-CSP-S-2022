#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[100005],b[100005];
int l1,l2,r1,r2;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=q;i++){
		cin>>l1>>r1>>l2>>r2;
		long long x=l1,y=l2;
		for(int j=l1;j<=r1;j++){
			int xn=j,yn=l2;
			for(int k=l2;k<=r2;k++){
				if(a[j]*b[k]<a[xn]*b[yn]){
					xn=j;
					yn=k;
				}
			}
			if(a[xn]*b[yn]>a[x]*b[y]||j==1){
				x=xn;
				y=yn;
			}
		}
		cout<<a[x]*b[y]<<endl;
	}
	return 0;
}

